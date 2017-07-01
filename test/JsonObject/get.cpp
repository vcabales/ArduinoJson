// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("JsonObject::get()") {
  DynamicJsonObject object;

  SECTION("GetConstCharPointer_GivenStringLiteral") {
    object.set("hello", "world");
    const char* value = object.get<const char*>("hello");
    REQUIRE_THAT(value, Equals("world"));
  }
}
