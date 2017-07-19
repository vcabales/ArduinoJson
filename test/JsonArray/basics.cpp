// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonArray basics") {
  DynamicJsonArray array;

  SECTION("success() returns true") {
    REQUIRE(array.success());
  }

  SECTION("size() starts at zero") {
    REQUIRE(0U == array.size());
  }

  SECTION("createNestedArray()") {
    JsonArray& arr = array.createNestedArray();
    REQUIRE(&arr == &array[0].as<JsonArray&>());
  }

  SECTION("createNestedObject()") {
    JsonObject& obj = array.createNestedObject();
    REQUIRE(&obj == &array[0].as<JsonObject&>());
  }
}
