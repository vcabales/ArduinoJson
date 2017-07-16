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

  SECTION("operator=(const JsonArray&)") {
    array.add(666);

    {
      StaticJsonArray<JSON_ARRAY_SIZE(2)+JSON_OBJECT_SIZE(1)> prototype;
      prototype.add(42);
      prototype.createNestedObject()["hello"] = "world";

      array = prototype;
    }

    CHECK(array.size() == 2);
    REQUIRE(array[0] == 42);
    REQUIRE(array[1].is<JsonObject>());
    REQUIRE(array[1]["hello"] == std::string("world"));
  }
}
