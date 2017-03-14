---
title: "Sloeber Arduino Eclipse Plugin"
layout: faq
tags: faq
faq-group: Known problems
---

When compiling ArduinoJson within the Sloeber Arduino Eclipse Plugin, you may encounter the following error:

```
error: expected class-name before '{' token class memstream : public std::istream
```

You need to add the `fuzzin/` folder to the "Source Folder Exclusion Patterns", like on the pricture bellow:

![Source Folder Exclusion Patterns](https://cloud.githubusercontent.com/assets/1175841/22299097/2af90b14-e323-11e6-8b21-5f0f91055e60.png)

See issues [ArduinoJson #432](https://github.com/bblanchon/ArduinoJson/issues/432) and [Sloeber #642](https://github.com/Sloeber/arduino-eclipse-plugin/issues/642).
