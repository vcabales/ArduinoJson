// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("StaticJsonBuffer::parseArray()") {
  SECTION("StaticJsonArray of the right size of 0 elements") {
    StaticJsonArray<JSON_ARRAY_SIZE(0)> arr;
    char input[] = "[]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("StaticJsonArray too small for 1 element") {
    StaticJsonArray<JSON_ARRAY_SIZE(1) - 1> arr;
    char input[] = "[1]";
    REQUIRE(false == parseJson(arr, input));
  }

  SECTION("StaticJsonArray of the right size of 1 element") {
    StaticJsonArray<JSON_ARRAY_SIZE(1)> arr;
    char input[] = "[1]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("StaticJsonArray too small for 1 nested object") {
    StaticJsonArray<JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(0) - 1> arr;
    char input[] = "[{}]";
    REQUIRE(false == parseJson(arr, input));
  }

  SECTION("StaticJsonArray of the right size of 1 nested object") {
    StaticJsonArray<JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(0)> arr;
    char input[] = "[{}]";
    REQUIRE(true == parseJson(arr, input));
  }

  SECTION("Input is char* NULL") {
    StaticJsonArray<100> arr;
    REQUIRE(false == parseJson(arr, static_cast<char*>(0)));
  }

  SECTION("Input is const char* NULL") {
    StaticJsonArray<100> arr;
    REQUIRE(false == parseJson(arr, static_cast<const char*>(0)));
  }

  SECTION("CopyStringNotSpaces") {
    StaticJsonBuffer<100> jsonBuffer;
    jsonBuffer.parseArray("  [ \"1234567\" ] ");
    REQUIRE(JSON_ARRAY_SIZE(1) + sizeof("1234567") == jsonBuffer.size());
    // note we use a string of 8 bytes to be sure that the StaticJsonBuffer
    // will not insert bytes to enforce alignement
  }
}
