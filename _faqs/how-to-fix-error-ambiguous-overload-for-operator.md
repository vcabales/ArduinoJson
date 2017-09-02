---
title: "Error: Ambiguous overload for 'operator='"
layout: faq
tags: faq
faq-group: Known problems
popularity: 101
---

Most of the time you can rely on implicit casts.

But there is one notable exception: when you convert a `JsonVariant` to a `String`.

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
ssid = network["ssid"].as<const char*>();
ssid = network["ssid"].as<String>();
```