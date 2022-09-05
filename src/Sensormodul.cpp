#include "Helper.h"
#include "HardwareDevices.h"

#include "Sensor.h"
#include "SensorBME680.h"
#include "SensorSGP30.h"
#include "OneWire.h"
#include "WireDevice.h"
#include "OneWireDS2482.h"
#include "IncludeManager.h"

// Reihenfolge beachten damit die Definitionen von Sensormodul.h ...
#include "Sensormodul.h"
// ... auf jeden Fall Vorrang haben (beeinflussen auch die Logik)
// #include "../../knx-logic/src/LogikmodulCore.h"
#include "Logic.h"

const uint8_t cFirmwareMajor = 3;    // 0-31
const uint8_t cFirmwareMinor = 8;    // 0-31
const uint8_t cFirmwareRevision = 0; // 0-63

// Achtung: Bitfelder in der ETS haben eine gewöhnungswürdige
// Semantik: ein 1 Bit-Feld mit einem BitOffset=0 wird in Bit 7(!) geschrieben
#define BIT_1WIRE 1
#define BIT_Temp 2
#define BIT_Hum 4
#define BIT_Pre 8
#define BIT_Voc 16
#define BIT_Co2 32
#define BIT_Co2Calc 64
#define BIT_LOGIC 128
#define BIT_LUX 256
#define BIT_TOF 512

uint32_t gStartupDelay;
uint32_t gHeartbeatDelay;
bool gIsRunning = false;
sSensorInfo gTemp;
sSensorInfo gHum;
sSensorInfo gPre;
sSensorInfo gVoc;
sSensorInfo gCo2;
sSensorInfo gCo2b;
sSensorInfo gDew;
sSensorInfo gLux;
sSensorInfo gTof;
WireDevice gDevice[COUNT_1WIRE_CHANNEL];
uint16_t gCountSaveInterrupt = 0;
uint32_t gSaveInterruptTimestamp = 0;
bool gForceSensorRead = true;
int8_t gTempOffset = 0;

uint16_t gSensor = 0;
Logic gLogic;
OneWireDS2482 *gBusMaster;

typedef bool (*getSensorValue)(MeasureType, float&);
void ProcessInterrupt();

uint16_t getError() {
    return (uint16_t)knx.getGroupObject(SENS_KoError).value(getDPT(VAL_DPT_7));
}

void setError(uint16_t iValue) {
    knx.getGroupObject(SENS_KoError).valueNoSend(iValue, getDPT(VAL_DPT_7));
}

void sendError() {
    knx.getGroupObject(SENS_KoError).objectWritten();
}

bool callOneWire() {
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
            if (getError()) sendError();
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
    static uint8_t sCalled = 1;
    // the following code should be called only once
    gLogic.processReadRequests();
    if (sCalled < 255) {

        // we evaluate only Bit 2 here, which holds the information about read external values on startup
        if (sCalled == 1 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_TempExtRead) & SENS_TempExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Temp).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Temp).requestObjectRead();
            }
        }
        if (sCalled == 2 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_HumExtRead) & SENS_HumExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Hum).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Hum).requestObjectRead();
            }
        }
        if (sCalled == 3 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_PreExtRead) & SENS_PreExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Pre).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Pre).requestObjectRead();
            }
        }
        if (sCalled == 4 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_VocExtRead) & SENS_VocExtReadMask) {
                knx.getGroupObject(SENS_KoExt1VOC).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2VOC).requestObjectRead();
            }
        }
        if (sCalled == 5 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_Co2ExtRead) & SENS_Co2ExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Co2).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Co2).requestObjectRead();
            }
        }
        if (sCalled == 6 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_LuxExtRead) & SENS_LuxExtReadMask)
            {
                knx.getGroupObject(SENS_KoExt1Lux).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Lux).requestObjectRead();
            }
        }
        if (sCalled == 7 && delayCheck(gStartupDelay, sCalled * 1000))
        {
            sCalled += 1;
            if (knx.paramByte(SENS_TofExtRead) & SENS_TofExtReadMask)
            {
                knx.getGroupObject(SENS_KoExt1Tof).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Tof).requestObjectRead();
            }
        }
        if (sCalled == 8)
        {
            sCalled = 255;
        }
    }
}

