// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonArray::add()") {
  DynamicJsonArray _array;

  SECTION("SizeIncreased_WhenValuesAreAdded") {
    _array.add("hello");
    REQUIRE(1U == _array.size());
  }

  SECTION("int") {
    _array.add(123);
    REQUIRE(123 == _array[0].as<int>());
    REQUIRE(_array[0].is<int>());
    REQUIRE(_array[0].is<double>());
  }

  SECTION("double") {
    _array.add(123.45);
    REQUIRE(123.45 == _array[0].as<double>());
    REQUIRE(_array[0].is<double>());
    REQUIRE_FALSE(_array[0].is<bool>());
  }

  SECTION("bool") {
    _array.add(true);
    REQUIRE(true == _array[0].as<bool>());
    REQUIRE(_array[0].is<bool>());
    REQUIRE_FALSE(_array[0].is<int>());
  }

  SECTION("const char*") {
    const char* str = "hello";
    _array.add(str);
    REQUIRE(str == _array[0].as<const char*>());
    REQUIRE(_array[0].is<const char*>());
    REQUIRE_FALSE(_array[0].is<int>());
  }

  SECTION("nested array") {
    DynamicJsonArray arr;

    _array.add(arr);

    // TODO: requires array comparison
    //    REQUIRE(&arr == &_array[0].as<JsonArray&>());
    REQUIRE(_array[0].is<JsonArray&>());
    REQUIRE_FALSE(_array[0].is<int>());
  }

  SECTION("nested object") {
    DynamicJsonObject obj;

    _array.add(obj);

    // TODO: requires array comparison
    // REQUIRE(&obj == &_array[0].as<JsonObject&>());
    REQUIRE(_array[0].is<JsonObject&>());
    REQUIRE_FALSE(_array[0].is<int>());
  }

  SECTION("array subscript") {
    const char* str = "hello";
    DynamicJsonArray arr;
    arr.add(str);

    _array.add(arr[0]);

    REQUIRE(str == _array[0]);
  }

  SECTION("object subscript") {
    const char* str = "hello";
    DynamicJsonObject obj;
    obj["x"] = str;

    _array.add(obj["x"]);

    REQUIRE(str == _array[0]);
  }
}
