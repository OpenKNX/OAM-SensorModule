// cSpell:words millis Millis Dewpoint EEPROM RSTL
#ifdef SENSORMODULE
#include "Helper.h"
#include "Schedule.h"
#include "oknx.h"

#ifdef WIREMODULE
#include "WireDevice.h"
#include "OneWireDS2482.h"
#endif

#include "SensorModule.h"
#include "Logic.h"

uint32_t gStartupDelay;
uint32_t gReadRequestDelay;
uint32_t gHeartbeatDelay;
uint32_t gSaveInterruptTimestamp;
uint16_t gCountSaveInterrupt;

SensorModule gSensor;
Logic gLogic;
#ifdef WIREMODULE
OneWireDS2482 *gBusMaster;
#endif

bool callOneWire() 
{
    return (boardWithOneWire() && ((knx.paramByte(SENS_Sensor1Wire) & SENS_Sensor1WireMask) >> SENS_Sensor1WireShift));
}

void ProcessHeartbeat()
{
    // the first heartbeat is send directly after startup delay of the device
    if (gHeartbeatDelay == 0 || delayCheck(gHeartbeatDelay, getDelayPattern(LOG_HeartbeatDelayBase)))
    {
        // we waited enough, let's send a heartbeat signal
        knx.getGroupObject(LOG_KoHeartbeat).value(true, getDPT(VAL_DPT_1));
        // if there is an error, we send it with heartbeat, too
        if (knx.paramByte(SENS_Error) & SENS_ErrorMask) {
            if (gSensor.getError()) gSensor.sendError();
        }
        gHeartbeatDelay = millis();
        // The module prints its firmware version to the console
        uint16_t lFirmwareVersion = knx.bau().deviceObject().version();
        printDebug("Firmware-Version [%d] %d.%d\n", lFirmwareVersion >> 11, (lFirmwareVersion >> 6) & 0x1F, lFirmwareVersion & 0x3F);
        // debug-helper for logic module
        // print("ParDewpoint: ");
        // println(knx.paramByte(SENS_Dewpoint));
        gLogic.debug();
    }
}

void ProcessReadRequests() {
    gLogic.processReadRequests();
    gSensor.processReadRequests(gStartupDelay, gReadRequestDelay);
}

// true solange der Start des gesamten Moduls verzögert werden soll
bool startupDelay()
{
    return !delayCheck(gStartupDelay, gReadRequestDelay);
}

bool processDiagnoseCommand()
{
    char *lBuffer = gLogic.getDiagnoseBuffer();
    bool lOutput = false;
    // let's check other modules for this command
    lOutput = gSensor.processDiagnoseCommand(lBuffer);
    if (!lOutput) lOutput = gLogic.processDiagnoseCommand();
    return lOutput;
}

void ProcessDiagnoseCommand(GroupObject &iKo) {
    // this method is called as soon as iKo is changed
    // an external change is expected
    // because this iKo also is changed within this method, 
    // the method is called again. This might result in 
    // an endless loop. This is prevented by the isCalled pattern.
    static bool sIsCalled = false;
    if (!sIsCalled) {
        sIsCalled = true;
        //diagnose is interactive and reacts on commands
        gLogic.initDiagnose(iKo);
        if (processDiagnoseCommand())
            gLogic.outputDiagnose(iKo);
        sIsCalled = false;
    }
};

void ProcessInputKo(GroupObject &iKo) {
    // check if we evaluate own KO
    if (iKo.asap() == LOG_KoDiagnose) {
        ProcessDiagnoseCommand(iKo);
    } else {
        gSensor.processInputKo(iKo);
#ifdef WIREMODULE
        WireDevice::processKOCallback(iKo);
#endif
        // else dispatch to logic module
        gLogic.processInputKo(iKo);
    }
}

// Schedule-callback for 1-Wire
void OneWireCallback(void *iInstance)
{
#ifdef WIREMODULE
    if (callOneWire()) {
        gBusMaster->loop();
        WireDevice::loop();
    }
#endif
}

