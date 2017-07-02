// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("parseJson(StaticJsonObject&)") {
  SECTION("StaticJsonObject of the right size of 0 elements") {
    StaticJsonObject<JSON_OBJECT_SIZE(0)> obj;
    char input[] = "{}";
    REQUIRE(true == parseJson(obj, input));
  }

  SECTION("StaticJsonObject too small for 1 element") {
    StaticJsonObject<JSON_OBJECT_SIZE(1) - 1> obj;
    char input[] = "{\"a\":1}";
    REQUIRE(false == parseJson(obj, input));
  }

  SECTION("StaticJsonObject of the right size of 1 element") {
    StaticJsonObject<JSON_OBJECT_SIZE(1)> obj;
    char input[] = "{\"a\":1}";
    REQUIRE(true == parseJson(obj, input));
  }

  SECTION("StaticJsonObject too small for 1 nested array") {
    StaticJsonObject<JSON_OBJECT_SIZE(1) + JSON_ARRAY_SIZE(0) - 1> obj;
    char input[] = "{\"a\":[]}";
    REQUIRE(false == parseJson(obj, input));
  }

  SECTION("StaticJsonObject of the right size of 1 nested array") {
    StaticJsonObject<JSON_OBJECT_SIZE(1) + JSON_ARRAY_SIZE(0)> obj;
    char input[] = "{\"a\":[]}";
    REQUIRE(true == parseJson(obj, input));
  }
}
