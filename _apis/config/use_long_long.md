---
title: ARDUINOJSON_USE_LONG_LONG
layout: api
tags: api
api-group: Configuration
---

Determine the type used to store integer values in `JsonVariant`.

* If `ARDUINOJSON_USE_LONG_LONG == 0`, then `JsonVariant` stores a `long`
* If `ARDUINOJSON_USE_LONG_LONG == 1`, then `JsonVariant` stores a `long long`

Default is `0` of `ARDUINO` is defined, `1` otherwise.
