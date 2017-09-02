---
title: The first parsing succeeds, why do the next ones fail?
layout: faq
tags: faq
faq-group: Deserialization
popularity: 216
---

You wrote a program that works fine for one or more iterations, but then fails.
This can be due to two causes.

### Cause 1: reuse of `JsonBuffer`

First, this can happen if you reuse the same `JsonBuffer`, for example:

```c++
StaticJsonBuffer<200> jsonBuffer;

for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

The solution is simply to NOT reuse the `JsonBuffer`, like this:

```c++
for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

Note that, contrary to a common belief, moving a `StaticJsonBuffer` inside of a loop has no negative impact on performance.

### Cause 2: reuse of JSON input

In order to make the JSON parsing without any allocation or duplication, ArduinoJson modifies the string in place: it inserts null terminators and unescapes special characters.

If you provide a writeable input, like a `char[]` or a `char*`, it will modify this input in place.
If you provide a read only input, like a `const char*` or a `String`, it will have to make a copy of it in order to be allowed to modify it.

That's why it's highly recommended to used a writeable input: you get a huge performance boost and memory usage is greatly reduced :+1:

Now, this behavior leads to unexpected result if you try to reuse the modified string, for instance:

```c++
char json[256];
readJsonFromSomewhere(json, sizeof(json));

for (int i=0; i<10; i++) {
    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

Only the first call to `parseObject()` will succeed because after that call, `json` will be altered and not be valid JSON anymore.

The solution is simply to parse the input only once, or get a fresh input at each iteration:

```c++
for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```