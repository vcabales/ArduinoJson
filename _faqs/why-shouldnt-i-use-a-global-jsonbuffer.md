---
title: Why shouldn't I use a global <code>JsonBuffer</code>?
layout: faq
tags: faq
faq-group: Common
popularity: 244
---

### Why shouldn't I use a global <code>JsonBuffer</code>?

`StaticJsonBuffer` and `DynamicJsonBuffer` are designed to be throwaway memory pools, they are not intended to be reused.
They are able to allocate memory, but not to release it; they always grow, as they are not able to shrink.
The only way to release the memory is to destroy the `JsonBuffer`.

That's why using a global `JsonBuffer` is always a bad idea!

### Why such a terrible limitation?

ArduinoJson is designed to do one thing and to do it well: **the JSON serialization**.
So before trying to use a global `JsonBuffer`, ask yourself first:

> Am I really using ArduinoJson for serialization, or am I pushing it beyond its initial intent?.
{: .alert .alert-warning}

In particular, you should not use `JsonObject` and `JsonArray` to store the internal state of your program as this would be terribly inefficient. Instead, write your own data structure and use ArduinoJson only in serialization functions, as shown in [What's the best way to use the library?]({{site.baseurl}}/faq/whats-the-best-way-to-use-the-library/)

### The "global JsonObject configuration" anti-pattern

Many projects use a JSON file to store their configuration: the file is read at startup and the content is kept in memory during the execution of the program.
In that situation, it's tempting to use a global `JsonObject` attached to a global `JsonBuffer`.
In theory, it's OK to use a global read-only `JsonObject`, because the `JsonBuffer` won't grow.
But in practice, it's a huge waste of memory and processor time.
The best way to deal with this is to use custom data structures as suggested in [What's the best way to use the library?]({{site.baseurl}}/faq/whats-the-best-way-to-use-the-library/).
This is a win in four levels:
1. Faster code (the object tree is walked only once at boot time)
2. Smaller RAM footprint (`JsonObject`, `JsonVariant`... have significant overhead)
3. Smaller code
4. It decouples the memory representation from the file format, which will be very handy when the file format evolves
Reducing the size of global variables is crucial as they reduce the RAM remaining for the rest.
Moreover, the JSON object tree consumes memory even if the program doesn't use it.
For example, if someone adds values in the JSON settings that are not actually used by the program, the memory will be used anyway.
One could even get to a situation where the program is unable to run because all the memory will be consumed by the settings.


#### The `.data` segment anti-pattern

One might think that a legitimate usage of a global buffer is to have a `StaticJsonBuffer` in the `.data` segment so that the compiler will issue an error if there is not enough memory.

While this seems like a good idea, it wastes a lot of RAM as it reserves memory that is used only a fraction of the time.
