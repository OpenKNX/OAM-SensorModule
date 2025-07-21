#include "Logic.h"
#include "OpenKNX.h"
#ifdef WIREMODULE
    #include "OneWireDS2482.h"
    #include "WireGateway.h"
#endif
#ifdef PRESENCEMODULE
    #include "Presence.h"
#endif
#include "SensorDevices.h"
#include "SensorModule.h"

#ifdef ARDUINO_ARCH_RP2040
    #include "FileTransferModule.h"
    #include "UsbExchangeModule.h"
    #if defined(KNX_IP_LAN) || defined(KNX_IP_WIFI)
        #include "NetworkModule.h"
    #endif
#endif
#ifdef ARDUINO_ARCH_RP2040
    #pragma message "Pico Core Version: " ARDUINO_PICO_VERSION_STR
#endif

#ifdef OPENKNX_BI_GPIO_PINS
    #ifdef BI_ChannelCount
        #include "GpioBinaryInputModule.h"
    #endif
#endif

#ifdef OPENKNX_ADC_ADS_GAIN
    #include "ADCInputModule.h"
#endif

#include "Sensor.h"
#ifdef BTN_ChannelCount
    #include "VirtualButtonModule.h"
#endif

void setup()
{
    const uint8_t firmwareRevision = 6;

#ifdef ARDUINO_ARCH_RP2040
    #ifdef ONEWIRE_5V_ENABLE
    pinMode(ONEWIRE_5V_ENABLE, OUTPUT);
    digitalWrite(ONEWIRE_5V_ENABLE, HIGH);
    #endif
#endif

#ifdef DEVICE_UP1_PM_HF
    pinMode(26, INPUT_PULLUP);
#endif

    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogic);
#ifdef WIREMODULE
    openknx.addModule(2, openknxWireGateway);
#endif
    openknx.addModule(6, openknxSensorDevicesModule);
    openknx.addModule(4, openknxSensorModule);
#ifdef PRESENCEMODULE
    openknx.addModule(3, openknxPresenceModule);
#endif
#ifdef ARDUINO_ARCH_RP2040
    openknx.addModule(5, openknxFileTransferModule);
#endif
#ifdef BTN_ChannelCount
    openknx.addModule(7, openknxVirtualButtonModule);
#endif
#ifdef OPENKNX_BI_GPIO_PINS
    #ifdef BI_ChannelCount
    openknx.addModule(8, openknxGpioBinaryInputModule);
    #endif
#endif
#ifdef OPENKNX_ADC_ADS_GAIN
    openknx.addModule(9, openknxADCInputModule);
#endif

    openknx.setup();
}

void loop()
{
    openknx.loop();
}