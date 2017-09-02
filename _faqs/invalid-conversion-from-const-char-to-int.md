---
title: "Error: <code>invalid conversion from 'const char*' to 'int' [-fpermissive]</code>"
layout: faq
tags: faq
faq-group: Deserialization
popularity: 124
---

Let's say you have the following JSON to parse:

```json
{
  "modules": [
    {
      "name": "hello",
      "id": 10
    },
    {
      "name": "world",
      "id": 20
    }
  ]
}
```

If you write the following program:

```c++
JsonObject& root =  jsonBuffer.parseOject(input);
JsonArray& modules = root["modules"];

const char* name = modules["hello"][0];
```

You'll get the following compilation error:

<code>
error: invalid conversion from 'const char*' to 'size_t {aka unsigned int}' [-fpermissive]
</code>

This is because `modules` is an array of object, as such it's indexed by an integer, not by a string.

The solution is:

```c++
const char* name = modules[0]["hello"];
```

See:

* [FAQ: Parsing succeeds but I can't read the values!]({{site.baseurl}}/faq/parsing-succeeds-but-i-cant-read-the-values/)
* [FAQ: Can I access to object member by its index, instead of its key?]({{site.baseurl}}/faq/can-i-access-to-object-member-by-its-index-instead-of-its-key/)
* [ArduinoJson Assistant]({{site.baseurl}}/assistant/)
