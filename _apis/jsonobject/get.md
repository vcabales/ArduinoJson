---
title: JsonObject::get()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Gets the value at the specified index.

##### Signature
```c++
bool            get<bool>           (TString key) const;
const char*     get<const char*>    (TString key) const;
double          get<double>         (TString key) const;
float           get<float>          (TString key) const;
JsonVariant     get<JsonVariant>    (TString key) const;
signed char     get<signed char>    (TString key) const;
signed int      get<signed int>     (TString key) const;
signed long     get<signed long>    (TString key) const;
signed short    get<signed short>   (TString key) const;
std::string     get<std::string>    (TString key) const;
String          get<String>         (TString key) const;
unsigned char   get<unsigned char>  (TString key) const;
unsigned int    get<unsigned int>   (TString key) const;
unsigned long   get<unsigned long>  (TString key) const;
unsigned short  get<unsigned short> (TString key) const;
```

##### Arguments

`key`: the key of the value in the object, can be a `const char*`, a `String` or an `std::string`.

##### Return value

The value at the specified key, converted to the specified type.
In case of an error (key not found or incompatible type), the default value of the specified type is returned.

##### Example

```c++
char json[] = "{\"pi\":3.14}";
StaticJsonBuffer<256> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject(json);
float pi = object.get<float>("pi"); // template version of get()
const char* value2 = object.get<const char*>("toto"); // returns NULL
```
