---
title: JsonVariant::is()
layout: api
tags: api
api-group: JsonVariant
---

##### Description

Test if the variant is currently holding a value of the specified type.

##### Signatures

```c++
bool is<bool>() const;

bool is<float>() const;
bool is<double>() const;

bool is<signed char>() const;
bool is<unsigned char>() const;
bool is<signed int>() const;
bool is<unsigned int>() const;
bool is<signed short>() const;
bool is<unsigned short>() const;
bool is<signed long>() const;
bool is<unsigned long>() const;
bool is<unsigned long long>() const;   // <- may require ARDUINOJSON_USE_LONG_LONG
bool is<signed long long>() const;     // <- may require ARDUINOJSON_USE_LONG_LONG
bool is<signed __int64>() const;       // <- may require ARDUINOJSON_USE_INT64
bool is<unsigned __int64>() const;     // <- may require ARDUINOJSON_USE_INT64

bool is<char*>() const;
bool is<const char*>() const;

bool is<JsonArray>() const;
bool is<JsonArray&>() const;
bool is<const JsonArray&>() const;
bool is<JsonObject>() const;
bool is<JsonObject&>() const;
bool is<const JsonObject&>() const;
```

##### Return value

* `true` if the variant is currently holding a value of the specified type,
* `false` if not

##### Example

```c++
JsonVariant variant = 42;
bool i = variant.is<int>(); // <- i == true
bool d = variant.is<double>(); // <- d == false
bool s = variant.is<char*>(); // <- s == false
```
