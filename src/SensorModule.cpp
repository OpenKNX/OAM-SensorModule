// cSpell:words millis Millis Divident Dewpoint Airquality airquality
#include "Helper.h"
#include "Schedule.h"

// #include "IncludeManager.h"
#include "HardwareDevices.h"

#include "SensorModule.h"
#include "Logic.h"

#include "Sensor.h"
#include "SensorBME680.h"
#include "SensorSGP30.h"

SensorModule *SensorModule::sInstance = nullptr;

SensorModule::SensorModule()
{
}

SensorModule::~SensorModule()
{
}


uint16_t SensorModule::getError() 
{
    return (uint16_t)knx.getGroupObject(SENS_KoError).value(getDPT(VAL_DPT_7));
}

void SensorModule::setError(uint16_t iValue) 
{
    knx.getGroupObject(SENS_KoError).valueNoSend(iValue, getDPT(VAL_DPT_7));
}

void SensorModule::sendError() 
{
    knx.getGroupObject(SENS_KoError).objectWritten();
}

void SensorModule::processReadRequests(uint32_t iStartupDelay, uint32_t iReadRequestDelay) 
{
    static uint8_t sReadRequestsCalled = 1;
    if (sReadRequestsCalled < 255) {

        // we evaluate only Bit 2 here, which holds the information about read external values on startup
        if (sReadRequestsCalled == 1 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_TempExtRead) & SENS_TempExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Temp).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Temp).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 2 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_HumExtRead) & SENS_HumExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Hum).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Hum).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 3 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_PreExtRead) & SENS_PreExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Pre).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Pre).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 4 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_VocExtRead) & SENS_VocExtReadMask) {
                knx.getGroupObject(SENS_KoExt1VOC).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2VOC).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 5 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_Co2ExtRead) & SENS_Co2ExtReadMask) {
                knx.getGroupObject(SENS_KoExt1Co2).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Co2).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 6 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_LuxExtRead) & SENS_LuxExtReadMask)
            {
                knx.getGroupObject(SENS_KoExt1Lux).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Lux).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 7 && delayCheck(iStartupDelay, iReadRequestDelay + sReadRequestsCalled * 1000))
        {
            sReadRequestsCalled += 1;
            if (knx.paramByte(SENS_TofExtRead) & SENS_TofExtReadMask)
            {
                knx.getGroupObject(SENS_KoExt1Tof).requestObjectRead();
                knx.getGroupObject(SENS_KoExt2Tof).requestObjectRead();
            }
        }
        if (sReadRequestsCalled == 8)
        {
            sReadRequestsCalled = 255;
        }
    }
}

// static
// this callback is used by BME680 during delays while measuring
// we implement this delay, but keep normal loop processing alive
void SensorModule::sensorDelayCallback(uint32_t iMillis) 
{
    // printDebug("sensorDelayCallback: Called with a delay of %lu ms\n", iMillis);
    uint32_t lMillis = millis();
    while (millis() - lMillis < iMillis) {
        if (sInstance != nullptr) {
            Schedule::loop();
        }
    }
    // printDebug("sensorDelayCallback: Left after %lu ms\n", millis() - lMillis);
}

