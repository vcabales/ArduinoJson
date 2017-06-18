---
title: "Error: <code>invalid conversion from 'const char*' to 'char*' [-fpermissive]</code>"
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 0
---

ArduinoJson returns keys and values as `const char*`.

If you try to put these values into a `char*`, the compiler will issue an error (or a warning) like the following:

```
invalid conversion from 'ArduinoJson::Internals::JsonVariantAs<char*>::type {aka const char*}' to 'char*' [-fpermissive]
```

This happens with any of the following expression:

```c++
char* sensor = root["sensor"];
char* sensor = root["sensor"].as<char*>();

// in a function whose return type is char*
return root["sensor"].as<char*>();
```

The solution is to replace `char*` by `const char*`

```c++
const char* sensor = root["sensor"];
const char* sensor = root["sensor"].as<char*>();

// change the return type of the function
return root["sensor"].as<char*>();
```

See also:

* [API Reference: JsonVariant::as&lt;T&gt;()]({{site.baseurl}}/api/jsonvariant/as/)