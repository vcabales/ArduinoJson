---
title: Why does my device crash or reboot?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 74
---

99.999% of the time, this is caused by a "stack overflow", i.e. you have too many variables in the "stack".

Before reading further, make sure that your target platform does have enough RAM to store the `JsonBuffer` and possibly the JSON input too:
* Use [ArduinoJson Assistant]({{site.baseurl}}/assistant/) to see how much memory you need.
* See [How to reduce memory usage?]({{site.baseurl}}/faq/how-to-reduce-memory-usage/).
* See [Can I parse a JSON input that is too big to fit in memory?]({{site.baseurl}}/faq/can-i-parse-a-json-input-that-is-too-big-to-fit-in-memory/)

Once you're sure that your device has enough RAM, you should move the `JsonBuffer` to the heap. Just replace your `StaticJsonBuffer` by a `DynamicJsonBuffer`.

If your JSON input is stored in the stack, you should move it to the heap too.

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