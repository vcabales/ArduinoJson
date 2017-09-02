---
title: What are the differences between <code>StaticJsonBuffer</code> and <code>DynamicJsonBuffer</code>?
layout: faq
tags: faq
faq-group: Common
popularity: 386
---

|                  | `StaticJsonBuffer`  | `DynamicJsonBuffer` |
| ---------------- | ------------------- | ------------------- |
| Size             | fixed               | variable :+1:       |
| Location         | stack :warning: <sup>(1)</sup> | heap     |
| Memory overhead  | small :+1:          | big                 |
| Code size        | small :+1:          | big                 |
| Speed            | fast :+1:           | slow<sup>(3)</sup>  |
| Cleanup          | automatic           | automatic           |
| Reusable         | no<sup>(2)</sup>    | no<sup>(2)</sup>    |
{: .table .table-striped .table-bordered .table-hover .table-sm}

<sup>(1)</sup> :warning: on most platforms, the stack cannot occupy all the RAM; for instance, it's limited to 4KB on the ESP8266.

<sup>(2)</sup> there is a workaround (see [How to reuse a `JsonBuffer`?]({{ site.baseurl }}/faq/how-to-reuse-a-jsonbuffer/) if you are looking for troubles).

<sup>(3)</sup> A `DynamicJsonBuffer` calls `malloc()` to allocate its memory, and it may have to do this several times if it needs to grow. However, you can specify an initial size to the constructor, so as to make sure that the buffer is big enough and that no further allocation will be needed.

:information_source: As a general rule, if your `StaticJsonBuffer` is bigger than 2KB, then it may be a good time to switch to a `DynamicJsonBuffer`.
