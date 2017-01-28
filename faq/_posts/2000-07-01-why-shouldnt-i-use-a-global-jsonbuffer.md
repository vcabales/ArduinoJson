---
title: Why shouldn't I use a global <code>JsonBuffer</code>?
layout: faq
tags: faq
---

`StaticJsonBuffer` and `DynamicJsonBuffer` are designed to be throwaway memory pools, they are not intended to be reused.
As a consequence, using a global `JsonBuffer` is almost always a bad idea.

ArduinoJson is designed to do one thing and to do it well: **the JSON serialization**.
In particular `JsonObject` and `JsonArray` should not replace your own data structures; that would be terribly inefficient.
So before trying to use a global `JsonBuffer`, ask yourself first "Am I really using ArduinoJson for serializing, or am I pushing it beyond its initial intent?".

If you believe you need to reuse a `JsonBuffer`, it's because [you're not using the library correctly](whats-the-best-way-to-use-the-library).

##### 1. There is a reason behind this.

Imagine a `clear()` function is available, someone could write:

```c++
JsonObject& myObject = jsonBuffer.createObject();
jsonBuffer.clear();
JsonArray& myArray = jsonBuffer.createArray();
```

And in this case `myObject` and `myArray` would point to the exact same location.
Therefore, any modification of one would corrupt the other.

That's why `StaticJsonBuffer` and `DynamicJsonBuffer` have been design to force you to use them in a scope.
If you believe you need a `clear()` function, then you're not using the library correctly.

##### 2. Allocating a `StaticJsonBuffer` is not expensive

Destructing an constructing a new `StaticJsonBuffer` is not expensive, it's exactly the same cost as the `clear()` function above.
