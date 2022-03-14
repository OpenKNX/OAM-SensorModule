#pragma once
#include <knx.h>

// Parameter with single occurance

#define LOG_NumChannels                0      // uint8_t
#define LOG_StartupDelay               1      // int32_t
#define LOG_Heartbeat                  5      // int32_t
#define LOG_ReadTimeDate               9      // 1 Bit, Bit 7
#define     LOG_ReadTimeDateMask 0x80
#define     LOG_ReadTimeDateShift 7
#define LOG_BuzzerInstalled            9      // 1 Bit, Bit 6
#define     LOG_BuzzerInstalledMask 0x40
#define     LOG_BuzzerInstalledShift 6
#define LOG_LedInstalled               9      // 1 Bit, Bit 5
#define     LOG_LedInstalledMask 0x20
#define     LOG_LedInstalledShift 5
#define LOG_EepromInstalled            9      // 1 Bit, Bit 4
#define     LOG_EepromInstalledMask 0x10
#define     LOG_EepromInstalledShift 4
#define LOG_NCN5130Installed           9      // 1 Bit, Bit 3
#define     LOG_NCN5130InstalledMask 0x08
#define     LOG_NCN5130InstalledShift 3
#define LOG_VacationKo                 9      // 1 Bit, Bit 2
#define     LOG_VacationKoMask 0x04
#define     LOG_VacationKoShift 2
#define LOG_HolidayKo                  9      // 1 Bit, Bit 1
#define     LOG_HolidayKoMask 0x02
#define     LOG_HolidayKoShift 1
#define LOG_VacationRead               9      // 1 Bit, Bit 0
#define     LOG_VacationReadMask 0x01
#define     LOG_VacationReadShift 0
#define LOG_HolidaySend               10      // 1 Bit, Bit 7
#define     LOG_HolidaySendMask 0x80
#define     LOG_HolidaySendShift 7
#define LOG_Timezone                  10      // 2 Bits, Bit 6-5
#define     LOG_TimezoneMask 0x60
#define     LOG_TimezoneShift 5
#define LOG_UseSummertime             10      // 1 Bit, Bit 4
#define     LOG_UseSummertimeMask 0x10
#define     LOG_UseSummertimeShift 4
#define LOG_Diagnose                  10      // 1 Bit, Bit 3
#define     LOG_DiagnoseMask 0x08
#define     LOG_DiagnoseShift 3
#define LOG_Watchdog                  10      // 1 Bit, Bit 2
#define     LOG_WatchdogMask 0x04
#define     LOG_WatchdogShift 2
#define LOG_Neujahr                   11      // 1 Bit, Bit 7
#define     LOG_NeujahrMask 0x80
#define     LOG_NeujahrShift 7
#define LOG_DreiKoenige               11      // 1 Bit, Bit 6
#define     LOG_DreiKoenigeMask 0x40
#define     LOG_DreiKoenigeShift 6
#define LOG_Weiberfastnacht           11      // 1 Bit, Bit 5
#define     LOG_WeiberfastnachtMask 0x20
#define     LOG_WeiberfastnachtShift 5
#define LOG_Rosenmontag               11      // 1 Bit, Bit 4
#define     LOG_RosenmontagMask 0x10
#define     LOG_RosenmontagShift 4
#define LOG_Fastnachtsdienstag        11      // 1 Bit, Bit 3
#define     LOG_FastnachtsdienstagMask 0x08
#define     LOG_FastnachtsdienstagShift 3
#define LOG_Aschermittwoch            11      // 1 Bit, Bit 2
#define     LOG_AschermittwochMask 0x04
#define     LOG_AschermittwochShift 2
#define LOG_Gruendonnerstag           11      // 1 Bit, Bit 1
#define     LOG_GruendonnerstagMask 0x02
#define     LOG_GruendonnerstagShift 1
#define LOG_Karfreitag                11      // 1 Bit, Bit 0
#define     LOG_KarfreitagMask 0x01
#define     LOG_KarfreitagShift 0
#define LOG_Ostersonntag              12      // 1 Bit, Bit 7
#define     LOG_OstersonntagMask 0x80
#define     LOG_OstersonntagShift 7
#define LOG_Ostermontag               12      // 1 Bit, Bit 6
#define     LOG_OstermontagMask 0x40
#define     LOG_OstermontagShift 6
#define LOG_TagDerArbeit              12      // 1 Bit, Bit 5
#define     LOG_TagDerArbeitMask 0x20
#define     LOG_TagDerArbeitShift 5
#define LOG_Himmelfahrt               12      // 1 Bit, Bit 4
#define     LOG_HimmelfahrtMask 0x10
#define     LOG_HimmelfahrtShift 4
#define LOG_Pfingstsonntag            12      // 1 Bit, Bit 3
#define     LOG_PfingstsonntagMask 0x08
#define     LOG_PfingstsonntagShift 3
#define LOG_Pfingstmontag             12      // 1 Bit, Bit 2
#define     LOG_PfingstmontagMask 0x04
#define     LOG_PfingstmontagShift 2
#define LOG_Frohleichnam              12      // 1 Bit, Bit 1
#define     LOG_FrohleichnamMask 0x02
#define     LOG_FrohleichnamShift 1
#define LOG_Friedensfest              12      // 1 Bit, Bit 0
#define     LOG_FriedensfestMask 0x01
#define     LOG_FriedensfestShift 0
#define LOG_MariaHimmelfahrt          13      // 1 Bit, Bit 7
#define     LOG_MariaHimmelfahrtMask 0x80
#define     LOG_MariaHimmelfahrtShift 7
#define LOG_DeutscheEinheit           13      // 1 Bit, Bit 6
#define     LOG_DeutscheEinheitMask 0x40
#define     LOG_DeutscheEinheitShift 6
#define LOG_Reformationstag           13      // 1 Bit, Bit 5
#define     LOG_ReformationstagMask 0x20
#define     LOG_ReformationstagShift 5
#define LOG_Allerheiligen             13      // 1 Bit, Bit 4
#define     LOG_AllerheiligenMask 0x10
#define     LOG_AllerheiligenShift 4
#define LOG_BussBettag                13      // 1 Bit, Bit 3
#define     LOG_BussBettagMask 0x08
#define     LOG_BussBettagShift 3
#define LOG_Advent1                   13      // 1 Bit, Bit 2
#define     LOG_Advent1Mask 0x04
#define     LOG_Advent1Shift 2
#define LOG_Advent2                   13      // 1 Bit, Bit 1
#define     LOG_Advent2Mask 0x02
#define     LOG_Advent2Shift 1
#define LOG_Advent3                   13      // 1 Bit, Bit 0
#define     LOG_Advent3Mask 0x01
#define     LOG_Advent3Shift 0
#define LOG_Advent4                   14      // 1 Bit, Bit 7
#define     LOG_Advent4Mask 0x80
#define     LOG_Advent4Shift 7
#define LOG_Heiligabend               14      // 1 Bit, Bit 6
#define     LOG_HeiligabendMask 0x40
#define     LOG_HeiligabendShift 6
#define LOG_Weihnachtstag1            14      // 1 Bit, Bit 5
#define     LOG_Weihnachtstag1Mask 0x20
#define     LOG_Weihnachtstag1Shift 5
#define LOG_Weihnachtstag2            14      // 1 Bit, Bit 4
#define     LOG_Weihnachtstag2Mask 0x10
#define     LOG_Weihnachtstag2Shift 4
#define LOG_Silvester                 14      // 1 Bit, Bit 3
#define     LOG_SilvesterMask 0x08
#define     LOG_SilvesterShift 3
#define LOG_Latitude                  15      // float
#define LOG_Longitude                 19      // float
#define LOG_BuzzerSilent              23      // uint16_t
#define LOG_BuzzerNormal              25      // uint16_t
#define LOG_BuzzerLoud                27      // uint16_t
#define LOG_LedMapping                29      // 3 Bits, Bit 7-5
#define     LOG_LedMappingMask 0xE0
#define     LOG_LedMappingShift 5

#define LOG_KoHeartbeat 1
#define LOG_KoTime 2
#define LOG_KoDate 3
#define LOG_KoVacation 4
#define LOG_KoHoliday1 5
#define LOG_KoHoliday2 6
#define LOG_KoDiagnose 7
#define LOG_KoLedLock 8
#define LOG_KoBuzzerLock 9

