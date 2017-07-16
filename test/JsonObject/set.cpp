// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>
#include <string>

TEST_CASE("JsonObject::set()") {
  DynamicJsonObject object;

  SECTION("SizeIncreased_WhenValuesAreAdded") {
    object.set("hello", 42);
    REQUIRE(1 == object.size());
  }

  SECTION("SizeUntouched_WhenSameValueIsAdded") {
    object["hello"] = 1;
    object["hello"] = 2;
    REQUIRE(1 == object.size());
  }

  SECTION("int") {
    object.set("hello", 123);

    REQUIRE(123 == object["hello"].as<int>());
    REQUIRE(object["hello"].is<int>());
    REQUIRE_FALSE(object["hello"].is<bool>());
  }

  SECTION("double") {
    object.set("hello", 123.45);

    REQUIRE(123.45 == object["hello"].as<double>());
    REQUIRE(object["hello"].is<double>());
    REQUIRE_FALSE(object["hello"].is<bool>());
  }

  SECTION("bool") {
    object.set("hello", true);

    REQUIRE(object["hello"].as<bool>());
    REQUIRE(object["hello"].is<bool>());
    REQUIRE_FALSE(object["hello"].is<long>());
  }

  SECTION("const char*") {
    object.set("hello", "h3110");

    REQUIRE(std::string("h3110") == object["hello"].as<const char*>());
    REQUIRE(object["hello"].is<const char*>());
    REQUIRE_FALSE(object["hello"].is<long>());
  }

  SECTION("nested array") {
    DynamicJsonArray arr;

    object.set("hello", arr);

    // TODO: requires array comparison
    //  REQUIRE(&arr == &object["hello"].as<JsonArray>());
    REQUIRE(object["hello"].is<JsonArray&>());
    REQUIRE_FALSE(object["hello"].is<JsonObject&>());
  }

  SECTION("nested object") {
    DynamicJsonObject obj;

    object.set("hello", obj);

    // TODO: requires array comparison
    //  REQUIRE(&obj == &object["hello"].as<JsonObject>());
    REQUIRE(object["hello"].is<JsonObject&>());
    REQUIRE_FALSE(object["hello"].is<JsonArray&>());
  }

  SECTION("array subscript") {
    DynamicJsonArray arr;
    arr.add(42);

    object.set("a", arr[0]);

    REQUIRE(42 == object["a"]);
  }

  SECTION("object subscript") {
    DynamicJsonObject obj;
    obj.set("x", 42);

    object.set("a", obj["x"]);

    REQUIRE(42 == object["a"]);
  }

  SECTION("ShouldReturnTrue_WhenAllocationSucceeds") {
    StaticJsonObject<JSON_OBJECT_SIZE(1) + 15> obj;

    REQUIRE(true == obj.set(std::string("hello"), std::string("world")));
  }

  SECTION("ShouldReturnFalse_WhenAllocationFails") {
    StaticJsonObject<JSON_OBJECT_SIZE(1) + 10> obj;

    REQUIRE(false == obj.set(std::string("hello"), std::string("world")));
  }
}
