#pragma once

#include <OpenKNXHardware.h>

#ifndef BOARD_ENDUSER
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
        #define KNX_I2C_SDA_PIN 20
        #define KNX_I2C_SCL_PIN 21
        #define KNX_I2C1_SDA_PIN 14
        #define KNX_I2C1_SCL_PIN 15
        #define KNX_I2C1_SDA_PIN 14
        #define KNX_I2C1_SCL_PIN 15
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18 // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_BUS_1WIRE Wire1
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
    #endif

    #ifdef BOARD_SMARTMF_1TE_RP2040
        #define PROG_LED_PIN 1
        #define PROG_LED_PIN_ACTIVE_ON HIGH
        #define PROG_BUTTON_PIN 0
        #define PROG_BUTTON_PIN_INTERRUPT_ON FALLING
        #define SAVE_INTERRUPT_PIN 29
        #define KNX_UART_RX_PIN 17
        #define KNX_UART_TX_PIN 16
        #define KNX_I2C_SDA_PIN 20
        #define KNX_I2C_SCL_PIN 21
        #define KNX_I2C1_SDA_PIN 14
        #define KNX_I2C1_SCL_PIN 15
        #define COUNT_1WIRE_BUSMASTER 1
        #define COUNT_1WIRE_CHANNEL 30
        #define I2C_1WIRE_DEVICE_ADDRESSS 0x18 // Address of DS2484 1-Wire-Busmaster chip
        #define I2C_BUS_1WIRE Wire1
        #define ONEWIRE_5V_ENABLE 5
        #define ONEWIRE_5V_SHORT 4
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
        #define KNX_I2C_SDA_PIN 20
        #define KNX_I2C_SCL_PIN 21
        #define KNX_I2C1_SDA_PIN 14
        #define KNX_I2C1_SCL_PIN 15
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
        #define KNX_I2C_SDA_PIN 20
        #define KNX_I2C_SCL_PIN 21
        // Buzzer
        #define BUZZER_PIN 27
        // #define I2C_1WIRE_DEVICE_ADDRESSS 0x18  // Address of DS2484 1-Wire-Busmaster chip
        // #define I2C_EEPROM_DEVICE_ADDRESSS 0x50 // Address of 24LC256 eeprom chip
        #define I2C_RGBLED_DEVICE_ADDRESS 0x60 // Address of PCA9632 RBGW-LED-Driver
    #endif
#endif