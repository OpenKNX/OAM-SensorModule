#pragma once

#define paramDelay(time) (uint32_t)((time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : (time & 0xC000) = 0x4000 ? (time & 0x3FFF) * 60000 : (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : (time & 0x3FFF) * 3600000 ) : 0 )

// Parameter with single occurrence


#define LOG_NumChannels                0      // uint8_t
#define LOG_StartupDelayBase           1      // 2 Bits, Bit 7-6
#define     LOG_StartupDelayBaseMask 0xC0
#define     LOG_StartupDelayBaseShift 6
#define LOG_StartupDelayTime           1      // 14 Bits, Bit 13-0
#define     LOG_StartupDelayTimeMask 0x3FFF
#define     LOG_StartupDelayTimeShift 0
#define LOG_HeartbeatDelayBase         3      // 2 Bits, Bit 7-6
#define     LOG_HeartbeatDelayBaseMask 0xC0
#define     LOG_HeartbeatDelayBaseShift 6
#define LOG_HeartbeatDelayTime         3      // 14 Bits, Bit 13-0
#define     LOG_HeartbeatDelayTimeMask 0x3FFF
#define     LOG_HeartbeatDelayTimeShift 0
#define LOG_ReadTimeDate               5      // 1 Bit, Bit 7
#define     LOG_ReadTimeDateMask 0x80
#define     LOG_ReadTimeDateShift 7
#define LOG_BuzzerInstalled            5      // 1 Bit, Bit 6
#define     LOG_BuzzerInstalledMask 0x40
#define     LOG_BuzzerInstalledShift 6
#define LOG_LedInstalled               5      // 1 Bit, Bit 5
#define     LOG_LedInstalledMask 0x20
#define     LOG_LedInstalledShift 5
#define LOG_CombinedTimeDate           5      // 1 Bit, Bit 4
#define     LOG_CombinedTimeDateMask 0x10
#define     LOG_CombinedTimeDateShift 4
#define LOG_VacationKo                 5      // 1 Bit, Bit 2
#define     LOG_VacationKoMask 0x04
#define     LOG_VacationKoShift 2
#define LOG_HolidayKo                  5      // 1 Bit, Bit 1
#define     LOG_HolidayKoMask 0x02
#define     LOG_HolidayKoShift 1
#define LOG_VacationRead               5      // 1 Bit, Bit 0
#define     LOG_VacationReadMask 0x01
#define     LOG_VacationReadShift 0
#define LOG_HolidaySend                6      // 1 Bit, Bit 7
#define     LOG_HolidaySendMask 0x80
#define     LOG_HolidaySendShift 7
#define LOG_SummertimeAll              6      // 2 Bits, Bit 7-6
#define     LOG_SummertimeAllMask 0xC0
#define     LOG_SummertimeAllShift 6
#define LOG_SummertimeDE               6      // 2 Bits, Bit 7-6
#define     LOG_SummertimeDEMask 0xC0
#define     LOG_SummertimeDEShift 6
#define LOG_SummertimeWorld            6      // 2 Bits, Bit 7-6
#define     LOG_SummertimeWorldMask 0xC0
#define     LOG_SummertimeWorldShift 6
#define LOG_SummertimeKO               6      // 2 Bits, Bit 7-6
#define     LOG_SummertimeKOMask 0xC0
#define     LOG_SummertimeKOShift 6
#define LOG_Diagnose                   6      // 1 Bit, Bit 3
#define     LOG_DiagnoseMask 0x08
#define     LOG_DiagnoseShift 3
#define LOG_Watchdog                   6      // 1 Bit, Bit 2
#define     LOG_WatchdogMask 0x04
#define     LOG_WatchdogShift 2
#define LOG_Neujahr                    7      // 1 Bit, Bit 7
#define     LOG_NeujahrMask 0x80
#define     LOG_NeujahrShift 7
#define LOG_DreiKoenige                7      // 1 Bit, Bit 6
#define     LOG_DreiKoenigeMask 0x40
#define     LOG_DreiKoenigeShift 6
#define LOG_Weiberfastnacht            7      // 1 Bit, Bit 5
#define     LOG_WeiberfastnachtMask 0x20
#define     LOG_WeiberfastnachtShift 5
#define LOG_Rosenmontag                7      // 1 Bit, Bit 4
#define     LOG_RosenmontagMask 0x10
#define     LOG_RosenmontagShift 4
#define LOG_Fastnachtsdienstag         7      // 1 Bit, Bit 3
#define     LOG_FastnachtsdienstagMask 0x08
#define     LOG_FastnachtsdienstagShift 3
#define LOG_Aschermittwoch             7      // 1 Bit, Bit 2
#define     LOG_AschermittwochMask 0x04
#define     LOG_AschermittwochShift 2
#define LOG_Frauentag                  7      // 1 Bit, Bit 1
#define     LOG_FrauentagMask 0x02
#define     LOG_FrauentagShift 1
#define LOG_Gruendonnerstag            7      // 1 Bit, Bit 0
#define     LOG_GruendonnerstagMask 0x01
#define     LOG_GruendonnerstagShift 0
#define LOG_Karfreitag                 8      // 1 Bit, Bit 7
#define     LOG_KarfreitagMask 0x80
#define     LOG_KarfreitagShift 7
#define LOG_Ostersonntag               8      // 1 Bit, Bit 6
#define     LOG_OstersonntagMask 0x40
#define     LOG_OstersonntagShift 6
#define LOG_Ostermontag                8      // 1 Bit, Bit 5
#define     LOG_OstermontagMask 0x20
#define     LOG_OstermontagShift 5
#define LOG_TagDerArbeit               8      // 1 Bit, Bit 4
#define     LOG_TagDerArbeitMask 0x10
#define     LOG_TagDerArbeitShift 4
#define LOG_Himmelfahrt                8      // 1 Bit, Bit 3
#define     LOG_HimmelfahrtMask 0x08
#define     LOG_HimmelfahrtShift 3
#define LOG_Pfingstsonntag             8      // 1 Bit, Bit 2
#define     LOG_PfingstsonntagMask 0x04
#define     LOG_PfingstsonntagShift 2
#define LOG_Pfingstmontag              8      // 1 Bit, Bit 1
#define     LOG_PfingstmontagMask 0x02
#define     LOG_PfingstmontagShift 1
#define LOG_Fronleichnam               8      // 1 Bit, Bit 0
#define     LOG_FronleichnamMask 0x01
#define     LOG_FronleichnamShift 0
#define LOG_Friedensfest               9      // 1 Bit, Bit 7
#define     LOG_FriedensfestMask 0x80
#define     LOG_FriedensfestShift 7
#define LOG_MariaHimmelfahrt           9      // 1 Bit, Bit 6
#define     LOG_MariaHimmelfahrtMask 0x40
#define     LOG_MariaHimmelfahrtShift 6
#define LOG_DeutscheEinheit            9      // 1 Bit, Bit 5
#define     LOG_DeutscheEinheitMask 0x20
#define     LOG_DeutscheEinheitShift 5
#define LOG_Nationalfeiertag          10      // 1 Bit, Bit 1
#define     LOG_NationalfeiertagMask 0x02
#define     LOG_NationalfeiertagShift 1
#define LOG_Reformationstag            9      // 1 Bit, Bit 4
#define     LOG_ReformationstagMask 0x10
#define     LOG_ReformationstagShift 4
#define LOG_Allerheiligen              9      // 1 Bit, Bit 3
#define     LOG_AllerheiligenMask 0x08
#define     LOG_AllerheiligenShift 3
#define LOG_BussBettag                 9      // 1 Bit, Bit 2
#define     LOG_BussBettagMask 0x04
#define     LOG_BussBettagShift 2
#define LOG_MariaEmpfaengnis          10      // 1 Bit, Bit 0
#define     LOG_MariaEmpfaengnisMask 0x01
#define     LOG_MariaEmpfaengnisShift 0
#define LOG_Advent1                    9      // 1 Bit, Bit 1
#define     LOG_Advent1Mask 0x02
#define     LOG_Advent1Shift 1
#define LOG_Advent2                    9      // 1 Bit, Bit 0
#define     LOG_Advent2Mask 0x01
#define     LOG_Advent2Shift 0
#define LOG_Advent3                   10      // 1 Bit, Bit 7
#define     LOG_Advent3Mask 0x80
#define     LOG_Advent3Shift 7
#define LOG_Advent4                   10      // 1 Bit, Bit 6
#define     LOG_Advent4Mask 0x40
#define     LOG_Advent4Shift 6
#define LOG_Heiligabend               10      // 1 Bit, Bit 5
#define     LOG_HeiligabendMask 0x20
#define     LOG_HeiligabendShift 5
#define LOG_Weihnachtstag1            10      // 1 Bit, Bit 4
#define     LOG_Weihnachtstag1Mask 0x10
#define     LOG_Weihnachtstag1Shift 4
#define LOG_Weihnachtstag2            10      // 1 Bit, Bit 3
#define     LOG_Weihnachtstag2Mask 0x08
#define     LOG_Weihnachtstag2Shift 3
#define LOG_Silvester                 10      // 1 Bit, Bit 2
#define     LOG_SilvesterMask 0x04
#define     LOG_SilvesterShift 2
#define LOG_Latitude                  11      // float
#define LOG_Longitude                 15      // float
#define LOG_BuzzerSilent              19      // uint16_t
#define LOG_BuzzerNormal              21      // uint16_t
#define LOG_BuzzerLoud                23      // uint16_t
#define LOG_LedMapping                25      // 3 Bits, Bit 7-5
#define     LOG_LedMappingMask 0xE0
#define     LOG_LedMappingShift 5
#define LOG_Timezone                  25      // 5 Bits, Bit 4-0
#define     LOG_TimezoneMask 0x1F
#define     LOG_TimezoneShift 0
#define LOG_TimezoneSign              25      // 1 Bit, Bit 4
#define     LOG_TimezoneSignMask 0x10
#define     LOG_TimezoneSignShift 4
#define LOG_TimezoneValue             25      // 4 Bits, Bit 3-0
#define     LOG_TimezoneValueMask 0x0F
#define     LOG_TimezoneValueShift 0

// Anzahl verfügbarer Logikkanäle
#define ParamLOG_NumChannels               (knx.paramByte(LOG_NumChannels))
// Zeitbasis
#define ParamLOG_StartupDelayBase          ((knx.paramByte(LOG_StartupDelayBase) & LOG_StartupDelayBaseMask) >> LOG_StartupDelayBaseShift)
// Zeit
#define ParamLOG_StartupDelayTime          (knx.paramWord(LOG_StartupDelayTime) & LOG_StartupDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_StartupDelayTimeMS        (paramDelay(knx.paramWord(LOG_StartupDelayTime)))
// Zeitbasis
#define ParamLOG_HeartbeatDelayBase        ((knx.paramByte(LOG_HeartbeatDelayBase) & LOG_HeartbeatDelayBaseMask) >> LOG_HeartbeatDelayBaseShift)
// Zeit
#define ParamLOG_HeartbeatDelayTime        (knx.paramWord(LOG_HeartbeatDelayTime) & LOG_HeartbeatDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_HeartbeatDelayTimeMS      (paramDelay(knx.paramWord(LOG_HeartbeatDelayTime)))
// Uhrzeit und Datum nach einem Neustart vom Bus lesen
#define ParamLOG_ReadTimeDate              ((bool)(knx.paramByte(LOG_ReadTimeDate) & LOG_ReadTimeDateMask))
// Akustischer Signalgeber vorhanden (Buzzer)?
#define ParamLOG_BuzzerInstalled           ((bool)(knx.paramByte(LOG_BuzzerInstalled) & LOG_BuzzerInstalledMask))
// Optischer Signalgeber vorhanden (RGB-LED)?
#define ParamLOG_LedInstalled              ((bool)(knx.paramByte(LOG_LedInstalled) & LOG_LedInstalledMask))
// Uhrzeit und Datum empfangen über
#define ParamLOG_CombinedTimeDate          ((bool)(knx.paramByte(LOG_CombinedTimeDate) & LOG_CombinedTimeDateMask))
// Urlaubsbehandlung aktivieren?
#define ParamLOG_VacationKo                ((bool)(knx.paramByte(LOG_VacationKo) & LOG_VacationKoMask))
// Feiertage auf dem Bus verfügbar machen?
#define ParamLOG_HolidayKo                 ((bool)(knx.paramByte(LOG_HolidayKo) & LOG_HolidayKoMask))
// Nach Neustart Urlaubsinfo lesen?
#define ParamLOG_VacationRead              ((bool)(knx.paramByte(LOG_VacationRead) & LOG_VacationReadMask))
// Nach Neuberechnung Feiertagsinfo senden?
#define ParamLOG_HolidaySend               ((bool)(knx.paramByte(LOG_HolidaySend) & LOG_HolidaySendMask))
// Sommerzeit ermitteln durch
#define ParamLOG_SummertimeAll             ((knx.paramByte(LOG_SummertimeAll) & LOG_SummertimeAllMask) >> LOG_SummertimeAllShift)
// Sommerzeit ermitteln durch
#define ParamLOG_SummertimeDE              ((knx.paramByte(LOG_SummertimeDE) & LOG_SummertimeDEMask) >> LOG_SummertimeDEShift)
// Sommerzeit ermitteln durch
#define ParamLOG_SummertimeWorld           ((knx.paramByte(LOG_SummertimeWorld) & LOG_SummertimeWorldMask) >> LOG_SummertimeWorldShift)
// Sommerzeit ermitteln durch
#define ParamLOG_SummertimeKO              ((knx.paramByte(LOG_SummertimeKO) & LOG_SummertimeKOMask) >> LOG_SummertimeKOShift)
// Diagnoseobjekt anzeigen
#define ParamLOG_Diagnose                  ((bool)(knx.paramByte(LOG_Diagnose) & LOG_DiagnoseMask))
// Watchdog aktivieren
#define ParamLOG_Watchdog                  ((bool)(knx.paramByte(LOG_Watchdog) & LOG_WatchdogMask))
// 1. Neujahr
#define ParamLOG_Neujahr                   ((bool)(knx.paramByte(LOG_Neujahr) & LOG_NeujahrMask))
// 2. Heilige Drei Könige
#define ParamLOG_DreiKoenige               ((bool)(knx.paramByte(LOG_DreiKoenige) & LOG_DreiKoenigeMask))
// 3. Weiberfastnacht
#define ParamLOG_Weiberfastnacht           ((bool)(knx.paramByte(LOG_Weiberfastnacht) & LOG_WeiberfastnachtMask))
// 4. Rosenmontag
#define ParamLOG_Rosenmontag               ((bool)(knx.paramByte(LOG_Rosenmontag) & LOG_RosenmontagMask))
// 5. Fastnachtsdienstag
#define ParamLOG_Fastnachtsdienstag        ((bool)(knx.paramByte(LOG_Fastnachtsdienstag) & LOG_FastnachtsdienstagMask))
// 6. Aschermittwoch
#define ParamLOG_Aschermittwoch            ((bool)(knx.paramByte(LOG_Aschermittwoch) & LOG_AschermittwochMask))
// 7. Frauentag
#define ParamLOG_Frauentag                 ((bool)(knx.paramByte(LOG_Frauentag) & LOG_FrauentagMask))
// 8. Gründonnerstag
#define ParamLOG_Gruendonnerstag           ((bool)(knx.paramByte(LOG_Gruendonnerstag) & LOG_GruendonnerstagMask))
// 9. Karfreitag
#define ParamLOG_Karfreitag                ((bool)(knx.paramByte(LOG_Karfreitag) & LOG_KarfreitagMask))
// 10. Ostersonntag
#define ParamLOG_Ostersonntag              ((bool)(knx.paramByte(LOG_Ostersonntag) & LOG_OstersonntagMask))
// 11. Ostermontag
#define ParamLOG_Ostermontag               ((bool)(knx.paramByte(LOG_Ostermontag) & LOG_OstermontagMask))
// 12. Tag der Arbeit
#define ParamLOG_TagDerArbeit              ((bool)(knx.paramByte(LOG_TagDerArbeit) & LOG_TagDerArbeitMask))
// 13. Christi Himmelfahrt
#define ParamLOG_Himmelfahrt               ((bool)(knx.paramByte(LOG_Himmelfahrt) & LOG_HimmelfahrtMask))
// 14. Pfingstsonntag
#define ParamLOG_Pfingstsonntag            ((bool)(knx.paramByte(LOG_Pfingstsonntag) & LOG_PfingstsonntagMask))
// 15. Pfingstmontag
#define ParamLOG_Pfingstmontag             ((bool)(knx.paramByte(LOG_Pfingstmontag) & LOG_PfingstmontagMask))
// 16. Fronleichnam
#define ParamLOG_Fronleichnam              ((bool)(knx.paramByte(LOG_Fronleichnam) & LOG_FronleichnamMask))
// 17. Hohes Friedensfest
#define ParamLOG_Friedensfest              ((bool)(knx.paramByte(LOG_Friedensfest) & LOG_FriedensfestMask))
// 18. Mariä Himmelfahrt
#define ParamLOG_MariaHimmelfahrt          ((bool)(knx.paramByte(LOG_MariaHimmelfahrt) & LOG_MariaHimmelfahrtMask))
// 19. Tag der Deutschen Einheit
#define ParamLOG_DeutscheEinheit           ((bool)(knx.paramByte(LOG_DeutscheEinheit) & LOG_DeutscheEinheitMask))
// 31. Nationalfeiertag (AT)
#define ParamLOG_Nationalfeiertag          ((bool)(knx.paramByte(LOG_Nationalfeiertag) & LOG_NationalfeiertagMask))
// 20. Reformationstag
#define ParamLOG_Reformationstag           ((bool)(knx.paramByte(LOG_Reformationstag) & LOG_ReformationstagMask))
// 21. Allerheiligen
#define ParamLOG_Allerheiligen             ((bool)(knx.paramByte(LOG_Allerheiligen) & LOG_AllerheiligenMask))
// 22. Buß- und Bettag
#define ParamLOG_BussBettag                ((bool)(knx.paramByte(LOG_BussBettag) & LOG_BussBettagMask))
// 32. Maria Empfängnis (AT)
#define ParamLOG_MariaEmpfaengnis          ((bool)(knx.paramByte(LOG_MariaEmpfaengnis) & LOG_MariaEmpfaengnisMask))
// 23. Erster Advent
#define ParamLOG_Advent1                   ((bool)(knx.paramByte(LOG_Advent1) & LOG_Advent1Mask))
// 24. Zweiter Advent
#define ParamLOG_Advent2                   ((bool)(knx.paramByte(LOG_Advent2) & LOG_Advent2Mask))
// 25. Dritter Advent
#define ParamLOG_Advent3                   ((bool)(knx.paramByte(LOG_Advent3) & LOG_Advent3Mask))
// 26. Vierter Advent
#define ParamLOG_Advent4                   ((bool)(knx.paramByte(LOG_Advent4) & LOG_Advent4Mask))
// 27. Heiligabend
#define ParamLOG_Heiligabend               ((bool)(knx.paramByte(LOG_Heiligabend) & LOG_HeiligabendMask))
// 28. Erster Weihnachtstag
#define ParamLOG_Weihnachtstag1            ((bool)(knx.paramByte(LOG_Weihnachtstag1) & LOG_Weihnachtstag1Mask))
// 29. Zweiter Weihnachtstag
#define ParamLOG_Weihnachtstag2            ((bool)(knx.paramByte(LOG_Weihnachtstag2) & LOG_Weihnachtstag2Mask))
// 30. Silvester
#define ParamLOG_Silvester                 ((bool)(knx.paramByte(LOG_Silvester) & LOG_SilvesterMask))
// Breitengrad
#define ParamLOG_Latitude                  (knx.paramFloat(LOG_Latitude, Float_Enc_IEEE754Single))
// Längengrad
#define ParamLOG_Longitude                 (knx.paramFloat(LOG_Longitude, Float_Enc_IEEE754Single))
// Frequenz für Buzzer (leise)
#define ParamLOG_BuzzerSilent              (knx.paramWord(LOG_BuzzerSilent))
// Frequenz für Buzzer (normal)
#define ParamLOG_BuzzerNormal              (knx.paramWord(LOG_BuzzerNormal))
// Frequenz für Buzzer (laut)
#define ParamLOG_BuzzerLoud                (knx.paramWord(LOG_BuzzerLoud))
// Lötpad A / B / C entspicht
#define ParamLOG_LedMapping                ((knx.paramByte(LOG_LedMapping) & LOG_LedMappingMask) >> LOG_LedMappingShift)
// Zeitzone
#define ParamLOG_Timezone                  (knx.paramByte(LOG_Timezone) & LOG_TimezoneMask)
// Zeitzone-Vorzeichen
#define ParamLOG_TimezoneSign              ((bool)(knx.paramByte(LOG_TimezoneSign) & LOG_TimezoneSignMask))
// Zeitzone-Wert
#define ParamLOG_TimezoneValue             (knx.paramByte(LOG_TimezoneValue) & LOG_TimezoneValueMask)

