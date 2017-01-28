---
title: Why parsing fails?
layout: faq
tags: faq
---

The parsing functions, `parseArray()` and `parseObject()`, may fail for 5 reasons:

1. [The input is not a valid JSON](#case-1-the-input-is-not-a-valid-json)
2. [The `StaticJsonBuffer` is too small](#case-2-the-staticjsonbuffer-is-too-small)
3. [The `StaticJsonBuffer` is too big (stack overflow)](#case-3-the-staticjsonbuffer-is-too-big)
4. [The `DynamicJsonBuffer` fails to allocate memory](#case-4-the-dynamicjsonbuffer-fails-to-allocate-memory)
5. [You called `parseObject()` instead of `parseArray()`](#case-5-you-called-parseobject-instead-of-parsearray)

#### Case 1: The input is not a valid JSON

This seems obvious, but a lot of issues are caused by from an invalid input.
In particular, if you're writing an HTTP client, you need to skip the HTTP headers and send only the JSON payload to ArduinoJson.

See:

* Issues [#108](https://github.com/bblanchon/ArduinoJson/issues/108), [#167](https://github.com/bblanchon/ArduinoJson/issues/167), [#218](https://github.com/bblanchon/ArduinoJson/issues/218), [#237](https://github.com/bblanchon/ArduinoJson/issues/237), [#424](https://github.com/bblanchon/ArduinoJson/issues/424), [#430](https://github.com/bblanchon/ArduinoJson/issues/430) and [#431](https://github.com/bblanchon/ArduinoJson/issues/431)

#### Case 2: The `StaticJsonBuffer` is too small

You can solve the problem by increasing the size of the `StaticJsonBuffer` or by switching to a `DynamicJsonBuffer`.

See:

* Issues [#53](https://github.com/bblanchon/ArduinoJson/issues/53), [#89](https://github.com/bblanchon/ArduinoJson/issues/89), [#202](https://github.com/bblanchon/ArduinoJson/issues/202), [#280](https://github.com/bblanchon/ArduinoJson/issues/280), [#293](https://github.com/bblanchon/ArduinoJson/issues/293) and [#296](https://github.com/bblanchon/ArduinoJson/issues/296)

#### Case 3: The `StaticJsonBuffer` is too big

You can try to switch to a `DynamicJsonBuffer`. Indeed, most platforms have a fixed size of the stack (usually 4KB on the ESP8266) the rest of the RAM being reserved to the heap. That's why moving the `JsonBuffer` from the stack to the heap can solve this kind of problem.

See:

* Issues [#167](https://github.com/bblanchon/ArduinoJson/issues/167) and [#234](https://github.com/bblanchon/ArduinoJson/issues/234).

#### Case 4: The `DynamicJsonBuffer` fails to allocate memory

You may have a memory leak, it up to you to find it. You can try to switch to `StaticJsonBuffer` which is more efficient.

Also, if the input string is constant, the `JsonBuffer` will have to make a copy of it.

```c++
// case 1: char array => no duplication => good
char[] json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 2: const char* => duplication => bad
const char* json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 3: String => duplication => bad
String json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);
```

To avoid any duplication, make sure you use an input of type `char*` or `char[]`

See:

* Issues [#154](https://github.com/bblanchon/ArduinoJson/issues/154), [#177](https://github.com/bblanchon/ArduinoJson/issues/177), [#179](https://github.com/bblanchon/ArduinoJson/issues/179) and [#223](https://github.com/bblanchon/ArduinoJson/issues/223) and [#320](https://github.com/bblanchon/ArduinoJson/issues/320).

#### Case 5: You called `parseObject()` instead of `parseArray()`

This is a very common question as people are often confused when the JSON input contains mixed arrays and objects.

The answer is very simple: it's the type of the root that matters.
This means that you just need to look at the first character: it's either a `[`, for an array, or a `{`, for an object.

For example, if the input is:

```json
{"mickey":["mouse"],"donald":["duck"]}
```

then you must call `parseObject()` because the root is an object.

And, if the input is:

```json
[{"mickey":"mouse","donald":"duck"}]
```

then you must call `parseArray()` because the root is an array.

Finally, if you cannot know in advance the type of the root, please open an issue. Don't worry this can be implemented very easily, it's just that nobody asked for it.

See:

* Issue [#391](https://github.com/bblanchon/ArduinoJson/issues/391)
