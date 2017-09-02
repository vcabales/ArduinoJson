---
title: How to know the type of a value?
layout: faq
tags: faq
faq-group: Deserialization
popularity: 66
---

`JsonVariant`, which is the type that hold the values in `JsonArray` and `JsonObject`, provides the method `is<T>()` that returns `true` if the value is of type `T`.

Examples:

```c++
object["key"] = "value";
object["key"].is<const char*>(); // returns true
object["key"].is<int>(); // returns false
object["key"].is<JsonObject&>(); // returns false

array.add(42);
array[0].is<const char*>(); // return false
array[0].is<int>(); // return true
array[0].is<JsonObject&>(); // return false
```

See issues [#148](https://github.com/bblanchon/ArduinoJson/issues/148), [#175](https://github.com/bblanchon/ArduinoJson/issues/175) and [#213](https://github.com/bblanchon/ArduinoJson/issues/213).