#define WIRE_WireError                 45      // 1 Bit, Bit 7
#define     WIRE_WireErrorMask 0x80
#define     WIRE_WireErrorShift 7
#define WIRE_BusMasterCount            45      // 2 Bits, Bit 6-5
#define     WIRE_BusMasterCountMask 0x60
#define     WIRE_BusMasterCountShift 5
#define WIRE_IdSearch                  45      // 1 Bit, Bit 4
#define     WIRE_IdSearchMask 0x10
#define     WIRE_IdSearchShift 4
#define WIRE_IButton1                  45      // 1 Bit, Bit 3
#define     WIRE_IButton1Mask 0x08
#define     WIRE_IButton1Shift 3
#define WIRE_IButton2                  45      // 1 Bit, Bit 2
#define     WIRE_IButton2Mask 0x04
#define     WIRE_IButton2Shift 2
#define WIRE_IButton3                  45      // 1 Bit, Bit 1
#define     WIRE_IButton3Mask 0x02
#define     WIRE_IButton3Shift 1
#define WIRE_Group1                    46      // 1 Bit, Bit 7
#define     WIRE_Group1Mask 0x80
#define     WIRE_Group1Shift 7
#define WIRE_Group2                    46      // 1 Bit, Bit 6
#define     WIRE_Group2Mask 0x40
#define     WIRE_Group2Shift 6
#define WIRE_Group3                    46      // 1 Bit, Bit 5
#define     WIRE_Group3Mask 0x20
#define     WIRE_Group3Shift 5
#define WIRE_Group4                    46      // 1 Bit, Bit 4
#define     WIRE_Group4Mask 0x10
#define     WIRE_Group4Shift 4
#define WIRE_Group5                    46      // 1 Bit, Bit 3
#define     WIRE_Group5Mask 0x08
#define     WIRE_Group5Shift 3
#define WIRE_Group6                    46      // 1 Bit, Bit 2
#define     WIRE_Group6Mask 0x04
#define     WIRE_Group6Shift 2
#define WIRE_Group7                    46      // 1 Bit, Bit 1
#define     WIRE_Group7Mask 0x02
#define     WIRE_Group7Shift 1
#define WIRE_Group8                    46      // 1 Bit, Bit 0
#define     WIRE_Group8Mask 0x01
#define     WIRE_Group8Shift 0
#define WIRE_Busmaster1RSTL            47      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1RSTLMask 0xF0
#define     WIRE_Busmaster1RSTLShift 4
#define WIRE_Busmaster1MSP             47      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1MSPMask 0x0F
#define     WIRE_Busmaster1MSPShift 0
#define WIRE_Busmaster1W0L             48      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1W0LMask 0xF0
#define     WIRE_Busmaster1W0LShift 4
#define WIRE_Busmaster1REC0            48      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1REC0Mask 0x0F
#define     WIRE_Busmaster1REC0Shift 0
#define WIRE_Busmaster1WPU             49      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1WPUMask 0xF0
#define     WIRE_Busmaster1WPUShift 4

#define WIRE_KoNewId 20
#define WIRE_KoErrorBusmaster1 21
#define WIRE_KoErrorBusmaster2 22
#define WIRE_KoErrorBusmaster3 23
#define WIRE_KoGroup1 24
#define WIRE_KoGroup2 25
#define WIRE_KoGroup3 26
#define WIRE_KoGroup4 27
#define WIRE_KoGroup5 28
#define WIRE_KoGroup6 29
#define WIRE_KoGroup7 30
#define WIRE_KoGroup8 31

#define SENS_Error                     75      // 1 Bit, Bit 7
#define     SENS_ErrorMask 0x80
#define     SENS_ErrorShift 7
#define SENS_Dewpoint                  75      // 1 Bit, Bit 6
#define     SENS_DewpointMask 0x40
#define     SENS_DewpointShift 6
#define SENS_Comfort                   75      // 1 Bit, Bit 5
#define     SENS_ComfortMask 0x20
#define     SENS_ComfortShift 5
#define SENS_Airquality                75      // 1 Bit, Bit 4
#define     SENS_AirqualityMask 0x10
#define     SENS_AirqualityShift 4
#define SENS_Accuracy                  75      // 1 Bit, Bit 3
#define     SENS_AccuracyMask 0x08
#define     SENS_AccuracyShift 3
#define SENS_DeleteData                75      // 1 Bit, Bit 2
#define     SENS_DeleteDataMask 0x04
#define     SENS_DeleteDataShift 2
#define SENS_TempOffset                76      // int8_t
#define SENS_TempCycle                 77      // int32_t
#define SENS_TempDeltaAbs              81      // uint16_t
#define SENS_TempDeltaPercent          83      // uint8_t
#define SENS_TempSmooth                84      // uint8_t
#define SENS_TempExtCount              85      // 2 Bits, Bit 1-0
#define     SENS_TempExtCountMask 0x03
#define     SENS_TempExtCountShift 0
#define SENS_TempExtRead               85      // 1 Bit, Bit 2
#define     SENS_TempExtReadMask 0x04
#define     SENS_TempExtReadShift 2
#define SENS_TempIntPercent            86      // uint8_t
#define SENS_TempExt1Percent           87      // uint8_t
#define SENS_TempExt2Percent           88      // uint8_t
#define SENS_HumOffset                 89      // int8_t
#define SENS_HumCycle                  90      // int32_t
#define SENS_HumDeltaAbs               94      // uint16_t
#define SENS_HumDeltaPercent           96      // uint8_t
#define SENS_HumSmooth                 97      // uint8_t
#define SENS_HumExtCount               98      // 2 Bits, Bit 1-0
#define     SENS_HumExtCountMask 0x03
#define     SENS_HumExtCountShift 0
#define SENS_HumExtRead                98      // 1 Bit, Bit 2
#define     SENS_HumExtReadMask 0x04
#define     SENS_HumExtReadShift 2
#define SENS_HumIntPercent             99      // uint8_t
#define SENS_HumExt1Percent            100      // uint8_t
#define SENS_HumExt2Percent            101      // uint8_t
#define SENS_PreOffset                 102      // int8_t
#define SENS_PreCycle                  103      // int32_t
#define SENS_PreDeltaAbs               107      // uint16_t
#define SENS_PreDeltaPercent           109      // uint8_t
#define SENS_PreSmooth                 110      // uint8_t
#define SENS_PreExtCount               111      // 2 Bits, Bit 1-0
#define     SENS_PreExtCountMask 0x03
#define     SENS_PreExtCountShift 0
#define SENS_PreExtRead                111      // 1 Bit, Bit 2
#define     SENS_PreExtReadMask 0x04
#define     SENS_PreExtReadShift 2
#define SENS_PreIntPercent             112      // uint8_t
#define SENS_PreExt1Percent            113      // uint8_t
#define SENS_PreExt2Percent            114      // uint8_t
#define SENS_VocOffset                 115      // int8_t
#define SENS_VocCycle                  116      // int32_t
#define SENS_VocDeltaAbs               120      // uint16_t
#define SENS_VocDeltPercent            122      // uint8_t
#define SENS_VocSmooth                 123      // uint8_t
#define SENS_VocExtCount               124      // 2 Bits, Bit 1-0
#define     SENS_VocExtCountMask 0x03
#define     SENS_VocExtCountShift 0
#define SENS_VocExtRead                124      // 1 Bit, Bit 2
#define     SENS_VocExtReadMask 0x04
#define     SENS_VocExtReadShift 2
#define SENS_VocIntPercent             125      // uint8_t
#define SENS_VocExt1Percent            126      // uint8_t
#define SENS_VocExt2Percent            127      // uint8_t
#define SENS_Co2Offset                 128      // int8_t
#define SENS_Co2Cycle                  129      // int32_t
#define SENS_Co2DeltaAbs               133      // uint16_t
#define SENS_Co2DeltaPercent           135      // uint8_t
#define SENS_Co2Smooth                 136      // uint8_t
#define SENS_Co2ExtCount               137      // 2 Bits, Bit 1-0
#define     SENS_Co2ExtCountMask 0x03
#define     SENS_Co2ExtCountShift 0
#define SENS_Co2ExtRead                137      // 1 Bit, Bit 2
#define     SENS_Co2ExtReadMask 0x04
#define     SENS_Co2ExtReadShift 2
#define SENS_Co2IntPercent             138      // uint8_t
#define SENS_Co2Ext1Percent            139      // uint8_t
#define SENS_Co2Ext2Percent            140      // uint8_t
#define SENS_SensorDevice              141      // 6 Bits, Bit 6-1
#define     SENS_SensorDeviceMask 0x7E
#define     SENS_SensorDeviceShift 1
#define SENS_Sensor1Wire               141      // 1 Bit, Bit 0
#define     SENS_Sensor1WireMask 0x01
#define     SENS_Sensor1WireShift 0
#define SENS_DewOffset                 142      // int8_t
#define SENS_DewCycle                  143      // int32_t
#define SENS_DewDeltaAbs               147      // uint16_t
#define SENS_DewDeltaPercent           149      // uint8_t
#define SENS_DewSmooth                 150      // uint8_t
#define SENS_LuxOffset                 151      // int8_t
#define SENS_LuxCycle                  152      // int32_t
#define SENS_LuxDeltaAbs               156      // uint16_t
#define SENS_LuxDeltPercent            158      // uint8_t
#define SENS_LuxSmooth                 159      // uint8_t
#define SENS_LuxExtCount               160      // 2 Bits, Bit 1-0
#define     SENS_LuxExtCountMask 0x03
#define     SENS_LuxExtCountShift 0
#define SENS_LuxExtRead                160      // 1 Bit, Bit 2
#define     SENS_LuxExtReadMask 0x04
#define     SENS_LuxExtReadShift 2
#define SENS_LuxIntPercent             161      // uint8_t
#define SENS_LuxExt1Percent            162      // uint8_t
#define SENS_LuxExt2Percent            163      // uint8_t
#define SENS_TofOffset                 164      // int8_t
#define SENS_TofCycle                  165      // int32_t
#define SENS_TofDeltaAbs               169      // uint16_t
#define SENS_TofDeltaPercent           171      // uint8_t
#define SENS_TofSmooth                 172      // uint8_t
#define SENS_TofExtCount               173      // 2 Bits, Bit 1-0
#define     SENS_TofExtCountMask 0x03
#define     SENS_TofExtCountShift 0
#define SENS_TofExtRead                173      // 1 Bit, Bit 2
#define     SENS_TofExtReadMask 0x04
#define     SENS_TofExtReadShift 2
#define SENS_TofIntPercent             174      // uint8_t
#define SENS_TofExt1Percent            175      // uint8_t
#define SENS_TofExt2Percent            176      // uint8_t
#define SENS_TempSensor                177      // 4 Bits, Bit 7-4
#define     SENS_TempSensorMask 0xF0
#define     SENS_TempSensorShift 4
#define SENS_HumSensor                 177      // 4 Bits, Bit 3-0
#define     SENS_HumSensorMask 0x0F
#define     SENS_HumSensorShift 0
#define SENS_PreSensor                 178      // 4 Bits, Bit 7-4
#define     SENS_PreSensorMask 0xF0
#define     SENS_PreSensorShift 4
#define SENS_VocSensor                 178      // 4 Bits, Bit 3-0
#define     SENS_VocSensorMask 0x0F
#define     SENS_VocSensorShift 0
#define SENS_Co2Sensor                 179      // 4 Bits, Bit 7-4
#define     SENS_Co2SensorMask 0xF0
#define     SENS_Co2SensorShift 4
#define SENS_LuxSensor                 179      // 4 Bits, Bit 3-0
#define     SENS_LuxSensorMask 0x0F
#define     SENS_LuxSensorShift 0
#define SENS_TofSensor                 180      // 4 Bits, Bit 7-4
#define     SENS_TofSensorMask 0xF0
#define     SENS_TofSensorShift 4

