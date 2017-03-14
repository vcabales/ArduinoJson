---
title: "Error: undefined reference to <code>__cxa_guard_acquire</code> and <code>__cxa_guard_release</code>"
layout: faq
tags: faq
faq-group: Known problems
---

You need to add the following flag:

> `-fno-threadsafe-statics`
> 
> Do not emit the extra code to use the routines specified in the C++ ABI for thread-safe initialization of local statics.
> You can use this option to reduce code size slightly in code that doesn't need to be thread-safe.
{:.alert .alert-info}

If you use the Arduino IDE, you need to edit the `platform.txt` of the board you're using:

* The file is located at `%LOCALAPPDATA%\Arduino15\packages\<brand>\hardware\<board>\<version>\platform.txt`
* The line to change is `compiler.cpp.flags`

See issue [#356](https://github.com/bblanchon/ArduinoJson/issues/356) and [#389](https://github.com/bblanchon/ArduinoJson/issues/389)
