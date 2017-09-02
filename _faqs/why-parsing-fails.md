---
title: Why parsing fails?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 432
---

The parsing functions, `parseArray()` and `parseObject()`, may fail for 6 reasons:

1. [The input is not a valid JSON](#case-1-the-input-is-not-a-valid-json)
2. [The `StaticJsonBuffer` is too small](#case-2-the-staticjsonbuffer-is-too-small)
3. [The `StaticJsonBuffer` is too big (stack overflow)](#case-3-the-staticjsonbuffer-is-too-big)
4. [The `DynamicJsonBuffer` fails to allocate memory](#case-4-the-dynamicjsonbuffer-fails-to-allocate-memory)
5. [You called `parseObject()` instead of `parseArray()`](#case-5-you-called-parseobject-instead-of-parsearray)
6. [The nesting limit is too low](#case-6-the-nesting-limit-is-too-low)

## Case 1: The input is not a valid JSON

This seems obvious, but a lot of issues are caused by an invalid input.

In particular, if you're writing an HTTP client, you need to

1. Skip the HTTP headers.
2. Use HTTP 1.0 to prevent [chunked transfer encoding](https://fr.wikipedia.org/wiki/Chunked_transfer_encoding)

See [JsonHttpClient.ino]({{site.baseurl}}/example/http-client/) for a reference implementation.

## Case 2: The `StaticJsonBuffer` is too small

A `JsonBuffer` is a memory pool where the JSON parser stores the tokens of the parsed object.

`StaticJsonBuffer` is an implementation of a `JsonBuffer` with fixed memory allocation.

This means that you need to specify the right size for the `StaticJsonBuffer`, otherwise the parser will not be able to allocate the memory it needs, and therefore it will return an error.

Use [ArduinoJson Assistant]({{site.baseurl}}/assistant/) to compute the required size.

See also: [How to reduce memory usage?]({{site.baseurl}}/faq/how-to-reduce-memory-usage/)

## Case 3: The `StaticJsonBuffer` is too big

A `StaticJsonBuffer` is usually allocated on the [stack](https://en.wikipedia.org/wiki/Stack-based_memory_allocation), if it's too big it will overlap with other variables. This usually leads to a crash or a reboot of the device.

If you are in this situation, you can either:

* Reduce the size of the `StaticJsonBuffer`, use [ArduinoJson Assistant]({{site.baseurl}}/assistant/) to compute the required size.
* Switch to a `DynamicJsonBuffer` which is allocated on the heap.

For example, a ESP8266 has 4KB of stack memory. This means you only have 4096 bytes to store all your local variables, function parameters and calls return addresses. If the [ArduinoJson Assistant]({{site.baseurl}}/assistant/) says you need more than 1KB of RAM for the `JsonBuffer`, then you should use a `DynamicJsonBuffer`.

See also: [How to reduce memory usage?]({{site.baseurl}}/faq/how-to-reduce-memory-usage/)

## Case 4: The `DynamicJsonBuffer` fails to allocate memory

Unlike the `StaticJsonBuffer` which has a fixed size, the `DynamicJsonBuffer` will automatically grow when full.
If the [heap memory](https://en.wikipedia.org/wiki/Memory_management#HEAP) is exhausted, the `DynamicJsonBuffer` will fail to allocate memory and the parsing will fail.

If you are in this situation:

* Make sure you have enough RAM, use [ArduinoJson Assistant]({{site.baseurl}}/assistant/) to compute the required size.
* Make sure you don't [reuse the same `JsonBuffer`]({{site.baseurl}}/faq/how-to-reuse-a-jsonbuffer/).
  In particular make sure you don't use a [global `JsonBuffer`]({{site.baseurl}}/faq/why-shouldnt-i-use-a-global-jsonbuffer/).

See also: [How to reduce memory usage?]({{site.baseurl}}/faq/how-to-reduce-memory-usage/)

## Case 5: You called `parseObject()` instead of `parseArray()`

This is a very common question as people are often confused when the JSON input contains mixed arrays and objects.

The answer is very simple: it's the type of the root that matters.
This means that you just need to look at the first character: it's either a `[`, for an array, or a `{`, for an object.

For example, if the input is:

```json
{"mickey":["mouse"],"donald":["duck"]}
```

then you must call [`parseObject()`]({{site.baseurl}}/api/jsonbuffer/parseobject/) because the root is an object.

And, if the input is:

```json
[{"mickey":"mouse","donald":"duck"}]
```

then you must call [`parseArray()`]({{site.baseurl}}/api/jsonbuffer/parsearray) because the root is an array.

Finally, if you cannot know in advance the type of the root, simply use [`JsonBuffer::parse()`]({{site.baseurl}}/api/jsonbuffer/parse/) which returns a `JsonVariant`.

See also: [Parsing succeeds but I can't read the values!]({{site.baseurl}}/faq/parsing-succeeds-but-i-cant-read-the-values/)

## Case 6: The nesting limit is too low

This can happen if you're parsing an array or an object with many nesting levels, i.e. with a very deep layout.

You can solve this in two ways:

1. You can pass an additional argument to [`parseObject()`]({{site.baseurl}}/api/jsonbuffer/parseobject) to specify the new limit.
2. You can define [`ARDUINOJSON_DEFAULT_NESTING_LIMIT`]({{site.baseurl}}/api/config/default_nesting_limit) which is the default for this argument
