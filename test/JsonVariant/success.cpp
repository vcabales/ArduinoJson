// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonVariant::success()") {
  DynamicJsonVariant variant;

  SECTION("ReturnsFalse_WhenUndefined") {
    REQUIRE(false == variant.success());
  }

  SECTION("ReturnsTrue_WhenInteger") {
    variant = 0;
    REQUIRE(true == variant.success());
  }

  SECTION("ReturnsTrue_WhenEmptyArray") {
    DynamicJsonArray array;

    variant = array;
    REQUIRE(true == variant.success());
  }

  SECTION("ReturnsTrue_WhenEmptyObject") {
    DynamicJsonObject object;

    variant = object;
    REQUIRE(true == variant.success());
  }

  SECTION("ReturnsFalse_WhenInvalidArray") {
    variant = JsonArray::invalid();
    REQUIRE(false == variant.success());
  }

  SECTION("ReturnsFalse_WhenInvalidObject") {
    variant = JsonObject::invalid();
    REQUIRE(false == variant.success());
  }
}
