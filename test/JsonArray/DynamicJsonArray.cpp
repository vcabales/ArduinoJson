// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

size_t getSize(DynamicJsonArray& array) {
  return array.buffer().size() + sizeof(JsonArray);
}

TEST_CASE("DynamicJsonArray") {
  DynamicJsonArray array;

  SECTION("growths when values are added") {
    REQUIRE(JSON_ARRAY_SIZE(0) == getSize(array));

    array.add("hello");
    REQUIRE(JSON_ARRAY_SIZE(1) == getSize(array));

    array.add("world");
    REQUIRE(JSON_ARRAY_SIZE(2) == getSize(array));
  }

  SECTION("CanAdd1000Values") {
    for (size_t i = 1; i <= 1000; i++) {
      array.add("hello");
    }
    REQUIRE(1000 == array.size());
  }
}