#define LOG_KoHeartbeat 1
#define LOG_KoTime 2
#define LOG_KoDate 3
#define LOG_KoVacation 4
#define LOG_KoHoliday1 5
#define LOG_KoHoliday2 6
#define LOG_KoDiagnose 7
#define LOG_KoLedLock 8
#define LOG_KoBuzzerLock 9
#define LOG_KoIsSummertime 10

// In Betrieb
#define KoLOG_Heartbeat                 (knx.getGroupObject(LOG_KoHeartbeat))
// Uhrzeit/Datum
#define KoLOG_Time                      (knx.getGroupObject(LOG_KoTime))
// Datum
#define KoLOG_Date                      (knx.getGroupObject(LOG_KoDate))
// Urlaub
#define KoLOG_Vacation                  (knx.getGroupObject(LOG_KoVacation))
// Welcher Feiertag ist heute?
#define KoLOG_Holiday1                  (knx.getGroupObject(LOG_KoHoliday1))
// Welcher Feiertag ist morgen?
#define KoLOG_Holiday2                  (knx.getGroupObject(LOG_KoHoliday2))
// Diagnose
#define KoLOG_Diagnose                  (knx.getGroupObject(LOG_KoDiagnose))
// LED sperren
#define KoLOG_LedLock                   (knx.getGroupObject(LOG_KoLedLock))
// Buzzer sperren
#define KoLOG_BuzzerLock                (knx.getGroupObject(LOG_KoBuzzerLock))
// Sommerzeit aktiv
#define KoLOG_IsSummertime              (knx.getGroupObject(LOG_KoIsSummertime))

#define WIRE_WireError                 26      // 1 Bit, Bit 7
#define     WIRE_WireErrorMask 0x80
#define     WIRE_WireErrorShift 7
#define WIRE_BusMasterCount            26      // 2 Bits, Bit 6-5
#define     WIRE_BusMasterCountMask 0x60
#define     WIRE_BusMasterCountShift 5
#define WIRE_IdSearch                  26      // 1 Bit, Bit 4
#define     WIRE_IdSearchMask 0x10
#define     WIRE_IdSearchShift 4
#define WIRE_IButton1                  26      // 1 Bit, Bit 3
#define     WIRE_IButton1Mask 0x08
#define     WIRE_IButton1Shift 3
#define WIRE_IButton2                  26      // 1 Bit, Bit 2
#define     WIRE_IButton2Mask 0x04
#define     WIRE_IButton2Shift 2
#define WIRE_IButton3                  26      // 1 Bit, Bit 1
#define     WIRE_IButton3Mask 0x02
#define     WIRE_IButton3Shift 1
#define WIRE_Group1                    27      // 1 Bit, Bit 7
#define     WIRE_Group1Mask 0x80
#define     WIRE_Group1Shift 7
#define WIRE_Group2                    27      // 1 Bit, Bit 6
#define     WIRE_Group2Mask 0x40
#define     WIRE_Group2Shift 6
#define WIRE_Group3                    27      // 1 Bit, Bit 5
#define     WIRE_Group3Mask 0x20
#define     WIRE_Group3Shift 5
#define WIRE_Group4                    27      // 1 Bit, Bit 4
#define     WIRE_Group4Mask 0x10
#define     WIRE_Group4Shift 4
#define WIRE_Group5                    27      // 1 Bit, Bit 3
#define     WIRE_Group5Mask 0x08
#define     WIRE_Group5Shift 3
#define WIRE_Group6                    27      // 1 Bit, Bit 2
#define     WIRE_Group6Mask 0x04
#define     WIRE_Group6Shift 2
#define WIRE_Group7                    27      // 1 Bit, Bit 1
#define     WIRE_Group7Mask 0x02
#define     WIRE_Group7Shift 1
#define WIRE_Group8                    27      // 1 Bit, Bit 0
#define     WIRE_Group8Mask 0x01
#define     WIRE_Group8Shift 0
#define WIRE_Busmaster1RSTL            28      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1RSTLMask 0xF0
#define     WIRE_Busmaster1RSTLShift 4
#define WIRE_Busmaster1MSP             28      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1MSPMask 0x0F
#define     WIRE_Busmaster1MSPShift 0
#define WIRE_Busmaster1W0L             29      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1W0LMask 0xF0
#define     WIRE_Busmaster1W0LShift 4
#define WIRE_Busmaster1REC0            29      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1REC0Mask 0x0F
#define     WIRE_Busmaster1REC0Shift 0
#define WIRE_Busmaster1WPU             30      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1WPUMask 0xF0
#define     WIRE_Busmaster1WPUShift 4

// Fehlerobjekt(e) anzeigen
#define ParamWIRE_WireError                 ((bool)(knx.paramByte(WIRE_WireError) & WIRE_WireErrorMask))
// Installierte Busmaster
#define ParamWIRE_BusMasterCount            ((knx.paramByte(WIRE_BusMasterCount) & WIRE_BusMasterCountMask) >> WIRE_BusMasterCountShift)
// Device-Suche
#define ParamWIRE_IdSearch                  ((bool)(knx.paramByte(WIRE_IdSearch) & WIRE_IdSearchMask))
// iButton auf Busmaster 1 auswerten?
#define ParamWIRE_IButton1                  ((bool)(knx.paramByte(WIRE_IButton1) & WIRE_IButton1Mask))
// iButton auf Busmaster 2 auswerten?
#define ParamWIRE_IButton2                  ((bool)(knx.paramByte(WIRE_IButton2) & WIRE_IButton2Mask))
// iButton auf Busmaster 3 auswerten?
#define ParamWIRE_IButton3                  ((bool)(knx.paramByte(WIRE_IButton3) & WIRE_IButton3Mask))
//                   Typ
#define ParamWIRE_Group1                    ((bool)(knx.paramByte(WIRE_Group1) & WIRE_Group1Mask))
//                   Typ
#define ParamWIRE_Group2                    ((bool)(knx.paramByte(WIRE_Group2) & WIRE_Group2Mask))
//                   Typ
#define ParamWIRE_Group3                    ((bool)(knx.paramByte(WIRE_Group3) & WIRE_Group3Mask))
//                   Typ
#define ParamWIRE_Group4                    ((bool)(knx.paramByte(WIRE_Group4) & WIRE_Group4Mask))
//                   Typ
#define ParamWIRE_Group5                    ((bool)(knx.paramByte(WIRE_Group5) & WIRE_Group5Mask))
//                   Typ
#define ParamWIRE_Group6                    ((bool)(knx.paramByte(WIRE_Group6) & WIRE_Group6Mask))
//                   Typ
#define ParamWIRE_Group7                    ((bool)(knx.paramByte(WIRE_Group7) & WIRE_Group7Mask))
//                   Typ
#define ParamWIRE_Group8                    ((bool)(knx.paramByte(WIRE_Group8) & WIRE_Group8Mask))
// tRSTL (in Mikrosekunden)
#define ParamWIRE_Busmaster1RSTL            ((knx.paramByte(WIRE_Busmaster1RSTL) & WIRE_Busmaster1RSTLMask) >> WIRE_Busmaster1RSTLShift)
// tMSP (in Mikrosekunden)
#define ParamWIRE_Busmaster1MSP             (knx.paramByte(WIRE_Busmaster1MSP) & WIRE_Busmaster1MSPMask)
// tW0L (in Mikrosekunden)
#define ParamWIRE_Busmaster1W0L             ((knx.paramByte(WIRE_Busmaster1W0L) & WIRE_Busmaster1W0LMask) >> WIRE_Busmaster1W0LShift)
// tREC0 (in Mikrosekunden)
#define ParamWIRE_Busmaster1REC0            (knx.paramByte(WIRE_Busmaster1REC0) & WIRE_Busmaster1REC0Mask)
// RWPU (in Ohm)
#define ParamWIRE_Busmaster1WPU             ((knx.paramByte(WIRE_Busmaster1WPU) & WIRE_Busmaster1WPUMask) >> WIRE_Busmaster1WPUShift)

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

// IDs unbekannter Geräte
#define KoWIRE_NewId                     (knx.getGroupObject(WIRE_KoNewId))
// Gerätefehler Busmaster 1
#define KoWIRE_ErrorBusmaster1           (knx.getGroupObject(WIRE_KoErrorBusmaster1))
// Gerätefehler Busmaster 2
#define KoWIRE_ErrorBusmaster2           (knx.getGroupObject(WIRE_KoErrorBusmaster2))
// Gerätefehler Busmaster 3
#define KoWIRE_ErrorBusmaster3           (knx.getGroupObject(WIRE_KoErrorBusmaster3))
// Gruppe 1
#define KoWIRE_Group1                    (knx.getGroupObject(WIRE_KoGroup1))
// Gruppe 2
#define KoWIRE_Group2                    (knx.getGroupObject(WIRE_KoGroup2))
// Gruppe 3
#define KoWIRE_Group3                    (knx.getGroupObject(WIRE_KoGroup3))
// Gruppe 4
#define KoWIRE_Group4                    (knx.getGroupObject(WIRE_KoGroup4))
// Gruppe 5
#define KoWIRE_Group5                    (knx.getGroupObject(WIRE_KoGroup5))
// Gruppe 6
#define KoWIRE_Group6                    (knx.getGroupObject(WIRE_KoGroup6))
// Gruppe 7
#define KoWIRE_Group7                    (knx.getGroupObject(WIRE_KoGroup7))
// Gruppe 8
#define KoWIRE_Group8                    (knx.getGroupObject(WIRE_KoGroup8))