void SensorModule::addSensorMetadata(Sensor* iSensor, uint8_t iSensorId, MeasureType iMeasureType)
{
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
void SensorModule::startSensor()
{
    Sensor* lSensor;
    
    gSensor = 0;
    uint8_t lSensorId = (knx.paramByte(SENS_TempSensor) & SENS_TempSensorMask) >> SENS_TempSensorShift;
    if (lSensorId > 0) {
        gSensor |= BIT_Temp;
        lSensor = Sensor::factory(lSensorId, Temperature);
        addSensorMetadata(lSensor, lSensorId, Temperature);
    }
    lSensorId = (knx.paramByte(SENS_HumSensor) & SENS_HumSensorMask) >> SENS_HumSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Hum;
        lSensor = Sensor::factory(lSensorId, Humidity);
        addSensorMetadata(lSensor, lSensorId, Humidity);
    }
    lSensorId = (knx.paramByte(SENS_PreSensor) & SENS_PreSensorMask) >> SENS_PreSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Pre;
        lSensor = Sensor::factory(lSensorId, Pressure);
        addSensorMetadata(lSensor, lSensorId, Pressure);
    }
    lSensorId = (knx.paramByte(SENS_VocSensor) & SENS_VocSensorMask) >> SENS_VocSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Voc | BIT_Co2Calc;
        lSensor = Sensor::factory(lSensorId, static_cast<MeasureType>(Voc | Accuracy | Co2Calc));
        addSensorMetadata(lSensor, lSensorId, static_cast<MeasureType>(Voc | Accuracy | Co2Calc));
    }
    lSensorId = (knx.paramByte(SENS_Co2Sensor) & SENS_Co2SensorMask) >> SENS_Co2SensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_Co2;
        lSensor = Sensor::factory(lSensorId, Co2);
        addSensorMetadata(lSensor, lSensorId, Co2);
    }
    lSensorId = (knx.paramByte(SENS_LuxSensor) & SENS_LuxSensorMask) >> SENS_LuxSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_LUX;
        lSensor = Sensor::factory(lSensorId, Lux);
        addSensorMetadata(lSensor, lSensorId, Lux);
    }
    lSensorId = (knx.paramByte(SENS_TofSensor) & SENS_TofSensorMask) >> SENS_TofSensorShift;
    if (lSensorId > 0)
    {
        gSensor |= BIT_TOF;
        lSensor = Sensor::factory(lSensorId, Tof);
        addSensorMetadata(lSensor, lSensorId, Tof);
    }
    // now start all sensors at the correct speed
    Sensor::beginSensors();
}

bool SensorModule::readSensorValue(MeasureType iMeasureType, float& eValue) 
{
    return Sensor::measureValue(iMeasureType, eValue);
}

// generic sensor processing
void SensorModule::processSensor(sSensorInfo* cData, getSensorValue fGetSensorValue, MeasureType iMeasureType, float iOffsetFactor, float iValueFactor, uint16_t iParamIndex, uint16_t iKoNumber, uint8_t iDpt)
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

bool SensorModule::inPolygon(sPoint *iPoly, uint8_t iLen, float iX, float iY)
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

