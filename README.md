OAM-SensorModule
===

Implementation of an knx sensor application, which combines some [OpenKNX-Projects](https://github.com/OpenKNX) to provide an ETS programmable device. It allows a parametrization via ETS in general, this project requires ETS 5.7 or higher.

It is implemented for the SAMD21 and RP2040 version of the [knx stack](https://github.com/thelsing/knx). 

It is a PlatformIO project and needs a working ETS 5.7 (or higher) installed on the same PC.

This uses the following OpenKNX-projects:

* [OAM-OneWireModule](https://github.com/OpenKNX/OAM-OneWireModule)
* [OAM-PresenceModule](https://github.com/OpenKNX/OAM-PresenceModule)
* [OAM-LogicModule](https://github.com/OpenKNX/OAM-LogicModule)
* [OFM-SensorModule](https://github.com/OpenKNX/OGM-SensorModule)
* [OGM-SensorDevices](https://github.com/OpenKNX/OGM-SensorDevices)
* [OGM-Common](https://github.com/OpenKNX/OGM-Common)
* [knx](https://github.com/thelsing/knx)

For more information look into our [OpenKNX-wiki](https://github.com/OpenKNX/OpenKNX/wiki).

There are application descriptions available:

* [Application Sensor](https://github.com/OpenKNX/OAM-SensorModule/blob/main/doc/Applikationsbeschreibung-Sensor.md) describes features of the sensor part of application and firmware (in German).
* [Application Presence](https://github.com/OpenKNX/OAM-PresenceModule/blob/main/doc/Applikationsbeschreibung-Presence.md) describes features of the Presence functionality of application and firmware (in German).
* [Application WireGateway](https://github.com/OpenKNX/OAM-OneWireModule/blob/main/doc/Applikationsbeschreibung-Wire.md) describes features of the one wire part of application and firmware (in German).
* [Application Logic](https://github.com/OpenKNX/OAM-LogicModule/blob/main/doc/Applikationsbeschreibung-Logik.md) describes features of the logic part of application and firmware (in German).

Thanks to all, who made this project successful.
