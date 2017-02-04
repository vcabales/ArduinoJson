---
title: JsonArray::success()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Tells if the array is valid, which can be used:

1. to check if the array was successfully parsed, or
2. to check if the array was successfully allocated.

##### Signatures

```c++
bool success() const;
```

##### Return value

`true` if the array was successfully parsed/allocated.
`false` if the parsing/allocation failed.

##### Examples

Example 1: parsing success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("[1,2]");
Serial.println(array.success()); // true
```

Example 2: parsing failure:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("{1,2}");
Serial.println(array.success()); // false
```

Example 3: allocation success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
Serial.println(array.success()); // true
```

Example 4: allocation failure:

```c++
StaticJsonBuffer<1> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
Serial.println(array.success()); // false
```
