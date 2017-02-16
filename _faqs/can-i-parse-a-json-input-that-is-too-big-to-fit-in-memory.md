---
title: Can I parse a JSON input that is too big to fit in memory?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 25
---

No.

This is a fundamental design principle in this library.
The JSON input must be in memory and must be mutable (i.e., not read-only) to allow zero-copy and zero-allocation, which is *the* strength of this library.

Let's see an example to understand why this is important:

```c++
char json[] = "{\"hello\":\"world\"}";
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

After executing the lines above, the variable `world` will point to the word `"world"` inside the `json` string. During the call to `parseObject()`, the `json` string has been modified to insert the necessary zero-terminator (`\0`), to cut the string `world`.
As you can see this process requires neither duplication nor allocation, but imposes the input to be stored in a `char[]`.

If this is not acceptable, you should have a look at other libraries, like [json-streaming-parser](https://github.com/squix78/json-streaming-parser).

See issues [#60](https://github.com/bblanchon/ArduinoJson/issues/60), [#119](https://github.com/bblanchon/ArduinoJson/issues/119), [#194](https://github.com/bblanchon/ArduinoJson/issues/194), [#200](https://github.com/bblanchon/ArduinoJson/issues/200) and [#223](https://github.com/bblanchon/ArduinoJson/issues/223).
