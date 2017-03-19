---
title: Print to Stream
popularity: 40
---

ArduinoJson is able to print directly to a <code>Print</code> or <code>std::ostream</code>

```c++
// Send the JSON to the serial port
root.printTo(Serial);

// ...an Ethernet connection
root.printTo(ethernetClient);

// ...or a Wifi connection
root.printTo(wifiClient);
```