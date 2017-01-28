---
title: Why do I have a segmentation fault?
layout: faq
tags: faq
---

`parseArray()` and `parseObject()` may cause a segmentation fault if the input string is in a read-only segment.

Indeed, the parser modifies the string for two reasons:

1. it inserts `\0` to terminate substrings,
2. it translate escaped characters like `\n` or `\t`.

Most of the time this wont be an issue, but there are some corner cases that can be problematic.

Let take the example bellow:

    char[] json = "[\"hello\",\"world\"]";
    StaticJsonBuffer<32> buffer;
    JsonArray& array = buffer.parseArray(json);

If you replace it by:

    char* json = "[\"hello\",\"world\"]";
    StaticJsonBuffer<32> buffer;
    JsonArray& array = buffer.parseArray(json);

Depending on your platform, you may have an exception because the parser tries to write at a location that is read-only.
In the first case `char json[]` declares an array of `char` initialized to the specified string.
In the second case `char* json` declares a pointer to a read-only string, in fact it should be a `const char*` instead of a `char*`.

See:

* issue [#378](https://github.com/bblanchon/ArduinoJson/issues/378)
* [Avoiding pitfalls: Make sure the string isn't read-only](https://github.com/bblanchon/ArduinoJson/wiki/Avoiding%20pitfalls#7-make-sure-the-string-isnt-read-only)