// Schedule-callback for 1-Wire
void LogicCallback(void *iInstance)
{
    gLogic.loop();
}

void appLoop()
{
    if (!knx.configured())
        return;

    // handle KNX stuff
    if (startupDelay())
        return;

    // at this point startup-delay is done
    // we process heartbeat
    ProcessHeartbeat();
    ProcessReadRequests();
    gSensor.loop();
}

void appSetup(bool iSaveSupported)
{
    // try to get rid of occasional I2C lock...
    // savePower();
    // ledProg(true);
    ledInfo(true);
    // delay(1000);
    // restorePower();
    ledProg(true);
    // check hardware availability
    boardCheck();
    // moved to sensor lib
    // Wire.begin();
    // Wire.setClock(400000);
    ledInfo(false);
    ledProg(false);
    // The module prints its firmware version to the console
    uint16_t lFirmwareVersion = knx.bau().deviceObject().version();
    printDebug("Firmware-Version [%d] %d.%d\n", lFirmwareVersion >> 11, (lFirmwareVersion >> 6) & 0x1F, lFirmwareVersion & 0x3F);

    if (knx.configured())
    {
        gStartupDelay = millis();
        gReadRequestDelay = getDelayPattern(LOG_StartupDelayBase);
        gHeartbeatDelay = 0;
        gCountSaveInterrupt = 0;
        // GroupObject &lKoRequestValues = knx.getGroupObject(SENS_KoRequestValues);
        if (GroupObject::classCallback() == 0)
            GroupObject::classCallback(ProcessInputKo);
        // we add here loop handlers of submodules, which have to be processed frequently
        Schedule::addCallback(LogicCallback, nullptr);
        gSensor.setup();
        gLogic.setup(false);
#ifdef WIREMODULE
        if (callOneWire())
        {
            Schedule::addCallback(OneWireCallback, nullptr);
            bool lSearchNewDevices = knx.paramByte(WIRE_IdSearch) & WIRE_IdSearchMask;
            // Logic should call busmaster loop as often als knx loop
            // Logic::addLoopCallback(WireBus::loopCallback, &gBusMaster);
            // gBusMaster->setup(0, lSearchNewDevices, true);
            gBusMaster = new OneWireDS2482(WireDevice::processNewIdCallback, WireDevice::knxLoopCallback);
            gBusMaster->setup(0, 0, lSearchNewDevices);
            gBusMaster->setupTiming(
                (knx.paramByte(WIRE_Busmaster1RSTL) & WIRE_Busmaster1RSTLMask) >> WIRE_Busmaster1RSTLShift,
                (knx.paramByte(WIRE_Busmaster1MSP) & WIRE_Busmaster1MSPMask) >> WIRE_Busmaster1MSPShift,
                (knx.paramByte(WIRE_Busmaster1W0L) & WIRE_Busmaster1W0LMask) >> WIRE_Busmaster1W0LShift,
                (knx.paramByte(WIRE_Busmaster1REC0) & WIRE_Busmaster1REC0Mask) >> WIRE_Busmaster1REC0Shift,
                (knx.paramByte(WIRE_Busmaster1WPU) & WIRE_Busmaster1WPUMask) >> WIRE_Busmaster1WPUShift);

            // initialize all known 1-Wire-sensors from application data
            for (uint8_t lDeviceIndex = 0; lDeviceIndex < COUNT_1WIRE_CHANNEL; lDeviceIndex++)
            {
                // check for family information
                uint8_t lFamily = knx.paramByte(lDeviceIndex * WIRE_ParamBlockSize + WIRE_ParamBlockOffset + WIRE_sFamilyCode);
                if (lFamily > 0)
                {
                    // looks strange, but all 1-wire devices are handled through static methods after creation
                    new WireDevice(lDeviceIndex, &gBusMaster);
                }
            }
        }
#endif
        openknx.flashUserData()->readFlash();
   }
}
#endif
