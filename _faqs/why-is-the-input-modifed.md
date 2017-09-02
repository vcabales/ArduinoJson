---
title: Why is the input modified?
layout: faq
tags: faq
faq-group: Deserialization
popularity: 26
---

The JSON parser works in two different modes, depending on whether the input is read-only or not.

### Mode 1: read-only input

The read-only mode is used when the JSON input has one of the following types:

1. `const char *`
2. `std::string`
3. `std::istream`
4. `String`
5. `Stream`
6. `const __FlashStringHelper*`

In this mode, the parser copies relevant pieces of the input in the `JsonBuffer`.

Examples:

```c++
const char* json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

String json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);
```

### Mode 2: zero-copy

The zero-copy mode is used when the JSON input has one of the following types:

1. `char*`
2. `char[]`

In this mode, the JSON parser **modifies the input in-place**.
The following modifications are performed:

1. `'\0'` are inserted at the end of each string
2. Escaped special characters (like `"\\n"`) are unescaped

Example:

```c++
char[] json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);
```