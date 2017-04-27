---
title: How to reduce memory usage?
layout: faq
tags: faq
faq-group: Deserialization
faq-popularity: 0
---

If the input string is constant, the `JsonBuffer` will have to make a copy of it.

```c++
// case 1: char array => no duplication => good
char[] json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 2: const char* => duplication => bad
const char* json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 3: String => duplication => bad
String json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);
```

To avoid any duplication, make sure you use an input of type `char*` or `char[]`.

>## Special case: streams
>
>A stream (`Stream` or `std::istream`) is a source of volatile bytes, so its content needs to be copied in RAM.
>
>The best thing to do is to let ArduinoJson do the duplication as it will ignore everything that is not required:
>1. punctuation
>2. spaces
>3. comments
>
>To do that, simply pass the stream to [`parseArray()`]({{site.baseurl}}/api/jsonbuffer/parsearray) or [`parseObject()`]({{site.baseurl}}/api/jsonbuffer/parseobject/).
>
>See [JsonHttpClient.ino]({{site.baseurl}}/example/http-client/) for an example.
{: .alert .alert-warning}

See also [Why is the input modified?]({{site.baseurl}}/faq/why-is-the-input-modifed/)