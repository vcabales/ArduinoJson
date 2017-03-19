---
title: Compatible with Flash Strings
popularity: 50
---

ArduinoJson works directly with strings stored in program memory (<code>PROGMEM</code>)

```c++
// You can use a Flash String as JSON input
JsonObject& root = jsonBuffer.parseObject(F("{\"city\":\"Paris\",\"temp\":18.5}"));

// ...as a value
root["cond"] = F("Sunny");

// ...or as a key
float temp = root["temp"];
```