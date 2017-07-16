// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonObject::operator[]") {
  DynamicJsonObject object;

  SECTION("SizeIncreased_WhenValuesAreAdded") {
    object["hello"] = 1;
    REQUIRE(1 == object.size());
  }

  SECTION("SizeUntouched_WhenSameValueIsAdded") {
    object["hello"] = 1;
    object["hello"] = 2;
    REQUIRE(1 == object.size());
  }

  SECTION("int") {
    object["hello"] = 123;

    REQUIRE(123 == object["hello"].as<int>());
    REQUIRE(true == object["hello"].is<int>());
    REQUIRE(false == object["hello"].is<bool>());
  }

  SECTION("volatile int") {  // issue #415
    volatile int i = 123;
    object["hello"] = i;

    REQUIRE(123 == object["hello"].as<int>());
    REQUIRE(true == object["hello"].is<int>());
    REQUIRE(false == object["hello"].is<bool>());
  }

  SECTION("double") {
    object["hello"] = 123.45;

    REQUIRE(true == object["hello"].is<double>());
    REQUIRE(false == object["hello"].is<long>());
    REQUIRE(123.45 == object["hello"].as<double>());
  }

  SECTION("bool") {
    object["hello"] = true;

    REQUIRE(true == object["hello"].is<bool>());
    REQUIRE(false == object["hello"].is<long>());
    REQUIRE(true == object["hello"].as<bool>());
  }

  SECTION("const char*") {
    object["hello"] = "h3110";

    REQUIRE(true == object["hello"].is<const char*>());
    REQUIRE(false == object["hello"].is<long>());
    REQUIRE(std::string("h3110") == object["hello"].as<const char*>());
    REQUIRE(std::string("h3110") ==
            object["hello"].as<char*>());  // <- short hand
  }

  SECTION("array") {
    DynamicJsonArray arr;

    object["hello"] = arr;

    // TODO: requires array comparison
    /*    REQUIRE(&arr == &object["hello"].as<JsonArray&>());
        REQUIRE(&arr == &object["hello"].as<JsonArray>());  // <- short hand
        REQUIRE(&arr == &object["hello"].as<const JsonArray&>());
        REQUIRE(&arr == &object["hello"].as<const JsonArray>());  // <- short
       hand*/
    REQUIRE(true == object["hello"].is<JsonArray&>());
    REQUIRE(true == object["hello"].is<JsonArray>());
    REQUIRE(true == object["hello"].is<const JsonArray&>());
    REQUIRE(true == object["hello"].is<const JsonArray>());
    REQUIRE(false == object["hello"].is<JsonObject&>());
  }

  SECTION("object") {
    DynamicJsonObject obj;

    object["hello"] = obj;

    // TODO: requires array comparison
    /* REQUIRE(&obj == &object["hello"].as<JsonObject&>());
     REQUIRE(&obj == &object["hello"].as<JsonObject>());  // <- short hand
     REQUIRE(&obj == &object["hello"].as<const JsonObject&>());
     REQUIRE(&obj == &object["hello"].as<const JsonObject>());  // <- short
     hand*/
    REQUIRE(true == object["hello"].is<JsonObject&>());
    REQUIRE(true == object["hello"].is<JsonObject>());
    REQUIRE(true == object["hello"].is<const JsonObject&>());
    REQUIRE(true == object["hello"].is<const JsonObject>());
    REQUIRE(false == object["hello"].is<JsonArray&>());
  }

  SECTION("array subscript") {
    DynamicJsonArray arr;
    arr.add(42);

    object["a"] = arr[0];

    REQUIRE(42 == object["a"]);
  }

  SECTION("object subscript") {
    DynamicJsonObject obj;
    obj.set("x", 42);

    object["a"] = obj["x"];

    REQUIRE(42 == object["a"]);
  }

  SECTION("KeyAsCharArray") {  // issue #423
    char key[] = "hello";
    object[key] = 42;
    REQUIRE(42 == object[key]);
  }
}