#define SENS_Error                     31      // 1 Bit, Bit 7
#define     SENS_ErrorMask 0x80
#define     SENS_ErrorShift 7
#define SENS_Dewpoint                  31      // 1 Bit, Bit 6
#define     SENS_DewpointMask 0x40
#define     SENS_DewpointShift 6
#define SENS_Comfort                   31      // 1 Bit, Bit 5
#define     SENS_ComfortMask 0x20
#define     SENS_ComfortShift 5
#define SENS_Airquality                31      // 1 Bit, Bit 4
#define     SENS_AirqualityMask 0x10
#define     SENS_AirqualityShift 4
#define SENS_Accuracy                  31      // 1 Bit, Bit 3
#define     SENS_AccuracyMask 0x08
#define     SENS_AccuracyShift 3
#define SENS_DeleteData                31      // 1 Bit, Bit 2
#define     SENS_DeleteDataMask 0x04
#define     SENS_DeleteDataShift 2
#define SENS_TempOffset                32      // int8_t
#define SENS_TempCycleBase             33      // 2 Bits, Bit 7-6
#define     SENS_TempCycleBaseMask 0xC0
#define     SENS_TempCycleBaseShift 6
#define SENS_TempCycleTime             33      // 14 Bits, Bit 13-0
#define     SENS_TempCycleTimeMask 0x3FFF
#define     SENS_TempCycleTimeShift 0
#define SENS_TempDeltaAbs              35      // uint16_t
#define SENS_TempDeltaPercent          37      // uint8_t
#define SENS_TempSmooth                38      // uint8_t
#define SENS_TempExtCount              39      // 2 Bits, Bit 1-0
#define     SENS_TempExtCountMask 0x03
#define     SENS_TempExtCountShift 0
#define SENS_TempExtRead               39      // 1 Bit, Bit 2
#define     SENS_TempExtReadMask 0x04
#define     SENS_TempExtReadShift 2
#define SENS_TempIntPercent            40      // uint8_t
#define SENS_TempExt1Percent           41      // uint8_t
#define SENS_TempExt2Percent           42      // uint8_t
#define SENS_HumOffset                 43      // int8_t
#define SENS_HumCycleBase              44      // 2 Bits, Bit 7-6
#define     SENS_HumCycleBaseMask 0xC0
#define     SENS_HumCycleBaseShift 6
#define SENS_HumCycleTime              44      // 14 Bits, Bit 13-0
#define     SENS_HumCycleTimeMask 0x3FFF
#define     SENS_HumCycleTimeShift 0
#define SENS_HumDeltaAbs               46      // uint16_t
#define SENS_HumDeltaPercent           48      // uint8_t
#define SENS_HumSmooth                 49      // uint8_t
#define SENS_HumExtCount               50      // 2 Bits, Bit 1-0
#define     SENS_HumExtCountMask 0x03
#define     SENS_HumExtCountShift 0
#define SENS_HumExtRead                50      // 1 Bit, Bit 2
#define     SENS_HumExtReadMask 0x04
#define     SENS_HumExtReadShift 2
#define SENS_HumIntPercent             51      // uint8_t
#define SENS_HumExt1Percent            52      // uint8_t
#define SENS_HumExt2Percent            53      // uint8_t
#define SENS_PreOffset                 54      // int8_t
#define SENS_PreCycleBase              55      // 2 Bits, Bit 7-6
#define     SENS_PreCycleBaseMask 0xC0
#define     SENS_PreCycleBaseShift 6
#define SENS_PreCycleTime              55      // 14 Bits, Bit 13-0
#define     SENS_PreCycleTimeMask 0x3FFF
#define     SENS_PreCycleTimeShift 0
#define SENS_PreDeltaAbs               57      // uint16_t
#define SENS_PreDeltaPercent           59      // uint8_t
#define SENS_PreSmooth                 60      // uint8_t
#define SENS_PreExtCount               61      // 2 Bits, Bit 1-0
#define     SENS_PreExtCountMask 0x03
#define     SENS_PreExtCountShift 0
#define SENS_PreExtRead                61      // 1 Bit, Bit 2
#define     SENS_PreExtReadMask 0x04
#define     SENS_PreExtReadShift 2
#define SENS_PreIntPercent             62      // uint8_t
#define SENS_PreExt1Percent            63      // uint8_t
#define SENS_PreExt2Percent            64      // uint8_t
#define SENS_VocOffset                 65      // int8_t
#define SENS_VocCycleBase              66      // 2 Bits, Bit 7-6
#define     SENS_VocCycleBaseMask 0xC0
#define     SENS_VocCycleBaseShift 6
#define SENS_VocCycleTime              66      // 14 Bits, Bit 13-0
#define     SENS_VocCycleTimeMask 0x3FFF
#define     SENS_VocCycleTimeShift 0
#define SENS_VocDeltaAbs               68      // uint16_t
#define SENS_VocDeltPercent            70      // uint8_t
#define SENS_VocSmooth                 71      // uint8_t
#define SENS_VocExtCount               72      // 2 Bits, Bit 1-0
#define     SENS_VocExtCountMask 0x03
#define     SENS_VocExtCountShift 0
#define SENS_VocExtRead                72      // 1 Bit, Bit 2
#define     SENS_VocExtReadMask 0x04
#define     SENS_VocExtReadShift 2
#define SENS_VocIntPercent             73      // uint8_t
#define SENS_VocExt1Percent            74      // uint8_t
#define SENS_VocExt2Percent            75      // uint8_t
#define SENS_Co2Offset                 76      // int8_t
#define SENS_Co2CycleBase              77      // 2 Bits, Bit 7-6
#define     SENS_Co2CycleBaseMask 0xC0
#define     SENS_Co2CycleBaseShift 6
#define SENS_Co2CycleTime              77      // 14 Bits, Bit 13-0
#define     SENS_Co2CycleTimeMask 0x3FFF
#define     SENS_Co2CycleTimeShift 0
#define SENS_Co2DeltaAbs               79      // uint16_t
#define SENS_Co2DeltaPercent           81      // uint8_t
#define SENS_Co2Smooth                 82      // uint8_t
#define SENS_Co2ExtCount               83      // 2 Bits, Bit 1-0
#define     SENS_Co2ExtCountMask 0x03
#define     SENS_Co2ExtCountShift 0
#define SENS_Co2ExtRead                83      // 1 Bit, Bit 2
#define     SENS_Co2ExtReadMask 0x04
#define     SENS_Co2ExtReadShift 2
#define SENS_Co2IntPercent             84      // uint8_t
#define SENS_Co2Ext1Percent            85      // uint8_t
#define SENS_Co2Ext2Percent            86      // uint8_t
#define SENS_Sensor1Wire               87      // 1 Bit, Bit 0
#define     SENS_Sensor1WireMask 0x01
#define     SENS_Sensor1WireShift 0
#define SENS_DewOffset                 88      // int8_t
#define SENS_DewCycleBase              89      // 2 Bits, Bit 7-6
#define     SENS_DewCycleBaseMask 0xC0
#define     SENS_DewCycleBaseShift 6
#define SENS_DewCycleTime              89      // 14 Bits, Bit 13-0
#define     SENS_DewCycleTimeMask 0x3FFF
#define     SENS_DewCycleTimeShift 0
#define SENS_DewDeltaAbs               91      // uint16_t
#define SENS_DewDeltaPercent           93      // uint8_t
#define SENS_DewSmooth                 94      // uint8_t
#define SENS_LuxOffset                 95      // int8_t
#define SENS_LuxCycleBase              96      // 2 Bits, Bit 7-6
#define     SENS_LuxCycleBaseMask 0xC0
#define     SENS_LuxCycleBaseShift 6
#define SENS_LuxCycleTime              96      // 14 Bits, Bit 13-0
#define     SENS_LuxCycleTimeMask 0x3FFF
#define     SENS_LuxCycleTimeShift 0
#define SENS_LuxDeltaAbs               98      // uint16_t
#define SENS_LuxDeltPercent            100      // uint8_t
#define SENS_LuxSmooth                 101      // uint8_t
#define SENS_LuxExtCount               102      // 2 Bits, Bit 1-0
#define     SENS_LuxExtCountMask 0x03
#define     SENS_LuxExtCountShift 0
#define SENS_LuxExtRead                102      // 1 Bit, Bit 2
#define     SENS_LuxExtReadMask 0x04
#define     SENS_LuxExtReadShift 2
#define SENS_LuxIntPercent             103      // uint8_t
#define SENS_LuxExt1Percent            104      // uint8_t
#define SENS_LuxExt2Percent            105      // uint8_t
#define SENS_TofOffset                 106      // int8_t
#define SENS_TofCycleBase              107      // 2 Bits, Bit 7-6
#define     SENS_TofCycleBaseMask 0xC0
#define     SENS_TofCycleBaseShift 6
#define SENS_TofCycleTime              107      // 14 Bits, Bit 13-0
#define     SENS_TofCycleTimeMask 0x3FFF
#define     SENS_TofCycleTimeShift 0
#define SENS_TofDeltaAbs               109      // uint16_t
#define SENS_TofDeltaPercent           111      // uint8_t
#define SENS_TofSmooth                 112      // uint8_t
#define SENS_TofExtCount               113      // 2 Bits, Bit 1-0
#define     SENS_TofExtCountMask 0x03
#define     SENS_TofExtCountShift 0
#define SENS_TofExtRead                113      // 1 Bit, Bit 2
#define     SENS_TofExtReadMask 0x04
#define     SENS_TofExtReadShift 2
#define SENS_TofIntPercent             114      // uint8_t
#define SENS_TofExt1Percent            115      // uint8_t
#define SENS_TofExt2Percent            116      // uint8_t
#define SENS_TempSensor                117      // 4 Bits, Bit 7-4
#define     SENS_TempSensorMask 0xF0
#define     SENS_TempSensorShift 4
#define SENS_HumSensor                 117      // 4 Bits, Bit 3-0
#define     SENS_HumSensorMask 0x0F
#define     SENS_HumSensorShift 0
#define SENS_PreSensor                 118      // 4 Bits, Bit 7-4
#define     SENS_PreSensorMask 0xF0
#define     SENS_PreSensorShift 4
#define SENS_VocSensor                 118      // 4 Bits, Bit 3-0
#define     SENS_VocSensorMask 0x0F
#define     SENS_VocSensorShift 0
#define SENS_Co2Sensor                 119      // 4 Bits, Bit 7-4
#define     SENS_Co2SensorMask 0xF0
#define     SENS_Co2SensorShift 4
#define SENS_LuxSensor                 119      // 4 Bits, Bit 3-0
#define     SENS_LuxSensorMask 0x0F
#define     SENS_LuxSensorShift 0
#define SENS_TofSensor                 120      // 4 Bits, Bit 7-4
#define     SENS_TofSensorMask 0xF0
#define     SENS_TofSensorShift 4

// Fehlerobjekt für Standardmesswerte anzeigen
#define ParamSENS_Error                     ((bool)(knx.paramByte(SENS_Error) & SENS_ErrorMask))
// Taupunkt berechnen
#define ParamSENS_Dewpoint                  ((bool)(knx.paramByte(SENS_Dewpoint) & SENS_DewpointMask))
// Behaglichkeitszone ausgeben
#define ParamSENS_Comfort                   ((bool)(knx.paramByte(SENS_Comfort) & SENS_ComfortMask))
// Luftqualitätsampel ausgeben
#define ParamSENS_Airquality                ((bool)(knx.paramByte(SENS_Airquality) & SENS_AirqualityMask))
// Kalibrierungsfortschritt ausgeben
#define ParamSENS_Accuracy                  ((bool)(knx.paramByte(SENS_Accuracy) & SENS_AccuracyMask))
// Kalibrierungsdaten löschen
#define ParamSENS_DeleteData                ((bool)(knx.paramByte(SENS_DeleteData) & SENS_DeleteDataMask))
// Temperatur anpassen (interner Messwert)
#define ParamSENS_TempOffset                ((int8_t)knx.paramByte(SENS_TempOffset))
// Zeitbasis
#define ParamSENS_TempCycleBase             ((knx.paramByte(SENS_TempCycleBase) & SENS_TempCycleBaseMask) >> SENS_TempCycleBaseShift)
// Zeit
#define ParamSENS_TempCycleTime             (knx.paramWord(SENS_TempCycleTime) & SENS_TempCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_TempCycleTimeMS           (paramDelay(knx.paramWord(SENS_TempCycleTime)))
// Temperatur bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_TempDeltaAbs              (knx.paramWord(SENS_TempDeltaAbs))
// Temperatur bei Abweichung vom vorherigen Wert senden(0=nicht senden)
#define ParamSENS_TempDeltaPercent          (knx.paramByte(SENS_TempDeltaPercent))
// Temperatur glätten: P =
#define ParamSENS_TempSmooth                (knx.paramByte(SENS_TempSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_TempExtCount              (knx.paramByte(SENS_TempExtCount) & SENS_TempExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_TempExtRead               ((bool)(knx.paramByte(SENS_TempExtRead) & SENS_TempExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_TempIntPercent            (knx.paramByte(SENS_TempIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_TempExt1Percent           (knx.paramByte(SENS_TempExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_TempExt2Percent           (knx.paramByte(SENS_TempExt2Percent))
// Luftfeuchte anpassen (interner Messwert)
#define ParamSENS_HumOffset                 ((int8_t)knx.paramByte(SENS_HumOffset))
// Zeitbasis
#define ParamSENS_HumCycleBase              ((knx.paramByte(SENS_HumCycleBase) & SENS_HumCycleBaseMask) >> SENS_HumCycleBaseShift)
// Zeit
#define ParamSENS_HumCycleTime              (knx.paramWord(SENS_HumCycleTime) & SENS_HumCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_HumCycleTimeMS            (paramDelay(knx.paramWord(SENS_HumCycleTime)))
// Luftfeuchte bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_HumDeltaAbs               (knx.paramWord(SENS_HumDeltaAbs))
// Luftfeuchte bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_HumDeltaPercent           (knx.paramByte(SENS_HumDeltaPercent))
// Luftfeuchte glätten: P =
#define ParamSENS_HumSmooth                 (knx.paramByte(SENS_HumSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_HumExtCount               (knx.paramByte(SENS_HumExtCount) & SENS_HumExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_HumExtRead                ((bool)(knx.paramByte(SENS_HumExtRead) & SENS_HumExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_HumIntPercent             (knx.paramByte(SENS_HumIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_HumExt1Percent            (knx.paramByte(SENS_HumExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_HumExt2Percent            (knx.paramByte(SENS_HumExt2Percent))
// Luftdruck anpassen (interner Messwert)
#define ParamSENS_PreOffset                 ((int8_t)knx.paramByte(SENS_PreOffset))
// Zeitbasis
#define ParamSENS_PreCycleBase              ((knx.paramByte(SENS_PreCycleBase) & SENS_PreCycleBaseMask) >> SENS_PreCycleBaseShift)
// Zeit
#define ParamSENS_PreCycleTime              (knx.paramWord(SENS_PreCycleTime) & SENS_PreCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_PreCycleTimeMS            (paramDelay(knx.paramWord(SENS_PreCycleTime)))
// Luftdruck bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_PreDeltaAbs               (knx.paramWord(SENS_PreDeltaAbs))
// Luftdruck bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_PreDeltaPercent           (knx.paramByte(SENS_PreDeltaPercent))
// Luftdruck glätten: P =
#define ParamSENS_PreSmooth                 (knx.paramByte(SENS_PreSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_PreExtCount               (knx.paramByte(SENS_PreExtCount) & SENS_PreExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_PreExtRead                ((bool)(knx.paramByte(SENS_PreExtRead) & SENS_PreExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_PreIntPercent             (knx.paramByte(SENS_PreIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_PreExt1Percent            (knx.paramByte(SENS_PreExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_PreExt2Percent            (knx.paramByte(SENS_PreExt2Percent))
// Voc anpassen (interner Messwert)
#define ParamSENS_VocOffset                 ((int8_t)knx.paramByte(SENS_VocOffset))
// Zeitbasis
#define ParamSENS_VocCycleBase              ((knx.paramByte(SENS_VocCycleBase) & SENS_VocCycleBaseMask) >> SENS_VocCycleBaseShift)
// Zeit
#define ParamSENS_VocCycleTime              (knx.paramWord(SENS_VocCycleTime) & SENS_VocCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_VocCycleTimeMS            (paramDelay(knx.paramWord(SENS_VocCycleTime)))
// Voc bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_VocDeltaAbs               (knx.paramWord(SENS_VocDeltaAbs))
// Voc bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_VocDeltPercent            (knx.paramByte(SENS_VocDeltPercent))
// Voc glätten: P =
#define ParamSENS_VocSmooth                 (knx.paramByte(SENS_VocSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_VocExtCount               (knx.paramByte(SENS_VocExtCount) & SENS_VocExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_VocExtRead                ((bool)(knx.paramByte(SENS_VocExtRead) & SENS_VocExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_VocIntPercent             (knx.paramByte(SENS_VocIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_VocExt1Percent            (knx.paramByte(SENS_VocExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_VocExt2Percent            (knx.paramByte(SENS_VocExt2Percent))
// CO2 anpassen (interner Messwert)
#define ParamSENS_Co2Offset                 ((int8_t)knx.paramByte(SENS_Co2Offset))
// Zeitbasis
#define ParamSENS_Co2CycleBase              ((knx.paramByte(SENS_Co2CycleBase) & SENS_Co2CycleBaseMask) >> SENS_Co2CycleBaseShift)
// Zeit
#define ParamSENS_Co2CycleTime              (knx.paramWord(SENS_Co2CycleTime) & SENS_Co2CycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_Co2CycleTimeMS            (paramDelay(knx.paramWord(SENS_Co2CycleTime)))
// CO2 bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_Co2DeltaAbs               (knx.paramWord(SENS_Co2DeltaAbs))
// CO2 bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_Co2DeltaPercent           (knx.paramByte(SENS_Co2DeltaPercent))
// CO2 glätten: P =
#define ParamSENS_Co2Smooth                 (knx.paramByte(SENS_Co2Smooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_Co2ExtCount               (knx.paramByte(SENS_Co2ExtCount) & SENS_Co2ExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_Co2ExtRead                ((bool)(knx.paramByte(SENS_Co2ExtRead) & SENS_Co2ExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_Co2IntPercent             (knx.paramByte(SENS_Co2IntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_Co2Ext1Percent            (knx.paramByte(SENS_Co2Ext1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_Co2Ext2Percent            (knx.paramByte(SENS_Co2Ext2Percent))
// 1 Wire aktivieren?
#define ParamSENS_Sensor1Wire               ((bool)(knx.paramByte(SENS_Sensor1Wire) & SENS_Sensor1WireMask))
// Taupunkt anpassen
#define ParamSENS_DewOffset                 ((int8_t)knx.paramByte(SENS_DewOffset))
// Zeitbasis
#define ParamSENS_DewCycleBase              ((knx.paramByte(SENS_DewCycleBase) & SENS_DewCycleBaseMask) >> SENS_DewCycleBaseShift)
// Zeit
#define ParamSENS_DewCycleTime              (knx.paramWord(SENS_DewCycleTime) & SENS_DewCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_DewCycleTimeMS            (paramDelay(knx.paramWord(SENS_DewCycleTime)))
// Taupunkt bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_DewDeltaAbs               (knx.paramWord(SENS_DewDeltaAbs))
// Taupunkt bei Abweichung vom vorherigen Wert senden(0=nicht senden)
#define ParamSENS_DewDeltaPercent           (knx.paramByte(SENS_DewDeltaPercent))
// Taupunkt glätten: P =
#define ParamSENS_DewSmooth                 (knx.paramByte(SENS_DewSmooth))
// Helligkeit anpassen(Bereich in der Nähe von 0 Lux)
#define ParamSENS_LuxOffset                 ((int8_t)knx.paramByte(SENS_LuxOffset))
// Zeitbasis
#define ParamSENS_LuxCycleBase              ((knx.paramByte(SENS_LuxCycleBase) & SENS_LuxCycleBaseMask) >> SENS_LuxCycleBaseShift)
// Zeit
#define ParamSENS_LuxCycleTime              (knx.paramWord(SENS_LuxCycleTime) & SENS_LuxCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_LuxCycleTimeMS            (paramDelay(knx.paramWord(SENS_LuxCycleTime)))
// Helligkeit bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_LuxDeltaAbs               (knx.paramWord(SENS_LuxDeltaAbs))
// Helligkeit bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_LuxDeltPercent            (knx.paramByte(SENS_LuxDeltPercent))
// Helligkeit glätten: P =
#define ParamSENS_LuxSmooth                 (knx.paramByte(SENS_LuxSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_LuxExtCount               (knx.paramByte(SENS_LuxExtCount) & SENS_LuxExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_LuxExtRead                ((bool)(knx.paramByte(SENS_LuxExtRead) & SENS_LuxExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_LuxIntPercent             (knx.paramByte(SENS_LuxIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_LuxExt1Percent            (knx.paramByte(SENS_LuxExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_LuxExt2Percent            (knx.paramByte(SENS_LuxExt2Percent))
// Entfernung anpassen (interner Messwert)
#define ParamSENS_TofOffset                 ((int8_t)knx.paramByte(SENS_TofOffset))
// Zeitbasis
#define ParamSENS_TofCycleBase              ((knx.paramByte(SENS_TofCycleBase) & SENS_TofCycleBaseMask) >> SENS_TofCycleBaseShift)
// Zeit
#define ParamSENS_TofCycleTime              (knx.paramWord(SENS_TofCycleTime) & SENS_TofCycleTimeMask)
// Zeit (in Millisekunden)
#define ParamSENS_TofCycleTimeMS            (paramDelay(knx.paramWord(SENS_TofCycleTime)))
// Entfernung bei absoluter Abweichung senden(0=nicht senden)
#define ParamSENS_TofDeltaAbs               (knx.paramWord(SENS_TofDeltaAbs))
// Entfernung bei Abweichung vom vorherigem Wert senden(0=nicht senden)
#define ParamSENS_TofDeltaPercent           (knx.paramByte(SENS_TofDeltaPercent))
// Entfernung glätten: P =
#define ParamSENS_TofSmooth                 (knx.paramByte(SENS_TofSmooth))
// Externe Messwerte berücksichtigen
#define ParamSENS_TofExtCount               (knx.paramByte(SENS_TofExtCount) & SENS_TofExtCountMask)
//     Externe Messwerte beim Start lesen
#define ParamSENS_TofExtRead                ((bool)(knx.paramByte(SENS_TofExtRead) & SENS_TofExtReadMask))
//     Anteil interner Messwert
#define ParamSENS_TofIntPercent             (knx.paramByte(SENS_TofIntPercent))
//     Anteil externer Messwert 1
#define ParamSENS_TofExt1Percent            (knx.paramByte(SENS_TofExt1Percent))
//     Anteil externer Messwert 2
#define ParamSENS_TofExt2Percent            (knx.paramByte(SENS_TofExt2Percent))
// Temperatursensor
#define ParamSENS_TempSensor                ((knx.paramByte(SENS_TempSensor) & SENS_TempSensorMask) >> SENS_TempSensorShift)
// Luftfeuchtesensor
#define ParamSENS_HumSensor                 (knx.paramByte(SENS_HumSensor) & SENS_HumSensorMask)
// Luftdrucksensor
#define ParamSENS_PreSensor                 ((knx.paramByte(SENS_PreSensor) & SENS_PreSensorMask) >> SENS_PreSensorShift)
// Voc-Sensor
#define ParamSENS_VocSensor                 (knx.paramByte(SENS_VocSensor) & SENS_VocSensorMask)
// Co2-Sensor
#define ParamSENS_Co2Sensor                 ((knx.paramByte(SENS_Co2Sensor) & SENS_Co2SensorMask) >> SENS_Co2SensorShift)
// Helligkeitssensor
#define ParamSENS_LuxSensor                 (knx.paramByte(SENS_LuxSensor) & SENS_LuxSensorMask)
// Näherungssensor
#define ParamSENS_TofSensor                 ((knx.paramByte(SENS_TofSensor) & SENS_TofSensorMask) >> SENS_TofSensorShift)

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

