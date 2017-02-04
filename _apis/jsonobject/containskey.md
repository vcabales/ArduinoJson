---
title: JsonObject::containsKey()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Tests if a key exists in the `JsonObject`.

##### Signature

```c++
bool containsKey(const char* key) const;
bool containsKey(const String& key) const;
bool containsKey(const std::string& key) const;
```

##### Arguments

`key`: the key to test.

##### Return value

`true` if the key is present is the `JsonObject`; `false` if not.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["city"] = "Paris";

bool hasCity = root.containsKey("city"); // true
bool hasCountry = root.containsKey("country"); // false
```
