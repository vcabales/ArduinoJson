// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonObject::containsKey()") {
  DynamicJsonObject object;

  SECTION("ContainsKeyReturnsFalseForNonExistingKey") {
    object.set("hello", 42);

    REQUIRE(false == object.containsKey("world"));
  }

  SECTION("ContainsKeyReturnsTrueForDefinedValue") {
    object.set("hello", 42);

    REQUIRE(true == object.containsKey("hello"));
  }

  SECTION("ContainsKeyReturnsFalseAfterRemove") {
    object.set("hello", 42);
    object.remove("hello");

    REQUIRE(false == object.containsKey("hello"));
  }
}
