---
title: JsonObject::set()
layout: api
tags: api
api-group: JsonObject
---

##### Description

Sets the value at specified key.

##### Signatures

```c++
bool set(TString key, bool value);
bool set(TString key, float value);
bool set(TString key, double value);
bool set(TString key, signed char value);
bool set(TString key, signed long value);
bool set(TString key, signed int value);
bool set(TString key, signed short value);
bool set(TString key, unsigned char value);
bool set(TString key, unsigned long value);
bool set(TString key, unsigned int value);
bool set(TString key, unsigned short value);
bool set(TString key, const char *value);
bool set(TString key, const String &value); // see Remarks
bool set(TString key, JsonArray &array);
bool set(TString key, JsonObject &object);
bool set(TString key, const JsonVariant &value);
```

##### Arguments

`key`: the key to attach the value to, can be a `const char*`, a `String` or an `std::string`.

`value`: the value to attach to the key.

##### Return value

`true` if allocation succeeded.

`false` if there was not enough space left in the `JsonBuffer`.

##### Remarks

When you use a `String` or an `std::string`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
This is true for both `key` and `value`.
To avoid this behavior, use `const char*` keys and values instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object.set("hello","world");
object.printTo(Serial);
```

will print the following string to the serial output:

```json
{"hello":"world"}
```
