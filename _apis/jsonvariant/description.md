---
title: JsonVariant description
layout: api
tags: api
api-group: JsonVariant
---

A variable that can hold different type of values:

* a boolean
* a char, short, int or a long (signed or unsigned)
* a string (const char*)
* a reference to a JsonArray or JsonObject

A `JsonVariant` can be any of theses types at a time, but can only hold one value.
Its type can change at run time.
