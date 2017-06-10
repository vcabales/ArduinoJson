---
title: Why ArduinoJson is slow?
layout: faq
tags: faq
faq-group: Serialization
faq-popularity: 70
---

First of all, ArduinoJson is **not slow** by itself. It's slow when used in conjunction with the `WifiClient` from the ESP8266 core.

The problem is that there is no buffer between ArduinoJson and the WifiClient.

To solve this, either:

1. Enable the [Nagle algorithm](https://en.wikipedia.org/wiki/Nagle%27s_algorithm) on `WifiClient` by calling `setNoDelay(false)`.
2. Serialize to a buffer and send the whole buffer in one shot.
3. Insert a [BufferedPrint](https://github.com/bblanchon/ArduinoJson/wiki/Bag%20of%20Tricks#buffered-output) proxy between ArduinoJson and `WifiClient`.

See issue [#166](https://github.com/bblanchon/ArduinoJson/issues/166), [#271](https://github.com/bblanchon/ArduinoJson/issues/271) and [#301](https://github.com/bblanchon/ArduinoJson/issues/301)
