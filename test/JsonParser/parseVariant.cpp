// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("parseJson(JsonVariant&)") {
  DynamicJsonVariant variant;

  SECTION("EmptyObject") {
    bool result = parseJson(variant, "{}");
    REQUIRE(result);
    REQUIRE(variant.is<JsonObject>());
  }

  SECTION("EmptyArray") {
    bool result = parseJson(variant, "[]");
    REQUIRE(result);
    REQUIRE(variant.is<JsonArray>());
  }

  SECTION("Integer") {
    bool result = parseJson(variant, "-42");
    REQUIRE(result);
    REQUIRE(variant.is<int>());
    REQUIRE_FALSE(variant.is<bool>());
    REQUIRE(variant == -42);
  }

  SECTION("Double") {
    bool result = parseJson(variant, "-1.23e+4");
    REQUIRE(result);
    REQUIRE_FALSE(variant.is<int>());
    REQUIRE(variant.is<double>());
    REQUIRE(variant.as<double>() == Approx(-1.23e+4));
  }

  SECTION("Double quoted string") {
    bool result = parseJson(variant, "\"hello world\"");
    REQUIRE(result);
    REQUIRE(variant.is<char*>());
    REQUIRE_THAT(variant.as<char*>(), Equals("hello world"));
  }

  SECTION("Single quoted string") {
    bool result = parseJson(variant, "\'hello world\'");
    REQUIRE(result);
    REQUIRE(variant.is<char*>());
    REQUIRE_THAT(variant.as<char*>(), Equals("hello world"));
  }

  SECTION("True") {
    bool result = parseJson(variant, "true");
    REQUIRE(result);
    REQUIRE(variant.is<bool>());
    REQUIRE(variant == true);
  }

  SECTION("False") {
    bool result = parseJson(variant, "false");
    REQUIRE(result);
    REQUIRE(variant.is<bool>());
    REQUIRE(variant == false);
  }

  SECTION("OpenBrace") {
    bool result = parseJson(variant, "{");
    REQUIRE_FALSE(result);
  }

  SECTION("Incomplete string") {
    bool result = parseJson(variant, "\"hello");
    REQUIRE(result);
    REQUIRE(variant.is<char*>());
    REQUIRE_THAT(variant.as<char*>(), Equals("hello"));
  }
}
