---
title: JsonObject::createNestedObject()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Creates a `JsonObject` as a child of the current object.

##### Signature

```c++
JsonObject& createNestedObject(const char* key) const;
JsonObject& createNestedObject(const String& key) const; // <- duplicates key
JsonObject& createNestedObject(const std::string& key) const; // <- duplicates key
```

##### Arguments

`key`: the key of the object in the object, can be a `const char*` or a `const String&`

##### Remarks

When you add a value using a `String` or a `std::string` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Return value

A reference to the new `JsonObject`.
You can check `JsonObject::success()` to verify that the allocatio succeeded.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["city"] = "Paris";
JsonObject& weather = root.createNestedObject("weather");
weather["temp"] = 14.2;
weather["cond"] = "cloudy";
root.prettyPrintTo(Serial);
```

will print

```json
{
  "city": "Paris",
  "weather": {
    "temp": 14.20,
    "cond": "cloudy"
  }
}
```
