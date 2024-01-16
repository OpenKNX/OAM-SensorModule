#include "Logic.h"
#ifdef WIREMODULE
    #include "OneWireDS2482.h"
    #include "WireGateway.h"
#endif
#ifdef PRESENCEMODULE
    #include "Presence.h"
#endif
#include "SensorModule.h"
#ifdef ARDUINO_ARCH_RP2040
    #include "FileTransferModule.h"
#endif
#include "OpenKNX.h"

#ifdef ARDUINO_ARCH_RP2040
    #pragma message "Pico Core Version: " ARDUINO_PICO_VERSION_STR
#endif

#include "Sensor.h"

#include <Wire.h>

void setup()
{
    const uint8_t firmwareRevision = 3;

#ifdef ARDUINO_ARCH_RP2040
    #ifdef KNX_I2C_SDA_PIN
    Wire.setSDA(KNX_I2C_SDA_PIN);
    Wire.setSCL(KNX_I2C_SCL_PIN);
    #endif
    #ifdef KNX_I2C1_SDA_PIN
    Wire1.setSDA(KNX_I2C1_SDA_PIN);
    Wire1.setSCL(KNX_I2C1_SCL_PIN);
    #endif
    #ifdef ONEWIRE_5V_ENABLE
    pinMode(ONEWIRE_5V_ENABLE, OUTPUT);
    digitalWrite(ONEWIRE_5V_ENABLE, HIGH);
    #endif
    Sensor::SetWire(Wire);
#endif

    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogic);
#ifdef WIREMODULE
    openknx.addModule(2, new WireGateway());
#endif
#ifdef PRESENCEMODULE
    openknx.addModule(3, openknxPresenceModule);
#endif
    openknx.addModule(4, openknxSensorModule);
#ifdef ARDUINO_ARCH_RP2040
    openknx.addModule(5, openknxFileTransferModule);
#endif
    openknx.setup();
}

void loop()
{
    openknx.loop();
}
