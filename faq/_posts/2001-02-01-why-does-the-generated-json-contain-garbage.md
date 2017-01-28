---
title: Why does the generated JSON contain garbage?
layout: faq
tags: faq
---

There are two key concepts you need to understand to use ArduinoJson:

1. `JsonObject`s and `JsonArray`s are stored in a `JsonBuffer`
2. `char*` are not copied

Similarly, there are two reasons to get garbage in the output:

1. `JsonBuffer` is not in memory anymore
2. The string pointed by the `char*` is not in memory anymore.

##### Example 1 of what you should not do:

```c++
JsonObject& myFunction() {
  StaticJsonBuffer<200> jsonBuffer;
  return jsonBuffer.createObject();
}
```

This is wrong because it returns a reference (a pointer if you prefer) to a `JsonObject` that is not in memory anymore.

##### Example 2 of what you should not do:

```c++
void myFunction(JsonObject& obj) {
  char myValue[] = "Hello World!";
  obj["value"] = myValue;
}
```

This is wrong because the `JsonObject` now contains a pointer to a string that is not in memory anymore.

See also:

* [Avoiding pitfalls: Do not assume that strings are copied](https://github.com/bblanchon/ArduinoJson/wiki/Avoiding-pitfalls#6-do-not-assume-that-strings-are-copied)
* Issues [#364](https://github.com/bblanchon/ArduinoJson/issues/364), [#366](https://github.com/bblanchon/ArduinoJson/issues/366)
