---
title: JsonObject::remove()
layout: api
tags: api
api-group: JsonObject
---

##### Description

Removes the element at the specified key.

**IMPORTANT**: This function doesn't free the memory allocated to the element in the `JsonBuffer`. This behavior has been prefered to keep the `JsonBuffer` fast and small, which is a foundational principle of the library.

##### Signatures

```c++
void remove(const char* key);
void remove(const String& key);
void remove(const std::string& key);
```

##### Arguments

`key`: the key to remove from the object.

##### Example

```c++
JsonObject& object = jsonBuffer.createObject();
object["A"] = 1;
object["B"] = 2;
object["C"] = 3;
object.remove("B");
object.printTo(Serial);
```

will print the following string to the serial output:

```json
{"A":1,"C":3}
```
