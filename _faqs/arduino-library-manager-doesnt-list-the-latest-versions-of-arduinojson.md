---
title: "Arduino Library Manager doesn't list the latest versions of ArduinoJson"
layout: faq
tags: faq
faq-group: Known problems
faq-popularity: 50
---

This is a very common issue.

If ArduinoJson doesn't appear in Libray Manager, or if only old versions are listed, try to delete the local cache.
This will force the Libray Manager to download the library list from scratch.

For example, on Windows, you need to delete:

* `%LOCALAPPDATA%\Arduino15\library_index.json`
* `%LOCALAPPDATA%\Arduino15\library_index.json.tmp.gz`

You don't even need to close Arduino, just re-open the library manager.
