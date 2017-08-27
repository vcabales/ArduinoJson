// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("DynamicJsonVariant::DynamicJsonVariant()") {
  SECTION("int") {
    DynamicJsonVariant variant = 123;

    REQUIRE(123 == variant.as<int>());
    REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  }

  SECTION("double") {
    DynamicJsonVariant variant = 123.45;

    REQUIRE(123.45 == variant.as<double>());
    REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  }

  SECTION("bool") {
    DynamicJsonVariant variant = true;

    REQUIRE(variant.as<bool>());
    REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  }

  SECTION("const char*") {
    DynamicJsonVariant variant = "hello";

    REQUIRE(std::string("hello") == variant.as<const char*>());
    REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  }

  SECTION("std::string") {
    DynamicJsonVariant variant = std::string("hello");

    REQUIRE(std::string("hello") == variant.as<std::string>());
    REQUIRE(sizeof(JsonVariant) + 6 == variant.memoryUsage());
  }

  SECTION("JsonObject") {
    DynamicJsonObject object;
    object["hello"] = "world";
    JsonArray& arr = object.createNestedArray("values");
    arr.add(42);

    DynamicJsonVariant variant = object;

    // modifiy object to make sure we made a copy
    object["hello"] = "dummy";
    arr.add(666);

    REQUIRE("{\"hello\":\"world\",\"values\":[42]}" ==
            variant.as<std::string>());
  }

  SECTION("JsonArray") {
    DynamicJsonArray array;
    array.add(42);
    JsonObject& object = array.createNestedObject();
    object["hello"] = "world";

    DynamicJsonVariant variant = array;

    // modify the array to make sure we make a copy
    array[0] = 666;
    object["hello"] = "dummy";

    REQUIRE("[42,{\"hello\":\"world\"}]" == variant.as<std::string>());
  }

  SECTION("DynamicJsonVariant") {
    DynamicJsonVariant original = 123;
    DynamicJsonVariant variant = original;

    REQUIRE(123 == variant.as<int>());
    REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  }

  // BUG: it's not possible to construct a DynamicJsonVariant from a
  // StaticJsonVariant
  //
  // SECTION("StaticJsonVariant") {
  //   StaticJsonVariant<10> original = 123;
  //   DynamicJsonVariant variant = original;

  //   REQUIRE(123 == variant.as<int>());
  //   REQUIRE(sizeof(JsonVariant) == variant.memoryUsage());
  // }
}