#define SENS_KoRequestValues 50
#define SENS_KoError 51
#define SENS_KoTemp 60
#define SENS_KoHum 61
#define SENS_KoPre 62
#define SENS_KoVOC 63
#define SENS_KoCo2 64
#define SENS_KoCo2b 65
#define SENS_KoDewpoint 66
#define SENS_KoComfort 67
#define SENS_KoAirquality 68
#define SENS_KoSensorAccuracy 69
#define SENS_KoExt1Temp 70
#define SENS_KoExt2Temp 71
#define SENS_KoExt1Hum 72
#define SENS_KoExt2Hum 73
#define SENS_KoExt1Pre 74
#define SENS_KoExt2Pre 75
#define SENS_KoExt1VOC 76
#define SENS_KoExt2VOC 77
#define SENS_KoExt1Co2 78
#define SENS_KoExt2Co2 79
#define SENS_KoExt1Lux 80
#define SENS_KoExt2Lux 81
#define SENS_KoExt1Tof 82
#define SENS_KoExt2Tof 83
#define SENS_KoLux 87
#define SENS_KoTof 88

// Parameter per channel
#define LOG_ParamBlockOffset 181
#define LOG_ParamBlockSize 104
#define LOG_fChannelDelay              0      // int32_t
#define LOG_fLogic                     4      // 8 Bits, Bit 7-0
#define LOG_fCalculate                 5      // 2 Bits, Bit 1-0
#define     LOG_fCalculateMask 0x03
#define     LOG_fCalculateShift 0
#define LOG_fDisable                   5      // 1 Bit, Bit 2
#define     LOG_fDisableMask 0x04
#define     LOG_fDisableShift 2
#define LOG_fAlarm                     5      // 1 Bit, Bit 3
#define     LOG_fAlarmMask 0x08
#define     LOG_fAlarmShift 3
#define LOG_fTrigger                   6      // 8 Bits, Bit 7-0
#define LOG_fTriggerE1                 6      // 1 Bit, Bit 0
#define     LOG_fTriggerE1Mask 0x01
#define     LOG_fTriggerE1Shift 0
#define LOG_fTriggerE2                 6      // 1 Bit, Bit 1
#define     LOG_fTriggerE2Mask 0x02
#define     LOG_fTriggerE2Shift 1
#define LOG_fTriggerI1                 6      // 1 Bit, Bit 2
#define     LOG_fTriggerI1Mask 0x04
#define     LOG_fTriggerI1Shift 2
#define LOG_fTriggerI2                 6      // 1 Bit, Bit 3
#define     LOG_fTriggerI2Mask 0x08
#define     LOG_fTriggerI2Shift 3
#define LOG_fTriggerTime               6      // 8 Bits, Bit 7-0
#define LOG_fTriggerGateClose          7      // 8 Bits, Bit 7-0
#define LOG_fTriggerGateOpen           8      // 8 Bits, Bit 7-0
#define LOG_fE1                        9      // 4 Bits, Bit 3-0
#define     LOG_fE1Mask 0x0F
#define     LOG_fE1Shift 0
#define LOG_fE1Convert                 9      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertMask 0xF0
#define     LOG_fE1ConvertShift 4
#define LOG_fE1ConvertFloat            9      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertFloatMask 0xF0
#define     LOG_fE1ConvertFloatShift 4
#define LOG_fE1ConvertSpecial          9      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertSpecialMask 0xF0
#define     LOG_fE1ConvertSpecialShift 4
#define LOG_fE1Dpt                    10      // 8 Bits, Bit 7-0
#define LOG_fE1Default                11      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultMask 0x03
#define     LOG_fE1DefaultShift 0
#define LOG_fE1DefaultEEPROM          11      // 1 Bit, Bit 2
#define     LOG_fE1DefaultEEPROMMask 0x04
#define     LOG_fE1DefaultEEPROMShift 2
#define LOG_fE1DefaultRepeat          11      // 1 Bit, Bit 3
#define     LOG_fE1DefaultRepeatMask 0x08
#define     LOG_fE1DefaultRepeatShift 3
#define LOG_fTYearDay                 11      // 1 Bit, Bit 4
#define     LOG_fTYearDayMask 0x10
#define     LOG_fTYearDayShift 4
#define LOG_fTRestoreState            11      // 2 Bits, Bit 6-5
#define     LOG_fTRestoreStateMask 0x60
#define     LOG_fTRestoreStateShift 5
#define LOG_fE1Repeat                 12      // int32_t
#define LOG_fE2                       16      // 4 Bits, Bit 3-0
#define     LOG_fE2Mask 0x0F
#define     LOG_fE2Shift 0
#define LOG_fE2Convert                16      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertMask 0xF0
#define     LOG_fE2ConvertShift 4
#define LOG_fE2ConvertFloat           16      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertFloatMask 0xF0
#define     LOG_fE2ConvertFloatShift 4
#define LOG_fE2ConvertSpecial         16      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertSpecialMask 0xF0
#define     LOG_fE2ConvertSpecialShift 4
#define LOG_fE2Dpt                    17      // 8 Bits, Bit 7-0
#define LOG_fE2Default                18      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultMask 0x03
#define     LOG_fE2DefaultShift 0
#define LOG_fE2DefaultEEPROM          18      // 1 Bit, Bit 2
#define     LOG_fE2DefaultEEPROMMask 0x04
#define     LOG_fE2DefaultEEPROMShift 2
#define LOG_fE2DefaultRepeat          18      // 1 Bit, Bit 3
#define     LOG_fE2DefaultRepeatMask 0x08
#define     LOG_fE2DefaultRepeatShift 3
#define LOG_fTHoliday                 18      // 2 Bits, Bit 4-3
#define     LOG_fTHolidayMask 0x18
#define     LOG_fTHolidayShift 3
#define LOG_fTVacation                18      // 2 Bits, Bit 6-5
#define     LOG_fTVacationMask 0x60
#define     LOG_fTVacationShift 5
#define LOG_fE2Repeat                 19      // int32_t
#define LOG_fTd1DuskDawn              19      // 4 Bits, Bit 7-4
#define     LOG_fTd1DuskDawnMask 0xF0
#define     LOG_fTd1DuskDawnShift 4
#define LOG_fTd2DuskDawn              19      // 4 Bits, Bit 3-0
#define     LOG_fTd2DuskDawnMask 0x0F
#define     LOG_fTd2DuskDawnShift 0
#define LOG_fTd3DuskDawn              20      // 4 Bits, Bit 7-4
#define     LOG_fTd3DuskDawnMask 0xF0
#define     LOG_fTd3DuskDawnShift 4
#define LOG_fTd4DuskDawn              20      // 4 Bits, Bit 3-0
#define     LOG_fTd4DuskDawnMask 0x0F
#define     LOG_fTd4DuskDawnShift 0
#define LOG_fTd5DuskDawn              21      // 4 Bits, Bit 7-4
#define     LOG_fTd5DuskDawnMask 0xF0
#define     LOG_fTd5DuskDawnShift 4
#define LOG_fTd6DuskDawn              21      // 4 Bits, Bit 3-0
#define     LOG_fTd6DuskDawnMask 0x0F
#define     LOG_fTd6DuskDawnShift 0
#define LOG_fTd7DuskDawn              22      // 4 Bits, Bit 7-4
#define     LOG_fTd7DuskDawnMask 0xF0
#define     LOG_fTd7DuskDawnShift 4
#define LOG_fTd8DuskDawn              22      // 4 Bits, Bit 3-0
#define     LOG_fTd8DuskDawnMask 0x0F
#define     LOG_fTd8DuskDawnShift 0
#define LOG_fE1LowDelta               23      // int32_t
#define LOG_fE1HighDelta              27      // int32_t
#define LOG_fE1LowDeltaFloat          23      // float
#define LOG_fE1HighDeltaFloat         27      // float
#define LOG_fE1Low0Valid              30      // 1 Bit, Bit 7
#define     LOG_fE1Low0ValidMask 0x80
#define     LOG_fE1Low0ValidShift 7
#define LOG_fE1Low1Valid              30      // 1 Bit, Bit 6
#define     LOG_fE1Low1ValidMask 0x40
#define     LOG_fE1Low1ValidShift 6
#define LOG_fE1Low2Valid              30      // 1 Bit, Bit 5
#define     LOG_fE1Low2ValidMask 0x20
#define     LOG_fE1Low2ValidShift 5
#define LOG_fE1Low3Valid              30      // 1 Bit, Bit 4
#define     LOG_fE1Low3ValidMask 0x10
#define     LOG_fE1Low3ValidShift 4
#define LOG_fE1Low4Valid              30      // 1 Bit, Bit 3
#define     LOG_fE1Low4ValidMask 0x08
#define     LOG_fE1Low4ValidShift 3
#define LOG_fE1Low5Valid              30      // 1 Bit, Bit 2
#define     LOG_fE1Low5ValidMask 0x04
#define     LOG_fE1Low5ValidShift 2
#define LOG_fE1Low6Valid              30      // 1 Bit, Bit 1
#define     LOG_fE1Low6ValidMask 0x02
#define     LOG_fE1Low6ValidShift 1
#define LOG_fE1Low7Valid              30      // 1 Bit, Bit 0
#define     LOG_fE1Low7ValidMask 0x01
#define     LOG_fE1Low7ValidShift 0
#define LOG_fE1LowDpt2                23      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt2               24      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt2               25      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt2               26      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt2Fix             23      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt5                23      // uint8_t
#define LOG_fE1HighDpt5               27      // uint8_t
#define LOG_fE1Low0Dpt5In             23      // uint8_t
#define LOG_fE1Low1Dpt5In             24      // uint8_t
#define LOG_fE1Low2Dpt5In             25      // uint8_t
#define LOG_fE1Low3Dpt5In             26      // uint8_t
#define LOG_fE1Low4Dpt5In             27      // uint8_t
#define LOG_fE1Low5Dpt5In             28      // uint8_t
#define LOG_fE1Low6Dpt5In             29      // uint8_t
#define LOG_fE1LowDpt5Fix             23      // uint8_t
#define LOG_fE1LowDpt5001             23      // uint8_t
#define LOG_fE1HighDpt5001            27      // uint8_t
#define LOG_fE1Low0Dpt5xIn            23      // uint8_t
#define LOG_fE1Low1Dpt5xIn            24      // uint8_t
#define LOG_fE1Low2Dpt5xIn            25      // uint8_t
#define LOG_fE1Low3Dpt5xIn            26      // uint8_t
#define LOG_fE1Low4Dpt5xIn            27      // uint8_t
#define LOG_fE1Low5Dpt5xIn            28      // uint8_t
#define LOG_fE1Low6Dpt5xIn            29      // uint8_t
#define LOG_fE1LowDpt5xFix            23      // uint8_t
#define LOG_fE1LowDpt6                23      // int8_t
#define LOG_fE1HighDpt6               27      // int8_t
#define LOG_fE1Low0Dpt6In             23      // int8_t
#define LOG_fE1Low1Dpt6In             24      // int8_t
#define LOG_fE1Low2Dpt6In             25      // int8_t
#define LOG_fE1Low3Dpt6In             26      // int8_t
#define LOG_fE1Low4Dpt6In             27      // int8_t
#define LOG_fE1Low5Dpt6In             28      // int8_t
#define LOG_fE1Low6Dpt6In             29      // int8_t
#define LOG_fE1LowDpt6Fix             23      // int8_t
#define LOG_fE1LowDpt7                23      // uint16_t
#define LOG_fE1HighDpt7               27      // uint16_t
#define LOG_fE1Low0Dpt7In             23      // uint16_t
#define LOG_fE1Low1Dpt7In             25      // uint16_t
#define LOG_fE1Low2Dpt7In             27      // uint16_t
#define LOG_fE1LowDpt7Fix             23      // uint16_t
#define LOG_fE1LowDpt8                23      // int16_t
#define LOG_fE1HighDpt8               27      // int16_t
#define LOG_fE1Low0Dpt8In             23      // int16_t
#define LOG_fE1Low1Dpt8In             25      // int16_t
#define LOG_fE1Low2Dpt8In             27      // int16_t
#define LOG_fE1LowDpt8Fix             23      // int16_t
#define LOG_fE1LowDpt9                23      // float
#define LOG_fE1HighDpt9               27      // float
#define LOG_fE1LowDpt9Fix             23      // float
#define LOG_fE1Low0Dpt17              23      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt17              24      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt17              25      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt17              26      // 8 Bits, Bit 7-0
#define LOG_fE1Low4Dpt17              27      // 8 Bits, Bit 7-0
#define LOG_fE1Low5Dpt17              28      // 8 Bits, Bit 7-0
#define LOG_fE1Low6Dpt17              29      // 8 Bits, Bit 7-0
#define LOG_fE1Low7Dpt17              30      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt17Fix            23      // 8 Bits, Bit 7-0
#define LOG_fE1LowDptRGB              23      // int32_t
#define LOG_fE1HighDptRGB             27      // int32_t
#define LOG_fE1LowDptRGBFix           23      // int32_t
#define LOG_fE2LowDelta               31      // int32_t
#define LOG_fE2HighDelta              35      // int32_t
#define LOG_fE2LowDeltaFloat          31      // float
#define LOG_fE2HighDeltaFloat         35      // float
#define LOG_fE2Low0Valid              38      // 1 Bit, Bit 7
#define     LOG_fE2Low0ValidMask 0x80
#define     LOG_fE2Low0ValidShift 7
#define LOG_fE2Low1Valid              38      // 1 Bit, Bit 6
#define     LOG_fE2Low1ValidMask 0x40
#define     LOG_fE2Low1ValidShift 6
#define LOG_fE2Low2Valid              38      // 1 Bit, Bit 5
#define     LOG_fE2Low2ValidMask 0x20
#define     LOG_fE2Low2ValidShift 5
#define LOG_fE2Low3Valid              38      // 1 Bit, Bit 4
#define     LOG_fE2Low3ValidMask 0x10
#define     LOG_fE2Low3ValidShift 4
#define LOG_fE2Low4Valid              38      // 1 Bit, Bit 3
#define     LOG_fE2Low4ValidMask 0x08
#define     LOG_fE2Low4ValidShift 3
#define LOG_fE2Low5Valid              38      // 1 Bit, Bit 2
#define     LOG_fE2Low5ValidMask 0x04
#define     LOG_fE2Low5ValidShift 2
#define LOG_fE2Low6Valid              38      // 1 Bit, Bit 1
#define     LOG_fE2Low6ValidMask 0x02
#define     LOG_fE2Low6ValidShift 1
#define LOG_fE2Low7Valid              38      // 1 Bit, Bit 0
#define     LOG_fE2Low7ValidMask 0x01
#define     LOG_fE2Low7ValidShift 0
#define LOG_fE2Low0Dpt2               31      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt2               32      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt2               33      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt2               34      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt2Fix             31      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt5                31      // uint8_t
#define LOG_fE2HighDpt5               35      // uint8_t
#define LOG_fE2Low0Dpt5In             31      // uint8_t
#define LOG_fE2Low1Dpt5In             32      // uint8_t
#define LOG_fE2Low2Dpt5In             33      // uint8_t
#define LOG_fE2Low3Dpt5In             34      // uint8_t
#define LOG_fE2Low4Dpt5In             35      // uint8_t
#define LOG_fE2Low5Dpt5In             36      // uint8_t
#define LOG_fE2Low6Dpt5In             37      // uint8_t
#define LOG_fE2LowDpt5Fix             31      // uint8_t
#define LOG_fE2LowDpt5001             31      // uint8_t
#define LOG_fE2HighDpt5001            35      // uint8_t
#define LOG_fE2Low0Dpt5xIn            31      // uint8_t
#define LOG_fE2Low1Dpt5xIn            32      // uint8_t
#define LOG_fE2Low2Dpt5xIn            33      // uint8_t
#define LOG_fE2Low3Dpt5xIn            34      // uint8_t
#define LOG_fE2Low4Dpt5xIn            35      // uint8_t
#define LOG_fE2Low5Dpt5xIn            36      // uint8_t
#define LOG_fE2Low6Dpt5xIn            37      // uint8_t
#define LOG_fE2LowDpt5xFix            31      // uint8_t
#define LOG_fE2LowDpt6                31      // int8_t
#define LOG_fE2HighDpt6               35      // int8_t
#define LOG_fE2Low0Dpt6In             31      // int8_t
#define LOG_fE2Low1Dpt6In             32      // int8_t
#define LOG_fE2Low2Dpt6In             33      // int8_t
#define LOG_fE2Low3Dpt6In             34      // int8_t
#define LOG_fE2Low4Dpt6In             35      // int8_t
#define LOG_fE2Low5Dpt6In             36      // int8_t
#define LOG_fE2Low6Dpt6In             37      // int8_t
#define LOG_fE2LowDpt6Fix             31      // int8_t
#define LOG_fE2LowDpt7                31      // uint16_t
#define LOG_fE2HighDpt7               35      // uint16_t
#define LOG_fE2Low0Dpt7In             31      // uint16_t
#define LOG_fE2Low1Dpt7In             33      // uint16_t
#define LOG_fE2Low2Dpt7In             35      // uint16_t
#define LOG_fE2LowDpt7Fix             31      // uint16_t
#define LOG_fE2LowDpt8                31      // int16_t
#define LOG_fE2HighDpt8               35      // int16_t
#define LOG_fE2Low0Dpt8In             31      // int16_t
#define LOG_fE2Low1Dpt8In             33      // int16_t
#define LOG_fE2Low2Dpt8In             35      // int16_t
#define LOG_fE2LowDpt8Fix             31      // int16_t
#define LOG_fE2LowDpt9                31      // float
#define LOG_fE2HighDpt9               35      // float
#define LOG_fE2LowDpt9Fix             31      // float
#define LOG_fE2Low0Dpt17              31      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt17              32      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt17              33      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt17              34      // 8 Bits, Bit 7-0
#define LOG_fE2Low4Dpt17              35      // 8 Bits, Bit 7-0
#define LOG_fE2Low5Dpt17              36      // 8 Bits, Bit 7-0
#define LOG_fE2Low6Dpt17              37      // 8 Bits, Bit 7-0
#define LOG_fE2Low7Dpt17              38      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt17Fix            31      // 8 Bits, Bit 7-0
#define LOG_fE2LowDptRGB              31      // int32_t
#define LOG_fE2HighDptRGB             35      // int32_t
#define LOG_fE2LowDptRGBFix           31      // int32_t
#define LOG_fTd1Value                 23      // 1 Bit, Bit 7
#define     LOG_fTd1ValueMask 0x80
#define     LOG_fTd1ValueShift 7
#define LOG_fTd1HourAbs               23      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourAbsMask 0x3E
#define     LOG_fTd1HourAbsShift 1
#define LOG_fTd1HourRel               23      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelMask 0x3E
#define     LOG_fTd1HourRelShift 1
#define LOG_fTd1MinuteAbs             23      // 6 Bits, Bit 0--5
#define LOG_fTd1MinuteRel             23      // 6 Bits, Bit 0--5
#define LOG_fTd1Weekday               24      // 3 Bits, Bit 2-0
#define     LOG_fTd1WeekdayMask 0x07
#define     LOG_fTd1WeekdayShift 0
#define LOG_fTd2Value                 25      // 1 Bit, Bit 7
#define     LOG_fTd2ValueMask 0x80
#define     LOG_fTd2ValueShift 7
#define LOG_fTd2HourAbs               25      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourAbsMask 0x3E
#define     LOG_fTd2HourAbsShift 1
#define LOG_fTd2HourRel               25      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelMask 0x3E
#define     LOG_fTd2HourRelShift 1
#define LOG_fTd2MinuteAbs             25      // 6 Bits, Bit 0--5
#define LOG_fTd2MinuteRel             25      // 6 Bits, Bit 0--5
#define LOG_fTd2Weekday               26      // 3 Bits, Bit 2-0
#define     LOG_fTd2WeekdayMask 0x07
#define     LOG_fTd2WeekdayShift 0
#define LOG_fTd3Value                 27      // 1 Bit, Bit 7
#define     LOG_fTd3ValueMask 0x80
#define     LOG_fTd3ValueShift 7
#define LOG_fTd3HourAbs               27      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourAbsMask 0x3E
#define     LOG_fTd3HourAbsShift 1
#define LOG_fTd3HourRel               27      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelMask 0x3E
#define     LOG_fTd3HourRelShift 1
#define LOG_fTd3MinuteAbs             27      // 6 Bits, Bit 0--5
#define LOG_fTd3MinuteRel             27      // 6 Bits, Bit 0--5
#define LOG_fTd3Weekday               28      // 3 Bits, Bit 2-0
#define     LOG_fTd3WeekdayMask 0x07
#define     LOG_fTd3WeekdayShift 0
#define LOG_fTd4Value                 29      // 1 Bit, Bit 7
#define     LOG_fTd4ValueMask 0x80
#define     LOG_fTd4ValueShift 7
#define LOG_fTd4HourAbs               29      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourAbsMask 0x3E
#define     LOG_fTd4HourAbsShift 1
#define LOG_fTd4HourRel               29      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelMask 0x3E
#define     LOG_fTd4HourRelShift 1
#define LOG_fTd4MinuteAbs             29      // 6 Bits, Bit 0--5
#define LOG_fTd4MinuteRel             29      // 6 Bits, Bit 0--5
#define LOG_fTd4Weekday               30      // 3 Bits, Bit 2-0
#define     LOG_fTd4WeekdayMask 0x07
#define     LOG_fTd4WeekdayShift 0
#define LOG_fTd5Value                 31      // 1 Bit, Bit 7
#define     LOG_fTd5ValueMask 0x80
#define     LOG_fTd5ValueShift 7
#define LOG_fTd5HourAbs               31      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourAbsMask 0x3E
#define     LOG_fTd5HourAbsShift 1
#define LOG_fTd5HourRel               31      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelMask 0x3E
#define     LOG_fTd5HourRelShift 1
#define LOG_fTd5MinuteAbs             31      // 6 Bits, Bit 0--5
#define LOG_fTd5MinuteRel             31      // 6 Bits, Bit 0--5
#define LOG_fTd5Weekday               32      // 3 Bits, Bit 2-0
#define     LOG_fTd5WeekdayMask 0x07
#define     LOG_fTd5WeekdayShift 0
#define LOG_fTd6Value                 33      // 1 Bit, Bit 7
#define     LOG_fTd6ValueMask 0x80
#define     LOG_fTd6ValueShift 7
#define LOG_fTd6HourAbs               33      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourAbsMask 0x3E
#define     LOG_fTd6HourAbsShift 1
#define LOG_fTd6HourRel               33      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelMask 0x3E
#define     LOG_fTd6HourRelShift 1
#define LOG_fTd6MinuteAbs             33      // 6 Bits, Bit 0--5
#define LOG_fTd6MinuteRel             33      // 6 Bits, Bit 0--5
#define LOG_fTd6Weekday               34      // 3 Bits, Bit 2-0
#define     LOG_fTd6WeekdayMask 0x07
#define     LOG_fTd6WeekdayShift 0
#define LOG_fTd7Value                 35      // 1 Bit, Bit 7
#define     LOG_fTd7ValueMask 0x80
#define     LOG_fTd7ValueShift 7
#define LOG_fTd7HourAbs               35      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourAbsMask 0x3E
#define     LOG_fTd7HourAbsShift 1
#define LOG_fTd7HourRel               35      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelMask 0x3E
#define     LOG_fTd7HourRelShift 1
#define LOG_fTd7MinuteAbs             35      // 6 Bits, Bit 0--5
#define LOG_fTd7MinuteRel             35      // 6 Bits, Bit 0--5
#define LOG_fTd7Weekday               36      // 3 Bits, Bit 2-0
#define     LOG_fTd7WeekdayMask 0x07
#define     LOG_fTd7WeekdayShift 0
#define LOG_fTd8Value                 37      // 1 Bit, Bit 7
#define     LOG_fTd8ValueMask 0x80
#define     LOG_fTd8ValueShift 7
#define LOG_fTd8HourAbs               37      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourAbsMask 0x3E
#define     LOG_fTd8HourAbsShift 1
#define LOG_fTd8HourRel               37      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelMask 0x3E
#define     LOG_fTd8HourRelShift 1
#define LOG_fTd8MinuteAbs             37      // 6 Bits, Bit 0--5
#define LOG_fTd8MinuteRel             37      // 6 Bits, Bit 0--5
#define LOG_fTd8Weekday               38      // 3 Bits, Bit 2-0
#define     LOG_fTd8WeekdayMask 0x07
#define     LOG_fTd8WeekdayShift 0
#define LOG_fTy1Weekday1              31      // 1 Bit, Bit 7
#define     LOG_fTy1Weekday1Mask 0x80
#define     LOG_fTy1Weekday1Shift 7
#define LOG_fTy1Weekday2              31      // 1 Bit, Bit 6
#define     LOG_fTy1Weekday2Mask 0x40
#define     LOG_fTy1Weekday2Shift 6
#define LOG_fTy1Weekday3              31      // 1 Bit, Bit 5
#define     LOG_fTy1Weekday3Mask 0x20
#define     LOG_fTy1Weekday3Shift 5
#define LOG_fTy1Weekday4              31      // 1 Bit, Bit 4
#define     LOG_fTy1Weekday4Mask 0x10
#define     LOG_fTy1Weekday4Shift 4
#define LOG_fTy1Weekday5              31      // 1 Bit, Bit 3
#define     LOG_fTy1Weekday5Mask 0x08
#define     LOG_fTy1Weekday5Shift 3
#define LOG_fTy1Weekday6              31      // 1 Bit, Bit 2
#define     LOG_fTy1Weekday6Mask 0x04
#define     LOG_fTy1Weekday6Shift 2
#define LOG_fTy1Weekday7              31      // 1 Bit, Bit 1
#define     LOG_fTy1Weekday7Mask 0x02
#define     LOG_fTy1Weekday7Shift 1
#define LOG_fTy1Day                   31      // 7 Bits, Bit 7-1
#define LOG_fTy1IsWeekday             31      // 1 Bit, Bit 0
#define     LOG_fTy1IsWeekdayMask 0x01
#define     LOG_fTy1IsWeekdayShift 0
#define LOG_fTy1Month                 32      // 4 Bits, Bit 7-4
#define     LOG_fTy1MonthMask 0xF0
#define     LOG_fTy1MonthShift 4
#define LOG_fTy2Weekday1              33      // 1 Bit, Bit 7
#define     LOG_fTy2Weekday1Mask 0x80
#define     LOG_fTy2Weekday1Shift 7
#define LOG_fTy2Weekday2              33      // 1 Bit, Bit 6
#define     LOG_fTy2Weekday2Mask 0x40
#define     LOG_fTy2Weekday2Shift 6
#define LOG_fTy2Weekday3              33      // 1 Bit, Bit 5
#define     LOG_fTy2Weekday3Mask 0x20
#define     LOG_fTy2Weekday3Shift 5
#define LOG_fTy2Weekday4              33      // 1 Bit, Bit 4
#define     LOG_fTy2Weekday4Mask 0x10
#define     LOG_fTy2Weekday4Shift 4
#define LOG_fTy2Weekday5              33      // 1 Bit, Bit 3
#define     LOG_fTy2Weekday5Mask 0x08
#define     LOG_fTy2Weekday5Shift 3
#define LOG_fTy2Weekday6              33      // 1 Bit, Bit 2
#define     LOG_fTy2Weekday6Mask 0x04
#define     LOG_fTy2Weekday6Shift 2
#define LOG_fTy2Weekday7              33      // 1 Bit, Bit 1
#define     LOG_fTy2Weekday7Mask 0x02
#define     LOG_fTy2Weekday7Shift 1
#define LOG_fTy2Day                   33      // 7 Bits, Bit 7-1
#define LOG_fTy2IsWeekday             33      // 1 Bit, Bit 0
#define     LOG_fTy2IsWeekdayMask 0x01
#define     LOG_fTy2IsWeekdayShift 0
#define LOG_fTy2Month                 34      // 4 Bits, Bit 7-4
#define     LOG_fTy2MonthMask 0xF0
#define     LOG_fTy2MonthShift 4
#define LOG_fTy3Weekday1              35      // 1 Bit, Bit 7
#define     LOG_fTy3Weekday1Mask 0x80
#define     LOG_fTy3Weekday1Shift 7
#define LOG_fTy3Weekday2              35      // 1 Bit, Bit 6
#define     LOG_fTy3Weekday2Mask 0x40
#define     LOG_fTy3Weekday2Shift 6
#define LOG_fTy3Weekday3              35      // 1 Bit, Bit 5
#define     LOG_fTy3Weekday3Mask 0x20
#define     LOG_fTy3Weekday3Shift 5
#define LOG_fTy3Weekday4              35      // 1 Bit, Bit 4
#define     LOG_fTy3Weekday4Mask 0x10
#define     LOG_fTy3Weekday4Shift 4
#define LOG_fTy3Weekday5              35      // 1 Bit, Bit 3
#define     LOG_fTy3Weekday5Mask 0x08
#define     LOG_fTy3Weekday5Shift 3
#define LOG_fTy3Weekday6              35      // 1 Bit, Bit 2
#define     LOG_fTy3Weekday6Mask 0x04
#define     LOG_fTy3Weekday6Shift 2
#define LOG_fTy3Weekday7              35      // 1 Bit, Bit 1
#define     LOG_fTy3Weekday7Mask 0x02
#define     LOG_fTy3Weekday7Shift 1
#define LOG_fTy3Day                   35      // 7 Bits, Bit 7-1
#define LOG_fTy3IsWeekday             35      // 1 Bit, Bit 0
#define     LOG_fTy3IsWeekdayMask 0x01
#define     LOG_fTy3IsWeekdayShift 0
#define LOG_fTy3Month                 36      // 4 Bits, Bit 7-4
#define     LOG_fTy3MonthMask 0xF0
#define     LOG_fTy3MonthShift 4
#define LOG_fTy4Weekday1              37      // 1 Bit, Bit 7
#define     LOG_fTy4Weekday1Mask 0x80
#define     LOG_fTy4Weekday1Shift 7
#define LOG_fTy4Weekday2              37      // 1 Bit, Bit 6
#define     LOG_fTy4Weekday2Mask 0x40
#define     LOG_fTy4Weekday2Shift 6
#define LOG_fTy4Weekday3              37      // 1 Bit, Bit 5
#define     LOG_fTy4Weekday3Mask 0x20
#define     LOG_fTy4Weekday3Shift 5
#define LOG_fTy4Weekday4              37      // 1 Bit, Bit 4
#define     LOG_fTy4Weekday4Mask 0x10
#define     LOG_fTy4Weekday4Shift 4
#define LOG_fTy4Weekday5              37      // 1 Bit, Bit 3
#define     LOG_fTy4Weekday5Mask 0x08
#define     LOG_fTy4Weekday5Shift 3
#define LOG_fTy4Weekday6              37      // 1 Bit, Bit 2
#define     LOG_fTy4Weekday6Mask 0x04
#define     LOG_fTy4Weekday6Shift 2
#define LOG_fTy4Weekday7              37      // 1 Bit, Bit 1
#define     LOG_fTy4Weekday7Mask 0x02
#define     LOG_fTy4Weekday7Shift 1
#define LOG_fTy4Day                   37      // 7 Bits, Bit 7-1
#define LOG_fTy4IsWeekday             37      // 1 Bit, Bit 0
#define     LOG_fTy4IsWeekdayMask 0x01
#define     LOG_fTy4IsWeekdayShift 0
#define LOG_fTy4Month                 38      // 4 Bits, Bit 7-4
#define     LOG_fTy4MonthMask 0xF0
#define     LOG_fTy4MonthShift 4
#define LOG_fI1                       39      // 4 Bits, Bit 7-4
#define     LOG_fI1Mask 0xF0
#define     LOG_fI1Shift 4
#define LOG_fI2                       39      // 4 Bits, Bit 3-0
#define     LOG_fI2Mask 0x0F
#define     LOG_fI2Shift 0
#define LOG_fI1Function               40      // uint8_t
#define LOG_fI2Function               41      // uint8_t
#define LOG_fOTimeBase                42      // 8 Bits, Bit 7-0
#define LOG_fOTime                    43      // int32_t
#define LOG_fOBlink                   47      // int32_t
#define LOG_fODelay                   51      // 1 Bit, Bit 7
#define     LOG_fODelayMask 0x80
#define     LOG_fODelayShift 7
#define LOG_fODelayOnRepeat           51      // 2 Bits, Bit 6-5
#define     LOG_fODelayOnRepeatMask 0x60
#define     LOG_fODelayOnRepeatShift 5
#define LOG_fODelayOnReset            51      // 1 Bit, Bit 4
#define     LOG_fODelayOnResetMask 0x10
#define     LOG_fODelayOnResetShift 4
#define LOG_fODelayOffRepeat          51      // 2 Bits, Bit 3-2
#define     LOG_fODelayOffRepeatMask 0x0C
#define     LOG_fODelayOffRepeatShift 2
#define LOG_fODelayOffReset           51      // 1 Bit, Bit 1
#define     LOG_fODelayOffResetMask 0x02
#define     LOG_fODelayOffResetShift 1
#define LOG_fODelayOn                 52      // int32_t
#define LOG_fODelayOff                56      // int32_t
#define LOG_fOStair                   60      // 1 Bit, Bit 7
#define     LOG_fOStairMask 0x80
#define     LOG_fOStairShift 7
#define LOG_fORetrigger               60      // 1 Bit, Bit 6
#define     LOG_fORetriggerMask 0x40
#define     LOG_fORetriggerShift 6
#define LOG_fOStairOff                60      // 1 Bit, Bit 5
#define     LOG_fOStairOffMask 0x20
#define     LOG_fOStairOffShift 5
#define LOG_fORepeat                  60      // 1 Bit, Bit 4
#define     LOG_fORepeatMask 0x10
#define     LOG_fORepeatShift 4
#define LOG_fOOutputFilter            60      // 2 Bits, Bit 3-2
#define     LOG_fOOutputFilterMask 0x0C
#define     LOG_fOOutputFilterShift 2
#define LOG_fORepeatOn                61      // int32_t
#define LOG_fORepeatOff               65      // int32_t
#define LOG_fODpt                     69      // 8 Bits, Bit 7-0
#define LOG_fOOn                      70      // 8 Bits, Bit 7-0
#define LOG_fOOnBuzzer                70      // 8 Bits, Bit 7-0
#define LOG_fOOnLed                   70      // 8 Bits, Bit 7-0
#define LOG_fOOnAll                   70      // 8 Bits, Bit 7-0
#define LOG_fOOnTone                  71      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt1                  71      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt2                  71      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt5                  71      // uint8_t
#define LOG_fOOnDpt5001               71      // uint8_t
#define LOG_fOOnDpt6                  71      // int8_t
#define LOG_fOOnDpt7                  71      // uint16_t
#define LOG_fOOnDpt8                  71      // int16_t
#define LOG_fOOnDpt9                  71      // float
#define LOG_fOOnDpt16                 71      // char*, 14 Byte
#define LOG_fOOnDpt17                 71      // 8 Bits, Bit 7-0
#define LOG_fOOnRGB                   71      // color, uint, 3 Byte
#define LOG_fOOnPAArea                71      // 4 Bits, Bit 7-4
#define     LOG_fOOnPAAreaMask 0xF0
#define     LOG_fOOnPAAreaShift 4
#define LOG_fOOnPALine                71      // 4 Bits, Bit 3-0
#define     LOG_fOOnPALineMask 0x0F
#define     LOG_fOOnPALineShift 0
#define LOG_fOOnPADevice              72      // uint8_t
#define LOG_fOOnFunction              71      // 8 Bits, Bit 7-0
#define LOG_fOOff                     85      // 8 Bits, Bit 7-0
#define LOG_fOOffBuzzer               85      // 8 Bits, Bit 7-0
#define LOG_fOOffLed                  85      // 8 Bits, Bit 7-0
#define LOG_fOOffAll                  85      // 8 Bits, Bit 7-0
#define LOG_fOOffTone                 86      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt1                 86      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt2                 86      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt5                 86      // uint8_t
#define LOG_fOOffDpt5001              86      // uint8_t
#define LOG_fOOffDpt6                 86      // int8_t
#define LOG_fOOffDpt7                 86      // uint16_t
#define LOG_fOOffDpt8                 86      // int16_t
#define LOG_fOOffDpt9                 86      // float
#define LOG_fOOffDpt16                86      // char*, 14 Byte
#define LOG_fOOffDpt17                86      // 8 Bits, Bit 7-0
#define LOG_fOOffRGB                  86      // color, uint, 3 Byte
#define LOG_fOOffPAArea               86      // 4 Bits, Bit 7-4
#define     LOG_fOOffPAAreaMask 0xF0
#define     LOG_fOOffPAAreaShift 4
#define LOG_fOOffPALine               86      // 4 Bits, Bit 3-0
#define     LOG_fOOffPALineMask 0x0F
#define     LOG_fOOffPALineShift 0
#define LOG_fOOffPADevice             87      // uint8_t
#define LOG_fOOffFunction             86      // 8 Bits, Bit 7-0
#define LOG_fE1UseOtherKO             100      // 1 Bit, Bit 7
#define     LOG_fE1UseOtherKOMask 0x80
#define     LOG_fE1UseOtherKOShift 7
#define LOG_fE1OtherKO                100      // uint12_t
#define LOG_fE2UseOtherKO             102      // 1 Bit, Bit 7
#define     LOG_fE2UseOtherKOMask 0x80
#define     LOG_fE2UseOtherKOShift 7
#define LOG_fE2OtherKO                102      // uint12_t

