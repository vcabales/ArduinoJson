---
title: "Error: redefinition of 'struct ArduinoJson::Internals::StringFuncs&lt;const char*&gt;'"
layout: faq
tags: faq
faq-group: Known problems
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

Then, you may have the following linker error:

```
undefined reference to__cxa_guard_release'
```

To solve this, you need to add `-fno-threadsafe-statics` in `platform.txt`.

See issue [#407](https://github.com/bblanchon/ArduinoJson/issues/407)
