---
title: JsonObject::createNestedArray()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Creates a `JsonArray` as a child of the current object.

##### Signatures

```c++
JsonArray& createNestedArray(const char* key) const;
JsonArray& createNestedArray(const String& key) const; // <- duplicates key
```

##### Arguments

`key`: the key of the array in the object, can be a `const char*` or a `const String&`

##### Remarks

When you add a value using a `String` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Return value

A reference to the new `JsonArray`.
You can check `JsonArray::success()` to verify that the allocatio succeeded.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["status"] = "on";
JsonArray& levels = root.createNestedArray("levels");
levels.add(10);
levels.add(30);
root.prettyPrintTo(Serial);
```

will print

```json
{
  "status": "on",
  "levels": [
    10,
    20
  ]
}
```
