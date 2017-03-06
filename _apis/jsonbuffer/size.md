---
title: JsonBuffer::size()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description

Gets the current size (ie the number of bytes used).

This should not be confused with the capacity of the `JsonBuffer`, which is the total number of bytes that the buffer can hold.

##### Signatures

```c++
size_t size() const;
```

##### Return value

The size (ie the number of bytes used) of the `JsonBuffer`.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
Serial.println(jsonBuffer.size());
jsonBuffer.createObject();
Serial.println(jsonBuffer.size());
jsonBuffer.createArray();
Serial.println(jsonBuffer.size());
```

would print this on an 8-bit AVR:

```
0
4
8
```


