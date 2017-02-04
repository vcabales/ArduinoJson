---
title: JsonVariant description
layout: api
tags: api
api-group: JsonVariant
---

A variable that can hold different type of values:

* a boolean
* a char, short, int or a long (signed or unsigned)
* a string (const char*)
* a reference to a JsonArray or JsonObject

A `JsonVariant` can be any of theses types at a time, but can only hold one value.
Its type can change at run time.


### JsonVariant::as()

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


### JsonVariant::is()

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
