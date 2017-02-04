---
title: JsonBuffer::parseObject()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description
Allocates and populate a JsonObject from a JSON string.

By design, the parser needs to alter the string to insert null-terminators and replace escaped chars.
If the JSON string is read-only, it will have to duplicate the input string, this consume more space in the `JsonBuffer`.
Therefore, it's recommended to have a JSON input in a `char[]` or a `char*`.

##### Signatures
```c++
// The first overload, which accepts a modifiable array of chars, is the most efficient
// since it allows the zero-copy feature.
JsonObject& parseObject(char* json, uint8_t nestingLimit=10);

// The three following overloads, which accept read-only strings, require a bigger JsonBuffer
// because parts of the JSON input has to be copied.
JsonObject& parseObject(const char* json, uint8_t nestingLimit=10);
JsonObject& parseObject(const String& json, uint8_t nestingLimit=10);
JsonObject& parseObject(const std::string& json, uint8_t nestingLimit=10);

// The two last overloads, which accept input streams, make copy of the input too.
JsonObject& parseObject(Stream& json, uint8_t nestingLimit=10);
JsonObject& parseObject(std::istream& json, uint8_t nestingLimit=10);
```

##### Arguments

`json` is the input string to be parsed.

`nestingLimit` specifies the maximum level of nesting allowed in the JSON string.
If set to `0`, only a flat object can be parsed.
If set to `1`, the object can contain nested objects or objects but only 1 level deep.
And bigger values will allow more level of nesting.
The purpose of this feature is to prevent stack overflow that could lead to a security risk.

##### Return value
Returns a reference to the new JsonObject or JsonObject::invalid() if the allocation fails.

##### Example

```c++
char json[] = "{\"hello\":\"world\"}";
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject(json);
const char* world = object["hello"];
```
