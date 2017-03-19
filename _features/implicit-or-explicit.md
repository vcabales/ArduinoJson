---
title: Implicit or Explict Casts
popularity: 70
---

ArduinoJson supports two coding styles, with implicit or explicit casts

Implicit cast:

```c++
const char* city = root["city"];
float temp = root["temperature"];
```

Explicit cast:

```c++
auto city = root["city"].as<const char*>();
auto temp = root["temperature"].as<float>();
```