// Sensorwerte anfordern
#define KoSENS_RequestValues             (knx.getGroupObject(SENS_KoRequestValues))
// Sensorfehler
#define KoSENS_Error                     (knx.getGroupObject(SENS_KoError))
// Temperatur
#define KoSENS_Temp                      (knx.getGroupObject(SENS_KoTemp))
// Luftfeuchte
#define KoSENS_Hum                       (knx.getGroupObject(SENS_KoHum))
// Luftdruck
#define KoSENS_Pre                       (knx.getGroupObject(SENS_KoPre))
// VOC
#define KoSENS_VOC                       (knx.getGroupObject(SENS_KoVOC))
// CO2
#define KoSENS_Co2                       (knx.getGroupObject(SENS_KoCo2))
// CO2-VOC
#define KoSENS_Co2b                      (knx.getGroupObject(SENS_KoCo2b))
// Taupunkt
#define KoSENS_Dewpoint                  (knx.getGroupObject(SENS_KoDewpoint))
// Behaglichkeit
#define KoSENS_Comfort                   (knx.getGroupObject(SENS_KoComfort))
// Luftqualitätsampel (1-6)
#define KoSENS_Airquality                (knx.getGroupObject(SENS_KoAirquality))
// Kalibrierungfortschritt
#define KoSENS_SensorAccuracy            (knx.getGroupObject(SENS_KoSensorAccuracy))
// Externe Temperatur 1
#define KoSENS_Ext1Temp                  (knx.getGroupObject(SENS_KoExt1Temp))
// Externe Temperatur 2
#define KoSENS_Ext2Temp                  (knx.getGroupObject(SENS_KoExt2Temp))
// Externe Luftfeuchte 1
#define KoSENS_Ext1Hum                   (knx.getGroupObject(SENS_KoExt1Hum))
// Externe Luftfeuchte 2
#define KoSENS_Ext2Hum                   (knx.getGroupObject(SENS_KoExt2Hum))
// Externer Luftdruck 1
#define KoSENS_Ext1Pre                   (knx.getGroupObject(SENS_KoExt1Pre))
// Externer Luftdruck 2
#define KoSENS_Ext2Pre                   (knx.getGroupObject(SENS_KoExt2Pre))
// Externer VOC 1
#define KoSENS_Ext1VOC                   (knx.getGroupObject(SENS_KoExt1VOC))
// Externer VOC 2
#define KoSENS_Ext2VOC                   (knx.getGroupObject(SENS_KoExt2VOC))
// Externer CO2 1
#define KoSENS_Ext1Co2                   (knx.getGroupObject(SENS_KoExt1Co2))
// Externer CO2 2
#define KoSENS_Ext2Co2                   (knx.getGroupObject(SENS_KoExt2Co2))
// Externe Helligkeit 1
#define KoSENS_Ext1Lux                   (knx.getGroupObject(SENS_KoExt1Lux))
// Externe Helligkeit 2
#define KoSENS_Ext2Lux                   (knx.getGroupObject(SENS_KoExt2Lux))
// Externe Entfernung 1
#define KoSENS_Ext1Tof                   (knx.getGroupObject(SENS_KoExt1Tof))
// Externe Entfernung 2
#define KoSENS_Ext2Tof                   (knx.getGroupObject(SENS_KoExt2Tof))
// Helligkeit
#define KoSENS_Lux                       (knx.getGroupObject(SENS_KoLux))
// Entfernung
#define KoSENS_Tof                       (knx.getGroupObject(SENS_KoTof))

#define LOG_ChannelCount 80

// Parameter per channel
#define LOG_ParamBlockOffset 121
#define LOG_ParamBlockSize 86
#define LOG_ParamCalcIndex(index) (index + LOG_ParamBlockOffset + _channelIndex * LOG_ParamBlockSize)

