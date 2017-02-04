---
title: JsonObject::success()
layout: api
tags: api
api-group: JsonObject
---

##### Description

Tells if the object is valid, which can be used:

1. to check if the object was successfully parsed, or
2. to check if the object was successfully allocated.

##### Signatures

```c++
bool success() const;
```

##### Return value

`true` if the object was successfully parsed/allocated.
`false` if the parsing/allocation failed.

##### Examples

Example 1: parsing success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject("{\"hello\":\"world\"}");
Serial.println(object.success()); // true
```

Example 2: parsing failure:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject("[\"hello\",\"world\"]");
Serial.println(object.success()); // false
```

Example 3: allocation success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
Serial.println(object.success()); // true
```

Example 4: allocation failure:

```c++
StaticJsonBuffer<1> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
Serial.println(object.success()); // false
```
