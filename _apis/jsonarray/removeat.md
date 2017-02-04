---
title: JsonArray::removeAt()
layout: api
tags: api
api-group: JsonArray
---

##### Description

Removes the element at the specified index.

**IMPORTANT**: This function doesn't free the memory allocated to the element in the `JsonBuffer`. This behavior has been prefered to keep the `JsonBuffer` fast and small, which is a foundational principle of the library.

##### Signature

```c++
void removeAt(size_t index);
```

##### Arguments

`index`: the zero-based position of the element in the array.

##### Example

```c++
JsonArray& array = jsonBuffer.createArray();
array.add("A");
array.add("B");
array.add("C");
array.removeAt(1);
array.printTo(Serial);
```

will print the following string to the serial output:

```json
["A","C"]
```
