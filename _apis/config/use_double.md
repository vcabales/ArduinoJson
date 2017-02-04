---
title: ARDUINOJSON_USE_DOUBLE
layout: api
tags: api
api-group: Configuration
---

Determine the type used to store floating point values in `JsonVariant`.

* If `ARDUINOJSON_USE_DOUBLE == 0`, then `JsonVariant` stores a `float`
* If `ARDUINOJSON_USE_DOUBLE == 1`, then `JsonVariant` stores a `double`

Default is `0` of `ARDUINO` is defined, `1` otherwise.
