// cSpell:words millis Millis Divident Dewpoint Airquality airquality
#include "Sensor.h"
#include "HardwareDevices.h"

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

typedef bool (*getSensorValue)(MeasureType, float&);

struct sPoint
{
    float x;
    float y;
};

class SensorModule
{
private:
    static SensorModule *sInstance;

    // the entries have the same order as the KOs starting with "Ext"
    uint8_t gIsExternalValueValid[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // polygon definition for comfort calculation
    sPoint comfort1[8] = {{17.0f, 88.8f}, {21.4f, 84.1f}, {25.0f, 60.0f}, {27.1f, 30.5f}, {25.9f, 29.5f}, {20.0f, 29.5f}, {17.1f, 48.8f}, {15.9f, 78.8f}};
    sPoint comfort2[4] = {{17.5f, 74.7f}, {22.0f, 72.9f}, {24.3f, 37.6f}, {18.9f, 41.8f}};

    sSensorInfo gTemp;
    sSensorInfo gHum;
    sSensorInfo gPre;
    sSensorInfo gVoc;
    sSensorInfo gCo2;
    sSensorInfo gCo2b;
    sSensorInfo gDew;
    sSensorInfo gLux;
    sSensorInfo gTof;
    bool gForceSensorRead = true;
    int8_t gTempOffset = 0;

    uint16_t gSensor = 0;


    static void sensorDelayCallback(uint32_t iMillis);
    static bool calculateDewValue(MeasureType iMeasureType, float& eValue);

    void processInterrupt();
    void addSensorMetadata(Sensor* iSensor, uint8_t iSensorId, MeasureType iMeasureType);
    void startSensor();
    bool readSensorValue(MeasureType iMeasureType, float& eValue);
    void processSensor(sSensorInfo* cData, getSensorValue fGetSensorValue, MeasureType iMeasureType, float iOffsetFactor, float iValueFactor, uint16_t iParamIndex, uint16_t iKoNumber, uint8_t iDpt);
    bool inPolygon(sPoint *iPoly, uint8_t iLen, float iX, float iY);
    void calculateComfort(bool iForce = false);
    void calculateAccuracy(bool iForce = false);
    uint8_t getAirquality(float iCurrent, float* iLimits); 
    void calculateAirquality(bool iForce = false);
    void processSensors(bool iForce = false);



public:
    SensorModule();
    ~SensorModule();

    uint16_t getError();
    void sendError();
    void setError(uint16_t iValue);
    void processReadRequests(uint32_t iStartupDelay, uint32_t iReadRequestDelay);
    bool processDiagnoseCommand(char *iBuffer);
    void processInputKo(GroupObject &iKo);
    void setup();
    void loop();
    void onBeforeRestartHandler(); 
    void onBeforeTablesUnloadHandler();

};

