// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>
#include <string>

void check(const JsonObject &object, const std::string &expected) {
  char actual[256];
  size_t actualLen = object.printTo(actual);
  size_t measuredLen = object.measureLength();

  REQUIRE(expected == actual);
  REQUIRE(expected.size() == actualLen);
  REQUIRE(expected.size() == measuredLen);
}
TEST_CASE("JsonObject::printTo()") {
  DynamicJsonObject object;

  SECTION("EmptyObject") {
    check(object, "{}");
  }

  SECTION("TwoStrings") {
    object["key1"] = "value1";
    object.set("key2", "value2");

    check(object, "{\"key1\":\"value1\",\"key2\":\"value2\"}");
  }

  SECTION("RemoveFirst") {
    object["key1"] = "value1";
    object["key2"] = "value2";
    object.remove("key1");

    check(object, "{\"key2\":\"value2\"}");
  }

  SECTION("RemoveLast") {
    object["key1"] = "value1";
    object["key2"] = "value2";
    object.remove("key2");

    check(object, "{\"key1\":\"value1\"}");
  }

  SECTION("RemoveUnexistingKey") {
    object["key1"] = "value1";
    object["key2"] = "value2";
    object.remove("key3");

    check(object, "{\"key1\":\"value1\",\"key2\":\"value2\"}");
  }

  SECTION("ReplaceExistingKey") {
    object["key"] = "value1";
    object["key"] = "value2";

    check(object, "{\"key\":\"value2\"}");
  }

  SECTION("TwoIntegers") {
    object["a"] = 1;
    object.set("b", 2);
    check(object, "{\"a\":1,\"b\":2}");
  }

  SECTION("RawJson") {
    object["a"] = RawJson("[1,2]");
    object.set("b", RawJson("[4,5]"));
    check(object, "{\"a\":[1,2],\"b\":[4,5]}");
  }

  SECTION("Two doubles") {
    object["a"] = 12.34;
    object.set("b", 56.78);
    check(object, "{\"a\":12.34,\"b\":56.78}");
  }

  SECTION("TwoNull") {
    object["a"] = static_cast<char *>(0);
    object.set("b", static_cast<char *>(0));
    check(object, "{\"a\":null,\"b\":null}");
  }

  SECTION("TwoBooleans") {
    object["a"] = true;
    object.set("b", false);
    check(object, "{\"a\":true,\"b\":false}");
  }

  SECTION("ThreeNestedArrays") {
    DynamicJsonArray arr;

    object.createNestedArray("a");
    object["b"] = arr;
    object.set("c", arr);

    check(object, "{\"a\":[],\"b\":[],\"c\":[]}");
  }

  SECTION("ThreeNestedObjects") {
    DynamicJsonObject obj;

    object.createNestedObject("a");
    object["b"] = obj;
    object.set("c", obj);

    check(object, "{\"a\":{},\"b\":{},\"c\":{}}");
  }
}
