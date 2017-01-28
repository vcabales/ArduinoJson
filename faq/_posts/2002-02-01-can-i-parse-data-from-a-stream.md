---
title: Can I parse data from a stream?
layout: faq
tags: faq
---

Yes.

Since ArduinoJson 5.8, `parseArray()` and `parseObject()` accept Arduino's `Stream` and `std::istream` as input:

```c++
JsonObject& root = jsonObject.parseObject(myStream);
```

CAUTION: parts of the input need to be copied into the `JsonBuffer`, so you need to increase its capacity accordingly.

See:

* [Examples: JsonHttpClient.ino](https://github.com/bblanchon/ArduinoJson/blob/master/examples/JsonHttpClient/JsonHttpClient.ino#L149)
* [API Reference: JsonBuffer::parseArray()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonbufferparsearray)
* [API Reference: JsonBuffer::parseObject()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonbufferparseobject)
* [JsonBuffer size calculator](https://bblanchon.github.io/ArduinoJson/)
* Issues [#119](https://github.com/bblanchon/ArduinoJson/issues/119), [#300](https://github.com/bblanchon/ArduinoJson/issues/300), [#422](https://github.com/bblanchon/ArduinoJson/issues/422) and [#429](https://github.com/bblanchon/ArduinoJson/issues/429)
