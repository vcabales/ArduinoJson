---
title: Why does my device crash or reboot?
layout: faq
tags: faq
---

99.999% of the time, this is caused by a "stack overflow", i.e. you have too many variables in the "stack".
The solution is to move variables to the "heap".

First, replace the `StaticJsonBuffer` by a `DynamicJsonBuffer`.
Then, use dynamic allocation for the JSON input.

For instance, if you have a program like this:

```c++
char content[MAX_CONTENT_SIZE];
StaticJsonBuffer<JSON_BUFFER_SIZE> jsonBuffer;

receive(content);
JsonObject& root = jsonBuffer.parseObject(content);

Serial.println(root["name"].asString());
```

you should transform it like that:

```c++
char* content = malloc(MAX_CONTENT_SIZE);
DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);

receive(content);
JsonObject& root = jsonBuffer.parseObject(content);

Serial.println(root["name"].asString());

free(content);
```

Of course, this is only possible if your target has enough memory.
Sometimes, it's just impossible because the MCU is too small.

See:

* Issues [#233](https://github.com/bblanchon/ArduinoJson/issues/233), [#234](https://github.com/bblanchon/ArduinoJson/issues/234), [#262](https://github.com/bblanchon/ArduinoJson/issues/262) and [#359](https://github.com/bblanchon/ArduinoJson/issues/359)
