---
title: "Arduino Zero, mkr1000 and all boards based on SAMD21"
layout: faq
tags: faq
faq-group: Known problems
---

There is a bug in [Arduino SAMD core](https://github.com/arduino/ArduinoCore-samd) that make `prettyPrintTo()` fail (issue [#327](https://github.com/bblanchon/ArduinoJson/issues/327))

It's been fixed on May 27th by [arduino/ArduinoCore-samd@8ef9bb3](https://github.com/arduino/ArduinoCore-samd/commit/8ef9bb3d7bd026b57a8568030d8992644c9b8de8) and [arduino/ArduinoCore-samd@8d0c167](https://github.com/arduino/ArduinoCore-samd/commit/8d0c1674628df1c2c7592f4fc17467c694f5a1be).
Unfortunately, version 1.6.6 only includes modifications up to May 19th, so the fix is not available through the Arduino Boards Manager.

I recommend to apply the modification manually or wait until the next release of the Arduino SAMD Core.
The files to change are [`USBCore.cpp`](https://github.com/arduino/ArduinoCore-samd/commit/8ef9bb3d7bd026b57a8568030d8992644c9b8de8) and [`CDC.cpp`](https://github.com/arduino/ArduinoCore-samd/commit/8d0c1674628df1c2c7592f4fc17467c694f5a1be).

They are located here on Windows:

```
%LOCALAPPDATA%\Arduino15\packages\arduino\hardware\samd\1.6.6\cores\arduino\USB
```