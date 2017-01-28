---
title: How to compute the JSON length?
layout: faq
tags: faq
---

Use `measureLength()` to compute the number of characters that will be printed by `printTo()`.

Use `measurePrettyLength()` to compute the number of characters that will be printed by `prettyPrintTo()`.

None of these methods include the zero-terminator.
So if you need to allocate a buffer, don't forget to add 1 to the size.

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["hello"] = world;

size_t len = root.measureLength(); // returns 17

size_t size = len+1;
char json[size];
root.printTo(json, size); // writes {"hello":"world"}
```

See issues [#75](https://github.com/bblanchon/ArduinoJson/issues/75), [#94](https://github.com/bblanchon/ArduinoJson/issues/94), [#166](https://github.com/bblanchon/ArduinoJson/issues/166), [#178](https://github.com/bblanchon/ArduinoJson/issues/178) and [#268](https://github.com/bblanchon/ArduinoJson/issues/268).
