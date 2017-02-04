---
title: JsonBuffer description
layout: api
tags: api
api-group: JsonBuffer
---

`JsonBuffer` is the entry point for using the library: it handles the memory management and calls the parser.

It implements a speed efficient memory pool and comes in two flavors:

1. `DynamicJsonBuffer` which is allocated on the heap and grows automatically
2. `StaticJsonBuffer` which is (most likely) allocated on the stack and has a fixed size.

`JsonBuffer` is optimized of fast allocation, but doesn't allow to free the allocated memory block.
To free a `JsonBuffer`, you must discard the entire object.

This is the source of a lot of question, please read the [FAQ in the wiki](https://github.com/bblanchon/ArduinoJson/wiki/FAQ) for clarifications.
