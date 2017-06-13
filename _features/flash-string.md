---
title: Compatible with Flash Strings
popularity: 50
---

ArduinoJson works directly with strings stored in program memory (<code>PROGMEM</code>)

You can use a Flash String as JSON input

```c++
JsonObject& root = jsonBuffer.parseObject(F("{\"city\":\"Paris\",\"temp\":18.5}"));
```

...as a value

```c++
root["cond"] = F("Sunny");
```

...or as a key

```c++
float temp = root[F("temp")];
```
