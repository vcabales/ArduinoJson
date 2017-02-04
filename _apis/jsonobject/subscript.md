---
title: JsonObject::operator[]
layout: api
tags: api
api-group: JsonObject
---

##### Description

A shortcut for `JsonObject::get()` and `JsonObject::set()`, with a map-like syntax.

##### Signatures

```c++
JsonVariant& operator[](const char* key);
JsonVariant& operator[](const String& key);
JsonVariant& operator[](const std::string& key);
const JsonVariant& operator[](const char* key) const;
const JsonVariant& operator[](const String& key) const;
const JsonVariant& operator[](const std::string& key) const;
```

##### Arguments

`key`: the key that the value will be associated to.

##### Return value

A reference to the `JsonVariant` in the object.

##### Remarks

When you add a value using a `String` or an `std::string` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Example

```c++
JsonObject& object = jsonBuffer::createObject();
object["hello"] = "world";
const char* world = object["hello"];
```
