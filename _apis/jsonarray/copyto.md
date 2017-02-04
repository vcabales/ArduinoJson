---
title: JsonArray::copyTo()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Extracts a C array from the `JsonArray`.

##### Signatures

```c++
JsonArray::copyTo(int array[]);
JsonArray::copyTo(double array[]);
JsonArray::copyTo(const char* array[]);
```

##### Return value

A `size_t` containing the number of values written in the array.

##### Example

```c++
int values[3];

StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("[1,2,3]");
array.copyTo(values);
```

now `values` contais `1`, `2` and `3`.
