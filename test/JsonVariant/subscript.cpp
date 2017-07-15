// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonVariant::operator[]") {
  DynamicJsonVariant var;

  SECTION("Array") {
    DynamicJsonArray array;
    array.add("element at index 0");
    array.add("element at index 1");

    var = array;

    REQUIRE(2 == var.size());
    REQUIRE(std::string("element at index 0") == var[0]);
    REQUIRE(std::string("element at index 1") == var[1]);
    REQUIRE(std::string("element at index 0") ==
            var[static_cast<unsigned char>(0)]);  // issue #381
    REQUIRE_FALSE(var[666].success());
    REQUIRE_FALSE(var[3].success());
    REQUIRE_FALSE(var["0"].success());
  }

  SECTION("Object") {
    DynamicJsonObject object;
    object["a"] = "element at key \"a\"";
    object["b"] = "element at key \"b\"";

    var = object;

    REQUIRE(2 == var.size());
    REQUIRE(std::string("element at key \"a\"") == var["a"]);
    REQUIRE(std::string("element at key \"b\"") == var["b"]);
    REQUIRE_FALSE(var["c"].success());
    REQUIRE_FALSE(var[0].success());
  }

  SECTION("Undefined") {
    REQUIRE(0 == var.size());
    REQUIRE_FALSE(var["0"].success());
    REQUIRE_FALSE(var[0].success());
  }

  SECTION("String") {
    var = "hello world";
    REQUIRE(0 == var.size());
    REQUIRE_FALSE(var["0"].success());
    REQUIRE_FALSE(var[0].success());
  }

  SECTION("ObjectSetValue") {
    DynamicJsonObject object;
    var = object;
    var["hello"] = "world";
    REQUIRE(1 == var.size());
    REQUIRE(std::string("world") == var["hello"]);
  }

  SECTION("ArraySetValue") {
    DynamicJsonArray array;
    array.add("hello");

    var = array;
    var[0] = "world";
    REQUIRE(1 == var.size());
    REQUIRE(std::string("world") == var[0]);
  }

  SECTION("NestedObjectSetValue") {
    DynamicJsonArray array;
    array.createNestedObject();

    var = array;
    var[0]["hello"] = "world";
    REQUIRE(1 == var.size());
    REQUIRE(1 == var[0].size());
    REQUIRE(std::string("world") == var[0]["hello"]);
  }
}
