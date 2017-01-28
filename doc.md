---
layout: page
title: API Reference
tags: doc
---

API Reference
===========

This is the detailed documentation of every class and function of the ArduinoJson library.
Some parts have been simplified to be easier to understand, so if you look at the source code, you might see some differences.


<!-- MarkdownTOC depth=3 autolink=true bracket=round lowercase_only_ascii=true -->

- [Configuration](#configuration)
  - [ARDUINOJSON_USE_DOUBLE](#arduinojsonusedouble)
  - [ARDUINOJSON_USE_LONG_LONG](#arduinojsonuselonglong)
  - [ARDUINOJSON_ENABLE_ARDUINO_STRING](#arduinojsonenablearduinostring)
  - [ARDUINOJSON_ENABLE_STD_STRING](#arduinojsonenablestdstring)
  - [ARDUINOJSON_DEFAULT_NESTING_LIMIT](#arduinojsondefaultnestinglimit)
- [JsonArray](#jsonarray)
  - [Constructor](#constructor)
    - [Example](#example)
  - [JsonArray::add\(\)](#jsonarrayadd)
    - [Description](#description)
    - [Signatures](#signatures)
    - [Arguments](#arguments)
    - [Return value](#return-value)
    - [Remarks](#remarks)
    - [Example](#example-1)
  - [JsonArray::copyFrom\(\)](#jsonarraycopyfrom)
    - [Description](#description-1)
    - [Signatures](#signatures-1)
    - [Return value](#return-value-1)
    - [Example](#example-2)
  - [JsonArray::copyTo\(\)](#jsonarraycopyto)
    - [Description](#description-2)
    - [Signatures](#signatures-2)
    - [Return value](#return-value-2)
    - [Example](#example-3)
  - [JsonArray::createNestedArray\(\)](#jsonarraycreatenestedarray)
    - [Description](#description-3)
    - [Signature](#signature)
    - [Return value](#return-value-3)
    - [Example](#example-4)
  - [JsonArray::createNestedObject\(\)](#jsonarraycreatenestedobject)
    - [Description](#description-4)
    - [Signature](#signature-1)
    - [Return value](#return-value-4)
    - [Example](#example-5)
  - [JsonArray::get\(\)](#jsonarrayget)
    - [Description](#description-5)
    - [Signature](#signature-2)
    - [Arguments](#arguments-1)
    - [Return value](#return-value-5)
    - [Example](#example-6)
  - [JsonArray::measureLength\(\)](#jsonarraymeasurelength)
    - [Description](#description-6)
    - [Return value](#return-value-6)
    - [Signature](#signature-3)
  - [JsonArray::measurePrettyLength\(\)](#jsonarraymeasureprettylength)
    - [Description](#description-7)
    - [Signature](#signature-4)
    - [Return value](#return-value-7)
  - [JsonArray::operator\[\]](#jsonarrayoperator)
    - [Description](#description-8)
    - [Signatures](#signatures-3)
    - [Arguments](#arguments-2)
    - [Return value](#return-value-8)
    - [Example](#example-7)
  - [JsonArray::prettyPrintTo\(\)](#jsonarrayprettyprintto)
    - [Description](#description-9)
    - [Signatures](#signatures-4)
    - [Arguments](#arguments-3)
    - [Return value](#return-value-9)
    - [Example](#example-8)
  - [JsonArray::printTo\(\)](#jsonarrayprintto)
    - [Description](#description-10)
    - [Signatures](#signatures-5)
    - [Arguments](#arguments-4)
    - [Return value](#return-value-10)
    - [Example](#example-9)
  - [JsonArray::removeAt\(\)](#jsonarrayremoveat)
    - [Description](#description-11)
    - [Signature](#signature-5)
    - [Arguments](#arguments-5)
    - [Example](#example-10)
  - [JsonArray::set\(\)](#jsonarrayset)
    - [Description](#description-12)
    - [Signatures](#signatures-6)
    - [Arguments](#arguments-6)
    - [Return value](#return-value-11)
    - [Remarks](#remarks-1)
    - [Example](#example-11)
  - [JsonArray::size\(\)](#jsonarraysize)
    - [Description](#description-13)
    - [Signature](#signature-6)
    - [Return value](#return-value-12)
    - [Example](#example-12)
  - [JsonArray::success\(\)](#jsonarraysuccess)
    - [Description](#description-14)
    - [Signatures](#signatures-7)
    - [Return value](#return-value-13)
    - [Examples](#examples)
- [JsonBuffer \(DynamicJsonBuffer and StaticJsonBuffer\)](#jsonbuffer-dynamicjsonbuffer-and-staticjsonbuffer)
  - [JsonBuffer::createArray\(\)](#jsonbuffercreatearray)
    - [Description](#description-15)
    - [Signature](#signature-7)
    - [Return value](#return-value-14)
    - [Example](#example-13)
  - [JsonBuffer::createObject\(\)](#jsonbuffercreateobject)
    - [Description](#description-16)
    - [Signature](#signature-8)
    - [Return value](#return-value-15)
    - [Example](#example-14)
  - [JsonBuffer::parseArray\(\)](#jsonbufferparsearray)
    - [Description](#description-17)
    - [Signatures](#signatures-8)
    - [Arguments](#arguments-7)
    - [Return value](#return-value-16)
    - [Example](#example-15)
  - [JsonBuffer::parseObject\(\)](#jsonbufferparseobject)
    - [Description](#description-18)
    - [Signatures](#signatures-9)
    - [Arguments](#arguments-8)
    - [Return value](#return-value-17)
    - [Example](#example-16)
  - [JsonBuffer::strdup\(\)](#jsonbufferstrdup)
    - [Description](#description-19)
    - [Signatures](#signatures-10)
    - [Arguments](#arguments-9)
    - [Return value](#return-value-18)
    - [Example](#example-17)
- [JsonObject](#jsonobject)
  - [Constructor](#constructor-1)
    - [Example](#example-18)
  - [JsonObject::begin\(\) / JsonObject::end\(\)](#jsonobjectbegin--jsonobjectend)
    - [Description](#description-20)
    - [Signatures](#signatures-11)
    - [Return value](#return-value-19)
    - [Example](#example-19)
  - [JsonObject::createNestedArray\(\)](#jsonobjectcreatenestedarray)
    - [Description](#description-21)
    - [Signatures](#signatures-12)
    - [Arguments](#arguments-10)
    - [Remarks](#remarks-2)
    - [Return value](#return-value-20)
    - [Example](#example-20)
  - [JsonObject::createNestedObject\(\)](#jsonobjectcreatenestedobject)
    - [Description](#description-22)
    - [Signature](#signature-9)
    - [Arguments](#arguments-11)
    - [Remarks](#remarks-3)
    - [Return value](#return-value-21)
    - [Example](#example-21)
  - [JsonObject::containsKey\(\)](#jsonobjectcontainskey)
    - [Description](#description-23)
    - [Signature](#signature-10)
    - [Arguments](#arguments-12)
    - [Return value](#return-value-22)
    - [Example](#example-22)
  - [JsonObject::get\(\)](#jsonobjectget)
    - [Description](#description-24)
    - [Signature](#signature-11)
    - [Arguments](#arguments-13)
    - [Return value](#return-value-23)
    - [Example](#example-23)
  - [JsonObject::measureLength\(\)](#jsonobjectmeasurelength)
    - [Description](#description-25)
    - [Return value](#return-value-24)
    - [Signature](#signature-12)
  - [JsonObject::measurePrettyLength\(\)](#jsonobjectmeasureprettylength)
    - [Description](#description-26)
    - [Return value](#return-value-25)
    - [Signature](#signature-13)
  - [JsonObject::operator\[\]](#jsonobjectoperator)
    - [Description](#description-27)
    - [Signatures](#signatures-13)
    - [Arguments](#arguments-14)
    - [Return value](#return-value-26)
    - [Remarks](#remarks-4)
    - [Example](#example-24)
  - [JsonObject::prettyPrintTo\(\)](#jsonobjectprettyprintto)
    - [Description](#description-28)
    - [Signatures](#signatures-14)
    - [Arguments](#arguments-15)
    - [Return value](#return-value-27)
    - [Example](#example-25)
  - [JsonObject::printTo\(\)](#jsonobjectprintto)
    - [Description](#description-29)
    - [Signatures](#signatures-15)
    - [Arguments](#arguments-16)
    - [Return value](#return-value-28)
    - [Example](#example-26)
  - [JsonObject::remove\(\)](#jsonobjectremove)
    - [Description](#description-30)
    - [Signatures](#signatures-16)
    - [Arguments](#arguments-17)
    - [Example](#example-27)
  - [JsonObject::set\(\)](#jsonobjectset)
    - [Description](#description-31)
    - [Signatures](#signatures-17)
    - [Arguments](#arguments-18)
    - [Return value](#return-value-29)
    - [Remarks](#remarks-5)
    - [Example](#example-28)
  - [JsonObject::size\(\)](#jsonobjectsize)
    - [Description](#description-32)
    - [Signature](#signature-14)
    - [Return value](#return-value-30)
    - [Example](#example-29)
  - [JsonObject::success\(\)](#jsonobjectsuccess)
    - [Description](#description-33)
    - [Signatures](#signatures-18)
    - [Return value](#return-value-31)
    - [Examples](#examples-1)
- [JsonVariant](#jsonvariant)
  - [JsonVariant::as\(\)](#jsonvariantas)
    - [Description](#description-34)
    - [Signatures](#signatures-19)
    - [Return value](#return-value-32)
    - [Example](#example-30)
  - [JsonVariant::is\(\)](#jsonvariantis)
    - [Description](#description-35)
    - [Signatures](#signatures-20)
    - [Return value](#return-value-33)
    - [Example](#example-31)

<!-- /MarkdownTOC -->


## Configuration

### ARDUINOJSON_USE_DOUBLE

Determine the type used to store floating point values in `JsonVariant`.

* If `ARDUINOJSON_USE_DOUBLE == 0`, then `JsonVariant` stores a `float`
* If `ARDUINOJSON_USE_DOUBLE == 1`, then `JsonVariant` stores a `double`

Default is `0` of `ARDUINO` is defined, `1` otherwise.

### ARDUINOJSON_USE_LONG_LONG

Determine the type used to store integer values in `JsonVariant`.

* If `ARDUINOJSON_USE_LONG_LONG == 0`, then `JsonVariant` stores a `long`
* If `ARDUINOJSON_USE_LONG_LONG == 1`, then `JsonVariant` stores a `long long`

Default is `0` of `ARDUINO` is defined, `1` otherwise.

### ARDUINOJSON_ENABLE_ARDUINO_STRING

Enable the support of the type `String` in the library.

Default is `1` of `ARDUINO` is defined, `0` otherwise.

### ARDUINOJSON_ENABLE_STD_STRING

Enable the support of the type `std::string` in the library.

Default is `0` of `ARDUINO` is defined, `1` otherwise.

### ARDUINOJSON_DEFAULT_NESTING_LIMIT

Defines the default value the second parameter of `parseObject()` and `parseArray()`, which limit the nesting in the JSON input. (the goal is to prevent stackoverflow).

Default is `10` of `ARDUINO` is defined, `50` otherwise.


## JsonArray

Represents an array in a JSON object tree.



### Constructor

The constructor is private, you cannot instantiate a `JsonArray` directly, you have to use a `JsonBuffer`.

Because the memory of a `JsonArray` is located a `JsonBuffer`, you always manipulate it through reference and you cannot copy it.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;

// create an empty array
JsonArray& array1 = jsonBuffer.createArray();

// parse a JSON array
char json[] = "[1,2,3]";
JsonArray& array2 = jsonBuffer.parseArray(json);
```



### JsonArray::add()

##### Description

Adds a value to the end of the array.

##### Signatures

```c++
bool add(bool value);
bool add(float value, uint8_t decimals = 2);
bool add(double value, uint8_t decimals = 2);
bool add(signed char value);
bool add(signed long value);
bool add(signed int value);
bool add(signed short value);
bool add(unsigned char value);
bool add(unsigned long value);
bool add(unsigned int value);
bool add(unsigned short value);
bool add(const char *value);
bool add(const String &value); // see Remarks
bool add(const std::string &value); // see Remarks
bool add(JsonArray &array);
bool add(JsonObject &object);
bool add(const JsonVariant &variant);
```

##### Arguments

`value`: the value to add to the array.

`decimals`: the number of digits to print after the decimal point.

##### Return value

`true` if the value was successfully added.

`false` if there was not enough memory in the `JsonBuffer`.

##### Remarks

When you call `add(const String&)` or `add(const std::string&)`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use `add(const char*)` instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add(3.14156, 4);
array.printTo(Serial);
```

will write

```json
["hello",3.1416]
```

### JsonArray::copyFrom()

##### Description

Populates the `JsonArray` with values from a C array.

##### Signatures

```c++
JsonArray::copyFrom(int array[]);
JsonArray::copyFrom(double array[]);
JsonArray::copyFrom(const char* array[]);
```

##### Return value

`true` if the operation is successful; or `false` if there was not enough room in the `JsonBuffer`.

##### Example

```c++
int values[] = {1, 2, 3};

StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.copyFrom(values);
array.printTo(Serial);
```

will write

```json
[1,2,3]
```


### JsonArray::copyTo()

##### Description

Extracts a C array from the `JsonArray`.

##### Signatures

```c++
JsonArray::copyTo(int array[]);
JsonArray::copyTo(double array[]);
JsonArray::copyTo(const char* array[]);
```

##### Return value

A `size_t` containing the number of values written in the array.

##### Example

```c++
int values[3];

StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("[1,2,3]");
array.copyTo(values);
```

now `values` contais `1`, `2` and `3`.



### JsonArray::createNestedArray()

##### Description

Adds a new nested array to the end of the array.

##### Signature

```c++
JsonArray& createNestedArray();
```

##### Return value

A reference to the new `JsonArray`.
You can check `JsonArray::success()` to verify that the allocation succeeded.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
JsonArray& nested = array.createNestedArray();
nested.add("world");
array.printTo(Serial);
```

will write

```json
["hello",["world"]]
```


### JsonArray::createNestedObject()

##### Description

Adds a new nested object to the end of the array.

##### Signature

```c++
JsonObject& createNestedObject();
```

##### Return value

A reference to the new `JsonObject`.
You can check `JsonObject::success()` to verify that the allocation succeeded.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
JsonObject& nested = array.createNestedObject();
nested["hello"] = "world";
array.printTo(Serial);
```

will write

```json
[{"hello":"world"}]
```


### JsonArray::get()

##### Description

Gets the value at the specified index.

##### Signature

```c++
bool            get<bool>           (size_t index) const;
const char*     get<const char*>    (size_t index) const;
double          get<double>         (size_t index) const;
float           get<float>          (size_t index) const;
JsonVariant     get<Variant>        (size_t index) const;
signed char     get<signed char>    (size_t index) const;
signed int      get<signed int>     (size_t index) const;
signed long     get<signed long>    (size_t index) const;
signed short    get<signed short>   (size_t index) const;
std::string     get<std::string>    (size_t index) const;
String          get<String>         (size_t index) const;
unsigned char   get<unsigned char>  (size_t index) const;
unsigned int    get<unsigned int>   (size_t index) const;
unsigned long   get<unsigned long>  (size_t index) const;
unsigned short  get<unsigned short> (size_t index) const;
```

##### Arguments

`index`: the index of the value in the array.

`T`: the type of the value

##### Return value

The value at the specified index. This can be a `JsonVariant` or a value of type T.

The template version of `get()` returns a value of the specified type.
In the case of an error (index out of range or incompatible type), the default value of the type `T` is returned.

##### Example

```c++
char json[] = "[1,3.14]";
StaticJsonBuffer<256> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray(json);
int value0 = array.get(0); // implicit cast of the JsonVariant
float value1 = array.get<float>(1); // template version of get()
const char* value2 = array.get(2); // returns NULL
```


### JsonArray::measureLength()

##### Description

Gets the length of string produced by `JsonArray::printTo()`.

This can be very handy to fill the `Content-Length` of an HTTP request or response.

##### Return value

The number of characters in the JSON string that would be generated by `JsonArray::printTo()`.

It doesn't include the zero-terminator.

##### Signature

```c++
size_t measureLength() const
```



### JsonArray::measurePrettyLength()

##### Description

Gets the length of string produced by `JsonArray::prettyPrintTo()`.

##### Signature

```c++
size_t measurePrettyLength() const
```

##### Return value

The number of characters in the JSON string that would be generated by `JsonArray::prettyPrintTo()`.

It doesn't include the zero-terminator.



### JsonArray::operator[]

##### Description

A shortcut for `JsonArray::get()` and `JsonArray::set()`, with an array-like syntax.

##### Signatures

```c++
JsonVariant& operator[](size_t index);
const JsonVariant& operator[](size_t index) const;
```

##### Arguments

`index`: the zero-based position of the value in the array.

##### Return value

A reference to the `JsonVariant` in the array.

##### Example

```c++
JsonArray& array = jsonBuffer::createArray();
array.add(42);
int value = array[0];
array[0] = 666;
```



### JsonArray::prettyPrintTo()

##### Description

Serialize the array to an indented JSON string.

This will create a "prettified" JSON, if you want a compact JSON without space or line break, use `JsonArray::print()`

##### Signatures

```c++
size_t prettyPrintTo(char* buffer, size_t size) const;
size_t prettyPrintTo(char buffer[size]) const;
size_t prettyPrintTo(Print &) const;
size_t prettyPrintTo(String &) const;
size_t prettyPrintTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add("world");
array.prettyPrintTo(Serial);
```

will write the following string to the serial output:

```json
[
  "hello",
  "world"
]
```



### JsonArray::printTo()

##### Description

Serialize the array to a JSON string.

This will create a compact JSON, if you want a pretty JSON with spaces and line breaks, use `JsonArray::prettyPrint()`

##### Signatures

```c++
size_t printTo(char* buffer, size_t size) const;
size_t printTo(char buffer[size]) const;
size_t printTo(Print &) const;
size_t printTo(String &) const;
size_t printTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add("world");
array.printTo(Serial);
```

will write the following string to the serial output:

```json
["hello","world"]
```



### JsonArray::removeAt()

##### Description

Removes the element at the specified index.

**IMPORTANT**: This function doesn't free the memory allocated to the element in the `JsonBuffer`. This behavior has been prefered to keep the `JsonBuffer` fast and small, which is a foundational principle of the library.

##### Signature

```c++
void removeAt(size_t index);
```

##### Arguments

`index`: the zero-based position of the element in the array.

##### Example

```c++
JsonArray& array = jsonBuffer.createArray();
array.add("A");
array.add("B");
array.add("C");
array.removeAt(1);
array.printTo(Serial);
```

will print the following string to the serial output:

```json
["A","C"]
```



### JsonArray::set()

##### Description

Sets the value at specified index.

##### Signatures

```c++
bool set(size_t index, bool value);
bool set(size_t index, const char *value);
bool set(size_t index, const JsonVariant &value);
bool set(size_t index, const std::string &value); // see Remarks
bool set(size_t index, const String &value); // see Remarks
bool set(size_t index, double value, uint8_t decimals = 2);
bool set(size_t index, float value, uint8_t decimals = 2);
bool set(size_t index, JsonArray &array);
bool set(size_t index, JsonObject &object);
bool set(size_t index, signed char value);
bool set(size_t index, signed int value);
bool set(size_t index, signed long value);
bool set(size_t index, signed short value);
bool set(size_t index, unsigned char value);
bool set(size_t index, unsigned int value);
bool set(size_t index, unsigned long value);
bool set(size_t index, unsigned short value);
```

##### Arguments

`index`: position to set value in array.

`value`: the value to set in index of array.

##### Return value

`true` if allocation succeeded.

`false` if there was not enough space left in the `JsonBuffer`, this can only happen when `value` is a `String`.

##### Remarks

When you call `set(size_t, const String&)` or `set(size_t, const std::string&)`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use `set(size_t, const char*)` instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.set(0,"hello");
array.add(1,3.14156, 4);
array.printTo(Serial); // [3.1416]
```



### JsonArray::size()

##### Description

Returns the number of element in the array.

##### Signature

```c++
size_t size() const;
```

##### Return value

An unsigned integer containing the number of elements in the array.

##### Example

```c++
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add("world");
Serial.println(array.size()); // 2
```



### JsonArray::success()

##### Description

Tells if the array is valid, which can be used:

1. to check if the array was successfully parsed, or
2. to check if the array was successfully allocated.

##### Signatures

```c++
bool success() const;
```

##### Return value

`true` if the array was successfully parsed/allocated.
`false` if the parsing/allocation failed.

##### Examples

Example 1: parsing success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("[1,2]");
Serial.println(array.success()); // true
```

Example 2: parsing failure:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray("{1,2}");
Serial.println(array.success()); // false
```

Example 3: allocation success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
Serial.println(array.success()); // true
```

Example 4: allocation failure:

```c++
StaticJsonBuffer<1> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
Serial.println(array.success()); // false
```



## JsonBuffer (DynamicJsonBuffer and StaticJsonBuffer)

`JsonBuffer` is the entry point for using the library: it handle the memory management and calls the parser.

It implements a speed efficient memory pool and comes in two flavors:

1. `DynamicJsonBuffer` which is allocated on the heap and grows automatically
2. `StaticJsonBuffer` which is (most likely) allocated on the stack and has a fixed size.

`JsonBuffer` is optimized of fast allocation, but doesn't allow to free the allocated memory block.
To free a `JsonBuffer`, you must discard the entire object.

This is the source of a lot of question, please read the [FAQ in the wiki](https://github.com/bblanchon/ArduinoJson/wiki/FAQ) for clarifications.



### JsonBuffer::createArray()
##### Description
Allocates an empty JsonArray.
##### Signature
```c++
JsonArray& createArray();
```
##### Return value
Returns a reference to the new JsonArray or JsonArray::invalid() if the allocation fails.
##### Example
```c++
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.createArray();
array.add("hello");
array.add("world");
```

### JsonBuffer::createObject()

##### Description
Allocates an empty JsonObject.

##### Signature
```c++
JsonObject createObject();
```
##### Return value
Returns a reference to the new JsonObject or JsonObject::invalid() if the allocation fails.
##### Example
```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
```



### JsonBuffer::parseArray()

##### Description
Allocates and populate a JsonArray from a JSON string.

By design, the parser needs to alter the string to insert null-terminators and replace escaped chars.
If the JSON string is read-only, it will have to duplicate the input string, this consume more space in the `JsonBuffer`.
Therefore, it's recommended to have a JSON input in a `char[]` or a `char*`.

##### Signatures
```c++
// The first overload, which accepts a modifiable array of chars, is the most efficient
// since it allows the zero-copy feature.
JsonArray& parseArray(char* json, uint8_t nestingLimit=10);

// The three following overloads, which accept read-only strings, require a bigger JsonBuffer
// because parts of the JSON input has to be copied.
JsonArray& parseArray(const char* json, uint8_t nestingLimit=10);
JsonArray& parseArray(const String& json, uint8_t nestingLimit=10);
JsonArray& parseArray(const std::string& json, uint8_t nestingLimit=10);

// The two last overloads, which accept input streams, make copy of the input too.
JsonArray& parseArray(Stream& json, uint8_t nestingLimit=10);
JsonArray& parseArray(std::istream& json, uint8_t nestingLimit=10);
```

##### Arguments

`json` is the input string to be parsed.

`nestingLimit` specifies the maximum level of nesting allowed in the JSON string.
If set to `0`, only a flat array can be parsed.
If set to `1`, the object can contain nested arrays or objects but only 1 level deep.
And bigger values will allow more level of nesting.
The purpose of this feature is to prevent stack overflow that could lead to a security risk.

##### Return value
Returns a reference to the new JsonArray or JsonArray::invalid() if the allocation fails.

##### Example

```c++
char json[] = "[\"hello\",\"world\"]";
StaticJsonBuffer<200> jsonBuffer;
JsonArray& array = jsonBuffer.parseArray(json);
const char* hello = array[0];
const char* world = array[1];
```



### JsonBuffer::parseObject()

##### Description
Allocates and populate a JsonObject from a JSON string.

By design, the parser needs to alter the string to insert null-terminators and replace escaped chars.
If the JSON string is read-only, it will have to duplicate the input string, this consume more space in the `JsonBuffer`.
Therefore, it's recommended to have a JSON input in a `char[]` or a `char*`.

##### Signatures
```c++
// The first overload, which accepts a modifiable array of chars, is the most efficient
// since it allows the zero-copy feature.
JsonObject& parseObject(char* json, uint8_t nestingLimit=10);

// The three following overloads, which accept read-only strings, require a bigger JsonBuffer
// because parts of the JSON input has to be copied.
JsonObject& parseObject(const char* json, uint8_t nestingLimit=10);
JsonObject& parseObject(const String& json, uint8_t nestingLimit=10);
JsonObject& parseObject(const std::string& json, uint8_t nestingLimit=10);

// The two last overloads, which accept input streams, make copy of the input too.
JsonObject& parseObject(Stream& json, uint8_t nestingLimit=10);
JsonObject& parseObject(std::istream& json, uint8_t nestingLimit=10);
```

##### Arguments

`json` is the input string to be parsed.

`nestingLimit` specifies the maximum level of nesting allowed in the JSON string.
If set to `0`, only a flat object can be parsed.
If set to `1`, the object can contain nested objects or objects but only 1 level deep.
And bigger values will allow more level of nesting.
The purpose of this feature is to prevent stack overflow that could lead to a security risk.

##### Return value
Returns a reference to the new JsonObject or JsonObject::invalid() if the allocation fails.

##### Example

```c++
char json[] = "{\"hello\":\"world\"}";
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject(json);
const char* world = object["hello"];
```


### JsonBuffer::strdup()

##### Description

Make a copy of the specified string.

##### Signatures

```c++
char* strdup(const char* str);
char* strdup(const String& str);
char* strdup(const std::string& str);
```

##### Arguments

`str`, the string to duplicate.

##### Return value

A newly allocate string, filled with a copy of `str`.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
char orig[16] = "hello";
char* dupl = jsonBuffer.strdup(orig);
strcpy(orig, "world");
Serial.println(dupl); // world
Serial.println(orig); // hello
```



## JsonObject

Represents an object (ie an unordered set of name/value pairs) in a JSON object tree.


### Constructor

The constructor is private, you cannot instanciate a `JsonObject` directly, you have to use a `JsonBuffer`.

Because the memory of a `JsonObject` is located a `JsonBuffer`, you always manipulate it through reference and you cannot copy it.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;

// create an empty object
JsonObject& object1 = jsonBuffer.createObject();

// parse a JSON object
char json[] = "[1,2,3]";
JsonObject& object2 = jsonBuffer.parseObject(json);
```


### JsonObject::begin() / JsonObject::end()

##### Description
Returns an iterator that can be use to get all key-value pairs in the object.

##### Signatures

```c++
JsonObject::iterator begin();
JsonObject::iterator end();
JsonObject::const_iterator begin() const;
JsonObject::const_iterator end() const;
```

##### Return value
A forward iterator pointing to a `JsonPair`, which itself contains two members `key` and `value`.

##### Example

```c++
char json[] = "{\"first\":\"hello\",\"second\":\"world\"}";
DynamicJsonBuffer jsonBuffer;
JsonObject& root = jsonBuffer.parseObject(json);

// using C++98 syntax:
for (JsonObject::iterator it=root.begin(); it!=root.end(); ++it) {
    Serial.println(it->key);
    Serial.println(it->value);
}

// using C++11 syntax:
for (auto kv : root) {
    Serial.println(kv.key);
    Serial.println(kv.value);
}
```

The code above would print:

```
first
hello
second
world
```


### JsonObject::createNestedArray()

##### Description
Creates a `JsonArray` as a child of the current object.

##### Signatures

```c++
JsonArray& createNestedArray(const char* key) const;
JsonArray& createNestedArray(const String& key) const; // <- duplicates key
```

##### Arguments

`key`: the key of the array in the object, can be a `const char*` or a `const String&`

##### Remarks

When you add a value using a `String` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Return value

A reference to the new `JsonArray`.
You can check `JsonArray::success()` to verify that the allocatio succeeded.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["status"] = "on";
JsonArray& levels = root.createNestedArray("levels");
levels.add(10);
levels.add(30);
root.prettyPrintTo(Serial);
```

will print

```json
{
  "status": "on",
  "levels": [
    10,
    20
  ]
}
```


### JsonObject::createNestedObject()

##### Description
Creates a `JsonObject` as a child of the current object.

##### Signature

```c++
JsonObject& createNestedObject(const char* key) const;
JsonObject& createNestedObject(const String& key) const; // <- duplicates key
JsonObject& createNestedObject(const std::string& key) const; // <- duplicates key
```

##### Arguments

`key`: the key of the object in the object, can be a `const char*` or a `const String&`

##### Remarks

When you add a value using a `String` or a `std::string` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Return value

A reference to the new `JsonObject`.
You can check `JsonObject::success()` to verify that the allocatio succeeded.

##### Example

```c++
StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["city"] = "Paris";
JsonObject& weather = root.createNestedObject("weather");
weather["temp"] = 14.2;
weather["cond"] = "cloudy";
root.prettyPrintTo(Serial);
```

will print

```json
{
  "city": "Paris",
  "weather": {
    "temp": 14.20,
    "cond": "cloudy"
  }
}
```


### JsonObject::containsKey()

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


### JsonObject::get()

##### Description
Gets the value at the specified index.

##### Signature
```c++
bool            get<bool>           (TString key) const;
const char*     get<const char*>    (TString key) const;
double          get<double>         (TString key) const;
float           get<float>          (TString key) const;
JsonVariant     get<JsonVariant>    (TString key) const;
signed char     get<signed char>    (TString key) const;
signed int      get<signed int>     (TString key) const;
signed long     get<signed long>    (TString key) const;
signed short    get<signed short>   (TString key) const;
std::string     get<std::string>    (TString key) const;
String          get<String>         (TString key) const;
unsigned char   get<unsigned char>  (TString key) const;
unsigned int    get<unsigned int>   (TString key) const;
unsigned long   get<unsigned long>  (TString key) const;
unsigned short  get<unsigned short> (TString key) const;
```

##### Arguments

`key`: the key of the value in the object, can be a `const char*`, a `String` or an `std::string`.

##### Return value

The value at the specified key, converted to the specified type.
In case of an error (key not found or incompatible type), the default value of the specified type is returned.

##### Example

```c++
char json[] = "{\"pi\":3.14}";
StaticJsonBuffer<256> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject(json);
float pi = object.get<float>("pi"); // template version of get()
const char* value2 = object.get<const char*>("toto"); // returns NULL
```


### JsonObject::measureLength()

##### Description

Gets the length of string produced by `JsonObject::printTo()`.

This can be very handy to fill the `Content-Length` of an HTTP request or response.

##### Return value

The number of characters in the JSON string that would be generated by `JsonObject::printTo()`.

It doesn't include the zero-terminator.

##### Signature

```c++
size_t measureLength() const
```



### JsonObject::measurePrettyLength()

##### Description

Gets the length of string produced by `JsonObject::prettyPrintTo()`.

##### Return value

The number of characters in the JSON string that would be generated by `JsonObject::prettyPrintTo()`.

It doesn't include the zero-terminator.

##### Signature

```c++
size_t measurePrettyLength() const
```


### JsonObject::operator[]

##### Description

A shortcut for `JsonObject::get()` and `JsonObject::set()`, with a map-like syntax.

##### Signatures

```c++
JsonVariant& operator[](const char* key);
JsonVariant& operator[](const String& key);
JsonVariant& operator[](const std::string& key);
const JsonVariant& operator[](const char* key) const;
const JsonVariant& operator[](const String& key) const;
const JsonVariant& operator[](const std::string& key) const;
```

##### Arguments

`key`: the key that the value will be associated to.

##### Return value

A reference to the `JsonVariant` in the object.

##### Remarks

When you add a value using a `String` or an `std::string` for key, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
To avoid this behavior, use a `const char*` key instead.

##### Example

```c++
JsonObject& object = jsonBuffer::createObject();
object["hello"] = "world";
const char* world = object["hello"];
```


### JsonObject::prettyPrintTo()

##### Description

Serialize the object to an indented JSON string.

This will create a "prettified" JSON, if you want a compact JSON without space or line break, use `JsonObject::print()`

##### Signatures

```c++
size_t prettyPrintTo(char* buffer, size_t size) const;
size_t prettyPrintTo(char buffer[size]) const;
size_t prettyPrintTo(Print &) const;
size_t prettyPrintTo(String &) const;
size_t prettyPrintTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or an `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
object.prettyPrintTo(Serial);
```

will write the following string to the serial output:

```json
{
  "hello": "world"
}
```



### JsonObject::printTo()

##### Description

Serialize the object to a JSON string.

This will create a compact JSON, if you want a pretty JSON with spaces and line breaks, use `JsonObject::prettyPrint()`

##### Signatures

```c++
size_t printTo(char* buffer, size_t size) const;
size_t printTo(char buffer[size]) const;
size_t printTo(Print &) const;
size_t printTo(String &) const;
size_t printTo(std::string &) const;
```

##### Arguments

The destination of the JSON string.

Can be either:

* a `buffer` with specified `size` (this includes the zero-terminator)
* an implementation of `Print` (like `Serial`, `EthernetClient`...)
* a `String` or an `std::string`

##### Return value

The number of bytes written

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
object.printTo(Serial);
```

will write the following string to the serial output:

```json
{"hello":"world"}
```


### JsonObject::remove()

##### Description

Removes the element at the specified key.

**IMPORTANT**: This function doesn't free the memory allocated to the element in the `JsonBuffer`. This behavior has been prefered to keep the `JsonBuffer` fast and small, which is a foundational principle of the library.

##### Signatures

```c++
void remove(const char* key);
void remove(const String& key);
void remove(const std::string& key);
```

##### Arguments

`key`: the key to remove from the object.

##### Example

```c++
JsonObject& object = jsonBuffer.createObject();
object["A"] = 1;
object["B"] = 2;
object["C"] = 3;
object.remove("B");
object.printTo(Serial);
```

will print the following string to the serial output:

```json
{"A":1,"C":3}
```


### JsonObject::set()

##### Description

Sets the value at specified key.

##### Signatures

```c++
bool set(TString key, bool value);
bool set(TString key, float value, uint8_t decimals = 2);
bool set(TString key, double value, uint8_t decimals = 2);
bool set(TString key, signed char value);
bool set(TString key, signed long value);
bool set(TString key, signed int value);
bool set(TString key, signed short value);
bool set(TString key, unsigned char value);
bool set(TString key, unsigned long value);
bool set(TString key, unsigned int value);
bool set(TString key, unsigned short value);
bool set(TString key, const char *value);
bool set(TString key, const String &value); // see Remarks
bool set(TString key, JsonArray &array);
bool set(TString key, JsonObject &object);
bool set(TString key, const JsonVariant &value);
```

##### Arguments

`key`: the key to attach the value to, can be a `const char*`, a `String` or an `std::string`.

`value`: the value to attach to the key.

##### Return value

`true` if allocation succeeded.

`false` if there was not enough space left in the `JsonBuffer`.

##### Remarks

When you use a `String` or an `std::string`, a copy of the string is made, causing the `JsonBuffer` to grow.
The memory allocated for the copy will only be freed when the whole `JsonBuffer` is discarded.
This is true for both `key` and `value`.
To avoid this behavior, use `const char*` keys and values instead.

##### Example

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
object.set("hello","world");
object.printTo(Serial);
```

will print the following string to the serial output:

```json
{"hello":"world"}
```


### JsonObject::size()

##### Description

Returns the number of key/value pairs in the object.

##### Signature

```c++
size_t size() const;
```

##### Return value

An unsigned integer containing the number of key/value pairs in the object.

##### Example

```c++
JsonObject& object = jsonBuffer.createObject();
object["hello"] = "world";
Serial.println(object.size()); // 1
```



### JsonObject::success()

##### Description

Tells if the object is valid, which can be used:

1. to check if the object was successfully parsed, or
2. to check if the object was successfully allocated.

##### Signatures

```c++
bool success() const;
```

##### Return value

`true` if the object was successfully parsed/allocated.
`false` if the parsing/allocation failed.

##### Examples

Example 1: parsing success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject("{\"hello\":\"world\"}");
Serial.println(object.success()); // true
```

Example 2: parsing failure:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.parseObject("[\"hello\",\"world\"]");
Serial.println(object.success()); // false
```

Example 3: allocation success:

```c++
StaticJsonBuffer<200> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
Serial.println(object.success()); // true
```

Example 4: allocation failure:

```c++
StaticJsonBuffer<1> jsonBuffer;
JsonObject& object = jsonBuffer.createObject();
Serial.println(object.success()); // false
```




## JsonVariant

A variable that can hold different type of values:

* a boolean
* a char, short, int or a long (signed or unsigned)
* a string (const char*)
* a reference to a JsonArray or JsonObject

A `JsonVariant` can be any of theses types at a time, but can only hold one value.
Its type can change at run time.


### JsonVariant::as()

##### Description

Get the value of the specified type.

##### Signatures

```c++
bool               as<bool>() const;

float              as<float>() const;
double             as<double>() const;

signed char        as<signed char>() const;
unsigned char      as<unsigned char>() const;
signed int         as<signed int>() const;
unsigned int       as<unsigned int>() const;
signed short       as<signed short>() const;
unsigned short     as<unsigned short>() const;
signed long        as<signed long>() const;
unsigned long      as<unsigned long>() const;
unsigned long long as<unsigned long long>() const;   // <- may require ARDUINOJSON_USE_LONG_LONG
signed long long   as<signed long long>() const;     // <- may require ARDUINOJSON_USE_LONG_LONG
signed __int64     as<signed __int64>() const;       // <- may require ARDUINOJSON_USE_INT64
unsigned __int64   as<unsigned __int64>() const;     // <- may require ARDUINOJSON_USE_INT64

const char*        as<char*>() const;
const char*        as<const char*>() const;
String             as<String>() const;               // <- causes duplication of the string
std::string        as<std::string>() const;          // <- causes duplication of the string

JsonArray&         as<JsonArray>() const;
JsonArray&         as<JsonArray&>() const;
JsonArray&         as<const JsonArray&>() const;
JsonObject&        as<JsonObject>() const;
JsonObject&        as<JsonObject&>() const;
JsonObject&        as<const JsonObject&>() const;
```

##### Return value

The value of the specified type or a default value if the `JsonVariant` is not compatible with the specified type.

The default value is:

* `0` for numerical types
* `NULL` for `const char*`
* `JsonArray::invalid()` for `JsonArray&`
* `JsonObject::invalid()` for `JsonObject&`

##### Example

```c++
JsonVariant variant = 42;
int i = variant.as<int>(); // <- i == 42
double d = variant.as<double>(); // <- d == 42.0
const char* s = variant.as<char*>(); // <- s == NULL
```


### JsonVariant::is()

##### Description

Test if the variant is currently holding a value of the specified type.

##### Signatures

```c++
bool is<bool>() const;

bool is<float>() const;
bool is<double>() const;

bool is<signed char>() const;
bool is<unsigned char>() const;
bool is<signed int>() const;
bool is<unsigned int>() const;
bool is<signed short>() const;
bool is<unsigned short>() const;
bool is<signed long>() const;
bool is<unsigned long>() const;
bool is<unsigned long long>() const;   // <- may require ARDUINOJSON_USE_LONG_LONG
bool is<signed long long>() const;     // <- may require ARDUINOJSON_USE_LONG_LONG
bool is<signed __int64>() const;       // <- may require ARDUINOJSON_USE_INT64
bool is<unsigned __int64>() const;     // <- may require ARDUINOJSON_USE_INT64

bool is<char*>() const;
bool is<const char*>() const;

bool is<JsonArray>() const;
bool is<JsonArray&>() const;
bool is<const JsonArray&>() const;
bool is<JsonObject>() const;
bool is<JsonObject&>() const;
bool is<const JsonObject&>() const;
```

##### Return value

* `true` if the variant is currently holding a value of the specified type,
* `false` if not

##### Example

```c++
JsonVariant variant = 42;
bool i = variant.is<int>(); // <- i == true
bool d = variant.is<double>(); // <- d == false
bool s = variant.is<char*>(); // <- s == false
```
