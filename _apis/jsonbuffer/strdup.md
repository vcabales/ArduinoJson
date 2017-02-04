---
title: JsonBuffer::strdup()
layout: api
tags: api
api-group: JsonBuffer
---

##### Description

Make a copy of the specified string.

##### Signatures

```c++
char* strdup(const char* str);
char* strdup(const String& str);
char* strdup(const std::string& str);
```

##### Arguments

`str`, the string to duplicate.

##### Return value

A newly allocate string, filled with a copy of `str`.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
char orig[16] = "hello";
char* dupl = jsonBuffer.strdup(orig);
strcpy(orig, "world");
Serial.println(dupl); // world
Serial.println(orig); // hello
```


