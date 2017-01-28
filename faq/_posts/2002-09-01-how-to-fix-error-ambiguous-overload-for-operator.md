---
title: How to fix error "Ambiguous overload for 'operator='"
layout: faq
tags: faq
---

There is a case where you need to help the compiler: it's when you convert a `JsonVariant` to a `String`.

For example:

```c++
String ssid = network["ssid"];
ssid = network["ssid"];
```

The first line will compile but the second will fail with the following error:

```
error: ambiguous overload for 'operator=' (operand types are 'String' and 'ArduinoJson::JsonObjectSubscript<const char*>')
```

The solution is to remove the ambiguity with any of the following replacement:

```c++
ssid = (const char*)network["ssid"];
ssid = network["ssid"].asString();
ssid = network["ssid"].as<const char*>();
ssid = network["ssid"].as<String>();
```

See issue [#118](https://github.com/bblanchon/ArduinoJson/issues/118), [#146](https://github.com/bblanchon/ArduinoJson/issues/146) and [#197](https://github.com/bblanchon/ArduinoJson/issues/197).