// Communication objects per channel (multiple occurance)
#define LOG_KoOffset 125
#define LOG_KoBlockSize 3
#define LOG_KoKOfE1 0
#define LOG_KoKOfE2 1
#define LOG_KoKOfO 2

// Parameter per channel
#define WIRE_ParamBlockOffset 389
#define WIRE_ParamBlockSize 18
#define WIRE_sDeviceId                  0      // char*, 7 Byte
#define WIRE_sFamilyCode                0      // 8 Bits, Bit 7-0
#define WIRE_sId0                       1      // 4 Bits, Bit 7-4
#define     WIRE_sId0Mask 0xF0
#define     WIRE_sId0Shift 4
#define WIRE_sId1                       1      // 4 Bits, Bit 3-0
#define     WIRE_sId1Mask 0x0F
#define     WIRE_sId1Shift 0
#define WIRE_sId2                       2      // 4 Bits, Bit 7-4
#define     WIRE_sId2Mask 0xF0
#define     WIRE_sId2Shift 4
#define WIRE_sId3                       2      // 4 Bits, Bit 3-0
#define     WIRE_sId3Mask 0x0F
#define     WIRE_sId3Shift 0
#define WIRE_sId4                       3      // 4 Bits, Bit 7-4
#define     WIRE_sId4Mask 0xF0
#define     WIRE_sId4Shift 4
#define WIRE_sId5                       3      // 4 Bits, Bit 3-0
#define     WIRE_sId5Mask 0x0F
#define     WIRE_sId5Shift 0
#define WIRE_sId6                       4      // 4 Bits, Bit 7-4
#define     WIRE_sId6Mask 0xF0
#define     WIRE_sId6Shift 4
#define WIRE_sId7                       4      // 4 Bits, Bit 3-0
#define     WIRE_sId7Mask 0x0F
#define     WIRE_sId7Shift 0
#define WIRE_sId8                       5      // 4 Bits, Bit 7-4
#define     WIRE_sId8Mask 0xF0
#define     WIRE_sId8Shift 4
#define WIRE_sId9                       5      // 4 Bits, Bit 3-0
#define     WIRE_sId9Mask 0x0F
#define     WIRE_sId9Shift 0
#define WIRE_sIdA                       6      // 4 Bits, Bit 7-4
#define     WIRE_sIdAMask 0xF0
#define     WIRE_sIdAShift 4
#define WIRE_sIdB                       6      // 4 Bits, Bit 3-0
#define     WIRE_sIdBMask 0x0F
#define     WIRE_sIdBShift 0
#define WIRE_sModelFunction             7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS18B20      7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2408       7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2413       7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2438       7      // 8 Bits, Bit 7-0
#define WIRE_sBusMasterSelect1          8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect1Mask 0xC0
#define     WIRE_sBusMasterSelect1Shift 6
#define WIRE_sBusMasterSelect2          8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect2Mask 0xC0
#define     WIRE_sBusMasterSelect2Shift 6
#define WIRE_sBusMasterSelect3          8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect3Mask 0xC0
#define     WIRE_sBusMasterSelect3Shift 6
#define WIRE_sSensorOffset              9      // int8_t
#define WIRE_sSensorCycle              10      // int32_t
#define WIRE_sSensorDeltaAbs           14      // uint16_t
#define WIRE_sSensorDeltaPercent       16      // uint8_t
#define WIRE_sSensorSmooth             17      // uint8_t
#define WIRE_siButtonSendStatus         9      // 1 Bit, Bit 7
#define     WIRE_siButtonSendStatusMask 0x80
#define     WIRE_siButtonSendStatusShift 7
#define WIRE_sGroup1                   10      // 1 Bit, Bit 7
#define     WIRE_sGroup1Mask 0x80
#define     WIRE_sGroup1Shift 7
#define WIRE_sGroup2                   10      // 1 Bit, Bit 6
#define     WIRE_sGroup2Mask 0x40
#define     WIRE_sGroup2Shift 6
#define WIRE_sGroup3                   10      // 1 Bit, Bit 5
#define     WIRE_sGroup3Mask 0x20
#define     WIRE_sGroup3Shift 5
#define WIRE_sGroup4                   10      // 1 Bit, Bit 4
#define     WIRE_sGroup4Mask 0x10
#define     WIRE_sGroup4Shift 4
#define WIRE_sGroup5                   10      // 1 Bit, Bit 3
#define     WIRE_sGroup5Mask 0x08
#define     WIRE_sGroup5Shift 3
#define WIRE_sGroup6                   10      // 1 Bit, Bit 2
#define     WIRE_sGroup6Mask 0x04
#define     WIRE_sGroup6Shift 2
#define WIRE_sGroup7                   10      // 1 Bit, Bit 1
#define     WIRE_sGroup7Mask 0x02
#define     WIRE_sGroup7Shift 1
#define WIRE_sGroup8                   10      // 1 Bit, Bit 0
#define     WIRE_sGroup8Mask 0x01
#define     WIRE_sGroup8Shift 0
#define WIRE_sIOSendStatus              9      // 1 Bit, Bit 7
#define     WIRE_sIOSendStatusMask 0x80
#define     WIRE_sIOSendStatusShift 7
#define WIRE_sIOReadRequest             9      // 1 Bit, Bit 6
#define     WIRE_sIOReadRequestMask 0x40
#define     WIRE_sIOReadRequestShift 6
#define WIRE_sIoBitmask0               10      // 1 Bit, Bit 0
#define     WIRE_sIoBitmask0Mask 0x01
#define     WIRE_sIoBitmask0Shift 0
#define WIRE_sIoBitmask1               10      // 1 Bit, Bit 1
#define     WIRE_sIoBitmask1Mask 0x02
#define     WIRE_sIoBitmask1Shift 1
#define WIRE_sIoBitmask2               10      // 1 Bit, Bit 2
#define     WIRE_sIoBitmask2Mask 0x04
#define     WIRE_sIoBitmask2Shift 2
#define WIRE_sIoBitmask3               10      // 1 Bit, Bit 3
#define     WIRE_sIoBitmask3Mask 0x08
#define     WIRE_sIoBitmask3Shift 3
#define WIRE_sIoBitmask4               10      // 1 Bit, Bit 4
#define     WIRE_sIoBitmask4Mask 0x10
#define     WIRE_sIoBitmask4Shift 4
#define WIRE_sIoBitmask5               10      // 1 Bit, Bit 5
#define     WIRE_sIoBitmask5Mask 0x20
#define     WIRE_sIoBitmask5Shift 5
#define WIRE_sIoBitmask6               10      // 1 Bit, Bit 6
#define     WIRE_sIoBitmask6Mask 0x40
#define     WIRE_sIoBitmask6Shift 6
#define WIRE_sIoBitmask7               10      // 1 Bit, Bit 7
#define     WIRE_sIoBitmask7Mask 0x80
#define     WIRE_sIoBitmask7Shift 7
#define WIRE_sIoInvertBitmask0         11      // 1 Bit, Bit 0
#define     WIRE_sIoInvertBitmask0Mask 0x01
#define     WIRE_sIoInvertBitmask0Shift 0
#define WIRE_sIoInvertBitmask1         11      // 1 Bit, Bit 1
#define     WIRE_sIoInvertBitmask1Mask 0x02
#define     WIRE_sIoInvertBitmask1Shift 1
#define WIRE_sIoInvertBitmask2         11      // 1 Bit, Bit 2
#define     WIRE_sIoInvertBitmask2Mask 0x04
#define     WIRE_sIoInvertBitmask2Shift 2
#define WIRE_sIoInvertBitmask3         11      // 1 Bit, Bit 3
#define     WIRE_sIoInvertBitmask3Mask 0x08
#define     WIRE_sIoInvertBitmask3Shift 3
#define WIRE_sIoInvertBitmask4         11      // 1 Bit, Bit 4
#define     WIRE_sIoInvertBitmask4Mask 0x10
#define     WIRE_sIoInvertBitmask4Shift 4
#define WIRE_sIoInvertBitmask5         11      // 1 Bit, Bit 5
#define     WIRE_sIoInvertBitmask5Mask 0x20
#define     WIRE_sIoInvertBitmask5Shift 5
#define WIRE_sIoInvertBitmask6         11      // 1 Bit, Bit 6
#define     WIRE_sIoInvertBitmask6Mask 0x40
#define     WIRE_sIoInvertBitmask6Shift 6
#define WIRE_sIoInvertBitmask7         11      // 1 Bit, Bit 7
#define     WIRE_sIoInvertBitmask7Mask 0x80
#define     WIRE_sIoInvertBitmask7Shift 7

// Communication objects per channel (multiple occurance)
#define WIRE_KoOffset 90
#define WIRE_KoBlockSize 1
#define WIRE_KoKOs 0

