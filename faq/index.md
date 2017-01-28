---
layout: page
title: FAQ
tags: faq
---

Frequently Asked Questions
===========

### Part 1 - Common questions

{% for post in site.categories.faq reversed  %}
{% capture post_year %}{{post.date | date: "%Y"}}{% endcapture %}
{% if post_year == "2000" %}
<li><a href='{{ site.baseurl }}{{ post.url }}'>{{ post.title }}</a></li>
{% endif %}
{% endfor %}

### Part 2 - Serialization questions

{% for post in site.categories.faq reversed  %}
{% capture post_year %}{{post.date | date: "%Y"}}{% endcapture %}
{% if post_year == "2001" %}
<li><a href='{{ site.baseurl }}{{ post.url }}'>{{ post.title }}</a></li>
{% endif %}
{% endfor %}

###  Part 3 - Deserialization/parsing questions

{% for post in site.categories.faq reversed  %}
{% capture post_year %}{{post.date | date: "%Y"}}{% endcapture %}
{% if post_year == "2002" %}
<li><a href='{{ site.baseurl }}{{ post.url }}'>{{ post.title }}</a></li>
{% endif %}
{% endfor %}
