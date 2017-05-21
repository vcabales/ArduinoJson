---
title: JsonArray::set()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Sets the value at specified index.

##### Signatures

```c++
bool set(size_t index, bool value);
bool set(size_t index, const char *value);
bool set(size_t index, const JsonVariant &value);
bool set(size_t index, const std::string &value); // see Remarks
bool set(size_t index, const String &value); // see Remarks
bool set(size_t index, double value);
bool set(size_t index, float value);
bool set(size_t index, JsonArray &array);
bool set(size_t index, JsonObject &object);
bool set(size_t index, signed char value);
bool set(size_t index, signed int value);
bool set(size_t index, signed long value);
bool set(size_t index, signed short value);
bool set(size_t index, unsigned char value);
bool set(size_t index, unsigned int value);
bool set(size_t index, unsigned long value);
bool set(size_t index, unsigned short value);
```

##### Arguments

`index`: position to set value in array.

`value`: the value to set in index of array.

##### Return value

`true` if allocation succeeded.

`false` if there was not enough space left in the `JsonBuffer`, this can only happen when `value` is a `String`.

##### Remarks

When you call `set(size_t, const String&)` or `set(size_t, const std::string&)`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use `set(size_t, const char*)` instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.set(0,"hello");
array.add(1,3.14156, 4);
array.printTo(Serial); // [3.1416]
```
