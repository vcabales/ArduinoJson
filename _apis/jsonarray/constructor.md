---
title: JsonArray constructor
layout: api
tags: api
api-group: JsonArray
---

The constructor is private, you cannot instantiate a `JsonArray` directly, you have to use a `JsonBuffer`.

Because the memory of a `JsonArray` is located a `JsonBuffer`, you always manipulate it through reference and you cannot copy it.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;

// create an empty array
JsonArray& array1 = jsonBuffer.createArray();

// parse a JSON array
char json[] = "[1,2,3]";
JsonArray& array2 = jsonBuffer.parseArray(json);
```
