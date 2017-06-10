---
title: How to write a function that works with both `JsonArray` and `JsonObject`?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 64
---

There is no base class for `JsonArray` and `JsonObject`.
(Back in version 3.0, they used to derive from `Printable`, but this inheritance has been removed to reduce the memory footprint.)

However, both `JsonArray` and `JsonObject` can be "stored" in a `JsonVariant`. (I put "stored" in quotes because the `JsonVariant` only contains a reference, not a copy.)

So here is your function:

```c++
void sendJson(JsonVariant json) {
    char buffer[512];
    json.printTo(buffer, sizeof(buffer));
    g_server.send(200, "application/json", buffer);
}
```

But in that case, you loose some specificities of the `JsonObject` class.
In particular, you don't have the `containsKey()` method.
If you need this function, you must cast the `JsonVariant` back to a `JsonObject&`.

For instance:

```c++
void myFunction(JsonVariant variant)
{
    if (variant.is<JsonArray&>())
    {
        JsonArray& array = variant;
        // ...
    }
    else if (variant.is<JsonObject&>())
    {
        JsonObject& object = variant;
        // ...
    }
    else
    {
        // ...
    }
}
```

See:

* Issues [#195](https://github.com/bblanchon/ArduinoJson/issues/195) and [#196](https://github.com/bblanchon/ArduinoJson/issues/196)