void loopSubmodules() {
    knx.loop();
    if (callOneWire()) {
        gBusMaster->loop();
        WireDevice::loop();
    }
    gLogic.loop();
}

// true solange der Start des gesamten Moduls verzögert werden soll
bool startupDelay()
{
    return !delayCheck(gStartupDelay, getDelayPattern(LOG_StartupDelayBase));
}

// this callback is used by BME680 during delays while mesauring
// we implement this delay, but keep normal loop processing alive
void sensorDelayCallback(uint32_t iMillis) {
    // printDebug("sensorDelayCallback: Called with a delay of %lu ms\n", iMillis);
    uint32_t lMillis = millis();
    while (millis() - lMillis < iMillis) {
        if (gIsRunning) {
            ProcessHeartbeat();
            ProcessInterrupt();
            loopSubmodules();
        }
    }
    // printDebug("sensorDelayCallback: Left after %lu ms\n", millis() - lMillis);
}

void AddSensorMetadata(Sensor* iSensor, uint8_t iSensorId, MeasureType iMeasureType) {
    // additional sensor specific metadata
    uint8_t lMagicWordOffset = knx.paramByte(SENS_DeleteData) & SENS_DeleteDataMask;
    if (iSensorId == SENS_BME680)
    {
        ((SensorBME680*)iSensor)->delayCallback(sensorDelayCallback);
        ((SensorBME680*)iSensor)->setMagicKeyOffset(lMagicWordOffset);
    }
    else if (iSensorId == SENS_SGP30)
    {
        ((SensorSGP30*)iSensor)->setMagicKeyOffset(lMagicWordOffset);
    }
    if (iMeasureType == Temperature) {
        int32_t lTempOffsetInt = (int8_t)gTempOffset;
        float lTempOffset = (float)lTempOffsetInt / 10.0;
        if (iSensor->prepareTemperatureOffset(lTempOffset)) 
            gTempOffset = 0; // disable temp offset in software
    }
}

// Starting all required sensors, this call may be blocking (with delay)
void StartSensor()
{
    Sensor* lSensor;
    
    gSensor = 0;
    uint8_t lSensorId = (knx.paramByte(SENS_TempSensor) & SENS_TempSensorMask) >> SENS_TempSensorShift;
    if (lSensorId > 0) {
        gSensor |= BIT_Temp;
        lSensor = Sensor::factory(lSensorId, Temperature);
        AddSensorMetadata(lSensor, lSensorId, Temperature);
    }
    lSensorId = (knx.paramByte(SENS_HumSensor) & SENS_HumSensorMask) >> SENS_HumSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Hum;
        lSensor = Sensor::factory(lSensorId, Humidity);
        AddSensorMetadata(lSensor, lSensorId, Humidity);
    }
    lSensorId = (knx.paramByte(SENS_PreSensor) & SENS_PreSensorMask) >> SENS_PreSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Pre;
        lSensor = Sensor::factory(lSensorId, Pressure);
        AddSensorMetadata(lSensor, lSensorId, Pressure);
    }
    lSensorId = (knx.paramByte(SENS_VocSensor) & SENS_VocSensorMask) >> SENS_VocSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Voc | BIT_Co2Calc;
        lSensor = Sensor::factory(lSensorId, static_cast<MeasureType>(Voc | Accuracy | Co2Calc));
        AddSensorMetadata(lSensor, lSensorId, static_cast<MeasureType>(Voc | Accuracy | Co2Calc));
    }
    lSensorId = (knx.paramByte(SENS_Co2Sensor) & SENS_Co2SensorMask) >> SENS_Co2SensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Co2;
        lSensor = Sensor::factory(lSensorId, Co2);
        AddSensorMetadata(lSensor, lSensorId, Co2);
    }
    lSensorId = (knx.paramByte(SENS_LuxSensor) & SENS_LuxSensorMask) >> SENS_LuxSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_LUX;
        lSensor = Sensor::factory(lSensorId, Lux);
        AddSensorMetadata(lSensor, lSensorId, Lux);
    }
    lSensorId = (knx.paramByte(SENS_TofSensor) & SENS_TofSensorMask) >> SENS_TofSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_TOF;
        lSensor = Sensor::factory(lSensorId, Tof);
        AddSensorMetadata(lSensor, lSensorId, Tof);
    }
    // now start all sensors at the correct speed
    Sensor::beginSensors();
}

