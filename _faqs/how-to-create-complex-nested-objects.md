---
title: How to create complex nested objects?
layout: faq
tags: faq
faq-group: Serialization
faq-popularity: 76
---

To create a nested object, call `createNestedObject()`.
To create a nested array, call `createNestedArray()`.

For example:

```c++
DynamicJsonBuffer jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

JsonObject& weather = root.createNestedObject("weather");
weather["temperature"] = 12;
weather["condition"] = "cloudy";

JsonArray& coords = root.createNestedArray("coords");
coords.add(48.7507371, 7);
coords.add(2.2625587, 7);

root.prettyPrintTo(Serial);
```

will generate:

```json
{
  "weather": {
    "temperature": 12,
    "condition": "cloudy"
  },
  "coords": [
    48.7507371,
    2.2625587
  ]
}
```

See:

* issues [#51](https://github.com/bblanchon/ArduinoJson/issues/51), [#252](https://github.com/bblanchon/ArduinoJson/issues/252) and [#264](https://github.com/bblanchon/ArduinoJson/issues/264)
* [API Reference: JsonArray::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonarraycreatenestedarray)
* [API Reference: JsonArray::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonarraycreatenestedarray)
* [API Reference: JsonObject::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonobjectcreatenestedarray)
* [API Reference: JsonObject::createNestedObject()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonobjectcreatenestedobject)
