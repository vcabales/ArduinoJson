// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("JsonVariant::operator=(const JsonVariant&)") {
  DynamicJsonVariant variant1;
  DynamicJsonVariant variant2;

  SECTION("integer") {
    variant1 = 123;
    variant2 = variant1;
    variant1 = 456;

    REQUIRE(123 == variant2.as<int>());
  }

  SECTION("double") {
    variant1 = 123.45;
    variant2 = variant1;
    variant1 = 456.78;

    REQUIRE(123.45 == variant2.as<double>());
  }

  SECTION("boolean") {
    variant1 = true;
    variant2 = variant1;
    variant1 = false;

    REQUIRE(variant2.as<bool>());
  }

  SECTION("char pointer") {
    variant1 = "hello";
    variant2 = variant1;
    variant1 = "world";

    REQUIRE(std::string("hello") == variant2.as<const char*>());
  }

  SECTION("string") {
    std::string s("hello");

    variant1 = "hello";
    variant2 = variant1;
    variant1 = "world";

    REQUIRE(std::string("hello") == variant2.as<std::string>());
  }

  SECTION("JsonObject") {
    DynamicJsonObject object;
    object["hello"] = "world";
    JsonArray& arr = object.createNestedArray("values");
    arr.add(42);

    std::string s;
    object.printTo(s);
    REQUIRE("{\"hello\":\"world\",\"values\":[42]}" == s);

    variant1 = object;

    // modifiy object to make sure we made a copy
    object["hello"] = "dummy";
    arr.add(666);

    REQUIRE("{\"hello\":\"world\",\"values\":[42]}" ==
            variant1.as<std::string>());
  }

  SECTION("JsonArray") {
    DynamicJsonArray array;

    array.add("hello");
    array.add("world");
    variant1 = array;
    array[1] = 666;

    REQUIRE("[\"hello\",\"world\"]" == variant1.as<std::string>());
  }
}
