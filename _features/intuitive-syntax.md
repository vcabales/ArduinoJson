---
title: Intuitive Syntax
popularity: 80
---

ArduinoJson has a simple and intuitive syntax to handle object and arrays.

```c++
JsonObject& root = jsonBuffer.parseObject(myJson);

const char* city = root["city"];
double temp = root["weather"]["temp"];
```