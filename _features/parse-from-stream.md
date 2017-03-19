---
title: Parse From Stream
popularity: 60
---

ArduinoJson is able to parse directly from an input <code>Stream</code> or <code>std::istream</code>

Parse input from the serial port:

```c++
JsonObject& root = jsonBuffer.parse(Serial);
```

...an Ethernet connection

```c++
JsonObject& root = jsonBuffer.parse(ethernetClient);
```

...or a Wifi connection

```c++
JsonObject& root = jsonBuffer.parse(wifiClient);
```