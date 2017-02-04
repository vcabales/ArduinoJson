---
layout: page
title: API Reference
tags: api
permalink: /api/index.html
---

API Reference
===========

This is the detailed documentation of every class and function of the ArduinoJson library.
Some parts have been simplified to be easier to understand, so if you look at the source code, you might see some differences.


<ul>
{% assign groups = site.apis | group_by: 'api-group' %}
{% for group in groups %}
  <li><code>{{ group.name }}</code>
    <ul>
    {% assign items = group.items | sort: 'title' %}
    {% for api in items %}
      <li><a href="{{ site.baseurl }}{{ api.url }}"><code>{{ api.title }}</code></a></li>
    {% endfor %}
    </ul>
  </li>
{% endfor %}
</ul>
