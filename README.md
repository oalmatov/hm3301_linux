# hm3301_linux

This is a C++ class designed to control the hm3301 sensor.

This has been tested with Raspberry Pi 3.

Repository Contents
--------------------

* **/examples** - Example for the library and Makefile. 
* **/src** - Source files for the library (.cpp, .h).
* **/library.properties** - General library properties for the package manager.

Methods
--------------------

* **readData()** - Read sensor data.
* **spm010()** - Outputs PM1.0 concentration (CF=1,Standard particulate matter, unit:ug/m3)
* **spm025()** - Outputs PM2.5 concentration (CF=1,Standard particulate matter, unit:ug/m3)
* **spm100()** - Outputs PM10.0 concentration (CF=1,Standard particulate matter, unit:ug/m3)
* **apm010()** - Outputs PM1.0 concentration (Atmospheric environment, unit:ug/m3)
* **apm025()** - Outputs PM2.5 concentration (Atmospheric environment, unit:ug/m3)
* **apm100()** - Outputs PM10.0 concentration (Atmospheric environment, unit:ug/m3)


