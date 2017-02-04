---
title: JsonArray::createNestedObject()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Adds a new nested object to the end of the array.

##### Signature

```c++
JsonObject& createNestedObject();
```

##### Return value

A reference to the new `JsonObject`.
You can check `JsonObject::success()` to verify that the allocation succeeded.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
JsonObject& nested = array.createNestedObject();
nested["hello"] = "world";
array.printTo(Serial);
```

will write

```json
[{"hello":"world"}]
```
