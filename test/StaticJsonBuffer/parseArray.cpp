// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("StaticJsonBuffer::parseArray()") {
  SECTION("StaticJsonBuffer of the right size of 0 elements") {
    StaticJsonBuffer<JSON_ARRAY_SIZE(0)> jb;
    JsonArray& arr = jb.createArray();
    char input[] = "[]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("StaticJsonBuffer too small for 1 element") {
    StaticJsonBuffer<JSON_ARRAY_SIZE(1) - 1> jb;
    JsonArray& arr = jb.createArray();
    char input[] = "[1]";
    REQUIRE(false == parseJson(arr, input));
  }

  SECTION("StaticJsonBuffer of the right size of 1 element") {
    StaticJsonBuffer<JSON_ARRAY_SIZE(1)> jb;
    JsonArray& arr = jb.createArray();
    char input[] = "[1]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("StaticJsonBuffer too small for 1 nested object") {
    StaticJsonBuffer<JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(0) - 1> jb;
    JsonArray& arr = jb.createArray();
    char input[] = "[{}]";
    REQUIRE(false == parseJson(arr, input));
  }

  SECTION("StaticJsonBuffer of the right size of 1 nested object") {
    StaticJsonBuffer<JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(0)> jb;
    JsonArray& arr = jb.createArray();
    char input[] = "[{}]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("CharPtrNull") {
    REQUIRE_FALSE(
        StaticJsonBuffer<100>().parseArray(static_cast<char*>(0)).success());
  }

  SECTION("ConstCharPtrNull") {
    REQUIRE_FALSE(StaticJsonBuffer<100>()
                      .parseArray(static_cast<const char*>(0))
                      .success());
  }

  SECTION("CopyStringNotSpaces") {
    StaticJsonBuffer<100> jsonBuffer;
    jsonBuffer.parseArray("  [ \"1234567\" ] ");
    REQUIRE(JSON_ARRAY_SIZE(1) + sizeof("1234567") == jsonBuffer.size());
    // note we use a string of 8 bytes to be sure that the StaticJsonBuffer
    // will not insert bytes to enforce alignement
  }
}
