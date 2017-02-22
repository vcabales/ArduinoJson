---
title: How to reuse a <code>JsonBuffer</code>?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 65
---

This is a very popular question: Where is `JsonBuffer::clear()`?

I have a strong opinion against that feature. Let me explain.

In a previous draft of ArduinoJson, I added this function because I found it very convenient in my tests.
Unfortunately, it became extremely tempting to write things like:

```c++
// STEP1: parse input
StaticJsonBuffer<200> jsonBuffer;
JsonObject& inputObject = jsonBuffer.parseObject(inputJson);

...etc...

// STEP2: generate output
jsonBuffer.clear();
JsonObject& outputObject = jsonBuffer.createObject();
outputObject["hello"] = inputObject["world"];
```

I became so inciting to make mistake like this that I decided to remove it.

Arduino is an environment used by programmer that are not experienced in C or C++.
Many of them come from managed languages like C# or Java.
When you look at the code above, it's not obvious that calling `jsonBuffer.clear()` will corrupt `inputObject`.
Then its very hard to understand what's wrong with this code, especially because it may work for the first member if the memory hasn't been erased yet.

That's why I came up with the current design that enforce programmers to use `JsonBuffer` in short scopes, along with `JsonObject&` and `JsonArray&`.

However, I didn't hide the assignment operator...
This mean that an advanced user, like you, can still write:

```c++
jsonBuffer = StaticJsonBuffer<200>();
```

to reset the buffer :wink:

See also:

* [Bag of tricks: clear()](https://github.com/bblanchon/ArduinoJson/wiki/Bag-of-Tricks#reuse-jsonbuffer)
* [Avoiding pitfalls: Don't reuse the same JsonBuffer]({{site.baseurl}}/doc/pitfalls/#4-dont-reuse-the-same-jsonbuffer)
* [FAQ: Why shouldn't I use a global `JsonBuffer`?]({{site.baseurl}}/faq/why-shouldnt-i-use-a-global-jsonbuffer).
* [FAQ: What's the best way to use the library?]({{site.baseurl}}/faq/whats-the-best-way-to-use-the-library)
* Issues [#72](https://github.com/bblanchon/ArduinoJson/issues/72), [#115](https://github.com/bblanchon/ArduinoJson/issues/115), [#141](https://github.com/bblanchon/ArduinoJson/issues/141), [#160](https://github.com/bblanchon/ArduinoJson/issues/160), [#203](https://github.com/bblanchon/ArduinoJson/issues/203), [#219](https://github.com/bblanchon/ArduinoJson/issues/219), [#242](https://github.com/bblanchon/ArduinoJson/issues/242), [#243](https://github.com/bblanchon/ArduinoJson/issues/243), [#341](https://github.com/bblanchon/ArduinoJson/issues/341), [#347](https://github.com/bblanchon/ArduinoJson/issues/347) and [#384](https://github.com/bblanchon/ArduinoJson/issues/384).
