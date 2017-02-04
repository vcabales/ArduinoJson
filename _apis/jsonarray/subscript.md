---
title: JsonArray::operator[]
layout: api
tags: api
api-group: JsonArray
---

##### Description

A shortcut for `JsonArray::get()` and `JsonArray::set()`, with an array-like syntax.

##### Signatures

```c++
JsonVariant& operator[](size_t index);
const JsonVariant& operator[](size_t index) const;
```

##### Arguments

`index`: the zero-based position of the value in the array.

##### Return value

A reference to the `JsonVariant` in the array.

##### Example

```c++
JsonArray& array = jsonBuffer::createArray();
array.add(42);
int value = array[0];
array[0] = 666;
```