#define LOG_fChannelDelayBase          0      // 2 Bits, Bit 7-6
#define     LOG_fChannelDelayBaseMask 0xC0
#define     LOG_fChannelDelayBaseShift 6
#define LOG_fChannelDelayTime          0      // 14 Bits, Bit 13-0
#define     LOG_fChannelDelayTimeMask 0x3FFF
#define     LOG_fChannelDelayTimeShift 0
#define LOG_fLogic                     2      // 8 Bits, Bit 7-0
#define LOG_fCalculate                 3      // 2 Bits, Bit 1-0
#define     LOG_fCalculateMask 0x03
#define     LOG_fCalculateShift 0
#define LOG_fDisable                   3      // 1 Bit, Bit 2
#define     LOG_fDisableMask 0x04
#define     LOG_fDisableShift 2
#define LOG_fAlarm                     3      // 1 Bit, Bit 3
#define     LOG_fAlarmMask 0x08
#define     LOG_fAlarmShift 3
#define LOG_fTGate                     3      // 1 Bit, Bit 4
#define     LOG_fTGateMask 0x10
#define     LOG_fTGateShift 4
#define LOG_fOInternalOn               3      // 1 Bit, Bit 5
#define     LOG_fOInternalOnMask 0x20
#define     LOG_fOInternalOnShift 5
#define LOG_fOInternalOff              3      // 1 Bit, Bit 6
#define     LOG_fOInternalOffMask 0x40
#define     LOG_fOInternalOffShift 6
#define LOG_fTrigger                   4      // 8 Bits, Bit 7-0
#define LOG_fTriggerE1                 4      // 1 Bit, Bit 0
#define     LOG_fTriggerE1Mask 0x01
#define     LOG_fTriggerE1Shift 0
#define LOG_fTriggerE2                 4      // 1 Bit, Bit 1
#define     LOG_fTriggerE2Mask 0x02
#define     LOG_fTriggerE2Shift 1
#define LOG_fTriggerI1                 4      // 1 Bit, Bit 2
#define     LOG_fTriggerI1Mask 0x04
#define     LOG_fTriggerI1Shift 2
#define LOG_fTriggerI2                 4      // 1 Bit, Bit 3
#define     LOG_fTriggerI2Mask 0x08
#define     LOG_fTriggerI2Shift 3
#define LOG_fTriggerTime               4      // 8 Bits, Bit 7-0
#define LOG_fTriggerGateClose          5      // 2 Bits, Bit 7-6
#define     LOG_fTriggerGateCloseMask 0xC0
#define     LOG_fTriggerGateCloseShift 6
#define LOG_fTriggerGateOpen           5      // 2 Bits, Bit 5-4
#define     LOG_fTriggerGateOpenMask 0x30
#define     LOG_fTriggerGateOpenShift 4
#define LOG_fE1                        6      // 4 Bits, Bit 3-0
#define     LOG_fE1Mask 0x0F
#define     LOG_fE1Shift 0
#define LOG_fE1Convert                 6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertMask 0xF0
#define     LOG_fE1ConvertShift 4
#define LOG_fE1ConvertFloat            6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertFloatMask 0xF0
#define     LOG_fE1ConvertFloatShift 4
#define LOG_fE1ConvertSpecial          6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertSpecialMask 0xF0
#define     LOG_fE1ConvertSpecialShift 4
#define LOG_fE1Dpt                     7      // 8 Bits, Bit 7-0
#define LOG_fE1Default                 8      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultMask 0x03
#define     LOG_fE1DefaultShift 0
#define LOG_fE1DefaultExt              8      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultExtMask 0x03
#define     LOG_fE1DefaultExtShift 0
#define LOG_fE1DefaultEEPROM           8      // 1 Bit, Bit 2
#define     LOG_fE1DefaultEEPROMMask 0x04
#define     LOG_fE1DefaultEEPROMShift 2
#define LOG_fE1DefaultRepeat           8      // 1 Bit, Bit 3
#define     LOG_fE1DefaultRepeatMask 0x08
#define     LOG_fE1DefaultRepeatShift 3
#define LOG_fTYearDay                  8      // 1 Bit, Bit 4
#define     LOG_fTYearDayMask 0x10
#define     LOG_fTYearDayShift 4
#define LOG_fTRestoreState             8      // 2 Bits, Bit 6-5
#define     LOG_fTRestoreStateMask 0x60
#define     LOG_fTRestoreStateShift 5
#define LOG_fE1RepeatBase              9      // 2 Bits, Bit 7-6
#define     LOG_fE1RepeatBaseMask 0xC0
#define     LOG_fE1RepeatBaseShift 6
#define LOG_fE1RepeatTime              9      // 14 Bits, Bit 13-0
#define     LOG_fE1RepeatTimeMask 0x3FFF
#define     LOG_fE1RepeatTimeShift 0
#define LOG_fE2                       11      // 4 Bits, Bit 3-0
#define     LOG_fE2Mask 0x0F
#define     LOG_fE2Shift 0
#define LOG_fE2Convert                11      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertMask 0xF0
#define     LOG_fE2ConvertShift 4
#define LOG_fE2ConvertFloat           11      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertFloatMask 0xF0
#define     LOG_fE2ConvertFloatShift 4
#define LOG_fE2ConvertSpecial         11      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertSpecialMask 0xF0
#define     LOG_fE2ConvertSpecialShift 4
#define LOG_fE2Dpt                    12      // 8 Bits, Bit 7-0
#define LOG_fE2Default                13      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultMask 0x03
#define     LOG_fE2DefaultShift 0
#define LOG_fE2DefaultExt             13      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultExtMask 0x03
#define     LOG_fE2DefaultExtShift 0
#define LOG_fE2DefaultEEPROM          13      // 1 Bit, Bit 2
#define     LOG_fE2DefaultEEPROMMask 0x04
#define     LOG_fE2DefaultEEPROMShift 2
#define LOG_fE2DefaultRepeat          13      // 1 Bit, Bit 3
#define     LOG_fE2DefaultRepeatMask 0x08
#define     LOG_fE2DefaultRepeatShift 3
#define LOG_fTHoliday                 13      // 2 Bits, Bit 4-3
#define     LOG_fTHolidayMask 0x18
#define     LOG_fTHolidayShift 3
#define LOG_fTVacation                13      // 2 Bits, Bit 6-5
#define     LOG_fTVacationMask 0x60
#define     LOG_fTVacationShift 5
#define LOG_fE2RepeatBase             14      // 2 Bits, Bit 7-6
#define     LOG_fE2RepeatBaseMask 0xC0
#define     LOG_fE2RepeatBaseShift 6
#define LOG_fE2RepeatTime             14      // 14 Bits, Bit 13-0
#define     LOG_fE2RepeatTimeMask 0x3FFF
#define     LOG_fE2RepeatTimeShift 0
#define LOG_fTd1DuskDawn              14      // 4 Bits, Bit 7-4
#define     LOG_fTd1DuskDawnMask 0xF0
#define     LOG_fTd1DuskDawnShift 4
#define LOG_fTd2DuskDawn              14      // 4 Bits, Bit 3-0
#define     LOG_fTd2DuskDawnMask 0x0F
#define     LOG_fTd2DuskDawnShift 0
#define LOG_fTd3DuskDawn              15      // 4 Bits, Bit 7-4
#define     LOG_fTd3DuskDawnMask 0xF0
#define     LOG_fTd3DuskDawnShift 4
#define LOG_fTd4DuskDawn              15      // 4 Bits, Bit 3-0
#define     LOG_fTd4DuskDawnMask 0x0F
#define     LOG_fTd4DuskDawnShift 0
#define LOG_fTd5DuskDawn              16      // 4 Bits, Bit 7-4
#define     LOG_fTd5DuskDawnMask 0xF0
#define     LOG_fTd5DuskDawnShift 4
#define LOG_fTd6DuskDawn              16      // 4 Bits, Bit 3-0
#define     LOG_fTd6DuskDawnMask 0x0F
#define     LOG_fTd6DuskDawnShift 0
#define LOG_fTd7DuskDawn              17      // 4 Bits, Bit 7-4
#define     LOG_fTd7DuskDawnMask 0xF0
#define     LOG_fTd7DuskDawnShift 4
#define LOG_fTd8DuskDawn              17      // 4 Bits, Bit 3-0
#define     LOG_fTd8DuskDawnMask 0x0F
#define     LOG_fTd8DuskDawnShift 0
#define LOG_fE1LowDelta               18      // int32_t
#define LOG_fE1HighDelta              22      // int32_t
#define LOG_fE1LowDeltaFloat          18      // float
#define LOG_fE1HighDeltaFloat         22      // float
#define LOG_fE1LowDeltaDouble         18      // float
#define LOG_fE1HighDeltaDouble        22      // float
#define LOG_fE1Low0Valid              25      // 1 Bit, Bit 7
#define     LOG_fE1Low0ValidMask 0x80
#define     LOG_fE1Low0ValidShift 7
#define LOG_fE1Low1Valid              25      // 1 Bit, Bit 6
#define     LOG_fE1Low1ValidMask 0x40
#define     LOG_fE1Low1ValidShift 6
#define LOG_fE1Low2Valid              25      // 1 Bit, Bit 5
#define     LOG_fE1Low2ValidMask 0x20
#define     LOG_fE1Low2ValidShift 5
#define LOG_fE1Low3Valid              25      // 1 Bit, Bit 4
#define     LOG_fE1Low3ValidMask 0x10
#define     LOG_fE1Low3ValidShift 4
#define LOG_fE1Low4Valid              25      // 1 Bit, Bit 3
#define     LOG_fE1Low4ValidMask 0x08
#define     LOG_fE1Low4ValidShift 3
#define LOG_fE1Low5Valid              25      // 1 Bit, Bit 2
#define     LOG_fE1Low5ValidMask 0x04
#define     LOG_fE1Low5ValidShift 2
#define LOG_fE1Low6Valid              25      // 1 Bit, Bit 1
#define     LOG_fE1Low6ValidMask 0x02
#define     LOG_fE1Low6ValidShift 1
#define LOG_fE1Low7Valid              25      // 1 Bit, Bit 0
#define     LOG_fE1Low7ValidMask 0x01
#define     LOG_fE1Low7ValidShift 0
#define LOG_fE1LowDpt2                18      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt2               19      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt2               20      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt2               21      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt2Fix             18      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt5                18      // uint8_t
#define LOG_fE1HighDpt5               22      // uint8_t
#define LOG_fE1Low0Dpt5In             18      // uint8_t
#define LOG_fE1Low1Dpt5In             19      // uint8_t
#define LOG_fE1Low2Dpt5In             20      // uint8_t
#define LOG_fE1Low3Dpt5In             21      // uint8_t
#define LOG_fE1Low4Dpt5In             22      // uint8_t
#define LOG_fE1Low5Dpt5In             23      // uint8_t
#define LOG_fE1Low6Dpt5In             24      // uint8_t
#define LOG_fE1LowDpt5Fix             18      // uint8_t
#define LOG_fE1LowDpt5001             18      // uint8_t
#define LOG_fE1HighDpt5001            22      // uint8_t
#define LOG_fE1Low0Dpt5xIn            18      // uint8_t
#define LOG_fE1Low1Dpt5xIn            19      // uint8_t
#define LOG_fE1Low2Dpt5xIn            20      // uint8_t
#define LOG_fE1Low3Dpt5xIn            21      // uint8_t
#define LOG_fE1Low4Dpt5xIn            22      // uint8_t
#define LOG_fE1Low5Dpt5xIn            23      // uint8_t
#define LOG_fE1Low6Dpt5xIn            24      // uint8_t
#define LOG_fE1LowDpt5xFix            18      // uint8_t
#define LOG_fE1LowDpt6                18      // int8_t
#define LOG_fE1HighDpt6               22      // int8_t
#define LOG_fE1Low0Dpt6In             18      // int8_t
#define LOG_fE1Low1Dpt6In             19      // int8_t
#define LOG_fE1Low2Dpt6In             20      // int8_t
#define LOG_fE1Low3Dpt6In             21      // int8_t
#define LOG_fE1Low4Dpt6In             22      // int8_t
#define LOG_fE1Low5Dpt6In             23      // int8_t
#define LOG_fE1Low6Dpt6In             24      // int8_t
#define LOG_fE1LowDpt6Fix             18      // int8_t
#define LOG_fE1LowDpt7                18      // uint16_t
#define LOG_fE1HighDpt7               22      // uint16_t
#define LOG_fE1Low0Dpt7In             18      // uint16_t
#define LOG_fE1Low1Dpt7In             20      // uint16_t
#define LOG_fE1Low2Dpt7In             22      // uint16_t
#define LOG_fE1LowDpt7Fix             18      // uint16_t
#define LOG_fE1LowDpt8                18      // int16_t
#define LOG_fE1HighDpt8               22      // int16_t
#define LOG_fE1Low0Dpt8In             18      // int16_t
#define LOG_fE1Low1Dpt8In             20      // int16_t
#define LOG_fE1Low2Dpt8In             22      // int16_t
#define LOG_fE1LowDpt8Fix             18      // int16_t
#define LOG_fE1LowDpt9                18      // float
#define LOG_fE1HighDpt9               22      // float
#define LOG_fE1LowDpt9Fix             18      // float
#define LOG_fE1LowDpt12               18      // uint32_t
#define LOG_fE1HighDpt12              22      // uint32_t
#define LOG_fE1LowDpt12Fix            18      // uint32_t
#define LOG_fE1LowDpt13               18      // int32_t
#define LOG_fE1HighDpt13              22      // int32_t
#define LOG_fE1LowDpt13Fix            18      // int32_t
#define LOG_fE1LowDpt14               18      // float
#define LOG_fE1HighDpt14              22      // float
#define LOG_fE1LowDpt14Fix            18      // float
#define LOG_fE1Low0Dpt17              18      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt17              19      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt17              20      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt17              21      // 8 Bits, Bit 7-0
#define LOG_fE1Low4Dpt17              22      // 8 Bits, Bit 7-0
#define LOG_fE1Low5Dpt17              23      // 8 Bits, Bit 7-0
#define LOG_fE1Low6Dpt17              24      // 8 Bits, Bit 7-0
#define LOG_fE1Low7Dpt17              25      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt17Fix            18      // 8 Bits, Bit 7-0
#define LOG_fE1LowDptRGB              18      // int32_t
#define LOG_fE1HighDptRGB             22      // int32_t
#define LOG_fE1LowDptRGBFix           18      // int32_t
#define LOG_fE2LowDelta               26      // int32_t
#define LOG_fE2HighDelta              30      // int32_t
#define LOG_fE2LowDeltaFloat          26      // float
#define LOG_fE2HighDeltaFloat         30      // float
#define LOG_fE2LowDeltaDouble         26      // float
#define LOG_fE2HighDeltaDouble        30      // float
#define LOG_fE2Low0Valid              33      // 1 Bit, Bit 7
#define     LOG_fE2Low0ValidMask 0x80
#define     LOG_fE2Low0ValidShift 7
#define LOG_fE2Low1Valid              33      // 1 Bit, Bit 6
#define     LOG_fE2Low1ValidMask 0x40
#define     LOG_fE2Low1ValidShift 6
#define LOG_fE2Low2Valid              33      // 1 Bit, Bit 5
#define     LOG_fE2Low2ValidMask 0x20
#define     LOG_fE2Low2ValidShift 5
#define LOG_fE2Low3Valid              33      // 1 Bit, Bit 4
#define     LOG_fE2Low3ValidMask 0x10
#define     LOG_fE2Low3ValidShift 4
#define LOG_fE2Low4Valid              33      // 1 Bit, Bit 3
#define     LOG_fE2Low4ValidMask 0x08
#define     LOG_fE2Low4ValidShift 3
#define LOG_fE2Low5Valid              33      // 1 Bit, Bit 2
#define     LOG_fE2Low5ValidMask 0x04
#define     LOG_fE2Low5ValidShift 2
#define LOG_fE2Low6Valid              33      // 1 Bit, Bit 1
#define     LOG_fE2Low6ValidMask 0x02
#define     LOG_fE2Low6ValidShift 1
#define LOG_fE2Low7Valid              33      // 1 Bit, Bit 0
#define     LOG_fE2Low7ValidMask 0x01
#define     LOG_fE2Low7ValidShift 0
#define LOG_fE2Low0Dpt2               26      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt2               27      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt2               28      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt2               29      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt2Fix             26      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt5                26      // uint8_t
#define LOG_fE2HighDpt5               30      // uint8_t
#define LOG_fE2Low0Dpt5In             26      // uint8_t
#define LOG_fE2Low1Dpt5In             27      // uint8_t
#define LOG_fE2Low2Dpt5In             28      // uint8_t
#define LOG_fE2Low3Dpt5In             29      // uint8_t
#define LOG_fE2Low4Dpt5In             30      // uint8_t
#define LOG_fE2Low5Dpt5In             31      // uint8_t
#define LOG_fE2Low6Dpt5In             32      // uint8_t
#define LOG_fE2LowDpt5Fix             26      // uint8_t
#define LOG_fE2LowDpt5001             26      // uint8_t
#define LOG_fE2HighDpt5001            30      // uint8_t
#define LOG_fE2Low0Dpt5xIn            26      // uint8_t
#define LOG_fE2Low1Dpt5xIn            27      // uint8_t
#define LOG_fE2Low2Dpt5xIn            28      // uint8_t
#define LOG_fE2Low3Dpt5xIn            29      // uint8_t
#define LOG_fE2Low4Dpt5xIn            30      // uint8_t
#define LOG_fE2Low5Dpt5xIn            31      // uint8_t
#define LOG_fE2Low6Dpt5xIn            32      // uint8_t
#define LOG_fE2LowDpt5xFix            26      // uint8_t
#define LOG_fE2LowDpt6                26      // int8_t
#define LOG_fE2HighDpt6               30      // int8_t
#define LOG_fE2Low0Dpt6In             26      // int8_t
#define LOG_fE2Low1Dpt6In             27      // int8_t
#define LOG_fE2Low2Dpt6In             28      // int8_t
#define LOG_fE2Low3Dpt6In             29      // int8_t
#define LOG_fE2Low4Dpt6In             30      // int8_t
#define LOG_fE2Low5Dpt6In             31      // int8_t
#define LOG_fE2Low6Dpt6In             32      // int8_t
#define LOG_fE2LowDpt6Fix             26      // int8_t
#define LOG_fE2LowDpt7                26      // uint16_t
#define LOG_fE2HighDpt7               30      // uint16_t
#define LOG_fE2Low0Dpt7In             26      // uint16_t
#define LOG_fE2Low1Dpt7In             28      // uint16_t
#define LOG_fE2Low2Dpt7In             30      // uint16_t
#define LOG_fE2LowDpt7Fix             26      // uint16_t
#define LOG_fE2LowDpt8                26      // int16_t
#define LOG_fE2HighDpt8               30      // int16_t
#define LOG_fE2Low0Dpt8In             26      // int16_t
#define LOG_fE2Low1Dpt8In             28      // int16_t
#define LOG_fE2Low2Dpt8In             30      // int16_t
#define LOG_fE2LowDpt8Fix             26      // int16_t
#define LOG_fE2LowDpt9                26      // float
#define LOG_fE2HighDpt9               30      // float
#define LOG_fE2LowDpt9Fix             26      // float
#define LOG_fE2LowDpt12               26      // uint32_t
#define LOG_fE2HighDpt12              30      // uint32_t
#define LOG_fE2LowDpt12Fix            26      // uint32_t
#define LOG_fE2LowDpt13               26      // int32_t
#define LOG_fE2HighDpt13              30      // int32_t
#define LOG_fE2LowDpt13Fix            26      // int32_t
#define LOG_fE2LowDpt14               26      // float
#define LOG_fE2HighDpt14              30      // float
#define LOG_fE2LowDpt14Fix            26      // float
#define LOG_fE2Low0Dpt17              26      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt17              27      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt17              28      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt17              29      // 8 Bits, Bit 7-0
#define LOG_fE2Low4Dpt17              30      // 8 Bits, Bit 7-0
#define LOG_fE2Low5Dpt17              31      // 8 Bits, Bit 7-0
#define LOG_fE2Low6Dpt17              32      // 8 Bits, Bit 7-0
#define LOG_fE2Low7Dpt17              33      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt17Fix            26      // 8 Bits, Bit 7-0
#define LOG_fE2LowDptRGB              26      // int32_t
#define LOG_fE2HighDptRGB             30      // int32_t
#define LOG_fE2LowDptRGBFix           26      // int32_t
#define LOG_fTd1Value                 18      // 1 Bit, Bit 7
#define     LOG_fTd1ValueMask 0x80
#define     LOG_fTd1ValueShift 7
#define LOG_fTd1Degree                18      // 6 Bits, Bit 6-1
#define     LOG_fTd1DegreeMask 0x7E
#define     LOG_fTd1DegreeShift 1
#define LOG_fTd1HourAbs               18      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourAbsMask 0x3E
#define     LOG_fTd1HourAbsShift 1
#define LOG_fTd1HourRel               18      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelMask 0x3E
#define     LOG_fTd1HourRelShift 1
#define LOG_fTd1MinuteAbs             18      // 6 Bits, Bit 0--5
#define LOG_fTd1MinuteRel             18      // 6 Bits, Bit 0--5
#define LOG_fTd1Weekday               19      // 3 Bits, Bit 2-0
#define     LOG_fTd1WeekdayMask 0x07
#define     LOG_fTd1WeekdayShift 0
#define LOG_fTd2Value                 20      // 1 Bit, Bit 7
#define     LOG_fTd2ValueMask 0x80
#define     LOG_fTd2ValueShift 7
#define LOG_fTd2Degree                20      // 6 Bits, Bit 6-1
#define     LOG_fTd2DegreeMask 0x7E
#define     LOG_fTd2DegreeShift 1
#define LOG_fTd2HourAbs               20      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourAbsMask 0x3E
#define     LOG_fTd2HourAbsShift 1
#define LOG_fTd2HourRel               20      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelMask 0x3E
#define     LOG_fTd2HourRelShift 1
#define LOG_fTd2MinuteAbs             20      // 6 Bits, Bit 0--5
#define LOG_fTd2MinuteRel             20      // 6 Bits, Bit 0--5
#define LOG_fTd2Weekday               21      // 3 Bits, Bit 2-0
#define     LOG_fTd2WeekdayMask 0x07
#define     LOG_fTd2WeekdayShift 0
#define LOG_fTd3Value                 22      // 1 Bit, Bit 7
#define     LOG_fTd3ValueMask 0x80
#define     LOG_fTd3ValueShift 7
#define LOG_fTd3Degree                22      // 6 Bits, Bit 6-1
#define     LOG_fTd3DegreeMask 0x7E
#define     LOG_fTd3DegreeShift 1
#define LOG_fTd3HourAbs               22      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourAbsMask 0x3E
#define     LOG_fTd3HourAbsShift 1
#define LOG_fTd3HourRel               22      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelMask 0x3E
#define     LOG_fTd3HourRelShift 1
#define LOG_fTd3MinuteAbs             22      // 6 Bits, Bit 0--5
#define LOG_fTd3MinuteRel             22      // 6 Bits, Bit 0--5
#define LOG_fTd3Weekday               23      // 3 Bits, Bit 2-0
#define     LOG_fTd3WeekdayMask 0x07
#define     LOG_fTd3WeekdayShift 0
#define LOG_fTd4Value                 24      // 1 Bit, Bit 7
#define     LOG_fTd4ValueMask 0x80
#define     LOG_fTd4ValueShift 7
#define LOG_fTd4Degree                24      // 6 Bits, Bit 6-1
#define     LOG_fTd4DegreeMask 0x7E
#define     LOG_fTd4DegreeShift 1
#define LOG_fTd4HourAbs               24      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourAbsMask 0x3E
#define     LOG_fTd4HourAbsShift 1
#define LOG_fTd4HourRel               24      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelMask 0x3E
#define     LOG_fTd4HourRelShift 1
#define LOG_fTd4MinuteAbs             24      // 6 Bits, Bit 0--5
#define LOG_fTd4MinuteRel             24      // 6 Bits, Bit 0--5
#define LOG_fTd4Weekday               25      // 3 Bits, Bit 2-0
#define     LOG_fTd4WeekdayMask 0x07
#define     LOG_fTd4WeekdayShift 0
#define LOG_fTd5Value                 26      // 1 Bit, Bit 7
#define     LOG_fTd5ValueMask 0x80
#define     LOG_fTd5ValueShift 7
#define LOG_fTd5Degree                26      // 6 Bits, Bit 6-1
#define     LOG_fTd5DegreeMask 0x7E
#define     LOG_fTd5DegreeShift 1
#define LOG_fTd5HourAbs               26      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourAbsMask 0x3E
#define     LOG_fTd5HourAbsShift 1
#define LOG_fTd5HourRel               26      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelMask 0x3E
#define     LOG_fTd5HourRelShift 1
#define LOG_fTd5MinuteAbs             26      // 6 Bits, Bit 0--5
#define LOG_fTd5MinuteRel             26      // 6 Bits, Bit 0--5
#define LOG_fTd5Weekday               27      // 3 Bits, Bit 2-0
#define     LOG_fTd5WeekdayMask 0x07
#define     LOG_fTd5WeekdayShift 0
#define LOG_fTd6Value                 28      // 1 Bit, Bit 7
#define     LOG_fTd6ValueMask 0x80
#define     LOG_fTd6ValueShift 7
#define LOG_fTd6Degree                28      // 6 Bits, Bit 6-1
#define     LOG_fTd6DegreeMask 0x7E
#define     LOG_fTd6DegreeShift 1
#define LOG_fTd6HourAbs               28      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourAbsMask 0x3E
#define     LOG_fTd6HourAbsShift 1
#define LOG_fTd6HourRel               28      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelMask 0x3E
#define     LOG_fTd6HourRelShift 1
#define LOG_fTd6MinuteAbs             28      // 6 Bits, Bit 0--5
#define LOG_fTd6MinuteRel             28      // 6 Bits, Bit 0--5
#define LOG_fTd6Weekday               29      // 3 Bits, Bit 2-0
#define     LOG_fTd6WeekdayMask 0x07
#define     LOG_fTd6WeekdayShift 0
#define LOG_fTd7Value                 30      // 1 Bit, Bit 7
#define     LOG_fTd7ValueMask 0x80
#define     LOG_fTd7ValueShift 7
#define LOG_fTd7Degree                30      // 6 Bits, Bit 6-1
#define     LOG_fTd7DegreeMask 0x7E
#define     LOG_fTd7DegreeShift 1
#define LOG_fTd7HourAbs               30      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourAbsMask 0x3E
#define     LOG_fTd7HourAbsShift 1
#define LOG_fTd7HourRel               30      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelMask 0x3E
#define     LOG_fTd7HourRelShift 1
#define LOG_fTd7MinuteAbs             30      // 6 Bits, Bit 0--5
#define LOG_fTd7MinuteRel             30      // 6 Bits, Bit 0--5
#define LOG_fTd7Weekday               31      // 3 Bits, Bit 2-0
#define     LOG_fTd7WeekdayMask 0x07
#define     LOG_fTd7WeekdayShift 0
#define LOG_fTd8Value                 32      // 1 Bit, Bit 7
#define     LOG_fTd8ValueMask 0x80
#define     LOG_fTd8ValueShift 7
#define LOG_fTd8Degree                32      // 6 Bits, Bit 6-1
#define     LOG_fTd8DegreeMask 0x7E
#define     LOG_fTd8DegreeShift 1
#define LOG_fTd8HourAbs               32      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourAbsMask 0x3E
#define     LOG_fTd8HourAbsShift 1
#define LOG_fTd8HourRel               32      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelMask 0x3E
#define     LOG_fTd8HourRelShift 1
#define LOG_fTd8MinuteAbs             32      // 6 Bits, Bit 0--5
#define LOG_fTd8MinuteRel             32      // 6 Bits, Bit 0--5
#define LOG_fTd8Weekday               33      // 3 Bits, Bit 2-0
#define     LOG_fTd8WeekdayMask 0x07
#define     LOG_fTd8WeekdayShift 0
#define LOG_fTy1Weekday1              26      // 1 Bit, Bit 7
#define     LOG_fTy1Weekday1Mask 0x80
#define     LOG_fTy1Weekday1Shift 7
#define LOG_fTy1Weekday2              26      // 1 Bit, Bit 6
#define     LOG_fTy1Weekday2Mask 0x40
#define     LOG_fTy1Weekday2Shift 6
#define LOG_fTy1Weekday3              26      // 1 Bit, Bit 5
#define     LOG_fTy1Weekday3Mask 0x20
#define     LOG_fTy1Weekday3Shift 5
#define LOG_fTy1Weekday4              26      // 1 Bit, Bit 4
#define     LOG_fTy1Weekday4Mask 0x10
#define     LOG_fTy1Weekday4Shift 4
#define LOG_fTy1Weekday5              26      // 1 Bit, Bit 3
#define     LOG_fTy1Weekday5Mask 0x08
#define     LOG_fTy1Weekday5Shift 3
#define LOG_fTy1Weekday6              26      // 1 Bit, Bit 2
#define     LOG_fTy1Weekday6Mask 0x04
#define     LOG_fTy1Weekday6Shift 2
#define LOG_fTy1Weekday7              26      // 1 Bit, Bit 1
#define     LOG_fTy1Weekday7Mask 0x02
#define     LOG_fTy1Weekday7Shift 1
#define LOG_fTy1Day                   26      // 7 Bits, Bit 7-1
#define     LOG_fTy1DayMask 0xFE
#define     LOG_fTy1DayShift 1
#define LOG_fTy1IsWeekday             26      // 1 Bit, Bit 0
#define     LOG_fTy1IsWeekdayMask 0x01
#define     LOG_fTy1IsWeekdayShift 0
#define LOG_fTy1Month                 27      // 4 Bits, Bit 7-4
#define     LOG_fTy1MonthMask 0xF0
#define     LOG_fTy1MonthShift 4
#define LOG_fTy2Weekday1              28      // 1 Bit, Bit 7
#define     LOG_fTy2Weekday1Mask 0x80
#define     LOG_fTy2Weekday1Shift 7
#define LOG_fTy2Weekday2              28      // 1 Bit, Bit 6
#define     LOG_fTy2Weekday2Mask 0x40
#define     LOG_fTy2Weekday2Shift 6
#define LOG_fTy2Weekday3              28      // 1 Bit, Bit 5
#define     LOG_fTy2Weekday3Mask 0x20
#define     LOG_fTy2Weekday3Shift 5
#define LOG_fTy2Weekday4              28      // 1 Bit, Bit 4
#define     LOG_fTy2Weekday4Mask 0x10
#define     LOG_fTy2Weekday4Shift 4
#define LOG_fTy2Weekday5              28      // 1 Bit, Bit 3
#define     LOG_fTy2Weekday5Mask 0x08
#define     LOG_fTy2Weekday5Shift 3
#define LOG_fTy2Weekday6              28      // 1 Bit, Bit 2
#define     LOG_fTy2Weekday6Mask 0x04
#define     LOG_fTy2Weekday6Shift 2
#define LOG_fTy2Weekday7              28      // 1 Bit, Bit 1
#define     LOG_fTy2Weekday7Mask 0x02
#define     LOG_fTy2Weekday7Shift 1
#define LOG_fTy2Day                   28      // 7 Bits, Bit 7-1
#define     LOG_fTy2DayMask 0xFE
#define     LOG_fTy2DayShift 1
#define LOG_fTy2IsWeekday             28      // 1 Bit, Bit 0
#define     LOG_fTy2IsWeekdayMask 0x01
#define     LOG_fTy2IsWeekdayShift 0
#define LOG_fTy2Month                 29      // 4 Bits, Bit 7-4
#define     LOG_fTy2MonthMask 0xF0
#define     LOG_fTy2MonthShift 4
#define LOG_fTy3Weekday1              30      // 1 Bit, Bit 7
#define     LOG_fTy3Weekday1Mask 0x80
#define     LOG_fTy3Weekday1Shift 7
#define LOG_fTy3Weekday2              30      // 1 Bit, Bit 6
#define     LOG_fTy3Weekday2Mask 0x40
#define     LOG_fTy3Weekday2Shift 6
#define LOG_fTy3Weekday3              30      // 1 Bit, Bit 5
#define     LOG_fTy3Weekday3Mask 0x20
#define     LOG_fTy3Weekday3Shift 5
#define LOG_fTy3Weekday4              30      // 1 Bit, Bit 4
#define     LOG_fTy3Weekday4Mask 0x10
#define     LOG_fTy3Weekday4Shift 4
#define LOG_fTy3Weekday5              30      // 1 Bit, Bit 3
#define     LOG_fTy3Weekday5Mask 0x08
#define     LOG_fTy3Weekday5Shift 3
#define LOG_fTy3Weekday6              30      // 1 Bit, Bit 2
#define     LOG_fTy3Weekday6Mask 0x04
#define     LOG_fTy3Weekday6Shift 2
#define LOG_fTy3Weekday7              30      // 1 Bit, Bit 1
#define     LOG_fTy3Weekday7Mask 0x02
#define     LOG_fTy3Weekday7Shift 1
#define LOG_fTy3Day                   30      // 7 Bits, Bit 7-1
#define     LOG_fTy3DayMask 0xFE
#define     LOG_fTy3DayShift 1
#define LOG_fTy3IsWeekday             30      // 1 Bit, Bit 0
#define     LOG_fTy3IsWeekdayMask 0x01
#define     LOG_fTy3IsWeekdayShift 0
#define LOG_fTy3Month                 31      // 4 Bits, Bit 7-4
#define     LOG_fTy3MonthMask 0xF0
#define     LOG_fTy3MonthShift 4
#define LOG_fTy4Weekday1              32      // 1 Bit, Bit 7
#define     LOG_fTy4Weekday1Mask 0x80
#define     LOG_fTy4Weekday1Shift 7
#define LOG_fTy4Weekday2              32      // 1 Bit, Bit 6
#define     LOG_fTy4Weekday2Mask 0x40
#define     LOG_fTy4Weekday2Shift 6
#define LOG_fTy4Weekday3              32      // 1 Bit, Bit 5
#define     LOG_fTy4Weekday3Mask 0x20
#define     LOG_fTy4Weekday3Shift 5
#define LOG_fTy4Weekday4              32      // 1 Bit, Bit 4
#define     LOG_fTy4Weekday4Mask 0x10
#define     LOG_fTy4Weekday4Shift 4
#define LOG_fTy4Weekday5              32      // 1 Bit, Bit 3
#define     LOG_fTy4Weekday5Mask 0x08
#define     LOG_fTy4Weekday5Shift 3
#define LOG_fTy4Weekday6              32      // 1 Bit, Bit 2
#define     LOG_fTy4Weekday6Mask 0x04
#define     LOG_fTy4Weekday6Shift 2
#define LOG_fTy4Weekday7              32      // 1 Bit, Bit 1
#define     LOG_fTy4Weekday7Mask 0x02
#define     LOG_fTy4Weekday7Shift 1
#define LOG_fTy4Day                   32      // 7 Bits, Bit 7-1
#define     LOG_fTy4DayMask 0xFE
#define     LOG_fTy4DayShift 1
#define LOG_fTy4IsWeekday             32      // 1 Bit, Bit 0
#define     LOG_fTy4IsWeekdayMask 0x01
#define     LOG_fTy4IsWeekdayShift 0
#define LOG_fTy4Month                 33      // 4 Bits, Bit 7-4
#define     LOG_fTy4MonthMask 0xF0
#define     LOG_fTy4MonthShift 4
#define LOG_fI1                       34      // 4 Bits, Bit 7-4
#define     LOG_fI1Mask 0xF0
#define     LOG_fI1Shift 4
#define LOG_fI2                       34      // 4 Bits, Bit 3-0
#define     LOG_fI2Mask 0x0F
#define     LOG_fI2Shift 0
#define LOG_fI1Function               35      // uint8_t
#define LOG_fI2Function               36      // uint8_t
#define LOG_fOStairtimeBase           37      // 2 Bits, Bit 7-6
#define     LOG_fOStairtimeBaseMask 0xC0
#define     LOG_fOStairtimeBaseShift 6
#define LOG_fOStairtimeTime           37      // 14 Bits, Bit 13-0
#define     LOG_fOStairtimeTimeMask 0x3FFF
#define     LOG_fOStairtimeTimeShift 0
#define LOG_fOBlinkBase               39      // 2 Bits, Bit 7-6
#define     LOG_fOBlinkBaseMask 0xC0
#define     LOG_fOBlinkBaseShift 6
#define LOG_fOBlinkTime               39      // 14 Bits, Bit 13-0
#define     LOG_fOBlinkTimeMask 0x3FFF
#define     LOG_fOBlinkTimeShift 0
#define LOG_fODelay                   41      // 1 Bit, Bit 7
#define     LOG_fODelayMask 0x80
#define     LOG_fODelayShift 7
#define LOG_fODelayOnRepeat           41      // 2 Bits, Bit 6-5
#define     LOG_fODelayOnRepeatMask 0x60
#define     LOG_fODelayOnRepeatShift 5
#define LOG_fODelayOnReset            41      // 1 Bit, Bit 4
#define     LOG_fODelayOnResetMask 0x10
#define     LOG_fODelayOnResetShift 4
#define LOG_fODelayOffRepeat          41      // 2 Bits, Bit 3-2
#define     LOG_fODelayOffRepeatMask 0x0C
#define     LOG_fODelayOffRepeatShift 2
#define LOG_fODelayOffReset           41      // 1 Bit, Bit 1
#define     LOG_fODelayOffResetMask 0x02
#define     LOG_fODelayOffResetShift 1
#define LOG_fODelayOnBase             42      // 2 Bits, Bit 7-6
#define     LOG_fODelayOnBaseMask 0xC0
#define     LOG_fODelayOnBaseShift 6
#define LOG_fODelayOnTime             42      // 14 Bits, Bit 13-0
#define     LOG_fODelayOnTimeMask 0x3FFF
#define     LOG_fODelayOnTimeShift 0
#define LOG_fODelayOffBase            44      // 2 Bits, Bit 7-6
#define     LOG_fODelayOffBaseMask 0xC0
#define     LOG_fODelayOffBaseShift 6
#define LOG_fODelayOffTime            44      // 14 Bits, Bit 13-0
#define     LOG_fODelayOffTimeMask 0x3FFF
#define     LOG_fODelayOffTimeShift 0
#define LOG_fOStair                   46      // 1 Bit, Bit 7
#define     LOG_fOStairMask 0x80
#define     LOG_fOStairShift 7
#define LOG_fORetrigger               46      // 1 Bit, Bit 6
#define     LOG_fORetriggerMask 0x40
#define     LOG_fORetriggerShift 6
#define LOG_fOStairOff                46      // 1 Bit, Bit 5
#define     LOG_fOStairOffMask 0x20
#define     LOG_fOStairOffShift 5
#define LOG_fORepeat                  46      // 1 Bit, Bit 4
#define     LOG_fORepeatMask 0x10
#define     LOG_fORepeatShift 4
#define LOG_fOOutputFilter            46      // 2 Bits, Bit 3-2
#define     LOG_fOOutputFilterMask 0x0C
#define     LOG_fOOutputFilterShift 2
#define LOG_fORepeatOnBase            47      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOnBaseMask 0xC0
#define     LOG_fORepeatOnBaseShift 6
#define LOG_fORepeatOnTime            47      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOnTimeMask 0x3FFF
#define     LOG_fORepeatOnTimeShift 0
#define LOG_fORepeatOffBase           49      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOffBaseMask 0xC0
#define     LOG_fORepeatOffBaseShift 6
#define LOG_fORepeatOffTime           49      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOffTimeMask 0x3FFF
#define     LOG_fORepeatOffTimeShift 0
#define LOG_fODpt                     51      // 8 Bits, Bit 7-0
#define LOG_fOOn                      52      // 8 Bits, Bit 7-0
#define LOG_fOOnBuzzer                52      // 8 Bits, Bit 7-0
#define LOG_fOOnLed                   52      // 8 Bits, Bit 7-0
#define LOG_fOOnAll                   52      // 8 Bits, Bit 7-0
#define LOG_fOOnTone                  53      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt1                  53      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt2                  53      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt5                  53      // uint8_t
#define LOG_fOOnDpt5001               53      // uint8_t
#define LOG_fOOnDpt6                  53      // int8_t
#define LOG_fOOnDpt7                  53      // uint16_t
#define LOG_fOOnDpt8                  53      // int16_t
#define LOG_fOOnDpt9                  53      // float
#define LOG_fOOnDpt12                 53      // uint32_t
#define LOG_fOOnDpt13                 53      // int32_t
#define LOG_fOOnDpt14                 53      // float
#define LOG_fOOnDpt16                 53      // char*, 14 Byte
#define LOG_fOOnDpt17                 53      // 8 Bits, Bit 7-0
#define LOG_fOOnRGB                   53      // 24 Bits, Bit 31-8
#define     LOG_fOOnRGBMask 0xFFFFFF00
#define     LOG_fOOnRGBShift 8
#define LOG_fOOnPAArea                53      // 4 Bits, Bit 7-4
#define     LOG_fOOnPAAreaMask 0xF0
#define     LOG_fOOnPAAreaShift 4
#define LOG_fOOnPALine                53      // 4 Bits, Bit 3-0
#define     LOG_fOOnPALineMask 0x0F
#define     LOG_fOOnPALineShift 0
#define LOG_fOOnPADevice              54      // uint8_t
#define LOG_fOOnFunction              53      // 8 Bits, Bit 7-0
#define LOG_fOOff                     67      // 8 Bits, Bit 7-0
#define LOG_fOOffBuzzer               67      // 8 Bits, Bit 7-0
#define LOG_fOOffLed                  67      // 8 Bits, Bit 7-0
#define LOG_fOOffAll                  67      // 8 Bits, Bit 7-0
#define LOG_fOOffTone                 68      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt1                 68      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt2                 68      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt5                 68      // uint8_t
#define LOG_fOOffDpt5001              68      // uint8_t
#define LOG_fOOffDpt6                 68      // int8_t
#define LOG_fOOffDpt7                 68      // uint16_t
#define LOG_fOOffDpt8                 68      // int16_t
#define LOG_fOOffDpt9                 68      // float
#define LOG_fOOffDpt12                68      // uint32_t
#define LOG_fOOffDpt13                68      // int32_t
#define LOG_fOOffDpt14                68      // float
#define LOG_fOOffDpt16                68      // char*, 14 Byte
#define LOG_fOOffDpt17                68      // 8 Bits, Bit 7-0
#define LOG_fOOffRGB                  68      // 24 Bits, Bit 31-8
#define     LOG_fOOffRGBMask 0xFFFFFF00
#define     LOG_fOOffRGBShift 8
#define LOG_fOOffPAArea               68      // 4 Bits, Bit 7-4
#define     LOG_fOOffPAAreaMask 0xF0
#define     LOG_fOOffPAAreaShift 4
#define LOG_fOOffPALine               68      // 4 Bits, Bit 3-0
#define     LOG_fOOffPALineMask 0x0F
#define     LOG_fOOffPALineShift 0
#define LOG_fOOffPADevice             69      // uint8_t
#define LOG_fOOffFunction             68      // 8 Bits, Bit 7-0
#define LOG_fE1UseOtherKO             82      // 1 Bit, Bit 7
#define     LOG_fE1UseOtherKOMask 0x80
#define     LOG_fE1UseOtherKOShift 7
#define LOG_fE1OtherKO                82      // 15 Bits, Bit 14-0
#define     LOG_fE1OtherKOMask 0x7FFF
#define     LOG_fE1OtherKOShift 0
#define LOG_fE2UseOtherKO             84      // 1 Bit, Bit 7
#define     LOG_fE2UseOtherKOMask 0x80
#define     LOG_fE2UseOtherKOShift 7
#define LOG_fE2OtherKO                84      // 15 Bits, Bit 14-0
#define     LOG_fE2OtherKOMask 0x7FFF
#define     LOG_fE2OtherKOShift 0

