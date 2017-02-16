---
title: Can I access to object member by its index, instead of its key?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 22
---

No.

But you can enumerate all the key-value pairs in the object, by using iterators:

```c++
char json[] = "{\"key\":\"value\"}";
JsonObject& object = jsonBuffer.parseObject(json);

for(JsonObject::iterator it=object.begin(); it!=object.end(); ++it)
{
    const char* key = it->key;

    if (it->value.is<char*>()) {
        const char* value = it->value;
        // ...
    }

    if (it->value.is<JsonObject>()) {
        JsonObject& value = it->value;
        // you can recursively traverse objects...
    }
}
```

See issue [#278](https://github.com/bblanchon/ArduinoJson/issues/278).
