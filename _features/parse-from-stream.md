---
title: Parse From Stream
popularity: 60
---

ArduinoJson is able to parse directly from an input <code>Stream</code> or <code>std::istream</code>

```c++
// parse input from the serial port
JsonObject& root = jsonBuffer.parse(Serial);

// ...an Ethernet connection
JsonObject& root = jsonBuffer.parse(ethernetClient);

// ...or a Wifi connection
JsonObject& root = jsonBuffer.parse(wifiClient);
```