---
title: Serialize and Deserialize
popularity: 100
---

ArduinoJson supports both JSON serialization and deserialization.

Read JSON:

```c++
JsonObject& root = jsonBuffer.parseObject(myInput);
```

...modify:

```c++
root["last_modification"] = time();
```

...write back:

```c++
root.printTo(myOutput)
```