// Dewpoint is a virtual sensor and might be implemented on sensor class level, but we implement it here (easier and shorter)
bool SensorModule::calculateDewValue(MeasureType iMeasureType, float& eValue) 
{
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

void SensorModule::calculateComfort(bool iForce /*= false*/)
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
            // comfort zone
            uint8_t lComfort = 0;
            if (inPolygon(comfort2, 4, lTemp, lHum))
            {
                lComfort = 2;
            }
            else if (inPolygon(comfort1, 8, lTemp, lHum))
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

void SensorModule::calculateAccuracy(bool iForce /*= false*/)
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

uint8_t SensorModule::getAirquality(float iCurrent, float* iLimits) 
{
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

void SensorModule::calculateAirquality(bool iForce /*= false*/)
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
            // do not calculate if underlying measures are not yet available
            float lValue = 0;

            // get airquality
            uint8_t lAirquality = 6;
            if ((gSensor & BIT_Co2)) {
                // do not calculate if underlying measures are not yet available
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

void SensorModule::processSensors(bool iForce /*= false*/)
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
        processSensor(&gTemp, Sensor::measureValue, Temperature, 10.0f, 1.0f, SENS_TempOffset, SENS_KoTemp, VAL_DPT_9);
        break;
    case BIT_Hum:
        processSensor(&gHum, Sensor::measureValue, Humidity, 1.0f, 1.0f, SENS_HumOffset, SENS_KoHum, VAL_DPT_9);
        break;
    case BIT_Pre:
        processSensor(&gPre, Sensor::measureValue, Pressure, 1.0f, 100.0f, SENS_PreOffset, SENS_KoPre, VAL_DPT_9);
        break;
    case BIT_Voc:
        processSensor(&gVoc, Sensor::measureValue, Voc, 1.0f, 1.0f, SENS_VocOffset, SENS_KoVOC, VAL_DPT_9);
        break;
    case BIT_Co2:
        processSensor(&gCo2, Sensor::measureValue, Co2, 1.0f, 1.0f, SENS_Co2Offset, SENS_KoCo2, VAL_DPT_9);
        break;
    case BIT_Co2Calc:
        processSensor(&gCo2b, Sensor::measureValue, Co2Calc, 1.0f, 1.0f, SENS_Co2Offset, SENS_KoCo2b, VAL_DPT_9);
        break;
    case BIT_LOGIC: // dew value, this constant is misleading...
        if ((gSensor & (BIT_Temp | BIT_Hum)) == (BIT_Temp | BIT_Hum))
            processSensor(&gDew, SensorModule::calculateDewValue, static_cast<MeasureType>(Temperature | Humidity), 10.0f, 1.0f, SENS_DewOffset, SENS_KoDewpoint, VAL_DPT_9);
        break;
    case BIT_LUX:
        processSensor(&gLux, Sensor::measureValue, Lux, 1.0f, 1.0f, SENS_LuxOffset, SENS_KoLux, VAL_DPT_9);
        break;
    case BIT_TOF:
        processSensor(&gTof, Sensor::measureValue, Tof, 1.0f, 1.0f, SENS_TofOffset, SENS_KoTof, VAL_DPT_7);
        break;
    case 0x400:
        if ((gSensor & (BIT_Temp | BIT_Hum)) == (BIT_Temp | BIT_Hum))
            calculateComfort(sForceComfort);
        sForceComfort = false;
        break;
    case 0x800:
        if (gSensor & (BIT_Voc | BIT_Co2 | BIT_Co2Calc)) 
            calculateAirquality(sForceAirquality);
        sForceAirquality = false;
        break;
    case 0x1000:
        if (gSensor & BIT_Voc) 
            calculateAccuracy(sForceAccuracy);
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

bool SensorModule::processDiagnoseCommand(char *iBuffer)
{
    bool lOutput = false;
    if (iBuffer[0] == 'c') {
        sprintf(iBuffer, "%d00 kHz", Sensor::getMaxI2cSpeed());
        lOutput = true;
    }
    return lOutput;
}

void SensorModule::processInputKo(GroupObject &iKo)
{
    // check if we evaluate own KO
    if (iKo.asap() == SENS_KoRequestValues)
     {
        // println("Request values called");
        // print("KO-Value is ");
        // println((bool)iKo.value(getDpt(VAL_DPT_1)));
        if ((bool)iKo.value(getDPT(VAL_DPT_1)))
            gForceSensorRead = true;
    } else if (iKo.asap() >= SENS_KoExt1Temp && iKo.asap() <= SENS_KoExt2Tof) {
        // as soon as we receive any external sensor value, we mark this in our validity map
        gIsExternalValueValid[iKo.asap() - SENS_KoExt1Temp] = 1;
    } 
}

void SensorModule::loop()
{
    if (!knx.configured())
        return;

    // set backreference, at this point it is also an "isRunning" info
    if (sInstance == nullptr)
        sInstance = this;

    // at Startup, we want to send all values immediately
    processSensors(gForceSensorRead);
    gForceSensorRead = false;
    // Schedule::loop();

    Sensor::sensorLoop();
    Schedule::loop();
}

void SensorModule::onBeforeRestartHandler() 
{
    // printDebug("before Restart called\n");
    Sensor::saveState();
}

void SensorModule::onBeforeTablesUnloadHandler() 
{
    static uint32_t sLastCalledTablesUnloadHandler = 0;
    printDebug("beforeTablesUnload called\n");
    if (sLastCalledTablesUnloadHandler == 0 || delayCheck(sLastCalledTablesUnloadHandler, 10000))
    {
        Sensor::saveState();
        sLastCalledTablesUnloadHandler = millis();
    }
}

void SensorModule::setup()
{
    if (knx.configured())
    {
        gTempOffset = (int8_t)knx.paramByte(SENS_TempOffset); // we handle temp offset in Sensor, if possible
        startSensor();
    }
}