---
title: JsonBuffer::clear()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description

Resets the `JsonBuffer`; size goes back to zero.

Allocated memory is freed in the case of a `DynamicJsonBuffer`.

This allows to reuse the `JsonBuffer`.

##### Signature

```c++
void clear();
```

##### Example

```c++
StaticJsonBuffer<200> jb;

JsonObject& obj1 = jb.parseObject(json1);
// we can use obj1 here...

jb.clear();
// now obj1 is dangling!!!

// ...but we can reuse the JsonBuffer
JsonObject& obj2 = jb.parseObject(json2);
```

> ##### Source of memory corruption :warning:
>
> Once you called `JsonBuffer::clear()`, all the objects and arrays allocated in this buffer become invalid.
>
> If you try to access such a reference (like the `obj1` in the example above), you're likely to crash your device or at least get very unexpected results.
>
> Don't try to keep the state of your application in a `JsonObject`, instead use custom structures.
{: .alert .alert-danger}