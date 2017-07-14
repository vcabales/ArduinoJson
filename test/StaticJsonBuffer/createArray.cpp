// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

// TODO: move
TEST_CASE("StaticJsonArray::memoryUsage()") {
  SECTION("GrowsWithArray") {
    StaticJsonArray<JSON_ARRAY_SIZE(2)> arr;

    REQUIRE(JSON_ARRAY_SIZE(0) == arr.memoryUsage());

    arr.add("hello");
    REQUIRE(JSON_ARRAY_SIZE(1) == arr.memoryUsage());

    arr.add("world");
    REQUIRE(JSON_ARRAY_SIZE(2) == arr.memoryUsage());
  }

  SECTION("ArrayDoesntGrowWhenFull") {
    StaticJsonArray<JSON_ARRAY_SIZE(1)> arr;

    arr.add("hello");
    arr.add("world");

    REQUIRE(1 == arr.size());
    REQUIRE(JSON_ARRAY_SIZE(1) == arr.memoryUsage());
  }
}
