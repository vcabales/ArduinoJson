---
title: JsonObject::prettyPrintTo()
layout: api
tags: api
api-group: JsonObject
---

##### Description

Serialize the object to an indented JSON string.

This will create a "prettified" JSON, if you want a compact JSON without space or line break, use `JsonObject::print()`

##### Signatures

```c++
size_t prettyPrintTo(char* buffer, size_t size) const;
size_t prettyPrintTo(char buffer[size]) const;
size_t prettyPrintTo(Print &) const;
size_t prettyPrintTo(String &) const;
size_t prettyPrintTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or an `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
object.prettyPrintTo(Serial);
```

will write the following string to the serial output:

```json
{
  "hello": "world"
}
```
