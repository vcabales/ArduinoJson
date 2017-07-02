---
title: JsonVariant::success()
layout: api
tags: api
api-group: JsonVariant
---

##### Description

Tells whether the variant contains a value.

##### Signature

```c++
bool success() const;
```

##### Return value

* `true` if the variant contains a value,
* `false` if the variant is empty or invalid.

##### Example

```c++
JsonVariant variant;
bool beforeAssign = variant.success(); // false
variant = 42;
bool afterAssign = variant.success(); // true
```
