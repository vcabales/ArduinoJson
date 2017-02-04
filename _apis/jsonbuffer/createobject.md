---
title: JsonBuffer::createObject()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description
Allocates an empty JsonObject.

##### Signature
```c++
JsonObject createObject();
```
##### Return value
Returns a reference to the new JsonObject or JsonObject::invalid() if the allocation fails.
##### Example
```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
```
