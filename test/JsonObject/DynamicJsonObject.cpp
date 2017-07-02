// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

size_t getSize(DynamicJsonObject& obj) {
  return obj.buffer().size() + sizeof(JsonObject);
}

TEST_CASE("DynamicJsonObject") {
  DynamicJsonObject obj;

  SECTION("growths as value are added") {
    REQUIRE(JSON_OBJECT_SIZE(0) == getSize(obj));

    obj["hello"] = 1;
    REQUIRE(JSON_OBJECT_SIZE(1) == getSize(obj));

    obj["world"] = 2;
    REQUIRE(JSON_OBJECT_SIZE(2) == getSize(obj));

    obj["world"] = 3;  // <- same key, should not grow
    REQUIRE(JSON_OBJECT_SIZE(2) == getSize(obj));
  }
}
