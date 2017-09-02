---
title: "Atmel Studio"
layout: faq
tags: faq
faq-group: Known problems
faq-popularity: 13
---

>:warning: To use ArduinoJson within Atmel Studio 7, **do not** use the "Add Arduino Library" feature.
{: .alert .alert-danger}

Instead, use one of the following solution.

### Option 1: Set include directory

1. Download (or `git clone`) ArduinoJson where you want.
2. Right-click on target project and click `Properties`
3. Open the `Toolchain` tab
4. Under `Compiler / Directies`, click on `Add Item`
   A dialog box entitled "Add Include Paths (-I)" should appear.
5. Enter the location of the `src/` folder of ArduinoJson

Now the compiler knows where to find `ArduinoJson.h`.

### Option 2: Use "single header" version

1. Download the "single header" from the [Releases](https://github.com/bblanchon/ArduinoJson/releases), for example `ArduinoJson-v5.10.0.h`.
   (you cannot use `git clone` to get the "single header")
2. Copy this file in your project folder.

The compiler will find `ArduinoJson-v5.10.0.h` as it's in your project folder.