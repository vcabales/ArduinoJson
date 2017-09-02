---
title: How to iterate over a <code>JsonVariant</code>?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 0
---

There is no iterator on `JsonVariant` because it would be ambiguous.

Before iterating on a variant, the program must cast it to either a `JsonArray` or `JsonObject`.

For instance, for an object:

```c++
for( const auto& kv : variant.as<JsonObject>() ) {
    Serial.println(kv.key);
    Serial.println(kv.value.as<char*>());
}
```

and for an array:

```c++
for( const auto& value : variant.as<JsonArray>() ) {
    Serial.println(value.as<char*>());
}
```

See:

* [API Reference: JsonVariant::as&lt;T&gt;()]({{site.baseurl}}/api/jsonvariant/as/)
* [API Reference: JsonArray::begin()/end()]({{site.baseurl}}/api/jsonarray/begin_end/)
* [API Reference: JsonObject::begin()/end()]({{site.baseurl}}/api/jsonobject/begin_end/)