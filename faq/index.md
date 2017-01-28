---
layout: page
title: FAQ
tags: faq
---

Frequently Asked Questions
===========

- [Part 1 - Common questions](#part-1---common-questions){% for post in site.categories.faq reversed  %}
  - [{{ post.title }}]({{ site.baseurl }}{{ post.url }}){% endfor %}
- [Part 2 - Serialization questions](#part-2---serialization-questions)
  - [Why some parts are missing?](#why-some-parts-are-missing)
  - [Why does the generated JSON contain garbage?](#why-does-the-generated-json-contain-garbage)
  - [How to compute the JSON length?](#how-to-compute-the-json-length)
  - [How to create complex nested objects?](#how-to-create-complex-nested-objects)
  - [How to insert a `null`?](#how-to-insert-a-null)
  - [The first serialization succeeds, why do the next ones fail?](#the-first-serialization-succeeds-why-do-the-next-ones-fail)
  - [Why ArduinoJson is slow?](#why-arduinojson-is-slow)
- [Part 3 - Deserialization/parsing questions](#part-3---deserializationparsing-questions)
  - [Why do I have a segmentation fault?](#why-do-i-have-a-segmentation-fault)
  - [Can I parse data from a stream?](#can-i-parse-data-from-a-stream)
  - [Can I parse a JSON input that is too big to fit in memory?](#can-i-parse-a-json-input-that-is-too-big-to-fit-in-memory)
  - [Why parsing fails?](#why-parsing-fails)
  - [The first parsing succeeds, why do the next ones fail?](#the-first-parsing-succeeds-why-do-the-next-ones-fail)
  - [Parsing succeeds but I can't read the values!](#parsing-succeeds-but-i-cant-read-the-values)
  - [How to know the type of a value?](#how-to-know-the-type-of-a-value)
  - [Can I access to object member by its index, instead of its key?](#can-i-access-to-object-member-by-its-index-instead-of-its-key)
  - [How to fix error "Ambiguous overload for 'operator='"](#how-to-fix-error-ambiguous-overload-for-operator)
  - [Why JsonVariant cannot be converted to char?](#why-jsonvariant-cannot-be-converted-to-char)


## Part 2 - Serialization questions


### Why some parts are missing?

Example: you want to write `{"p1":[0, 1]}`, but instead you get `{"p1":[]}`.

This is because the `StaticJsonBuffer` too small.

Solution: Increase the size of the `StaticJsonBuffer` or switch to a `DynamicJsonBuffer`.

See also:

* [What are the differences between StaticJsonBuffer and DynamicJsonBuffer?](#what-are-the-differences-between-staticjsonbuffer-and-dynamicjsonbuffer)
* [How to determine the buffer size?](#how-to-determine-the-buffer-size)
* [JsonBuffer size calculator](https://bblanchon.github.io/ArduinoJson/)
* Issues [#360](https://github.com/bblanchon/ArduinoJson/issues/360), [#372](https://github.com/bblanchon/ArduinoJson/issues/372), [#374](https://github.com/bblanchon/ArduinoJson/issues/374) and [#380](https://github.com/bblanchon/ArduinoJson/issues/380)


### Why does the generated JSON contain garbage?

There are two key concepts you need to understand to use ArduinoJson:

1. `JsonObject`s and `JsonArray`s are stored in a `JsonBuffer`
2. `char*` are not copied

Similarly, there are two reasons to get garbage in the output:

1. `JsonBuffer` is not in memory anymore
2. The string pointed by the `char*` is not in memory anymore.

##### Example 1 of what you should not do:

```c++
JsonObject& myFunction() {
  StaticJsonBuffer<200> jsonBuffer;
  return jsonBuffer.createObject();
}
```

This is wrong because it returns a reference (a pointer if you prefer) to a `JsonObject` that is not in memory anymore.

##### Example 2 of what you should not do:

```c++
void myFunction(JsonObject& obj) {
  char myValue[] = "Hello World!";
  obj["value"] = myValue;
}
```

This is wrong because the `JsonObject` now contains a pointer to a string that is not in memory anymore.

See also:

* [Avoiding pitfalls: Do not assume that strings are copied](https://github.com/bblanchon/ArduinoJson/wiki/Avoiding-pitfalls#6-do-not-assume-that-strings-are-copied)
* Issues [#364](https://github.com/bblanchon/ArduinoJson/issues/364), [#366](https://github.com/bblanchon/ArduinoJson/issues/366)

### How to compute the JSON length?

Use `measureLength()` to compute the number of characters that will be printed by `printTo()`.

Use `measurePrettyLength()` to compute the number of characters that will be printed by `prettyPrintTo()`.

None of these methods include the zero-terminator.
So if you need to allocate a buffer, don't forget to add 1 to the size.

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["hello"] = world;

size_t len = root.measureLength(); // returns 17

size_t size = len+1;
char json[size];
root.printTo(json, size); // writes {"hello":"world"}
```

See issues [#75](https://github.com/bblanchon/ArduinoJson/issues/75), [#94](https://github.com/bblanchon/ArduinoJson/issues/94), [#166](https://github.com/bblanchon/ArduinoJson/issues/166), [#178](https://github.com/bblanchon/ArduinoJson/issues/178) and [#268](https://github.com/bblanchon/ArduinoJson/issues/268).


### How to create complex nested objects?

To create a nested object, call `createNestedObject()`.
To create a nested array, call `createNestedArray()`.

For example:

```c++
DynamicJsonBuffer jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

JsonObject& weather = root.createNestedObject("weather");
weather["temperature"] = 12;
weather["condition"] = "cloudy";

JsonArray& coords = root.createNestedArray("coords");
coords.add(48.7507371, 7);
coords.add(2.2625587, 7);

root.prettyPrintTo(Serial);
```

will generate:

```json
{
  "weather": {
    "temperature": 12,
    "condition": "cloudy"
  },
  "coords": [
    48.7507371,
    2.2625587
  ]
}
```

See:

* issues [#51](https://github.com/bblanchon/ArduinoJson/issues/51), [#252](https://github.com/bblanchon/ArduinoJson/issues/252) and [#264](https://github.com/bblanchon/ArduinoJson/issues/264)
* [API Reference: JsonArray::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonarraycreatenestedarray)
* [API Reference: JsonArray::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonarraycreatenestedarray)
* [API Reference: JsonObject::createNestedArray()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonobjectcreatenestedarray)
* [API Reference: JsonObject::createNestedObject()](https://github.com/bblanchon/ArduinoJson/wiki/API-Reference#jsonobjectcreatenestedobject)


### How to insert a `null`?

There are two ways to serialize a `null`:

* either set the value to `(char*)0`,
* or set the value to `RawJson("null")`

For example, to generate the following JSON:

```json
{"myValue":null}
```

you can write:

```c++
DynamicJsonBuffer jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["myValue"] = (char*)0; // or (char*)NULL if you prefer
root.printTo(Serial);
```

See:

* issue [#418](https://github.com/bblanchon/ArduinoJson/issues/418)



### The first serialization succeeds, why do the next ones fail?

This is usually caused by a reused `JsonBuffer`.
The solution is simply to NOT reuse the `JsonBuffer`.

See [The first parsing succeeds, why do the next ones fail?](#the-first-parsing-succeeds-why-do-the-next-ones-fail)



### Why ArduinoJson is slow?

First of all, ArduinoJson is **not slow** by itself. It's slow when used in conjunction with the `WifiClient` from the ESP8266 core.

The problem is that there is no buffer between ArduinoJson and the WifiClient.

To solve this, either:

1. Enable the [Nagle algorithm](https://en.wikipedia.org/wiki/Nagle%27s_algorithm) on `WifiClient` by calling `setNoDelay(false)`.
2. Serialize to a buffer and send the whole buffer in one shot.
3. Insert a [BufferedPrint](https://github.com/bblanchon/ArduinoJson/wiki/Bag%20of%20Tricks#buffered-output) proxy between ArduinoJson and `WifiClient`.

See issue [#166](https://github.com/bblanchon/ArduinoJson/issues/166), [#271](https://github.com/bblanchon/ArduinoJson/issues/271) and [#301](https://github.com/bblanchon/ArduinoJson/issues/301)


## Part 3 - Deserialization/parsing questions


### Why do I have a segmentation fault?

`parseArray()` and `parseObject()` may cause a segmentation fault if the input string is in a read-only segment.

Indeed, the parser modifies the string for two reasons:

1. it inserts `\0` to terminate substrings,
2. it translate escaped characters like `\n` or `\t`.

Most of the time this wont be an issue, but there are some corner cases that can be problematic.

Let take the example bellow:

    char[] json = "[\"hello\",\"world\"]";
    StaticJsonBuffer<32> buffer;
    JsonArray& array = buffer.parseArray(json);

If you replace it by:

    char* json = "[\"hello\",\"world\"]";
    StaticJsonBuffer<32> buffer;
    JsonArray& array = buffer.parseArray(json);

Depending on your platform, you may have an exception because the parser tries to write at a location that is read-only.
In the first case `char json[]` declares an array of `char` initialized to the specified string.
In the second case `char* json` declares a pointer to a read-only string, in fact it should be a `const char*` instead of a `char*`.

See:

* issue [#378](https://github.com/bblanchon/ArduinoJson/issues/378)
* [Avoiding pitfalls: Make sure the string isn't read-only](https://github.com/bblanchon/ArduinoJson/wiki/Avoiding%20pitfalls#7-make-sure-the-string-isnt-read-only)


### Can I parse data from a stream?

Yes.

Since ArduinoJson 5.8, `parseArray()` and `parseObject()` accept Arduino's `Stream` and `std::istream` as input:

```c++
JsonObject& root = jsonObject.parseObject(myStream);
```

CAUTION: parts of the input need to be copied into the `JsonBuffer`, so you need to increase its capacity accordingly.

See:

* [Examples: JsonHttpClient.ino](https://github.com/bblanchon/ArduinoJson/blob/master/examples/JsonHttpClient/JsonHttpClient.ino#L149)
* [API Reference: JsonBuffer::parseArray()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonbufferparsearray)
* [API Reference: JsonBuffer::parseObject()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonbufferparseobject)
* [JsonBuffer size calculator](https://bblanchon.github.io/ArduinoJson/)
* Issues [#119](https://github.com/bblanchon/ArduinoJson/issues/119), [#300](https://github.com/bblanchon/ArduinoJson/issues/300), [#422](https://github.com/bblanchon/ArduinoJson/issues/422) and [#429](https://github.com/bblanchon/ArduinoJson/issues/429)



### Can I parse a JSON input that is too big to fit in memory?

No.

This is a fundamental design principle in this library.
The JSON input must be in memory and must be mutable (i.e., not read-only) to allow zero-copy and zero-allocation, which is *the* strength of this library.

Let's see an example to understand why this is important:

```c++
char json[] = "{\"hello\":\"world\"}";
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

After executing the lines above, the variable `world` will point to the word `"world"` inside the `json` string. During the call to `parseObject()`, the `json` string has been modified to insert the necessary zero-terminator (`\0`), to cut the string `world`.
As you can see this process requires neither duplication nor allocation, but imposes the input to be stored in a `char[]`.

To parse data from a stream, you'll have to read its content and put it in a `char[]`:

```c++
#define MAX_JSON_SIZE 256

char json[MAX_SIZE];
stream.readBytesUntil('\n', json, MAX_JSON_SIZE);
```

If this is not acceptable, you should have a look at other libraries, like [json-streaming-parser](https://github.com/squix78/json-streaming-parser).

See issues [#60](https://github.com/bblanchon/ArduinoJson/issues/60), [#119](https://github.com/bblanchon/ArduinoJson/issues/119), [#194](https://github.com/bblanchon/ArduinoJson/issues/194), [#200](https://github.com/bblanchon/ArduinoJson/issues/200) and [#223](https://github.com/bblanchon/ArduinoJson/issues/223).



### Why parsing fails?

The parsing functions, `parseArray()` and `parseObject()`, may fail for 5 reasons:

1. [The input is not a valid JSON](#case-1-the-input-is-not-a-valid-json)
2. [The `StaticJsonBuffer` is too small](#case-2-the-staticjsonbuffer-is-too-small)
3. [The `StaticJsonBuffer` is too big (stack overflow)](#case-3-the-staticjsonbuffer-is-too-big)
4. [The `DynamicJsonBuffer` fails to allocate memory](#case-4-the-dynamicjsonbuffer-fails-to-allocate-memory)
5. [You called `parseObject()` instead of `parseArray()`](#case-5-you-called-parseobject-instead-of-parsearray)

#### Case 1: The input is not a valid JSON

This seems obvious, but a lot of issues are caused by from an invalid input.
In particular, if you're writing an HTTP client, you need to skip the HTTP headers and send only the JSON payload to ArduinoJson.

See:

* Issues [#108](https://github.com/bblanchon/ArduinoJson/issues/108), [#167](https://github.com/bblanchon/ArduinoJson/issues/167), [#218](https://github.com/bblanchon/ArduinoJson/issues/218), [#237](https://github.com/bblanchon/ArduinoJson/issues/237), [#424](https://github.com/bblanchon/ArduinoJson/issues/424), [#430](https://github.com/bblanchon/ArduinoJson/issues/430) and [#431](https://github.com/bblanchon/ArduinoJson/issues/431)

#### Case 2: The `StaticJsonBuffer` is too small

You can solve the problem by increasing the size of the `StaticJsonBuffer` or by switching to a `DynamicJsonBuffer`.

See:

* Issues [#53](https://github.com/bblanchon/ArduinoJson/issues/53), [#89](https://github.com/bblanchon/ArduinoJson/issues/89), [#202](https://github.com/bblanchon/ArduinoJson/issues/202), [#280](https://github.com/bblanchon/ArduinoJson/issues/280), [#293](https://github.com/bblanchon/ArduinoJson/issues/293) and [#296](https://github.com/bblanchon/ArduinoJson/issues/296)

#### Case 3: The `StaticJsonBuffer` is too big

You can try to switch to a `DynamicJsonBuffer`. Indeed, most platforms have a fixed size of the stack (usually 4KB on the ESP8266) the rest of the RAM being reserved to the heap. That's why moving the `JsonBuffer` from the stack to the heap can solve this kind of problem.

See:

* Issues [#167](https://github.com/bblanchon/ArduinoJson/issues/167) and [#234](https://github.com/bblanchon/ArduinoJson/issues/234).

#### Case 4: The `DynamicJsonBuffer` fails to allocate memory

You may have a memory leak, it up to you to find it. You can try to switch to `StaticJsonBuffer` which is more efficient.

Also, if the input string is constant, the `JsonBuffer` will have to make a copy of it.

```c++
// case 1: char array => no duplication => good
char[] json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 2: const char* => duplication => bad
const char* json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);

// case 3: String => duplication => bad
String json = "{\"hello\":\"world\"}";
jsonBuffer.parseObject(json);
```

To avoid any duplication, make sure you use an input of type `char*` or `char[]`

See:

* Issues [#154](https://github.com/bblanchon/ArduinoJson/issues/154), [#177](https://github.com/bblanchon/ArduinoJson/issues/177), [#179](https://github.com/bblanchon/ArduinoJson/issues/179) and [#223](https://github.com/bblanchon/ArduinoJson/issues/223) and [#320](https://github.com/bblanchon/ArduinoJson/issues/320).

#### Case 5: You called `parseObject()` instead of `parseArray()`

This is a very common question as people are often confused when the JSON input contains mixed arrays and objects.

The answer is very simple: it's the type of the root that matters.
This means that you just need to look at the first character: it's either a `[`, for an array, or a `{`, for an object.

For example, if the input is:

```json
{"mickey":["mouse"],"donald":["duck"]}
```

then you must call `parseObject()` because the root is an object.

And, if the input is:

```json
[{"mickey":"mouse","donald":"duck"}]
```

then you must call `parseArray()` because the root is an array.

Finally, if you cannot know in advance the type of the root, please open an issue. Don't worry this can be implemented very easily, it's just that nobody asked for it.

See:

* Issue [#391](https://github.com/bblanchon/ArduinoJson/issues/391)


### The first parsing succeeds, why do the next ones fail?

This can be due to two causes.

##### Cause 1: reuse of `JsonBuffer`

First, this can happen if you reuse the same `JsonBuffer`, for example:

```c++
StaticJsonBuffer<200> jsonBuffer;

for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

The solution is simply to NOT reuse the `JsonBuffer`, like this:

```c++
for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

Note that, contrary to a common belief, moving a `StaticJsonBuffer` inside of a loop has no negative impact on performance.

See issue [#243](https://github.com/bblanchon/ArduinoJson/issues/243) and [#305](https://github.com/bblanchon/ArduinoJson/issues/305).

##### Cause 2: reuse of JSON input

In order to make the JSON parsing without any allocation or duplication, ArduinoJson modifies the string in place: it inserts null terminators and unescapes special characters.

If you provide a writeable input, like a `char[]` or a `char*`, it will modify this input in place.
If you provide a read only input, like a `const char*` or a `String`, it will have to make a copy of it in order to be allowed to modify it.

That's why it's highly recommended to used a writeable input: you get a huge performance boost and memory usage is greatly reduced :+1:

Now, this behavior leads to unexpected result if you try to reuse the modified string, for instance:

```c++
char json[256];
readJsonFromSomewhere(json, sizeof(json));

for (int i=0; i<10; i++) {
    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

Only the first call to `parseObject()` will succeed because after that call, `json` will be altered and not be valid JSON anymore.

The solution is simply to parse the input only once, or get a fresh input at each iteration:

```c++
for (int i=0; i<10; i++) {
    char json[256];
    readJsonFromSomewhere(json, sizeof(json));

    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parse(json);
    if (root.success()) {
       Serial.println("parseObject() succeeded");
    } else {
       Serial.println("parseObject() failed!");
    }
}
```

See issue [#153](https://github.com/bblanchon/ArduinoJson/issues/153), [#160](https://github.com/bblanchon/ArduinoJson/issues/160) and [#286](https://github.com/bblanchon/ArduinoJson/issues/286).



### Parsing succeeds but I can't read the values!

99.999% of the time, this is caused by a confusion between arrays and objects.

This often happens when the JSON contains `[{` or `:[`.

##### Example 1:

```json
[{"hello":"world"}]
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root[0]["hello"];
```

##### Example 2:

```json
{"hello":["world"]}
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root["hello"][0];
```

##### Example 3:

```json
{"hello":[{"new":"world"}]}
```

Wrong implementation:

```c++
JsonObject& root = jsonBuffer.parseObject(json);
const char* world = root["hello"]["new"];
```

Good implementation:

```c++
JsonArray& root = jsonBuffer.parseArray(json);
const char* world = root["hello"][0]["new"];
```

See issues [#187](https://github.com/bblanchon/ArduinoJson/issues/187), [#203](https://github.com/bblanchon/ArduinoJson/issues/203) and [#245](https://github.com/bblanchon/ArduinoJson/issues/245).



### How to know the type of a value?

`JsonVariant`, which is the type that hold the values in `JsonArray` and `JsonObject`, provides the method `is<T>()` that returns `true` if the value is of type `T`.

Examples:

```c++
object["key"] = "value";
object["key"].is<const char*>(); // returns true
object["key"].is<int>(); // returns false
object["key"].is<JsonObject&>(); // returns false

array.add(42);
array[0].is<const char*>(); // return false
array[0].is<int>(); // return true
array[0].is<JsonObject&>(); // return false
```

See issues [#148](https://github.com/bblanchon/ArduinoJson/issues/148), [#175](https://github.com/bblanchon/ArduinoJson/issues/175) and [#213](https://github.com/bblanchon/ArduinoJson/issues/213).


### Can I access to object member by its index, instead of its key?

No.

But you can enumerate all the key-value pairs in the object, by using iterators:

```c++
char json[] = "{\"key\":\"value\"}";
JsonObject& object = jsonBuffer.parseObject(json);

for(JsonObject::iterator it=object.begin(); it!=object.end(); ++it)
{
    const char* key = it->key;

    if (it->value.is<char*>()) {
        const char* value = it->value;
        // ...
    }

    if (it->value.is<JsonObject>()) {
        JsonObject& value = it->value;
        // you can recursively traverse objects...
    }
}
```

See issue [#278](https://github.com/bblanchon/ArduinoJson/issues/278).

### How to fix error "Ambiguous overload for 'operator='"

There is a case where you need to help the compiler: it's when you convert a `JsonVariant` to a `String`.

For example:

```c++
String ssid = network["ssid"];
ssid = network["ssid"];
```

The first line will compile but the second will fail with the following error:

```
error: ambiguous overload for 'operator=' (operand types are 'String' and 'ArduinoJson::JsonObjectSubscript<const char*>')
```

The solution is to remove the ambiguity with any of the following replacement:

```c++
ssid = (const char*)network["ssid"];
ssid = network["ssid"].asString();
ssid = network["ssid"].as<const char*>();
ssid = network["ssid"].as<String>();
```

See issue [#118](https://github.com/bblanchon/ArduinoJson/issues/118), [#146](https://github.com/bblanchon/ArduinoJson/issues/146) and [#197](https://github.com/bblanchon/ArduinoJson/issues/197).

### Why JsonVariant cannot be converted to char?

The `char` type has been intentionally disabled to avoid an ambiguity.

Imagine you have this input: `{'time':'8'}`; what should be the value of `root["time"]` as a `char`?

I see two possible answers:

* Either you see `char` as an integer; in that case, the result should be `8`.
* Or you see `char` as a character; in that case, the result should be `56` (the ASCII code of character `8`)

Since there is not good answer to this question, the `char` type has been disabled, but `unsigned char` and `signed char` works as integers.

However, I highly encourage you to use `char` to store characters, and `int8_t` or `uint8_t` to store integers. If you compile with Arduino, you also have the [byte](https://www.arduino.cc/en/Reference/Byte) type.

See also:

* [API Reference: JsonVariant::as()](https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference#jsonvariantas)
* Issues [#337](https://github.com/bblanchon/ArduinoJson/issues/337) and [#370](https://github.com/bblanchon/ArduinoJson/issues/370)
