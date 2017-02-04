---
title: ARDUINOJSON_DEFAULT_NESTING_LIMIT
layout: api
tags: api
api-group: Configuration
---

Defines the default value the second parameter of `parseObject()` and `parseArray()`, which limit the nesting in the JSON input. (the goal is to prevent stackoverflow).

Default is `10` of `ARDUINO` is defined, `50` otherwise.
