---
title: JsonObject::containsKey()
layout: api
tags: api
api-group: JsonObject
---

##### Description
Tests if a key exists in the `JsonObject`.

##### Signature

```c++
bool containsKey(const char* key) const;
bool containsKey(const String& key) const;
bool containsKey(const std::string& key) const;
```

##### Arguments

`key`: the key to test.

##### Return value

`true` if the key is present is the `JsonObject`; `false` if not.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["city"] = "Paris";

bool hasCity = root.containsKey("city"); // true
bool hasCountry = root.containsKey("country"); // false
```

> #### Avoid this function when you can!
> 
> Using this function is not strictly necessary and can be avoided most of the time.
> Indeed, since ArduinoJson implements the [Null Object Pattern](https://en.wikipedia.org/wiki/Null_Object_pattern), it is always safe to read the object.
> If the key doesn't exist, it will return an empty value.
> 
> For example:
> 
> ```c++
> if (root.containsKey("error"))
> {
>   const char* error = root["error"]
>   Serial.println(error);
>   return;
> }
> ```
> 
> Can be written like this:
> 
> ```c++
> const char* error = root["error"];
> if (error) 
> {
>   Serial.println(error);
>   return;
> }
> ```
> 
> This will lead to a **smaller** and **faster** code, since the look-up is only done once.
{: .alert .alert-danger }

> #### How to test nested keys?
> 
> You cannot test the presence of nested keys with `containsKey()` but, as explain above, it's safe to read the object anyway.
> 
> For example, when [Weather Underground](www.wunderground.com) returns an error like:
> 
> ```json
> {
>   "response": {
>     "version": "0.1",
>     "termsofService": "http://www.wunderground.com/weather/api/d/terms.html",
>     "features": {
>       "conditions": 1
>     },
>     "error": {
>       "type": "querynotfound",
>       "description": "No cities match your search query"
>     }
>   }
> }
> ```
> 
> You should not try to call `containsKey("response")`, `containsKey("error")` and `containsKey("description")`.
> Instead, just get the value and test if it's `NULL`:
> 
> ```c++
> const char* error = root["response"]["error"]["description"];
> if (error)
> {
>   Serial.println(error);
>   return;
> }
> ```
{: .alert .alert-info }