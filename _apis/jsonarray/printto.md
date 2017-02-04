---
title: JsonArray::printTo()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Serialize the array to a JSON string.

This will create a compact JSON, if you want a pretty JSON with spaces and line breaks, use `JsonArray::prettyPrint()`

##### Signatures

```c++
size_t printTo(char* buffer, size_t size) const;
size_t printTo(char buffer[size]) const;
size_t printTo(Print &) const;
size_t printTo(String &) const;
size_t printTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add("world");
array.printTo(Serial);
```

will write the following string to the serial output:

```json
["hello","world"]
```
