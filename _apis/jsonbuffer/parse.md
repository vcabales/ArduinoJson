---
title: JsonBuffer::parse()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description
Parses a JSON input and returns a `JsonVariant` which can contain an array or an object.

Use this function when you cannot know the type of input at compile-time; otherwise prefer [`JsonBuffer::parseArray()`]({{site.baseurl}}/api/jsonbuffer/parsearray/) and [`JsonBuffer::parseObject()`]({{site.baseurl}}/api/jsonbuffer/parseobject/).

By design, the parser needs to alter the string to insert null-terminators and replace escaped chars.
If the JSON string is read-only, it will have to duplicate the input string, this consume more space in the `JsonBuffer`.
Therefore, it's recommended to have a JSON input in a `char[]` or a `char*`.

##### Signatures
```c++
// The first overload, which accepts a modifiable array of chars, is the most efficient
// since it allows the zero-copy feature.
JsonVariant parse(char* json, uint8_t nestingLimit=10);

// The three following overloads, which accept read-only strings, require a bigger JsonBuffer
// because parts of the JSON input has to be copied.
JsonVariant parse(const char* json, uint8_t nestingLimit=10);
JsonVariant parse(const String& json, uint8_t nestingLimit=10);
JsonVariant parse(const std::string& json, uint8_t nestingLimit=10);

// The two last overloads, which accept input streams, make copy of the input too.
JsonVariant parse(Stream& json, uint8_t nestingLimit=10);
JsonVariant parse(std::istream& json, uint8_t nestingLimit=10);
```

##### Arguments

`json` is the input string to be parsed.

`nestingLimit` specifies the maximum level of nesting allowed in the JSON string.
If set to `0`, only a flat array or object can be parsed.
If set to `1`, the array or object can contain nested arrays or objects but only 1 level deep.
And bigger values will allow more level of nesting.
The purpose of this feature is to prevent stack overflow that could lead to a security risk.

##### Return value
Returns a `JsonVariant` which contains a reference `JsonArray` or to a `JsonObject`.

Use [`JsonVariant::is<T>()`]({{site.baseurl}}/api/jsonvariant/is/) to check the type of the value.

##### Example

```c++
char json[] = "[\"hello\",\"world\"]";

StaticJsonBuffer<200> jsonBuffer;
JsonVariant variant = jsonBuffer.parse(json);

if (variant.is<JsonArray>()) // true in this example
{
    JsonArray& array = variant;
    const char* hello = array[0];
    const char* world = array[1];

}
```