bool ReadSensorValue(MeasureType iMeasureType, float& eValue) {
    return Sensor::measureValue(iMeasureType, eValue);
}

// the entries have the same order as the KOs starting with "Ext"
uint8_t gIsExternalValueValid[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// generic sensor processing
void ProcessSensor(sSensorInfo* cData, getSensorValue fGetSensorValue, MeasureType iMeasureType, float iOffsetFactor, float iValueFactor, uint16_t iParamIndex, uint16_t iKoNumber, uint8_t iDpt)
{   
    // we process just a sensor, which is selected in ETS
    if ((gSensor & iMeasureType) != iMeasureType) return;

    bool lForce = cData->sendDelay == 0;
    bool lSend = lForce;

    // process send cycle
    uint32_t lCycle = getDelayPattern(iParamIndex + 1);

    // we waited enough, let's send the value
    if (lCycle && delayCheck(cData->sendDelay, lCycle))
        lSend = true;

    // process read cycle
    if (lForce || delayCheck(cData->readDelay, 5000))
    {
        // we waited enough, let's read the sensor
        int32_t lOffset;
        if (iMeasureType == Temperature) {
            lOffset = (int8_t)gTempOffset;
        } else {
            lOffset = (int8_t)knx.paramByte(iParamIndex);
        }
        float lValue;
        bool lValid = fGetSensorValue(iMeasureType, lValue);
        if (lValid) {
            // we have now the internal sensor value, we correct it now
            lValue = lValue / iValueFactor;
            lValue += (lOffset / iOffsetFactor);
            // if there are external values to take into account, we do it here
            uint8_t lNumExternalValues = knx.paramByte(iParamIndex + 7) & 3;
            float lDivisor = 0.0f;
            float lDivident = 0.0f;
            float lFactor = 0.0f;
            uint8_t lExtKoIndex = (iKoNumber - SENS_KoTemp) * 2;
            if (iKoNumber > SENS_KoLux) {
                lExtKoIndex = (iKoNumber - SENS_KoLux + 5) * 2;
            }
            switch (lNumExternalValues)
            {
                case 2:
                    lFactor = knx.paramByte(iParamIndex + 10) * gIsExternalValueValid[lExtKoIndex + 1]; // factor for external value 2
                    lDivident = (float)knx.getGroupObject(lExtKoIndex + SENS_KoExt2Temp).value(getDPT(iDpt)) * lFactor;
                    lDivisor = lFactor;
                case 1:
                    lFactor = knx.paramByte(iParamIndex + 9) * gIsExternalValueValid[lExtKoIndex]; // factor for external value 1
                    lDivident += (float)knx.getGroupObject(lExtKoIndex + SENS_KoExt1Temp).value(getDPT(iDpt)) * lFactor;
                    lDivisor += lFactor;
                    lFactor = knx.paramByte(iParamIndex + 8); // factor for internal value
                    lDivident += lValue * lFactor;
                    lDivisor += lFactor;
                    if (lDivisor > 0.0f) lValue = lDivident / lDivisor;
                    break;
                default:
                    lDivisor = 1.0f;
                    break;
            }
            if (lDivisor > 0.1f) {
                // smoothing (? glätten ?) of the new value
                // Formel: Value = ValueAlt + (ValueNeu - ValueAlt) / p
                float lValueAlt = (float)knx.getGroupObject(iKoNumber).value(getDPT(iDpt));
                if (!(lForce && lValueAlt == 0.0f)) {
                    lValue = lValueAlt + (lValue - lValueAlt) / knx.paramByte(iParamIndex + 6);
                }
                // evaluate sending conditions (relative delta / absolute delta)
                if (cData->lastSentValue != 0.0f) {
                    float lDelta = 100.0f - lValue / cData->lastSentValue * 100.0f;
                    uint8_t lPercent = knx.paramByte(iParamIndex + 5);
                    if (lPercent > 0 && (uint8_t)round(abs(lDelta)) >= lPercent)
                        lSend = true;
                    float lAbsolute = knx.paramWord(iParamIndex + 3) / iOffsetFactor;
                    if (lAbsolute > 0.0f && roundf(abs(lValue - cData->lastSentValue)) >= lAbsolute)
                        lSend = true;
                }
                // we always store the new value in KO, even it it is not sent (to satisfy potential read request)
                if (lValue <= -0.01f || lValue >= 0.01f)
                    knx.getGroupObject(iKoNumber).valueNoSend(lValue, getDPT(iDpt));
            }
        } else {
            lSend = false;
        }
        cData->readDelay = millis();
    }
    if (lSend)
    {
        if ((getError() & iMeasureType) == 0) {
            float lValue = (float)knx.getGroupObject(iKoNumber).value(getDPT(iDpt));
            if (lValue <= -0.01f || lValue >= 0.01f) {
                knx.getGroupObject(iKoNumber).objectWritten();
                cData->lastSentValue = lValue;
            }
        }
        cData->sendDelay = millis();
        if (cData->sendDelay == 0) cData->sendDelay = 1;
    }
}

struct sPoint
{
    float x;
    float y;
};

sPoint comfort1[8] = {{17.0f, 88.8f}, {21.4f, 84.1f}, {25.0f, 60.0f}, {27.1f, 30.5f}, {25.9f, 29.5f}, {20.0f, 29.5f}, {17.1f, 48.8f}, {15.9f, 78.8f}};
sPoint comfort2[4] = {{17.5f, 74.7f}, {22.0f, 72.9f}, {24.3f, 37.6f}, {18.9f, 41.8f}};

bool InPolygon(sPoint *iPoly, uint8_t iLen, float iX, float iY)
{
    int j = iLen - 1;
    bool lResult = false;
    for (int i = 0; i < iLen; i++)
    {
        if (((iPoly[i].y > iY) != (iPoly[j].y > iY)) && (iX < (iPoly[j].x - iPoly[i].x) * (iY - iPoly[i].y) / (iPoly[j].y - iPoly[i].y) + iPoly[i].x))
        {
            lResult = !lResult;
        }
        j = i;
    }
    return lResult;
}

// static bool sTempHumValid = false;

// Dewpoint is a vitual sensor and might be implemented on sensor class level, but we implement it here (easier and shorter)
bool CalculateDewValue(MeasureType iMeasureType, float& eValue) {
    float lTemp = knx.getGroupObject(SENS_KoTemp).value(getDPT(VAL_DPT_9));
    float lHum = knx.getGroupObject(SENS_KoHum).value(getDPT(VAL_DPT_9));
    bool lTempHumValid = (((lTemp < 0.0f) || (lTemp > 0.0f)) && lHum > 0.0f);
    if (lTempHumValid) {
        float lLogHum = log(lHum / 100.0f);
        // eValue = 243.12f * ((17.62f * lTemp) / (243.12f + lTemp) + lLogHum) / ((17.62f * 243.12f) / (243.12f + lTemp) - lLogHum);
        eValue = 243.12f * ((17.62f * lTemp) / (243.12f + lTemp) + lLogHum) / (4283.7744 / (243.12f + lTemp) - lLogHum);
    }
    return lTempHumValid;
}

void CalculateComfort(bool iForce = false)
{
    static uint32_t sMillis = 0;
    bool lSend = iForce;
    if (iForce || delayCheck(sMillis, 1000))
    {
        sMillis = millis();
        // do not calculate if underlying measures are corrupt
        if (getError() & (Temperature | Humidity)) return;

        float lTemp = roundf(knx.getGroupObject(SENS_KoTemp).value(getDPT(VAL_DPT_9)));
        float lHum = roundf(knx.getGroupObject(SENS_KoHum).value(getDPT(VAL_DPT_9)));
        bool lTempHumValid = (((lTemp < 0.0f) || lTemp > 0.0f) && lHum > 0.0f);
        if (lTempHumValid && (knx.paramByte(SENS_Comfort) & SENS_ComfortMask))
        {
            // comfortzone
            uint8_t lComfort = 0;
            if (InPolygon(comfort2, 4, lTemp, lHum))
            {
                lComfort = 2;
            }
            else if (InPolygon(comfort1, 8, lTemp, lHum))
            {
                lComfort = 1;
            }
            if ((uint8_t)knx.getGroupObject(SENS_KoComfort).value(getDPT(VAL_DPT_5)) != lComfort)
                lSend = true;
            if (lSend)
                knx.getGroupObject(SENS_KoComfort).value(lComfort, getDPT(VAL_DPT_5));
        }
    }
}

void CalculateAccuracy(bool iForce = false)
{
    static uint32_t sMillis = 0;
    bool lSend = iForce;
    if (iForce || delayCheck(sMillis, 60000))
    {
        sMillis = millis();
        // do not calculate if underlying measures are corrupt
        if (getError() & Accuracy) return;

        if (knx.paramByte(SENS_Accuracy) & SENS_AccuracyMask)
        {
            // get accuracy
            float lAccuracyMeasure;
            bool lSuccess = Sensor::measureValue(Accuracy, lAccuracyMeasure);
            if (lSuccess) {
                uint8_t lAccuracy = (uint8_t)lAccuracyMeasure;
                uint8_t lOldAccuracy = (uint8_t)knx.getGroupObject(SENS_KoSensorAccuracy).value(getDPT(VAL_DPT_5001));
                if (lOldAccuracy != lAccuracy)
                    lSend = true;
                if (lSend)
                    knx.getGroupObject(SENS_KoSensorAccuracy).value(lAccuracy, getDPT(VAL_DPT_5001));
            }
        }
    }
}

uint8_t getAirquality(float iCurrent, float* iLimits) {
    uint8_t lResult = 6;
    for (uint8_t i = 0; i < 5; i++)
    {
        if (iCurrent < iLimits[i]) {
            lResult = i + 1;
            break;
        }
    }
    return lResult;
}

void CalculateAirquality(bool iForce = false)
{
    static uint32_t sMillis = 0;
    static float sVocLimits[5] = {51.0f,101.0f,151.0f,201.0f,301.0f};
    static float sCo2Limits[5] = {401.0f,701.0f,1001.0f,1401.0f,2001.0f};

    bool lSend = iForce;
    if (iForce || delayCheck(sMillis, 5000))
    {
        sMillis = millis();
        // do not calculate if underlying measures are corrupt
        if (getError() & (Voc | Co2)) return;

        if (knx.paramByte(SENS_Airquality) & SENS_AirqualityMask)
        {
            // do not calculate if underlying measureas are not yet available
            float lValue = 0;

            // get airquality
            uint8_t lAirquality = 6;
            if ((gSensor & BIT_Co2)) {
                // do not calculate if underlying measureas are not yet available
                if (!Sensor::measureValue(Co2, lValue))
                    return;
                lValue = knx.getGroupObject(SENS_KoCo2).value(getDPT(VAL_DPT_9));
                if (lValue <= 1.0)
                    lValue = knx.getGroupObject(SENS_KoCo2b).value(getDPT(VAL_DPT_9));
                lAirquality = getAirquality(lValue, sCo2Limits);
            } else if ((gSensor & BIT_Voc)) {
                if (!Sensor::measureValue(Voc, lValue))
                    return;
                lValue = knx.getGroupObject(SENS_KoVOC).value(getDPT(VAL_DPT_9));
                lAirquality = getAirquality(lValue, sVocLimits);
            }
            if ((uint8_t)knx.getGroupObject(SENS_KoAirquality).value(getDPT(VAL_DPT_5)) != lAirquality)
                lSend = true;
            if (lSend)
                knx.getGroupObject(SENS_KoAirquality).value(lAirquality, getDPT(VAL_DPT_5));
        }
    }
}

void ProcessSensors(bool iForce = false)
{
    static uint16_t sMeasureType = BIT_Temp;
    static bool sForceComfort = false;
    static bool sForceAirquality = false;
    static bool sForceAccuracy = false;

    if (iForce) {
        // in case we force sending of value, we set all send delays to 0
        gTemp.sendDelay = 0;
        gHum.sendDelay = 0;
        gPre.sendDelay = 0;
        gVoc.sendDelay = 0;
        gCo2.sendDelay = 0;
        gCo2b.sendDelay = 0;
        gDew.sendDelay = 0;
        gLux.sendDelay = 0;
        gTof.sendDelay = 0;
        sForceComfort = true;
        sForceAirquality = true;
        sForceAccuracy = true;
    }
    switch (sMeasureType)
    {
    case BIT_Temp:
        ProcessSensor(&gTemp, ReadSensorValue, Temperature, 10.0f, 1.0f, SENS_TempOffset, SENS_KoTemp, VAL_DPT_9);
        break;
    case BIT_Hum:
        ProcessSensor(&gHum, ReadSensorValue, Humidity, 1.0f, 1.0f, SENS_HumOffset, SENS_KoHum, VAL_DPT_9);
        break;
    case BIT_Pre:
        ProcessSensor(&gPre, ReadSensorValue, Pressure, 1.0f, 100.0f, SENS_PreOffset, SENS_KoPre, VAL_DPT_9);
        break;
    case BIT_Voc:
        ProcessSensor(&gVoc, ReadSensorValue, Voc, 1.0f, 1.0f, SENS_VocOffset, SENS_KoVOC, VAL_DPT_9);
        break;
    case BIT_Co2:
        ProcessSensor(&gCo2, ReadSensorValue, Co2, 1.0f, 1.0f, SENS_Co2Offset, SENS_KoCo2, VAL_DPT_9);
        break;
    case BIT_Co2Calc:
        ProcessSensor(&gCo2b, ReadSensorValue, Co2Calc, 1.0f, 1.0f, SENS_Co2Offset, SENS_KoCo2b, VAL_DPT_9);
        break;
    case BIT_LOGIC: // dew value, this constant is misleading...
        if ((gSensor & (BIT_Temp | BIT_Hum)) == (BIT_Temp | BIT_Hum))
            ProcessSensor(&gDew, CalculateDewValue, static_cast<MeasureType>(Temperature | Humidity), 10.0f, 1.0f, SENS_DewOffset, SENS_KoDewpoint, VAL_DPT_9);
        break;
    case BIT_LUX:
        ProcessSensor(&gLux, ReadSensorValue, Lux, 1.0f, 1.0f, SENS_LuxOffset, SENS_KoLux, VAL_DPT_9);
        break;
    case BIT_TOF:
        ProcessSensor(&gTof, ReadSensorValue, Tof, 1.0f, 1.0f, SENS_TofOffset, SENS_KoTof, VAL_DPT_7);
        break;
    case 0x400:
        if ((gSensor & (BIT_Temp | BIT_Hum)) == (BIT_Temp | BIT_Hum))
            CalculateComfort(sForceComfort);
        sForceComfort = false;
        break;
    case 0x800:
        if (gSensor & (BIT_Voc | BIT_Co2 | BIT_Co2Calc)) 
            CalculateAirquality(sForceAirquality);
        sForceAirquality = false;
        break;
    case 0x1000:
        if (gSensor & BIT_Voc) 
            CalculateAccuracy(sForceAccuracy);
        sForceAccuracy = false;
        break;
    default:
        sMeasureType = 1;
        // error processing
        uint8_t lError = Sensor::getError();
        if (lError != getError()) {
            setError(lError);
            if (knx.paramByte(SENS_Error) & SENS_ErrorMask)
                sendError();
        }
        break;
    }
    sMeasureType <<= 1;
}

bool processDiagnoseCommand() {
    char* lBuffer = gLogic.getDiagnoseBuffer();
    bool lOutput = false;
    if (lBuffer[0] == 'v') {
        // Command v: retrun fimware version, do not forward this to logic,
        // because it means firmware version of the outermost module
        // The module prints its firmware version to the console
        uint16_t lFirmwareVersion = knx.bau().deviceObject().version();
        sprintf(lBuffer, "VER [%d] %d.%d", lFirmwareVersion >> 11, (lFirmwareVersion >> 6) & 0x1F, lFirmwareVersion & 0x3F);
        lOutput = true;
    } else if (lBuffer[0] == 'c') {
        sprintf(lBuffer, "%d00 kHz", Sensor::getMaxI2cSpeed());
        lOutput = true;
    } else {
        // let's check other modules for this command
        lOutput = gLogic.processDiagnoseCommand();
    }
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

void ProcessKoCallback(GroupObject &iKo) {
    // check if we evaluate own KO
    if (iKo.asap() == LOG_KoDiagnose) {
        ProcessDiagnoseCommand(iKo);
    } else if (iKo.asap() == SENS_KoRequestValues) {
        println("Request values called");
        // print("KO-Value is ");
        // println((bool)iKo.value(getDpt(VAL_DPT_1)));
        if ((bool)iKo.value(getDPT(VAL_DPT_1)))
            gForceSensorRead = true;
    } else if (iKo.asap() >= SENS_KoExt1Temp && iKo.asap() <= SENS_KoExt2Tof) {
        // as soon as we receive any external sensor value, we mark this in our validity map
        gIsExternalValueValid[iKo.asap() - SENS_KoExt1Temp] = 1;
    } else {
        WireDevice::processKOCallback(iKo);
        // else dispatch to logicmodule
        gLogic.processInputKo(iKo);
    }
}

void ProcessInterrupt() {
    if (gSaveInterruptTimestamp) {
        printDebug("Sensormodul: SAVE-Interrupt processing started after %lu ms\n", millis() - gSaveInterruptTimestamp);
        gSaveInterruptTimestamp = millis();
        // for the moment, we send only an Info on error object in case of an save interrumpt
        uint16_t lError = getError();
        setError(lError | 128);
        sendError();
        // switch off all energy intensive hardware to gain time for EEPROM write
        savePower();
        // call according logic interrupt handler
        gLogic.processInterrupt(true);
        Sensor::saveState();
        printDebug("Sensormodul: SAVE-Interrupt processing duration was %lu ms\n", millis() - gSaveInterruptTimestamp);
        // in case, SaveInterrupt was a false positive
        // we restore power and I2C-Bus
        // Wire.end();
        // wait another 200 ms
        delay(2000);
        restorePower();
        delay(1000);
        // Wire.begin();
        // Sensor::restartSensors();
        gSaveInterruptTimestamp = 0;
    }
}


void appLoop()
{
    if (!knx.configured())
        return;

    // handle KNX stuff
    if (startupDelay())
        return;

    gIsRunning = true;
    ProcessInterrupt();

    // at this point startup-delay is done
    // we process heartbeat
    ProcessHeartbeat();
    ProcessReadRequests();
    loopSubmodules();

    // at Startup, we want to send all values immediately
    ProcessSensors(gForceSensorRead);
    gForceSensorRead = false;
    loopSubmodules();

    Sensor::sensorLoop();
    loopSubmodules();
}

// handle interrupt from save pin
void onSafePinInterruptHandler() {
    gCountSaveInterrupt += 1;
    gSaveInterruptTimestamp = millis();
}

void beforeRestartHandler() {
    printDebug("before Restart called\n");
    Sensor::saveState();
    gLogic.onBeforeRestartHandler();
    // we try get a clean state on I2C bus
    Wire.end();
}

void beforeTablesUnloadHandler() {
    static uint32_t sLastCalled = 0;
    printDebug("beforeTablesUnload called\n");
    if (sLastCalled == 0 || delayCheck(sLastCalled, 10000))
    {
        Sensor::saveState();
        gLogic.onBeforeTablesUnloadHandler();
        sLastCalled = millis();
    }
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
        gHeartbeatDelay = 0;
        gCountSaveInterrupt = 0;
        gTempOffset = (int8_t)knx.paramByte(SENS_TempOffset); // we handle temp offset in Sensor, if possible
        // GroupObject &lKoRequestValues = knx.getGroupObject(SENS_KoRequestValues);
        if (GroupObject::classCallback() == 0)
            GroupObject::classCallback(ProcessKoCallback);
        if (knx.beforeRestartCallback() == 0) knx.beforeRestartCallback(beforeRestartHandler);
        if (TableObject::beforeTablesUnloadCallback() == 0) TableObject::beforeTablesUnloadCallback(beforeTablesUnloadHandler);
        StartSensor();
#ifdef SAVE_INTERRUPT_PIN
        if (iSaveSupported)
            attachInterrupt(digitalPinToInterrupt(SAVE_INTERRUPT_PIN), onSafePinInterruptHandler, FALLING);
#endif
        gLogic.setup(false);
        if (callOneWire())
        {
            bool lSearchNewDevices = knx.paramByte(WIRE_IdSearch) & WIRE_IdSearchMask;
            // Loogic should call busmaster loop as often als knx loop
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
                    // looks strange, but all 1-wire devices are handled throug static methods after creation
                    new WireDevice(lDeviceIndex, &gBusMaster);
                }
            }
        }
    }
}