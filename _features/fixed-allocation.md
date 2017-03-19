---
title: Fixed Memory Allocation
popularity: 90
---

ArduinoJson uses a fixed memory allocation, allowing to work on devices with very little RAM.

You can choose to store data in the stack:

```c++
StaticJsonBuffer<512> jsonBuffer
```

...or on the heap

```c++
DynamicJsonBuffer jsonBuffer(512)
```
