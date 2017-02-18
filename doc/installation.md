---
layout: doc
title: Installation
tags: doc
---

## If you use Arduino 1.6.x or newer

ArduinoJson is available in Arduino's Library Manager.
You can automatically install it from there.

> ##### Something wrong with the Library Manager?
>If ArduinoJson doesn't appear in Library Manager, or if only old versions are listed, try to delete the local cache. For example, on Windows, you need to delete:
>
>* `%LOCALAPPDATA%\Arduino15\library_index.json`
>* `%LOCALAPPDATA%\Arduino15\library_index.json.tmp.gz`
>You don't even need to close Arduino, just re-open the library manager.
{: .alert .alert-warning}


## If you use an old version of the Arduino IDE

You needed to [download the zip package](https://github.com/bblanchon/ArduinoJson/releases) and extract it to:

    <your Arduino Sketch folder>/libraries/ArduinoJson

Then restart the Arduino IDE.

## If you don't use Arduino IDE

ArduinoJson is a header-only library, so you just need to [download](https://github.com/bblanchon/ArduinoJson/releases) the package and unzip it in a convenient location.

Then add the `include/` folder to your compiler's or your IDE's include directories.

## Testing the examples

In Arduino IDE, click `File` / `Example` / `ArduinoJson`.

![Screen capture of Arduino IDE](http://i.imgur.com/g5UwkVh.png)

## What's next?

1. [Decoding JSON]({{site.baseurl}}/doc/decoding/)
2. [Generating JSON]({{site.baseurl}}/doc/encoding/)
