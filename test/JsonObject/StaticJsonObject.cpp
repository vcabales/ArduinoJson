// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("StaticJsonObject::memoryUsage()") {
  SECTION("GrowsWithObject") {
    StaticJsonObject<JSON_OBJECT_SIZE(3)> obj;

    REQUIRE(JSON_OBJECT_SIZE(0) == obj.memoryUsage());

    obj["hello"];
    REQUIRE(JSON_OBJECT_SIZE(0) == obj.memoryUsage());

    obj["hello"] = 1;
    REQUIRE(JSON_OBJECT_SIZE(1) == obj.memoryUsage());

    obj["world"] = 2;
    REQUIRE(JSON_OBJECT_SIZE(2) == obj.memoryUsage());

    obj["world"] = 3;  // <- same key, should not grow
    REQUIRE(JSON_OBJECT_SIZE(2) == obj.memoryUsage());
  }

  SECTION("ObjectDoesntGrowWhenFull") {
    StaticJsonObject<JSON_OBJECT_SIZE(1)> obj;

    obj["hello"] = 1;
    obj["world"] = 2;

    REQUIRE(JSON_OBJECT_SIZE(1) == obj.memoryUsage());
    REQUIRE(1 == obj.size());

    char json[64];
    obj.printTo(json, sizeof(json));
    REQUIRE(std::string("{\"hello\":1}") == json);
  }
}