// Zeitbasis
#define ParamLOG_fChannelDelayBase         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fChannelDelayBase)) & LOG_fChannelDelayBaseMask) >> LOG_fChannelDelayBaseShift)
// Zeit
#define ParamLOG_fChannelDelayTime         (knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime)) & LOG_fChannelDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fChannelDelayTimeMS       (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime))))
// Logik-Operation
#define ParamLOG_fLogic                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fLogic)))
// Logik auswerten
#define ParamLOG_fCalculate                (knx.paramByte(LOG_ParamCalcIndex(LOG_fCalculate)) & LOG_fCalculateMask)
// Kanal deaktivieren (zu Testzwecken)
#define ParamLOG_fDisable                  ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fDisable)) & LOG_fDisableMask))
// Alarmausgabe (Buzzer oder LED trotz Sperre schalten)?
#define ParamLOG_fAlarm                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fAlarm)) & LOG_fAlarmMask))
// Tor geht sofort wieder zu
#define ParamLOG_fTGate                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTGate)) & LOG_fTGateMask))
// Wert EIN intern weiterleiten
#define ParamLOG_fOInternalOn              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOn)) & LOG_fOInternalOnMask))
// Wert AUS intern weiterleiten
#define ParamLOG_fOInternalOff             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOff)) & LOG_fOInternalOffMask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTrigger                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fTrigger)))
//           Eingang 1
#define ParamLOG_fTriggerE1                ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE1)) & LOG_fTriggerE1Mask))
//           Eingang 2
#define ParamLOG_fTriggerE2                ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE2)) & LOG_fTriggerE2Mask))
//           Kanalausgang X
#define ParamLOG_fTriggerI1                ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI1)) & LOG_fTriggerI1Mask))
//           Kanalausgang Y
#define ParamLOG_fTriggerI2                ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI2)) & LOG_fTriggerI2Mask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTriggerTime              (knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerTime)))
// Beim schließen vom Tor wird
#define ParamLOG_fTriggerGateClose         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateClose)) & LOG_fTriggerGateCloseMask) >> LOG_fTriggerGateCloseShift)
// Beim öffnen vom Tor wird
#define ParamLOG_fTriggerGateOpen          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateOpen)) & LOG_fTriggerGateOpenMask) >> LOG_fTriggerGateOpenShift)
// Eingang 1
#define ParamLOG_fE1                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1)) & LOG_fE1Mask)
// Wert für Eingang 1 wird ermittelt durch
#define ParamLOG_fE1Convert                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Convert)) & LOG_fE1ConvertMask) >> LOG_fE1ConvertShift)
// Wert für Eingang 1 wird ermittelt durch
#define ParamLOG_fE1ConvertFloat           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertFloat)) & LOG_fE1ConvertFloatMask) >> LOG_fE1ConvertFloatShift)
// Wert für Eingang 1 wird ermittelt durch
#define ParamLOG_fE1ConvertSpecial         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertSpecial)) & LOG_fE1ConvertSpecialMask) >> LOG_fE1ConvertSpecialShift)
// DPT für Eingang 1
#define ParamLOG_fE1Dpt                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Dpt)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE1Default                (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Default)) & LOG_fE1DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE1DefaultExt             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultExt)) & LOG_fE1DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE1DefaultEEPROM          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultEEPROM)) & LOG_fE1DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE1DefaultRepeat          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultRepeat)) & LOG_fE1DefaultRepeatMask))
// Typ der Zeitschaltuhr
#define ParamLOG_fTYearDay                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTYearDay)) & LOG_fTYearDayMask))
// Beim Neustart letzte Schaltzeit nachholen
#define ParamLOG_fTRestoreState            ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTRestoreState)) & LOG_fTRestoreStateMask) >> LOG_fTRestoreStateShift)
// Zeitbasis
#define ParamLOG_fE1RepeatBase             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1RepeatBase)) & LOG_fE1RepeatBaseMask) >> LOG_fE1RepeatBaseShift)
// Zeit
#define ParamLOG_fE1RepeatTime             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime)) & LOG_fE1RepeatTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fE1RepeatTimeMS           (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime))))
// Eingang 2
#define ParamLOG_fE2                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2)) & LOG_fE2Mask)
// Wert für Eingang 2 wird ermittelt durch
#define ParamLOG_fE2Convert                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Convert)) & LOG_fE2ConvertMask) >> LOG_fE2ConvertShift)
// Wert für Eingang 2 wird ermittelt durch
#define ParamLOG_fE2ConvertFloat           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertFloat)) & LOG_fE2ConvertFloatMask) >> LOG_fE2ConvertFloatShift)
// Wert für Eingang 2 wird ermittelt durch
#define ParamLOG_fE2ConvertSpecial         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertSpecial)) & LOG_fE2ConvertSpecialMask) >> LOG_fE2ConvertSpecialShift)
// DPT für Eingang 2
#define ParamLOG_fE2Dpt                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Dpt)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE2Default                (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Default)) & LOG_fE2DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE2DefaultExt             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultExt)) & LOG_fE2DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE2DefaultEEPROM          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultEEPROM)) & LOG_fE2DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE2DefaultRepeat          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultRepeat)) & LOG_fE2DefaultRepeatMask))
// Feiertagsbehandlung
#define ParamLOG_fTHoliday                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTHoliday)) & LOG_fTHolidayMask) >> LOG_fTHolidayShift)
// Urlaubsbehandlung
#define ParamLOG_fTVacation                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTVacation)) & LOG_fTVacationMask) >> LOG_fTVacationShift)
// Zeitbasis
#define ParamLOG_fE2RepeatBase             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2RepeatBase)) & LOG_fE2RepeatBaseMask) >> LOG_fE2RepeatBaseShift)
// Zeit
#define ParamLOG_fE2RepeatTime             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime)) & LOG_fE2RepeatTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fE2RepeatTimeMS           (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime))))
// Zeitbezug
#define ParamLOG_fTd1DuskDawn              ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1DuskDawn)) & LOG_fTd1DuskDawnMask) >> LOG_fTd1DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd2DuskDawn              (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2DuskDawn)) & LOG_fTd2DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd3DuskDawn              ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3DuskDawn)) & LOG_fTd3DuskDawnMask) >> LOG_fTd3DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd4DuskDawn              (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4DuskDawn)) & LOG_fTd4DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd5DuskDawn              ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5DuskDawn)) & LOG_fTd5DuskDawnMask) >> LOG_fTd5DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd6DuskDawn              (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6DuskDawn)) & LOG_fTd6DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd7DuskDawn              ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7DuskDawn)) & LOG_fTd7DuskDawnMask) >> LOG_fTd7DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd8DuskDawn              (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8DuskDawn)) & LOG_fTd8DuskDawnMask)
// Von-Wert
#define ParamLOG_fE1LowDelta               ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDelta)))
// Bis-Wert
#define ParamLOG_fE1HighDelta              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1HighDelta)))
// Von-Wert
#define ParamLOG_fE1LowDeltaFloat          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaFloat         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDeltaDouble         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaDouble        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low0Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Valid)) & LOG_fE1Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low1Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Valid)) & LOG_fE1Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low2Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Valid)) & LOG_fE1Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low3Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Valid)) & LOG_fE1Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low4Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Valid)) & LOG_fE1Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low5Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Valid)) & LOG_fE1Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low6Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Valid)) & LOG_fE1Low6ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low7Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low7Valid)) & LOG_fE1Low7ValidMask))
// Eingang 1 ist EIN, wenn Wert gleich
#define ParamLOG_fE1LowDpt2                (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low1Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low2Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low3Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt2)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt2Fix             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt2Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt5                (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5)))
// Bis-Wert
#define ParamLOG_fE1HighDpt5               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5)))
// Eingang 1 ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5In)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt5Fix             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt5001             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5001)))
// Bisrt
#define ParamLOG_fE1HighDpt5001            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5001)))
// Eingang 1 ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5xIn)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt5xFix            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE1LowDpt6                ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6)))
// Bis-Wert
#define ParamLOG_fE1HighDpt6               ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt6)))
// Eingang 1 ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt6In)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt6Fix             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt7                (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7)))
// Bis-Wert
#define ParamLOG_fE1HighDpt7               (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt7)))
// Eingang 1 ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt7In)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt7Fix             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt8                ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8)))
// Bis-Wert
#define ParamLOG_fE1HighDpt8               ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt8)))
// Eingang 1 ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt8In)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt8Fix             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt9                (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt9               (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt9), Float_Enc_IEEE754Single))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt9Fix             (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDpt12               (knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDpt12)))
// Bis-Wert
#define ParamLOG_fE1HighDpt12              (knx.paramLong(LOG_ParamCalcIndex(LOG_fE1HighDpt12)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt12Fix            (knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt13               ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDpt13)))
// Bis-Wert
#define ParamLOG_fE1HighDpt13              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1HighDpt13)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt13Fix            ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt14               (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt14              (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt14), Float_Enc_IEEE754Single))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt14Fix            (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang 1 ist EIN bei Szene
#define ParamLOG_fE1Low0Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low1Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low2Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low3Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low4Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low5Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low6Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low7Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low7Dpt17)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDpt17Fix            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE1LowDptRGB              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE1HighDptRGB             ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1HighDptRGB)))
// Eingang 1 ist konstant
#define ParamLOG_fE1LowDptRGBFix           ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE1LowDptRGBFix)))
// Von-Wert
#define ParamLOG_fE2LowDelta               ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDelta)))
// Bis-Wert
#define ParamLOG_fE2HighDelta              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2HighDelta)))
// Von-Wert
#define ParamLOG_fE2LowDeltaFloat          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaFloat         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDeltaDouble         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaDouble        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low0Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Valid)) & LOG_fE2Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low1Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Valid)) & LOG_fE2Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low2Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Valid)) & LOG_fE2Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low3Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Valid)) & LOG_fE2Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low4Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Valid)) & LOG_fE2Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low5Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Valid)) & LOG_fE2Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low6Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Valid)) & LOG_fE2Low6ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low7Valid              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low7Valid)) & LOG_fE2Low7ValidMask))
// Eingang 2 ist EIN, wenn Wert gleich 
#define ParamLOG_fE2Low0Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low1Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low2Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low3Dpt2               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt2)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt2Fix             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt2Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt5                (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5               (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5)))
// Eingang 2 ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5In             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5In)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt5Fix             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt5001             (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5001)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5001            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5001)))
// Eingang 2 ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5xIn            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5xIn)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt5xFix            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE2LowDpt6                ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6)))
// Bis-Wert
#define ParamLOG_fE2HighDpt6               ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt6)))
// Eingang 2 ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt6In             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt6In)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt6Fix             ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt7                (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7)))
// Bis-Wert
#define ParamLOG_fE2HighDpt7               (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt7)))
// Eingang 2 ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt7In             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt7In)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt7Fix             (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt8                ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8)))
// Bis-Wert
#define ParamLOG_fE2HighDpt8               ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt8)))
// Eingang 2 ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt8In             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt8In)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt8Fix             ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt9                (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt9               (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt9), Float_Enc_IEEE754Single))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt9Fix             (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDpt12               (knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDpt12)))
// Bis-Wert
#define ParamLOG_fE2HighDpt12              (knx.paramLong(LOG_ParamCalcIndex(LOG_fE2HighDpt12)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt12Fix            (knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt13               ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDpt13)))
// Bis-Wert
#define ParamLOG_fE2HighDpt13              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2HighDpt13)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt13Fix            ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt14               (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt14              (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt14), Float_Enc_IEEE754Single))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt14Fix            (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang 2 ist EIN bei Szene
#define ParamLOG_fE2Low0Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low1Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low2Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low3Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low4Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low5Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low6Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low7Dpt17              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low7Dpt17)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDpt17Fix            (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE2LowDptRGB              ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE2HighDptRGB             ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2HighDptRGB)))
// Eingang 2 ist konstant
#define ParamLOG_fE2LowDptRGBFix           ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fE2LowDptRGBFix)))
// Schaltwert
#define ParamLOG_fTd1Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Value)) & LOG_fTd1ValueMask))
// Grad
#define ParamLOG_fTd1Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Degree)) & LOG_fTd1DegreeMask) >> LOG_fTd1DegreeShift)
// Stunde
#define ParamLOG_fTd1HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourAbs)) & LOG_fTd1HourAbsMask) >> LOG_fTd1HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd1HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourRel)) & LOG_fTd1HourRelMask) >> LOG_fTd1HourRelShift)
// Minute
#define ParamLOG_fTd1MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteAbs)))
// Minute
#define ParamLOG_fTd1MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteRel)))
// Wochentag
#define ParamLOG_fTd1Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Weekday)) & LOG_fTd1WeekdayMask)
// Schaltwert
#define ParamLOG_fTd2Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Value)) & LOG_fTd2ValueMask))
// Grad
#define ParamLOG_fTd2Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Degree)) & LOG_fTd2DegreeMask) >> LOG_fTd2DegreeShift)
// Stunde
#define ParamLOG_fTd2HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourAbs)) & LOG_fTd2HourAbsMask) >> LOG_fTd2HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd2HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourRel)) & LOG_fTd2HourRelMask) >> LOG_fTd2HourRelShift)
// Minute
#define ParamLOG_fTd2MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteAbs)))
// Minute
#define ParamLOG_fTd2MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteRel)))
// Wochentag
#define ParamLOG_fTd2Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Weekday)) & LOG_fTd2WeekdayMask)
// Schaltwert
#define ParamLOG_fTd3Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Value)) & LOG_fTd3ValueMask))
// Grad
#define ParamLOG_fTd3Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Degree)) & LOG_fTd3DegreeMask) >> LOG_fTd3DegreeShift)
// Stunde
#define ParamLOG_fTd3HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourAbs)) & LOG_fTd3HourAbsMask) >> LOG_fTd3HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd3HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourRel)) & LOG_fTd3HourRelMask) >> LOG_fTd3HourRelShift)
// Minute
#define ParamLOG_fTd3MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteAbs)))
// Minute
#define ParamLOG_fTd3MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteRel)))
// Wochentag
#define ParamLOG_fTd3Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Weekday)) & LOG_fTd3WeekdayMask)
// Schaltwert
#define ParamLOG_fTd4Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Value)) & LOG_fTd4ValueMask))
// Grad
#define ParamLOG_fTd4Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Degree)) & LOG_fTd4DegreeMask) >> LOG_fTd4DegreeShift)
// Stunde
#define ParamLOG_fTd4HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourAbs)) & LOG_fTd4HourAbsMask) >> LOG_fTd4HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd4HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourRel)) & LOG_fTd4HourRelMask) >> LOG_fTd4HourRelShift)
// Minute
#define ParamLOG_fTd4MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteAbs)))
// Minute
#define ParamLOG_fTd4MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteRel)))
// Wochentag
#define ParamLOG_fTd4Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Weekday)) & LOG_fTd4WeekdayMask)
// Schaltwert
#define ParamLOG_fTd5Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Value)) & LOG_fTd5ValueMask))
// Grad
#define ParamLOG_fTd5Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Degree)) & LOG_fTd5DegreeMask) >> LOG_fTd5DegreeShift)
// Stunde
#define ParamLOG_fTd5HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourAbs)) & LOG_fTd5HourAbsMask) >> LOG_fTd5HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd5HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourRel)) & LOG_fTd5HourRelMask) >> LOG_fTd5HourRelShift)
// Minute
#define ParamLOG_fTd5MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteAbs)))
// Minute
#define ParamLOG_fTd5MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteRel)))
// Wochentag
#define ParamLOG_fTd5Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Weekday)) & LOG_fTd5WeekdayMask)
// Schaltwert
#define ParamLOG_fTd6Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Value)) & LOG_fTd6ValueMask))
// Grad
#define ParamLOG_fTd6Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Degree)) & LOG_fTd6DegreeMask) >> LOG_fTd6DegreeShift)
// Stunde
#define ParamLOG_fTd6HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourAbs)) & LOG_fTd6HourAbsMask) >> LOG_fTd6HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd6HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourRel)) & LOG_fTd6HourRelMask) >> LOG_fTd6HourRelShift)
// Minute
#define ParamLOG_fTd6MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteAbs)))
// Minute
#define ParamLOG_fTd6MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteRel)))
// Wochentag
#define ParamLOG_fTd6Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Weekday)) & LOG_fTd6WeekdayMask)
// Schaltwert
#define ParamLOG_fTd7Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Value)) & LOG_fTd7ValueMask))
// Grad
#define ParamLOG_fTd7Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Degree)) & LOG_fTd7DegreeMask) >> LOG_fTd7DegreeShift)
// Stunde
#define ParamLOG_fTd7HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourAbs)) & LOG_fTd7HourAbsMask) >> LOG_fTd7HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd7HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourRel)) & LOG_fTd7HourRelMask) >> LOG_fTd7HourRelShift)
// Minute
#define ParamLOG_fTd7MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteAbs)))
// Minute
#define ParamLOG_fTd7MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteRel)))
// Wochentag
#define ParamLOG_fTd7Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Weekday)) & LOG_fTd7WeekdayMask)
// Schaltwert
#define ParamLOG_fTd8Value                 ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Value)) & LOG_fTd8ValueMask))
// Grad
#define ParamLOG_fTd8Degree                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Degree)) & LOG_fTd8DegreeMask) >> LOG_fTd8DegreeShift)
// Stunde
#define ParamLOG_fTd8HourAbs               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourAbs)) & LOG_fTd8HourAbsMask) >> LOG_fTd8HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd8HourRel               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourRel)) & LOG_fTd8HourRelMask) >> LOG_fTd8HourRelShift)
// Minute
#define ParamLOG_fTd8MinuteAbs             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteAbs)))
// Minute
#define ParamLOG_fTd8MinuteRel             (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteRel)))
// Wochentag
#define ParamLOG_fTd8Weekday               (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Weekday)) & LOG_fTd8WeekdayMask)
// Mo
#define ParamLOG_fTy1Weekday1              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday1)) & LOG_fTy1Weekday1Mask))
// Di
#define ParamLOG_fTy1Weekday2              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday2)) & LOG_fTy1Weekday2Mask))
// Mi
#define ParamLOG_fTy1Weekday3              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday3)) & LOG_fTy1Weekday3Mask))
// Do
#define ParamLOG_fTy1Weekday4              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday4)) & LOG_fTy1Weekday4Mask))
// Fr
#define ParamLOG_fTy1Weekday5              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday5)) & LOG_fTy1Weekday5Mask))
// Sa
#define ParamLOG_fTy1Weekday6              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday6)) & LOG_fTy1Weekday6Mask))
// So
#define ParamLOG_fTy1Weekday7              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday7)) & LOG_fTy1Weekday7Mask))
// Tag
#define ParamLOG_fTy1Day                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Day)) & LOG_fTy1DayMask) >> LOG_fTy1DayShift)
// Wochentag
#define ParamLOG_fTy1IsWeekday             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1IsWeekday)) & LOG_fTy1IsWeekdayMask))
// Monat
#define ParamLOG_fTy1Month                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Month)) & LOG_fTy1MonthMask) >> LOG_fTy1MonthShift)
// Mo
#define ParamLOG_fTy2Weekday1              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday1)) & LOG_fTy2Weekday1Mask))
// Di
#define ParamLOG_fTy2Weekday2              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday2)) & LOG_fTy2Weekday2Mask))
// Mi
#define ParamLOG_fTy2Weekday3              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday3)) & LOG_fTy2Weekday3Mask))
// Do
#define ParamLOG_fTy2Weekday4              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday4)) & LOG_fTy2Weekday4Mask))
// Fr
#define ParamLOG_fTy2Weekday5              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday5)) & LOG_fTy2Weekday5Mask))
// Sa
#define ParamLOG_fTy2Weekday6              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday6)) & LOG_fTy2Weekday6Mask))
// So
#define ParamLOG_fTy2Weekday7              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday7)) & LOG_fTy2Weekday7Mask))
// Tag
#define ParamLOG_fTy2Day                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Day)) & LOG_fTy2DayMask) >> LOG_fTy2DayShift)
// Wochentag
#define ParamLOG_fTy2IsWeekday             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2IsWeekday)) & LOG_fTy2IsWeekdayMask))
// Monat
#define ParamLOG_fTy2Month                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Month)) & LOG_fTy2MonthMask) >> LOG_fTy2MonthShift)
// Mo
#define ParamLOG_fTy3Weekday1              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday1)) & LOG_fTy3Weekday1Mask))
// Di
#define ParamLOG_fTy3Weekday2              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday2)) & LOG_fTy3Weekday2Mask))
// Mi
#define ParamLOG_fTy3Weekday3              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday3)) & LOG_fTy3Weekday3Mask))
// Do
#define ParamLOG_fTy3Weekday4              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday4)) & LOG_fTy3Weekday4Mask))
// Fr
#define ParamLOG_fTy3Weekday5              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday5)) & LOG_fTy3Weekday5Mask))
// Sa
#define ParamLOG_fTy3Weekday6              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday6)) & LOG_fTy3Weekday6Mask))
// So
#define ParamLOG_fTy3Weekday7              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday7)) & LOG_fTy3Weekday7Mask))
// Tag
#define ParamLOG_fTy3Day                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Day)) & LOG_fTy3DayMask) >> LOG_fTy3DayShift)
// Wochentag
#define ParamLOG_fTy3IsWeekday             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3IsWeekday)) & LOG_fTy3IsWeekdayMask))
// Monat
#define ParamLOG_fTy3Month                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Month)) & LOG_fTy3MonthMask) >> LOG_fTy3MonthShift)
// Mo
#define ParamLOG_fTy4Weekday1              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday1)) & LOG_fTy4Weekday1Mask))
// Di
#define ParamLOG_fTy4Weekday2              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday2)) & LOG_fTy4Weekday2Mask))
// Mi
#define ParamLOG_fTy4Weekday3              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday3)) & LOG_fTy4Weekday3Mask))
// Do
#define ParamLOG_fTy4Weekday4              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday4)) & LOG_fTy4Weekday4Mask))
// Fr
#define ParamLOG_fTy4Weekday5              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday5)) & LOG_fTy4Weekday5Mask))
// Sa
#define ParamLOG_fTy4Weekday6              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday6)) & LOG_fTy4Weekday6Mask))
// So
#define ParamLOG_fTy4Weekday7              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday7)) & LOG_fTy4Weekday7Mask))
// Tag
#define ParamLOG_fTy4Day                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Day)) & LOG_fTy4DayMask) >> LOG_fTy4DayShift)
// Wochentag
#define ParamLOG_fTy4IsWeekday             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4IsWeekday)) & LOG_fTy4IsWeekdayMask))
// Monat
#define ParamLOG_fTy4Month                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Month)) & LOG_fTy4MonthMask) >> LOG_fTy4MonthShift)
// Kanalausgang X
#define ParamLOG_fI1                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1)) & LOG_fI1Mask) >> LOG_fI1Shift)
// Kanalausgang Y
#define ParamLOG_fI2                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fI2)) & LOG_fI2Mask)
// Kanalausgang X als interner Eingang 1, X =
#define ParamLOG_fI1Function               (knx.paramByte(LOG_ParamCalcIndex(LOG_fI1Function)))
// Kanalausgang Y als interner Eingang 2, Y =
#define ParamLOG_fI2Function               (knx.paramByte(LOG_ParamCalcIndex(LOG_fI2Function)))
// Zeitbasis
#define ParamLOG_fOStairtimeBase           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairtimeBase)) & LOG_fOStairtimeBaseMask) >> LOG_fOStairtimeBaseShift)
// Zeit
#define ParamLOG_fOStairtimeTime           (knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime)) & LOG_fOStairtimeTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fOStairtimeTimeMS         (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime))))
// Zeitbasis
#define ParamLOG_fOBlinkBase               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOBlinkBase)) & LOG_fOBlinkBaseMask) >> LOG_fOBlinkBaseShift)
// Zeit
#define ParamLOG_fOBlinkTime               (knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime)) & LOG_fOBlinkTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fOBlinkTimeMS             (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime))))
// Ausgang schaltet zeitverzögert
#define ParamLOG_fODelay                   ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelay)) & LOG_fODelayMask))
// Erneutes EIN führt zu
#define ParamLOG_fODelayOnRepeat           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnRepeat)) & LOG_fODelayOnRepeatMask) >> LOG_fODelayOnRepeatShift)
// Darauffolgendes AUS führt zu
#define ParamLOG_fODelayOnReset            ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnReset)) & LOG_fODelayOnResetMask))
// Erneutes AUS führt zu
#define ParamLOG_fODelayOffRepeat          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffRepeat)) & LOG_fODelayOffRepeatMask) >> LOG_fODelayOffRepeatShift)
// Darauffolgendes EIN führt zu
#define ParamLOG_fODelayOffReset           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffReset)) & LOG_fODelayOffResetMask))
// Zeitbasis
#define ParamLOG_fODelayOnBase             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnBase)) & LOG_fODelayOnBaseMask) >> LOG_fODelayOnBaseShift)
// Zeit
#define ParamLOG_fODelayOnTime             (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime)) & LOG_fODelayOnTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fODelayOnTimeMS           (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime))))
// Zeitbasis
#define ParamLOG_fODelayOffBase            ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffBase)) & LOG_fODelayOffBaseMask) >> LOG_fODelayOffBaseShift)
// Zeit
#define ParamLOG_fODelayOffTime            (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime)) & LOG_fODelayOffTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fODelayOffTimeMS          (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime))))
// Ausgang hat eine Treppenlichtfunktion
#define ParamLOG_fOStair                   ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStair)) & LOG_fOStairMask))
// Treppenlicht kann verlängert werden
#define ParamLOG_fORetrigger               ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORetrigger)) & LOG_fORetriggerMask))
// Treppenlicht kann ausgeschaltet werden
#define ParamLOG_fOStairOff                ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairOff)) & LOG_fOStairOffMask))
// Ausgang wiederholt zyklisch
#define ParamLOG_fORepeat                  ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeat)) & LOG_fORepeatMask))
// Wiederholungsfilter
#define ParamLOG_fOOutputFilter            ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOutputFilter)) & LOG_fOOutputFilterMask) >> LOG_fOOutputFilterShift)
// Zeitbasis
#define ParamLOG_fORepeatOnBase            ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOnBase)) & LOG_fORepeatOnBaseMask) >> LOG_fORepeatOnBaseShift)
// Zeit
#define ParamLOG_fORepeatOnTime            (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime)) & LOG_fORepeatOnTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fORepeatOnTimeMS          (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime))))
// Zeitbasis
#define ParamLOG_fORepeatOffBase           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOffBase)) & LOG_fORepeatOffBaseMask) >> LOG_fORepeatOffBaseShift)
// Zeit
#define ParamLOG_fORepeatOffTime           (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime)) & LOG_fORepeatOffTimeMask)
// Zeit (in Millisekunden)
#define ParamLOG_fORepeatOffTimeMS         (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime))))
// DPT für Ausgang
#define ParamLOG_fODpt                     (knx.paramByte(LOG_ParamCalcIndex(LOG_fODpt)))
// Wert für EIN senden?
#define ParamLOG_fOOn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOn)))
// Wert für EIN senden?
#define ParamLOG_fOOnBuzzer                (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnBuzzer)))
// Wert für EIN senden?
#define ParamLOG_fOOnLed                   (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnLed)))
// Wert für EIN senden?
#define ParamLOG_fOOnAll                   (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnAll)))
//     Wert für EIN senden als
#define ParamLOG_fOOnTone                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnTone)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt1                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt1)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt2                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt2)))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt5                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt5001               (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5001)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt6                  ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt6)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt7                  (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt7)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt8                  ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt8)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt9                  (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt9), Float_Enc_IEEE754Single))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt12                 (knx.paramLong(LOG_ParamCalcIndex(LOG_fOOnDpt12)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt13                 ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fOOnDpt13)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt14                 (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt14), Float_Enc_IEEE754Single))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt16                 (knx.paramData(LOG_ParamCalcIndex(LOG_fOOnDpt16)))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt17                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt17)))
//     Wert für EIN senden als (3-Byte-RGB)
#define ParamLOG_fOOnRGB                   ((knx.paramLong(LOG_ParamCalcIndex(LOG_fOOnRGB)) & LOG_fOOnRGBMask) >> LOG_fOOnRGBShift)
// 
#define ParamLOG_fOOnPAArea                ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPAArea)) & LOG_fOOnPAAreaMask) >> LOG_fOOnPAAreaShift)
// 
#define ParamLOG_fOOnPALine                (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPALine)) & LOG_fOOnPALineMask)
// 
#define ParamLOG_fOOnPADevice              (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPADevice)))
//     Wert für EIN ermitteln als
#define ParamLOG_fOOnFunction              (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnFunction)))
// Wert für AUS senden?
#define ParamLOG_fOOff                     (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOff)))
// Wert für AUS senden?
#define ParamLOG_fOOffBuzzer               (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffBuzzer)))
// Wert für AUS senden?
#define ParamLOG_fOOffLed                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffLed)))
// Wert für AUS senden?
#define ParamLOG_fOOffAll                  (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffAll)))
//     Wert für AUS senden als
#define ParamLOG_fOOffTone                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffTone)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt1                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt1)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt2                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt2)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5001              (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5001)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt6                 ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt6)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt7                 (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt7)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt8                 ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt8)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt9                 (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt9), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt12                (knx.paramLong(LOG_ParamCalcIndex(LOG_fOOffDpt12)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt13                ((int32_t)knx.paramLong(LOG_ParamCalcIndex(LOG_fOOffDpt13)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt14                (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt14), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt16                (knx.paramData(LOG_ParamCalcIndex(LOG_fOOffDpt16)))
//     Wert für AUS senden als 
#define ParamLOG_fOOffDpt17                (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt17)))
//     Wert für AUS senden als (3-Byte-RGB)
#define ParamLOG_fOOffRGB                  ((knx.paramLong(LOG_ParamCalcIndex(LOG_fOOffRGB)) & LOG_fOOffRGBMask) >> LOG_fOOffRGBShift)
// 
#define ParamLOG_fOOffPAArea               ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPAArea)) & LOG_fOOffPAAreaMask) >> LOG_fOOffPAAreaShift)
// 
#define ParamLOG_fOOffPALine               (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPALine)) & LOG_fOOffPALineMask)
// 
#define ParamLOG_fOOffPADevice             (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPADevice)))
//     Wert für AUS ermitteln als
#define ParamLOG_fOOffFunction             (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffFunction)))
// Kommunikationsobjekt für Eingang 1
#define ParamLOG_fE1UseOtherKO             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1UseOtherKO)) & LOG_fE1UseOtherKOMask))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE1OtherKO                (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1OtherKO)) & LOG_fE1OtherKOMask)
// Kommunikationsobjekt für Eingang 2
#define ParamLOG_fE2UseOtherKO             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2UseOtherKO)) & LOG_fE2UseOtherKOMask))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE2OtherKO                (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2OtherKO)) & LOG_fE2OtherKOMask)

