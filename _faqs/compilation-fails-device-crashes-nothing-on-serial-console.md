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