# TMP102ArduinoShield

Equipment
-------------------------

- Arduino Uno
- Shield Ethernet C3 PKA04'2
- TMP102 Digital I2C (RED)
- Simple Switch
- 2 Ethernet cable


Introduction
-------------------------
This script receives the temperature of the sensor, and the return via http to the server.
For the recovery part in MYSQL. A simple PHP page with your SQL query along with the GET variable will do.


Details
-------------------------
- Please replace my values with those of your environment
- If you use WAMP server 3. See insert <Require all granted> in the file httpd-vhosts.conf. Otherwise you will have 403 errors with the arduino.
- You need to download the UIPEthernet lib. This is compatible with my shield. If you are using another Shield, the ethernet.h lib may be the one to use for you.

