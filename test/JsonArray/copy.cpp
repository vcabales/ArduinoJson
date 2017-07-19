// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

template <typename TArray>
TArray buildArray() {
  TArray array;
  array.add(42);
  array.createNestedObject()["hello"] = "world";
  return array;
}

void validateArray(JsonArray& array) {
  CHECK(array.size() == 2);
  REQUIRE(array[0] == 42);
  REQUIRE(array[1].is<JsonObject>());
  REQUIRE(array[1]["hello"] == std::string("world"));
}

TEST_CASE("DynamicJsonArray::operator=()") {
  DynamicJsonArray array;
  array.add(666);
  array.add(666);

  SECTION("operator=(const DynamicJsonArray&)") {
    array = buildArray<DynamicJsonArray>();
    validateArray(array);
  }

  SECTION("operator=(const StaticJsonArray<N>&)") {
    const size_t SIZE = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(1);
    array = buildArray<StaticJsonArray<SIZE> >();
    validateArray(array);
  }
}
