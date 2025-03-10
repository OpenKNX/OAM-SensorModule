#pragma once

#ifndef BOARD_ENDUSER

    #define FIRMWARE_NAME "Sensormodul-Big"
    
    // UP1 als 1-Kanal-Sensormodul
    #ifdef BOARD_UP1_SENSOR_1KANAL
        #define OKNXHW_UP1_CONTROLLER2040   // this loads the pin definitions from OpenKNXHardware.h
        #define HARDWARE_NAME "SEN-UP1-8xTH"

        #define I2C_SDA_PIN 20 // Channel E on SEN-UP1-8xTH
        #define I2C_SCL_PIN 21 // Channel E on SEN-UP1-8xTH

        #define OPENKNX_BI_GPIO_PINS 25, 24, 23, 22 // Channel C, D on SEN-UP1-8xTH
        #define OPENKNX_BI_GPIO_COUNT 4
        #define OPENKNX_BI_ONLEVEL LOW
    #endif

    // UP1-PM-HF
    // https://github.com/OpenKNX/OpenKNX/wiki/UP1-PM-HF
    #ifdef DEVICE_UP1_PM_HF
        #define DEVICE_ID "UP1-PM-HF"
        #define DEVICE_NAME "OpenKNX UP1 Präsenzmelder+"


        #define OKNXHW_UP1_CONTROLLER2040


        #define OKNXHW_SENSOR_HF_SERIAL Serial2
        #define OKNXHW_SENSOR_HF_RX_PIN
        #define OKNXHW_SENSOR_HF_TX_PIN
        #define OKNXHW_SENSOR_HF_PWR_PIN


        #define OKNXHW_SENSOR_J40_WIRE Wire1
        #define OKNXHW_SENSOR_J40_SDA 10
        #define OKNXHW_SENSOR_J40_SCL 11


        #define PRESENCE_LED_PIN 25 // red channel of central RGB LED
        #define PRESENCE_LED_PIN_ACTIVE_ON LOW
        // #define MOVE_LED_PIN 26 // green channel of central RGB LED
        // #define MOVE_LED_PIN_ACTIVE_ON LOW
        #define MOVE_LED_PIN 27 // blue channel of central RGB LED
        #define MOVE_LED_PIN_ACTIVE_ON LOW


        #define I2C_WIRE Wire
        #define I2C_SDA_PIN 28
        #define I2C_SCL_PIN 29
        #define HF_SERIAL Serial2
        #define HF_SERIAL_SPEED 115200
        #define HF_POWER_PIN 18
        #define HF_UART_TX_PIN 20
        #define HF_UART_RX_PIN 21
        #define OPENKNX_BI_GPIO_PINS 19,22,23,24
        #define OPENKNX_BI_GPIO_COUNT 4
        #define OPENKNX_BI_ONLEVEL LOW


    #endif

    #include <OpenKNXHardware.h>

    #ifdef DEVICE_REG1_BASE_V1
        #define I2C_SDA_PIN OKNXHW_REG1_SENSOR_SDA_TX_PIN
        #define I2C_SCL_PIN OKNXHW_REG1_SENSOR_SCL_RX_PIN
    #endif

    #ifdef DEVICE_REG1_BASE_V0
        #define I2C_SDA_PIN OKNXHW_REG1_SENSOR_SDA_TX_PIN
        #define I2C_SCL_PIN OKNXHW_REG1_SENSOR_SCL_RX_PIN
    #endif

    // // Board specific definitions
    // // #define BOARD_MASIFI
    // // ################################################
    // // ### Board Configuration
    // // ################################################
    // #ifdef BOARD_DEVEL
    // #define PROG_LED_PIN 26
    // #define PROG_LED_PIN_ACTIVE_ON LOW
    // #define PROG_BUTTON_PIN 10
    // #define PROG_BUTTON_PIN_INTERRUPT_ON RISING
    // #define SAVE_INTERRUPT_PIN 17
    // #define BUZZER_PIN 18
    // #define I2C_EEPROM_DEVICE_ADDRESSS 0xFF // Address of 24LC256 eeprom chip
    // #endif
    // #ifdef BOARD_ENOCEAN
    // #ifndef PROG_LED_PIN
    // #define PROG_LED_PIN 10
    // #define PROG_LED_PIN_ACTIVE_ON HIGH
    // #endif
    // #ifndef PROG_BUTTON_PIN
    // #define PROG_BUTTON_PIN 8
    // #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
    // #endif
    // #define SAVE_INTERRUPT_PIN A9
    // // #define INFO_LED_PIN 38
    // // #define INFO_LED_PIN_ACTIVE_ON HIGH
    // // #define COUNT_LOG_CHANNEL 80
    // // Buzzer
    // // #define BUZZER_PIN 9
    // // #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
    // #define NO_I2C
    // #endif
    #ifdef BOARD_MASIFI_V1
        #define PROG_LED_PIN 13
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 11
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN 8
        #define INFO_LED_PIN 38
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_PM_CHANNEL 6
        // #define COUNT_LOG_CHANNEL 80
        // Buzzer
        #define BUZZER_PIN 9
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x1A  // Address of DS2482 1-Wire-Busmaster chip
        #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60  // Address of PCA9632 RGBW-LED-Driver
    #endif
    #ifdef BOARD_MASIFI_V2
        #define PROG_LED_PIN 13
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 11
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN 8
        #define INFO_LED_PIN 38
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_PM_CHANNEL 6
        // #define COUNT_LOG_CHANNEL 99
        // Buzzer
        #define BUZZER_PIN 9
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60  // Address of PCA9632 RGBW-LED-Driver
    #endif
    #ifdef BOARD_MASIFI_V3
        #define PROG_LED_PIN 13
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 11
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN A2 // 8
        #define INFO_LED_PIN 38
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_PM_CHANNEL 6
        // #define COUNT_LOG_CHANNEL 80
        // Buzzer
        #define BUZZER_PIN 9
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60  // Address of PCA9632 RGBW-LED-Driver
    #endif
    #ifdef BOARD_MASIFI_V31
        #define PROG_LED_PIN 13
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 12
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN A2 // 8
        #define INFO_LED_PIN 38
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_PM_CHANNEL 6
        // #define COUNT_LOG_CHANNEL 80
        // Buzzer
        #define BUZZER_PIN 9
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60  // Address of PCA9632 RGBW-LED-Driver
    #endif
    #ifdef BOARD_MASIFI_V40
        #define PROG_LED_PIN 1
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 0
        #define SAVE_INTERRUPT_PIN 29
        // #define INFO_LED_PIN 38
        // #define INFO_LED_PIN_ACTIVE_ON HIGH
        // #define COUNT_1WIRE_BUSMASTER 1
        // #define COUNT_1WIRE_CHANNEL 30
        #define KNX_UART_RX_PIN 17
        #define KNX_UART_TX_PIN 16
        #define I2C_WIRE Wire
        #define I2C_SDA_PIN 20
        #define I2C_SCL_PIN 21
        // #define I2C_WIRE Wire1
        // #define I2C_SDA_PIN 14
        // #define I2C_SCL_PIN 15
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18 // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_BUS_1WIRE Wire1
        #define I2C_SDA_1WIRE_PIN 14
        #define I2C_SCL_1WIRE_PIN 15
        #define ONEWIRE_5V_ENABLE 5
        #define ONEWIRE_5V_SHORT 4
        // Buzzer
        #define BUZZER_PIN 27
        // #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60 // Address of PCA9632 RGBW-LED-Driver
        #define HW_ANALOG_ID 26
        #define HW_REVISION_ID1 10
        #define HW_REVISION_ID2 11
        #define HW_REVISION_ID3 12
        #define OPENKNX_BI_GPIO_PINS 2, 4, 6, 7
        #define OPENKNX_BI_GPIO_COUNT 4
        #define OPENKNX_ADC_ADS_ADDR 0x49
        #define OPENKNX_ADC_ADS_GAIN 2
        #define OPENKNX_ADC_ADS_WIRE I2C_BUS_1WIRE
        #define OPENKNX_ADC_ADS_SDA I2C_SDA_1WIRE_PIN
        #define OPENKNX_ADC_ADS_SCL I2C_SCL_1WIRE_PIN
    #endif

    #ifdef BOARD_SMARTMF_1TE_RP2040
        #define PROG_LED_PIN 1
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 0
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN 29
        #define KNX_UART_RX_PIN 17
        #define KNX_UART_TX_PIN 16
        #define I2C_SDA_PIN 20
        #define I2C_SCL_PIN 21
        #define I2C1_SDA_PIN 14
        #define I2C1_SCL_PIN 15
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18 // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_BUS_1WIRE Wire1
        #define ONEWIRE_5V_ENABLE 5
        #define ONEWIRE_5V_SHORT 4
        #define OPENKNX_BI_GPIO_PINS 14, 15, 4
        #define OPENKNX_BI_GPIO_COUNT 3
        #define OPENKNX_BI_ONLEVEL LOW
    #endif

    // Sensormodul-Breakout-Board
    #ifdef BOARD_MASIFI_SENSOR_BREAKOUT
        #define PROG_LED_PIN 1
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 0
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN 22
        // #define INFO_LED_PIN 38
        // #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define KNX_UART_RX_PIN 17
        #define KNX_UART_TX_PIN 16
        #define I2C_SDA_PIN 20
        #define I2C_SCL_PIN 21
        #define I2C1_SDA_PIN 14
        #define I2C1_SCL_PIN 15
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18 // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_BUS_1WIRE Wire1
        #define ONEWIRE_5V_ENABLE 5
        #define ONEWIRE_5V_SHORT 4
        // Buzzer
        #define BUZZER_PIN 9
        // #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60 // Address of PCA9632 RGBW-LED-Driver
        #define HW_ANALOG_ID 26
        #define HW_REVISION_ID1 10
        #define HW_REVISION_ID2 11
        #define HW_REVISION_ID3 12
    #endif

    #ifdef BOARD_MASIFI_AUSSEN_V13
        #define PROG_LED_PIN 13
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 12
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN A2 // 8
        #define INFO_LED_PIN 38
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_LOG_CHANNEL 80
        // Buzzer
        #define BUZZER_PIN 9
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60  // Address of PCA9632 RBGW-LED-Driver
    #endif
    // Sensormodul auf RP2040 Basis
    #ifdef BOARD_MASIFI_PICO
        #define PROG_LED_PIN 12
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 28
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN D29 // 8
        // #define INFO_LED_PIN 38
        // #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        // #define COUNT_PM_CHANNEL 6
        // #define COUNT_LOG_CHANNEL 99
        #define KNX_UART_RX_PIN 17
        #define KNX_UART_TX_PIN 16
        #define I2C_WIRE Wire
        #define I2C_SDA_PIN 20
        #define I2C_SCL_PIN 21
        // Buzzer
        #define BUZZER_PIN 27
        // #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        // #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60 // Address of PCA9632 RBGW-LED-Driver
    #endif

    #ifdef BOARD_AB_PRE
        #define BOARD_AB_PRE_BASE
        #define DEVICE_ID "AB-PRE"
        #define HARDWARE_NAME "AB-PRE"
        #define DEVICE_NAME "AB-SmartHouse Presence MultiSensor"
    #endif

    #ifdef BOARD_AB_PRE_MR16
        #define BOARD_AB_PRE_BASE
        #define DEVICE_ID "AB-PRE-MR16"
        #define HARDWARE_NAME "AB-PRE-MR16"
        #define DEVICE_NAME "AB-SmartHouse Presence MR16"
    #endif

    #ifdef BOARD_AB_PRE_WALL
        #define BOARD_AB_PRE_BASE
        #define DEVICE_ID "AB-PRE-WALL"
        #define HARDWARE_NAME "AB-PRE-WALL"
        #define DEVICE_NAME "AB-SmartHouse Presence Wall"
    #endif

    // Sensormodul auf RP2040 Basis
    #ifdef BOARD_AB_PRE_BASE
        #define PROG_LED_PIN 10
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 9
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define INFO_LED_PIN 11
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define PRESENCE_LED_PIN 28
        #define PRESENCE_LED_PIN_ACTIVE_ON HIGH
        #define MOVE_LED_PIN 29
        #define MOVE_LED_PIN_ACTIVE_ON HIGH
        #define KNX_UART_TX_PIN 12
        #define KNX_UART_RX_PIN 13
        #define SAVE_INTERRUPT_PIN 0
        #define I2C_WIRE Wire1
        #define I2C_SDA_PIN 2
        #define I2C_SCL_PIN 3
        #define HF_SERIAL Serial2
        #define HF_SERIAL_SPEED 115200
        #define HF_POWER_PIN 27
        #define HF_UART_TX_PIN 4
        #define HF_UART_RX_PIN 5
        #define PIR_PIN 26
        #define OPENKNX_BI_GPIO_PINS 14, 15
        #define OPENKNX_BI_GPIO_COUNT 2
        #define OPENKNX_BI_ONLEVEL LOW
    #endif

    #ifdef BOARD_MASIFI_HFPM_DEVEL2
        #define PROG_LED_PIN 18
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 17
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        // #define INFO_LED_PIN 9
        // #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define PRESENCE_LED_PIN 0
        #define PRESENCE_LED_PIN_ACTIVE_ON HIGH
        #define MOVE_LED_PIN 1
        #define MOVE_LED_PIN_ACTIVE_ON HIGH
        #define KNX_UART_TX_PIN 12
        #define KNX_UART_RX_PIN 13
        #define I2C_WIRE Wire1
        #define I2C_SDA_PIN 26 // I2C1
        #define I2C_SCL_PIN 27 // I2C1
        #define HF_SERIAL Serial2
        #define HF_SERIAL_SPEED 9600
        #define HF_UART_TX_PIN 4
        #define HF_UART_RX_PIN 5
        #define HF_S1_PIN 2
        #define HF_S2_PIN 3
        #define HF_POWER_PIN 10
        #define SAVE_INTERRUPT_PIN 11
        #define SmartMF_HardwareVariant_PIN 29
        #define SmartMF_HardwareRevision_ID1 22
        #define SmartMF_HardwareRevision_ID2 23
        #define SmartMF_HardwareRevision_ID3 24
    // #define SENSOR_I2C_OPT300x Wire1
    // #define SENSOR_I2C_VEML7700 Wire1
    #endif

    #ifdef BOARD_MASIFI_HFPM_V20
        #define PROG_LED_PIN 18
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 17
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        // #define INFO_LED_PIN 9
        // #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define PRESENCE_LED_PIN 0
        #define PRESENCE_LED_PIN_ACTIVE_ON HIGH
        #define MOVE_LED_PIN 1
        #define MOVE_LED_PIN_ACTIVE_ON HIGH
        #define KNX_UART_TX_PIN 12
        #define KNX_UART_RX_PIN 13
        #define I2C_WIRE Wire1
        #define I2C_SDA_PIN 26 // I2C1
        #define I2C_SCL_PIN 27 // I2C1
        #define HF_SERIAL Serial2
        #define HF_SERIAL_SPEED 9600
        #define HF_UART_TX_PIN 4
        #define HF_UART_RX_PIN 5
        #define HF_S1_PIN 2
        #define HF_S2_PIN 3
        #define HF_POWER_PIN 28
        #define SAVE_INTERRUPT_PIN 11
        #define SmartMF_HardwareVariant_PIN 29
        #define SmartMF_HardwareRevision_ID1 22
        #define SmartMF_HardwareRevision_ID2 23
        #define SmartMF_HardwareRevision_ID3 24
    // #define SENSOR_I2C_OPT300x Wire1
    // #define SENSOR_I2C_VEML7700 Wire1
    #endif

    #ifdef DEVICE_SMARTMF_REALPRESENCE_HLK
        #define DEVICE_ID "SMARTMF-RP_V2"
        #define DEVICE_NAME "Smart-MF RealPresence 2.0"

        #define PROG_LED_PIN 18
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 17
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define INFO_LED_PIN 16
        #define INFO_LED_PIN_ACTIVE_ON HIGH
        #define PRESENCE_LED_PIN 1
        #define PRESENCE_LED_PIN_ACTIVE_ON HIGH
        #define MOVE_LED_PIN 0
        #define MOVE_LED_PIN_ACTIVE_ON HIGH
        #define KNX_UART_TX_PIN 12
        #define KNX_UART_RX_PIN 13
        #define SAVE_INTERRUPT_PIN 11
        #define I2C_WIRE Wire1
        #define I2C_SDA_PIN 26
        #define I2C_SCL_PIN 27
        #define HF_SERIAL Serial2
        #define HF_SERIAL_SPEED 115200
        #define HF_POWER_PIN 28
        #define HF_UART_TX_PIN 4
        #define HF_UART_RX_PIN 5

    #endif

#endif