// deprecated
#define LOG_KoOffset 125

// Communication objects per channel (multiple occurrence)
#define LOG_KoBlockOffset 125
#define LOG_KoBlockSize 3

#define LOG_KoCalcNumber(index) (index + LOG_KoBlockOffset + _channelIndex * LOG_KoBlockSize)
#define LOG_KoCalcIndex(number) (((number - LOG_KoBlockOffset) >= 0) ? (number - LOG_KoOffset) % LOG_KoBlockSize : -1)

#define LOG_KoKOfE1 0
#define LOG_KoKOfE2 1
#define LOG_KoKOfO 2

// Eingang 1
#define KoLOG_KOfE1                     (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE1)))
// Eingang 2
#define KoLOG_KOfE2                     (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE2)))
// Ausgang
#define KoLOG_KOfO                      (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfO)))

#define WIRE_ChannelCount 30

// Parameter per channel
#define WIRE_ParamBlockOffset 7001
#define WIRE_ParamBlockSize 18
#define WIRE_ParamCalcIndex(index) (index + WIRE_ParamBlockOffset + _channelIndex * WIRE_ParamBlockSize)

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
#define WIRE_sSensorDelayBase          10      // 2 Bits, Bit 7-6
#define     WIRE_sSensorDelayBaseMask 0xC0
#define     WIRE_sSensorDelayBaseShift 6
#define WIRE_sSensorDelayTime          10      // 14 Bits, Bit 13-0
#define     WIRE_sSensorDelayTimeMask 0x3FFF
#define     WIRE_sSensorDelayTimeShift 0
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

