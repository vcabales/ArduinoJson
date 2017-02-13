---
title: JsonObject::begin() / JsonObject::end()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Returns an iterator that can be used to get all key-value pairs in the object.

##### Signatures

```c++
JsonObject::iterator begin();
JsonObject::iterator end();
JsonObject::const_iterator begin() const;
JsonObject::const_iterator end() const;
```

##### Return value
A forward iterator pointing to a `JsonPair`, which itself contains two members `key` and `value`.

##### Example

```c++
char json[] = "{\"first\":\"hello\",\"second\":\"world\"}";
DynamicJsonBuffer jsonBuffer;
JsonObject& root = jsonBuffer.parseObject(json);

// using C++11 syntax (preferred):
for (auto kv : root) {
    Serial.println(kv.key);
    Serial.println(kv.value.as<char*>());
}

// using C++98 syntax (for older compilers):
for (JsonObject::iterator it=root.begin(); it!=root.end(); ++it) {
    Serial.println(it->key);
    Serial.println(it->value.as<char*>());
}
```

The code above would print:

```
first
hello
second
world
```
