---
layout: doc
title: Memory Model
tags: doc
---

## Fixed memory allocation

### Introducing `StaticJsonBuffer`

Arduino JSON uses a preallocated memory pool to store the object tree, this is done by the `StaticJsonBuffer` class.

Before using any function of the library you need to create a `StaticJsonBuffer`. Then you can use this instance to create arrays and objects, or parse a JSON string.

`StaticJsonBuffer` has a template parameter that determines its capacity. For example, the following line creates a `StaticJsonBuffer` with a capacity of 200 bytes:

```c++
StaticJsonBuffer<200> jsonBuffer;
```

The bigger the buffer is, the more complex the object tree can be, but also the more memory you need.

### How to determine the buffer size?

So the big question you should have in mind right now is *How can I determine the size?*.

There are basically two approaches here:

1. either you can predict the content of the object tree,
2. or, you know how much memory is available.

In the first case, you know some constraints on the object tree. For instance, let's say that you know in advance (and by that I mean "at compilation time") that you want to generate an object with 3 values, one of them being an array with 2 values, like the following:

```json
{"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}
```

To determine the memory usage of this object tree, you use the two macros `JSON_ARRAY_SIZE(n)` and `JSON_OBJECT_SIZE(n)`, both take the number of elements as an argument.
For the example above, it would be:

```c++
const int BUFFER_SIZE = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2);
StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
```

If you're in this situation, [ArduinoJson Assistant]({{ site.baseurl }}/assistant/) will be of great help.

In the second case, let's say you dynamically generate a JSON object tree of a random complexity so you can't put a limit based on that. But on the other hand, you don't want your program to crash because the object tree doesn't fit in memory.
The solution here is to determine how much memory is available, or in other words how much memory you can afford for the JSON object tree.

### Why choose fixed allocation?

This fixed allocation approach may seem a bit strange, especially if you are a desktop application developer used to dynamic allocation, but it makes a lot of sense in an embedded context:

1. the code is smaller
2. it uses less memory
3. it doesn't create memory fragmentation
4. it is predictable

Don't forget that the memory is "freed" as soon as the `StaticJsonBuffer` is out of scope, like any other variable. It only holds the memory for a short amount of time.

## Dynamic memory allocation

This library also supports dynamic memory allocation.

However, usage of this memory model make sense only for devices with more that 10KB or RAM

To switch to dynamic memory allocation, simply replace:

```c++
StaticJsonBuffer<N> jsonBuffer;
```

by

```c++
DynamicJsonBuffer jsonBuffer;
```

Memory is released in `DynamicJsonBuffer`'s destructor, so you don't have to do anything special.

## Memory usage

#### Object size for 8-bit AVR

| Type                    | Size       |
|-------------------------|------------|
| JsonArray of N element  | 4 + 8 * N  |
| JsonObject of N element | 4 + 10 * N |
{: .table .table-bordered .table-responsive }

#### Object size on ESP8266

| Type                    | Size       |
|-------------------------|------------|
| JsonVariant             | 8          |
| JsonArray of N element  | 8 + 12 * N |
| JsonObject of N element | 8 + 16 * N |
{: .table .table-bordered .table-responsive }

#### Object size on ESP8266 if `JsonFloat` is changed to `double`

| Type                    | Size       |
|-------------------------|------------|
| JsonVariant             | 16         |
| JsonArray of N element  | 8 + 24 * N |
| JsonObject of N element | 8 + 32 * N |
{: .table .table-bordered .table-responsive }

#### Object size on x86 (tested on Visual Studio 2015)

| Type                    | Size        |
|-------------------------|-------------|
| JsonVariant             | 16          |
| JsonArray of N element  | 12 + 24 * N |
| JsonObject of N element | 12 + 32 * N |
{: .table .table-bordered .table-responsive }

#### Object size on x64 (tested on Visual Studio 2015)

| Type                    | Size        |
|-------------------------|-------------|
| JsonVariant             | 16          |
| JsonArray of N element  | 24 + 24 * N |
| JsonObject of N element | 24 + 32 * N |
{: .table .table-bordered .table-responsive }

Use [ArduinoJson Assistant]({{ site.baseurl }}/assistant/) to compute the size require for your project.
