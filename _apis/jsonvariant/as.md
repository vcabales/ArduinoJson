---
title: JsonVariant::as()
layout: api
tags: api
api-group: JsonVariant
---

##### Description

Get the value of the specified type.

##### Signatures

```c++
bool               as<bool>() const;

float              as<float>() const;
double             as<double>() const;

signed char        as<signed char>() const;
unsigned char      as<unsigned char>() const;
signed int         as<signed int>() const;
unsigned int       as<unsigned int>() const;
signed short       as<signed short>() const;
unsigned short     as<unsigned short>() const;
signed long        as<signed long>() const;
unsigned long      as<unsigned long>() const;
unsigned long long as<unsigned long long>() const;   // <- may require ARDUINOJSON_USE_LONG_LONG
signed long long   as<signed long long>() const;     // <- may require ARDUINOJSON_USE_LONG_LONG
signed __int64     as<signed __int64>() const;       // <- may require ARDUINOJSON_USE_INT64
unsigned __int64   as<unsigned __int64>() const;     // <- may require ARDUINOJSON_USE_INT64

const char*        as<char*>() const;
const char*        as<const char*>() const;
String             as<String>() const;               // <- causes duplication of the string
std::string        as<std::string>() const;          // <- causes duplication of the string

JsonArray&         as<JsonArray>() const;
JsonArray&         as<JsonArray&>() const;
JsonArray&         as<const JsonArray&>() const;
JsonObject&        as<JsonObject>() const;
JsonObject&        as<JsonObject&>() const;
JsonObject&        as<const JsonObject&>() const;
```

##### Return value

The value of the specified type or a default value if the `JsonVariant` is not compatible with the specified type.

The default value is:

* `0` for numerical types
* `NULL` for `const char*`
* `JsonArray::invalid()` for `JsonArray&`
* `JsonObject::invalid()` for `JsonObject&`

##### Example

```c++
JsonVariant variant = 42;
int i = variant.as<int>(); // <- i == 42
double d = variant.as<double>(); // <- d == 42.0
const char* s = variant.as<char*>(); // <- s == NULL
```
