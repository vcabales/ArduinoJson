---
title: JsonArray::remove()
layout: api
tags: api
api-group: JsonArray
redirect_from: /api/jsonarray/removeat/
---

##### Description

Removes the element at the specified index.

##### Signature

```c++
void remove(size_t index);
```

##### Arguments

`index`: the zero-based position of the element in the array.

##### Example

```c++
JsonArray& array = jsonBuffer.createArray();
array.add("A");
array.add("B");
array.add("C");
array.remove(1);
array.printTo(Serial);
```

will print the following string to the serial output:

```json
["A","C"]
```

> ##### Causes memory leaks :warning:
>
> This function doesn't free the memory allocated to the element in the `JsonBuffer`.
>
> This is a conscious design decision made to keep the `JsonBuffer` fast and small, which is a fundamental principle of the library.
>
> As a consequence, you cannot remove and add elements in a loop, otherwise the `JsonBuffer` will overflow.
>
> Don't try to keep the state of your application in a `JsonArray`, instead use custom structures.
{: .alert .alert-danger}

>This function use to be named `removeAt()` in version older than 5.9.0
>{: .alert .alert-info }
