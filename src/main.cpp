#include "HardwareDevices.h"
#include "Sensor.h"
#include "hardware.h"
#include "knxprod.h"
#include "oknx.h"
#include <Wire.h>
#include <knx.h>

void appSetup(bool iSaveSupported);
void appLoop();

void setup()
{
    SERIAL_DEBUG.begin(115200);
    pinMode(PROG_LED_PIN, OUTPUT);
    digitalWrite(PROG_LED_PIN, HIGH);
    delay(DEBUG_DELAY);
    digitalWrite(PROG_LED_PIN, LOW);
    SERIAL_DEBUG.println("Startup called...");

#ifdef ARDUINO_ARCH_RP2040
    Serial1.setRX(KNX_UART_RX_PIN);
    Serial1.setTX(KNX_UART_TX_PIN);
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

    ArduinoPlatform::SerialDebug = &SERIAL_DEBUG;

#ifdef INFO_LED_PIN
    pinMode(INFO_LED_PIN, OUTPUT);
    ledInfo(true);
#endif

    // pin or GPIO the programming led is connected to. Default is LED_BUILDIN
    knx.ledPin(PROG_LED_PIN);
    // is the led active on HIGH or low? Default is LOW
    knx.ledPinActiveOn(PROG_LED_PIN_ACTIVE_ON);
    // pin or GPIO programming button is connected to. Default is 0
    knx.buttonPin(PROG_BUTTON_PIN);
    // Is the interrupt created in RISING or FALLING signal? Default is RISING
    // knx.buttonPinInterruptOn(PROG_BUTTON_PIN_INTERRUPT_ON);

    // all MAIN_* parameters are generated by OpenKNXproducer for correct version checking by ETS
    // If you want just a bugfix firmware update without ETS-Application dependency, just increase firmwareRevision.
    // As soon, as you want again a sync between ETS-Application and firmware, set firmwareRevision to 0.
    const uint8_t firmwareRevision = 1;
    openknx.readMemory(MAIN_OpenKnxId, MAIN_ApplicationNumber, MAIN_ApplicationVersion, firmwareRevision);

    appSetup(SAVE_INTERRUPT_PIN);

    // start the framework.
    knx.start();
    ledInfo(false);
}

void loop()
{
    // don't delay here to much. Otherwise you might lose packages or mess up the timing with ETS
    knx.loop();

    // only run the application code if the device was configured with ETS
    if (knx.configured())
        appLoop();
}
