---
title: ARDUINOJSON_USE_DOUBLE
layout: api
tags: api
api-group: Configuration
---

`ARDUINOJSON_USE_DOUBLE` determines the type used to store floating point values in `JsonVariant`:

* If `ARDUINOJSON_USE_DOUBLE == 0`, then `JsonVariant` stores a `float`
* If `ARDUINOJSON_USE_DOUBLE == 1`, then `JsonVariant` stores a `double`

Default is `0` on embedded systems, `1` otherwise.

```c++
#define ARDUINOJSON_USE_DOUBLE 1 // we need to store 64-bit doubles
#include <ArduinoJson.h>
```

:warning: Caution: the memory consumption will be higher, and the results given by the [ArduinoJson Assistant]({{ site.baseurl }}/assistant/) will be wrong.

