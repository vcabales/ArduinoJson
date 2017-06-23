---
title: JsonObject::remove()
layout: api
tags: api
api-group: JsonObject
---

##### Description

Removes the element at the specified key.

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

> ##### Causes memory leaks :warning:
>
> This function doesn't free the memory allocated to the element in the `JsonBuffer`.
>
> This is a conscious design decision made to keep the `JsonBuffer` fast and small, which is a fundamental principle of the library.
>
> As a consequence, you cannot remove and add elements in a loop, otherwise the `JsonBuffer` will overflow.
>
> Don't try to keep the state of your application in a `JsonObject`, instead use custom structures.
{: .alert .alert-danger}