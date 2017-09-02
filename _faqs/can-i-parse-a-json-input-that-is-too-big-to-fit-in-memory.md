---
title: Can I parse a JSON input that is too big to fit in memory?
layout: faq
tags: faq
faq-group: Deserialization
popularity: 161
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

On the other hand, if you use a read-only input like a `const char*`, a `String` or a `Stream`, a copy of the input will be made in the `JsonBuffer`. This copy will be smaller than the original input because the spaces, comments and punctuation will be removed; but most of the JSON input will be stored in RAM.

If this is not possible for you to store the JSON input or if the `JsonBuffer` cannot fit in RAM, you need to switch to a JSON library that has a different parsing strategy, like [json-streaming-parser](https://github.com/squix78/json-streaming-parser).