// Geräte-Id
#define ParamWIRE_sDeviceId                 (knx.paramData(WIRE_ParamCalcIndex(WIRE_sDeviceId)))
// Familienkode
#define ParamWIRE_sFamilyCode               (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sFamilyCode)))
// 
#define ParamWIRE_sId0                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId0)) & WIRE_sId0Mask) >> WIRE_sId0Shift)
// 
#define ParamWIRE_sId1                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId1)) & WIRE_sId1Mask)
// 
#define ParamWIRE_sId2                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId2)) & WIRE_sId2Mask) >> WIRE_sId2Shift)
// 
#define ParamWIRE_sId3                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId3)) & WIRE_sId3Mask)
// 
#define ParamWIRE_sId4                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId4)) & WIRE_sId4Mask) >> WIRE_sId4Shift)
// 
#define ParamWIRE_sId5                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId5)) & WIRE_sId5Mask)
// 
#define ParamWIRE_sId6                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId6)) & WIRE_sId6Mask) >> WIRE_sId6Shift)
// 
#define ParamWIRE_sId7                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId7)) & WIRE_sId7Mask)
// 
#define ParamWIRE_sId8                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId8)) & WIRE_sId8Mask) >> WIRE_sId8Shift)
// 
#define ParamWIRE_sId9                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId9)) & WIRE_sId9Mask)
// 
#define ParamWIRE_sIdA                      ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIdA)) & WIRE_sIdAMask) >> WIRE_sIdAShift)
// 
#define ParamWIRE_sIdB                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIdB)) & WIRE_sIdBMask)
// Modellfunktion
#define ParamWIRE_sModelFunction            (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunction)))
// Sensorgenauigkeit
#define ParamWIRE_sModelFunctionDS18B20     (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS18B20)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2408      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2408)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2413      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2413)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2438      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2438)))
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect1         ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect1)) & WIRE_sBusMasterSelect1Mask) >> WIRE_sBusMasterSelect1Shift)
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect2         ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect2)) & WIRE_sBusMasterSelect2Mask) >> WIRE_sBusMasterSelect2Shift)
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect3         ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect3)) & WIRE_sBusMasterSelect3Mask) >> WIRE_sBusMasterSelect3Shift)
// Sensorwert anpassen
#define ParamWIRE_sSensorOffset             ((int8_t)knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorOffset)))
// Zeitbasis
#define ParamWIRE_sSensorDelayBase          ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorDelayBase)) & WIRE_sSensorDelayBaseMask) >> WIRE_sSensorDelayBaseShift)
// Zeit
#define ParamWIRE_sSensorDelayTime          (knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDelayTime)) & WIRE_sSensorDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamWIRE_sSensorDelayTimeMS        (paramDelay(knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDelayTime))))
// Bei absoluter Abweichung senden(0=nicht senden)
#define ParamWIRE_sSensorDeltaAbs           (knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDeltaAbs)))
// Bei Abweichung vom vorherigen Wert senden(0=nicht senden)
#define ParamWIRE_sSensorDeltaPercent       (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorDeltaPercent)))
// Sensorwert glätten: P =
#define ParamWIRE_sSensorSmooth             (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorSmooth)))
// Nach Neustart Zustand auf den Bus senden (auch für alle beteiligten Gruppen)?
#define ParamWIRE_siButtonSendStatus        ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_siButtonSendStatus)) & WIRE_siButtonSendStatusMask))
// Gruppe 1
#define ParamWIRE_sGroup1                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup1)) & WIRE_sGroup1Mask))
// Gruppe 2
#define ParamWIRE_sGroup2                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup2)) & WIRE_sGroup2Mask))
// Gruppe 3
#define ParamWIRE_sGroup3                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup3)) & WIRE_sGroup3Mask))
// Gruppe 4
#define ParamWIRE_sGroup4                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup4)) & WIRE_sGroup4Mask))
// Gruppe 5
#define ParamWIRE_sGroup5                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup5)) & WIRE_sGroup5Mask))
// Gruppe 6
#define ParamWIRE_sGroup6                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup6)) & WIRE_sGroup6Mask))
// Gruppe 7
#define ParamWIRE_sGroup7                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup7)) & WIRE_sGroup7Mask))
// Gruppe 8
#define ParamWIRE_sGroup8                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup8)) & WIRE_sGroup8Mask))
// Eingänge: Nach Neustart Zustand auf den Bus senden?
#define ParamWIRE_sIOSendStatus             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIOSendStatus)) & WIRE_sIOSendStatusMask))
// Ausgänge: Nach Neustart Wert vom Bus lesen und Ausgang passend setzen?
#define ParamWIRE_sIOReadRequest            ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIOReadRequest)) & WIRE_sIOReadRequestMask))
// 
#define ParamWIRE_sIoBitmask0               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask0)) & WIRE_sIoBitmask0Mask))
// 
#define ParamWIRE_sIoBitmask1               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask1)) & WIRE_sIoBitmask1Mask))
// 
#define ParamWIRE_sIoBitmask2               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask2)) & WIRE_sIoBitmask2Mask))
// 
#define ParamWIRE_sIoBitmask3               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask3)) & WIRE_sIoBitmask3Mask))
// 
#define ParamWIRE_sIoBitmask4               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask4)) & WIRE_sIoBitmask4Mask))
// 
#define ParamWIRE_sIoBitmask5               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask5)) & WIRE_sIoBitmask5Mask))
// 
#define ParamWIRE_sIoBitmask6               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask6)) & WIRE_sIoBitmask6Mask))
// 
#define ParamWIRE_sIoBitmask7               ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask7)) & WIRE_sIoBitmask7Mask))
// 
#define ParamWIRE_sIoInvertBitmask0         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask0)) & WIRE_sIoInvertBitmask0Mask))
// 
#define ParamWIRE_sIoInvertBitmask1         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask1)) & WIRE_sIoInvertBitmask1Mask))
// 
#define ParamWIRE_sIoInvertBitmask2         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask2)) & WIRE_sIoInvertBitmask2Mask))
// 
#define ParamWIRE_sIoInvertBitmask3         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask3)) & WIRE_sIoInvertBitmask3Mask))
// 
#define ParamWIRE_sIoInvertBitmask4         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask4)) & WIRE_sIoInvertBitmask4Mask))
// 
#define ParamWIRE_sIoInvertBitmask5         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask5)) & WIRE_sIoInvertBitmask5Mask))
// 
#define ParamWIRE_sIoInvertBitmask6         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask6)) & WIRE_sIoInvertBitmask6Mask))
// 
#define ParamWIRE_sIoInvertBitmask7         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask7)) & WIRE_sIoInvertBitmask7Mask))

// deprecated
#define WIRE_KoOffset 90

// Communication objects per channel (multiple occurrence)
#define WIRE_KoBlockOffset 90
#define WIRE_KoBlockSize 1

#define WIRE_KoCalcNumber(index) (index + WIRE_KoBlockOffset + _channelIndex * WIRE_KoBlockSize)
#define WIRE_KoCalcIndex(number) (((number - WIRE_KoBlockOffset) >= 0) ? (number - WIRE_KoOffset) % WIRE_KoBlockSize : -1)

#define WIRE_KoKOs 0

// Dynamic
#define KoWIRE_KOs                       (knx.getGroupObject(WIRE_KoCalcNumber(WIRE_KoKOs)))

#define MAIN_OpenKnxId 0xA0
#define MAIN_ApplicationNumber 17
#define MAIN_ApplicationVersion 6
#define MAIN_OrderNumber "OpenKnxSensorDev"
