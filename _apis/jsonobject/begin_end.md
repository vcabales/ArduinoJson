---
title: JsonObject::begin() / JsonObject::end()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Returns an iterator that can be use to get all key-value pairs in the object.

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

// using C++98 syntax:
for (JsonObject::iterator it=root.begin(); it!=root.end(); ++it) {
    Serial.println(it->key);
    Serial.println(it->value);
}

// using C++11 syntax:
for (auto kv : root) {
    Serial.println(kv.key);
    Serial.println(kv.value);
}
```

The code above would print:

```
first
hello
second
world
```
