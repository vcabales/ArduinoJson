---
title: JsonArray::begin() / JsonArray::end()
layout: api
tags: api
api-group: JsonArray
---

##### Description
Returns an iterator that can be used to get all elements of the object.

##### Signatures

```c++
JsonArray::iterator begin();
JsonArray::iterator end();
JsonArray::const_iterator begin() const;
JsonArray::const_iterator end() const;
```

##### Return value
A forward iterator pointing to a `JsonVariant`.

##### Example

```c++
char json[] = "[\"one\",\"two\",\"three\"]";
DynamicJsonBuffer jsonBuffer;
JsonArray& arr = jsonBuffer.parseArray(json);

// using C++11 syntax (preferred):
for (auto value : arr) {
    Serial.println(value.as<char*>());
}

// using C++98 syntax (for older compilers):
for (JsonArray::iterator it=arr.begin(); it!=arr.end(); ++it) {
    Serial.println(it->as<char*>());
}
```

The code above would print:

```text
one
two
three
```
