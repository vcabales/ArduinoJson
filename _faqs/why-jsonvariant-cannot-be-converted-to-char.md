---
title: Why JsonVariant cannot be converted to char?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 8
---

The `char` type has been intentionally disabled to avoid an ambiguity.

Imagine you have this input: `{'time':'8'}`; what should be the value of `root["time"]` as a `char`?

I see two possible answers:

* Either you see `char` as an integer; in that case, the result should be `8`.
* Or you see `char` as a character; in that case, the result should be `56` (the ASCII code of character `8`)

Since there is not good answer to this question, the `char` type has been disabled, but `unsigned char` and `signed char` works as integers.

However, I highly encourage you to use `char` to store characters, and `int8_t` or `uint8_t` to store integers. If you compile with Arduino, you also have the [byte](https://www.arduino.cc/en/Reference/Byte) type.

See also:

* [API Reference: JsonVariant::as()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonvariantas)
* Issues [#337](https://github.com/bblanchon/ArduinoJson/issues/337) and [#370](https://github.com/bblanchon/ArduinoJson/issues/370)
