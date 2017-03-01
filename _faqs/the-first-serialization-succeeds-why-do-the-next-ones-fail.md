---
title: The first serialization succeeds, why do the next ones fail?
layout: faq
tags: faq
faq-group: Serialization
faq-popularity: 24
---

This is usually caused by a reused `JsonBuffer`.
The solution is simply to NOT reuse the `JsonBuffer`.

See [The first parsing succeeds, why do the next ones fail?]({{ site.baseurl }}/faq/the-first-parsing-succeeds-why-do-the-next-ones-fail/)
