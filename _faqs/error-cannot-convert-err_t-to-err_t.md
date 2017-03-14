---
title: "Error: cannot convert 'err_t' to 'err_t (*)()"
layout: faq
tags: faq
faq-group: Known problems
---

There is currently a bug in the Arduino Core for Adafruit WICED Feather causing the following error:

```
error: cannot convert 'err_t' to 'err_t (*)()
```

See issue [#404](https://github.com/bblanchon/ArduinoJson/issues/404)