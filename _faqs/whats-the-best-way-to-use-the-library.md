---
title: What's the best way to use the library?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 425
---

Here is the canonical example for serializing and deserializing with ArduinoJson.

By following this example, you are making the best usage of your memory and you maintain a good software design.

```c++
struct SensorData {
   const char* name;
   int time;
   float value;
};

#define SENSORDATA_JSON_SIZE (JSON_OBJECT_SIZE(3))

bool deserialize(SensorData& data, char* json)
{
    StaticJsonBuffer<SENSORDATA_JSON_SIZE> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(json);
    data.name = root["name"];
    data.time = root["time"];
    data.value = root["value"];
    return root.success();
}

void serialize(const SensorData& data, char* json, size_t maxSize)
{
    StaticJsonBuffer<SENSORDATA_JSON_SIZE> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["name"] = data.name;
    root["time"] = data.time;
    root["value"] = data.value;
    root.printTo(json, maxSize);
}
```

As you can see the `StaticJsonBuffer` is kept in memory as short as possible, so that the remain of your program is unaffected by the JSON serialization.

Also you can see that neither `JsonArray` nor `JsonObject` leak out of the serialization code. This maintain a good isolation and reduce the coupling with the library.
