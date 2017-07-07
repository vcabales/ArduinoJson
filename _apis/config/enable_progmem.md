---
title: ARDUINOJSON_ENABLE_PROGMEM
layout: api
tags: api
api-group: Configuration
---

Enables the support of strings stored in program memory, ie in Flash.

The default is `1` of `PROGMEM` is defined, `0` otherwise.

### How to force the value?

If you need to force the support of PROGMEM strings, add this at the top of your program:

```c++
#define ARDUINOJSON_ENABLE_PROGMEM 1
#include <ArduinoJson.h>
```

On the other hand, if you need to disable PROGMEM string, do:

```c++
#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h>
```

This is useful if your platform defines `PROGMEM` but doesn't actually support Flash-stored strings.

### Where a PROGMEM string can be used?

Once enabled, you can use a PROGMEM string in many places.

1. You can use a PROGMEM string as your JSON input

    ```c++
    // WARNING: the content of the PROGMEM string will be duplicated in the JsonBuffer.
    JsonObject& root = jsonBuffer.parseObject(F("{\"sensor\":\"gps\",\"time\":1351824120,"
                               "\"data\":[48.756080,2.302038]}"));
    ```

2. You can use a PROGMEM string to get an element of a JsonObject

    ```c++
    long time = root[F("time")];
    ```

3. You can use a PROGMEM string to set an element of a JsonObject

    ```c++
    // WARNING: the content of the PROGMEM string will be duplicated in the JsonBuffer.
    root[F("time")] = time;
    ```

4. You can set a JsonObject (or JsonArray) element to a PROGMEM string:

    ```c++
    // WARNING: the content of the PROGMEM string will be duplicated in the JsonBuffer.
    root["sensor"] = F("gps");
    ```

5. You can compare the content of a JsonObject with a PROGMEM string

    ```c++
    if (root["sensor"] == F("gps")) {
        // ...
    }
    ```