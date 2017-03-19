---
title: Serialize and Deserialize
popularity: 100
---

ArduinoJson supports both JSON serialization and deserialization.

```c++
// read JSON
JsonObject& root = jsonBuffer.parseObject(myInput);

// modify
root["last_modification"] = time();

// write JSON
root.printTo(myOutput)
```