---
title: ARDUINOJSON_ENABLE_ARDUINO_STRING
layout: api
tags: api
api-group: Configuration
---

Enables the support of the type `String` in the library.

The default is `1` of `ARDUINO` is defined, `0` otherwise.
In other words, `String` is supported as soon as you work in an Arduino-compatible environment

### How to force the value?

If you need to force the support of `String`, add this at the top of your program:

```c++
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#include <ArduinoJson.h>
```

On the other hand, if you need to disable `String`, do:

```c++
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 0
#include <ArduinoJson.h>
```

### Where a `String` can be used?

Once enabled, you can use a `String` in many places.


1. You can use a String as your JSON input

    ```c++
    // WARNING: the content of the String will be duplicated in the JsonBuffer.
    String input = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
    JsonObject& root = jsonBuffer.parseObject(input);
    ```

2. You can use a String to get an element of a JsonObject

    ```c++
    long time = root[String("time")];
    ```

3. You can use a String to set an element of a JsonObject

    ```c++
    // WARNING: the content of the String will be duplicated in the JsonBuffer.
    root[String("time")] = time;
    ```

4. You can get a String from a JsonObject or JsonArray

    ```c++
    String sensor = root["sensor"];
    ```

5. You can set a String to a JsonObject or JsonArray:

    ```c++
    // WARNING: the content of the String will be duplicated in the JsonBuffer.
    root["sensor"] = sensor;
    ```

6. You can also concatenate strings

    ```c++
    // WARNING: the content of the String will be duplicated in the JsonBuffer.
    root[String("sen") + "sor"] = String("gp") + "s";
    ```

7. You can compare the content of a JsonObject with a String

    ```c++
    if (root["sensor"] == sensor) {
        // ...
    }
    ```

8. You can print the resulting JSON to a String

    ```c++
    String output;
    root.printTo(output);
    ```

### Where a `String` can **not** be used?

1. Unfortunately, the following doesn't work (issue #118):

    ```c++
    String sensor = "something";
    sensor = root["sensor"]; // <-  error "ambiguous overload for 'operator='"
    ```

2. As a workaround, you need to replace by:

    ```c++
    sensor = root["sensor"].as<String>();
    ```
