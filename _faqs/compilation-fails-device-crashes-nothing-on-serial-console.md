---
title: Compilation fails? Device crashes? Nothing on serial console?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 113
---

<!-- MarkdownTOC depth=3 autolink=true bracket=round lowercase_only_ascii=true -->

- [Arduino Library Manager doesn't list the latest versions of ArduinoJson](#arduino-library-manager-doesnt-list-the-latest-versions-of-arduinojson)
- [CodeBender](#codebender)
- [Arduino Zero, mkr1000 and all boards based on SAMD21](#arduino-zero-mkr1000-and-all-boards-based-on-samd21)
- [Warning: ignoring packed attribute because of unpacked non-POD field](#warning-ignoring-packed-attribute-because-of-unpacked-non-pod-field)
- [Error: undefined reference to `__cxa_guard_acquire` and `__cxa_guard_release`](#error-undefined-reference-to-cxaguardacquire-and-cxaguardrelease)
- [Adafruit WICED](#adafruit-wiced)
- [ESP32](#esp32)
- [Sloeber Arduino Eclipse Plugin](#sloeber-arduino-eclipse-plugin)

<!-- /MarkdownTOC -->

Despite the effort on writing portable code, there are compatibility issues with a few platform.

## Arduino Library Manager doesn't list the latest versions of ArduinoJson

This is a very common issue.
If ArduinoJson doesn't appear in Libray Manager, or if only old versions are listed, try to delete the local cache.
This will force the Libray Manager to download the library list from scratch.

For example, on Windows, you need to delete:

* `%LOCALAPPDATA%\Arduino15\library_index.json`
* `%LOCALAPPDATA%\Arduino15\library_index.json.tmp.gz`

You don't even need to close Arduino, just re-open the library manager.

## CodeBender

For some reason, it's not possible to use ArduinoJson with CodeBender.

See discussion here: http://feedback.codebender.cc/forums/280538-library-requests/suggestions/7238254-arduinojson-support

## Arduino Zero, mkr1000 and all boards based on SAMD21

There is a bug in [Arduino SAMD core](https://github.com/arduino/ArduinoCore-samd) that make `prettyPrintTo()` fail (issue [#327](https://github.com/bblanchon/ArduinoJson/issues/327))

It's been fixed on May 27th by [arduino/ArduinoCore-samd@8ef9bb3](https://github.com/arduino/ArduinoCore-samd/commit/8ef9bb3d7bd026b57a8568030d8992644c9b8de8) and [arduino/ArduinoCore-samd@8d0c167](https://github.com/arduino/ArduinoCore-samd/commit/8d0c1674628df1c2c7592f4fc17467c694f5a1be).
Unfortunately, version 1.6.6 only includes modifications up to May 19th, so the fix is not available through the Arduino Boards Manager.

I recommend to apply the modification manually or wait until the next release of the Arduino SAMD Core.
The files to change are [`USBCore.cpp`](https://github.com/arduino/ArduinoCore-samd/commit/8ef9bb3d7bd026b57a8568030d8992644c9b8de8) and [`CDC.cpp`](https://github.com/arduino/ArduinoCore-samd/commit/8d0c1674628df1c2c7592f4fc17467c694f5a1be).

They are located here on Windows:

```
%LOCALAPPDATA%\Arduino15\packages\arduino\hardware\samd\1.6.6\cores\arduino\USB
```

## Warning: ignoring packed attribute because of unpacked non-POD field

If you pass the flag `--fpack-struct` to the compiler, it will generate the following warning:

```
warning: ignoring packed attribute because of unpacked non-POD field
```

No solution has been found so far: you need to remove that flag if you want to get rid of that warning.

See issue [#255](https://github.com/bblanchon/ArduinoJson/issues/255)

## Error: undefined reference to `__cxa_guard_acquire` and `__cxa_guard_release`

You need to add the following flag:

> `-fno-threadsafe-statics`
> Do not emit the extra code to use the routines specified in the C++ ABI for thread-safe initialization of local statics. You can use this option to reduce code size slightly in code that doesn't need to be thread-safe.

See issue [#356](https://github.com/bblanchon/ArduinoJson/issues/356) and [#389](https://github.com/bblanchon/ArduinoJson/issues/389)


## Adafruit WICED

There is currently a bug in the Arduino Core for Adafruit WICED Feather causing the following error:

```
error: cannot convert 'err_t' to 'err_t (*)()
```

See issue [#404](https://github.com/bblanchon/ArduinoJson/issues/404)

## ESP32

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


## Sloeber Arduino Eclipse Plugin

When compiling ArduinoJson within the Sloeber Arduino Eclipse Plugin, you may encounter the following error:

```
C:/Utilities/sloeber/arduinoPlugin/libraries/ArduinoJson/5.8.2/fuzzing/fuzzer.cpp:3:39: error: expected class-name before '{' token class memstream : public std::istream
```

You need to add the `fuzzin/` folder to the "Source Folder Exclusion Patterns", like on the pricture bellow:

![Source Folder Exclusion Patterns](https://cloud.githubusercontent.com/assets/1175841/22299097/2af90b14-e323-11e6-8b21-5f0f91055e60.png)

See issues [ArduinoJson #432](https://github.com/bblanchon/ArduinoJson/issues/432) and [Sloeber #642](https://github.com/Sloeber/arduino-eclipse-plugin/issues/642).
