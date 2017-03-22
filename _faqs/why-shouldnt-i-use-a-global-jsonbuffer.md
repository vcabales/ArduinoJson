---
title: Why shouldn't I use a global <code>JsonBuffer</code>?
layout: faq
tags: faq
faq-group: Common
faq-popularity: 67
---

`StaticJsonBuffer` and `DynamicJsonBuffer` are designed to be throwaway memory pools, they are not intended to be reused.
As a consequence, using a global `JsonBuffer` is not possible.

Make sure you read: [How to reuse a `JsonBuffer`?]({{site.baseurl}}/faq/how-to-reuse-a-jsonbuffer/).

ArduinoJson is designed to do one thing and to do it well: **the JSON serialization**.
So before trying to use a global `JsonBuffer`, ask yourself first:

> Am I really using ArduinoJson for serialization, or am I pushing it beyond its initial intent?.
{: .alert .alert-warning}

In particular, you should not use `JsonObject` and `JsonArray` to store the internal state of your program as this would be terribly inefficient. Instead, write your own data structure and use ArduinoJson only in serialization functions, as shown in [What's the best way to use the library?]({{site.baseurl}}/faq/whats-the-best-way-to-use-the-library/)

The only legitimate usage of a global buffer is to have a `StaticJsonBuffer` in the `.data` segment to that the compiler will issue an error if there is not enough memory. While this seems like a good idea, it wastes a lot of RAM as it reserves memory that is used only a fraction of the time. Again, make sure you read: [How to reuse a `JsonBuffer`?]({{site.baseurl}}/faq/how-to-reuse-a-jsonbuffer/).