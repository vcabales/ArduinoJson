---
title: Parsing succeeds but I can't read the values!
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 40
---

99.999% of the time, this is caused by a confusion between arrays and objects.

This often happens when the JSON contains `[{` or `:[`.

##### Example 1:

```json
[{"hello":"world"}]
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root[0]["hello"];
```

##### Example 2:

```json
{"hello":["world"]}
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root["hello"][0];
```

##### Example 3:

```json
{"hello":[{"new":"world"}]}
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"]["new"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root["hello"][0]["new"];
```

See:

* Issues [#187](https://github.com/bblanchon/ArduinoJson/issues/187), [#203](https://github.com/bblanchon/ArduinoJson/issues/203) and [#245](https://github.com/bblanchon/ArduinoJson/issues/245).
* [ArduinoJson Assistant]({{ site.baseurl }}/assistant/)
