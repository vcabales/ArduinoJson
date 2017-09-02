---
title: "ESP32"
layout: faq
tags: faq
faq-group: Known problems
faq-popularity: 112
---

There is currently a bug in the [Arduino Core for ESP32](https://github.com/espressif/arduino-esp32) causing the following error:

```
error: redefinition of 'struct ArduinoJson::Internals::StringFuncs<const char*>'
```

The solution is to disable `PROGMEM` support in ArduinoJson.
To do that, just add the following line at the top of your program:

```c++
#define ARDUINOJSON_ENABLE_PROGMEM 0
```

Then, you may have the following linker error [undefined reference to `__cxa_guard_acquire` and `__cxa_guard_release`]({{site.baseurl}}/faq/error-undefined-reference-to-cxaguardacquire-and-cxaguardrelease/)
