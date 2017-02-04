---
title: JsonArray::add()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Adds a value to the end of the array.

##### Signatures

```c++
bool add(bool value);
bool add(float value, uint8_t decimals = 2);
bool add(double value, uint8_t decimals = 2);
bool add(signed char value);
bool add(signed long value);
bool add(signed int value);
bool add(signed short value);
bool add(unsigned char value);
bool add(unsigned long value);
bool add(unsigned int value);
bool add(unsigned short value);
bool add(const char *value);
bool add(const String &value); // see Remarks
bool add(const std::string &value); // see Remarks
bool add(JsonArray &array);
bool add(JsonObject &object);
bool add(const JsonVariant &variant);
```

##### Arguments

`value`: the value to add to the array.

`decimals`: the number of digits to print after the decimal point.

##### Return value

`true` if the value was successfully added.

`false` if there was not enough memory in the `JsonBuffer`.

##### Remarks

When you call `add(const String&)` or `add(const std::string&)`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use `add(const char*)` instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add(3.14156, 4);
array.printTo(Serial);
```

will write

```json
["hello",3.1416]
```
