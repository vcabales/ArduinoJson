// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("parseJson(JsonObject&)") {
  DynamicJsonObject obj;

  SECTION("EmptyObject") {
    bool result = parseJson(obj, "{}");
    REQUIRE(true == result);
    REQUIRE(obj.size() == 0);
  }

  SECTION("MissingOpeningBrace") {
    bool result = parseJson(obj, "}");
    REQUIRE(result == false);
  }

  SECTION("MissingClosingBrace") {
    bool result = parseJson(obj, "{");
    REQUIRE(result == false);
  }

  SECTION("MissingColonAndValue") {
    bool result = parseJson(obj, "{\"key\"}");
    REQUIRE(result == false);
  }

  SECTION("MissingQuotesAndColonAndValue") {
    bool result = parseJson(obj, "{key}");
    REQUIRE(result == false);
  }

  SECTION("OneString") {
    bool result = parseJson(obj, "{\"key\":\"value\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringSingleQuotes") {
    bool result = parseJson(obj, "{'key':'value'}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringNoQuotes") {
    bool result = parseJson(obj, "{key:value}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringSpaceBeforeKey") {
    bool result = parseJson(obj, "{ \"key\":\"value\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringSpaceAfterKey") {
    bool result = parseJson(obj, "{\"key\" :\"value\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringSpaceBeforeValue") {
    bool result = parseJson(obj, "{\"key\": \"value\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("OneStringSpaceAfterValue") {
    bool result = parseJson(obj, "{\"key\":\"value\" }");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 1);
    REQUIRE(obj["key"] == "value");
  }

  SECTION("TwoStrings") {
    bool result = parseJson(obj, "{\"key1\":\"value1\",\"key2\":\"value2\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == "value1");
    REQUIRE(obj["key2"] == "value2");
  }

  SECTION("TwoStringsSpaceBeforeComma") {
    bool result = parseJson(obj, "{\"key1\":\"value1\" ,\"key2\":\"value2\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == "value1");
    REQUIRE(obj["key2"] == "value2");
  }

  SECTION("TwoStringsSpaceAfterComma") {
    bool result = parseJson(obj, "{\"key1\":\"value1\" ,\"key2\":\"value2\"}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == "value1");
    REQUIRE(obj["key2"] == "value2");
  }

  SECTION("EndingWithAComma") {
    bool result = parseJson(obj, "{\"key1\":\"value1\",}");
    REQUIRE(result == false);
  }

  SECTION("TwoIntergers") {
    bool result = parseJson(obj, "{\"key1\":42,\"key2\":-42}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == 42);
    REQUIRE(obj["key2"] == -42);
  }

  SECTION("TwoDoubles") {
    bool result = parseJson(obj, "{\"key1\":12.345,\"key2\":-7E89}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == 12.345);
    REQUIRE(obj["key2"] == -7E89);
  }

  SECTION("TwoBooleans") {
    bool result = parseJson(obj, "{\"key1\":true,\"key2\":false}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"] == true);
    REQUIRE(obj["key2"] == false);
  }

  SECTION("TwoNulls") {
    bool result = parseJson(obj, "{\"key1\":null,\"key2\":null}");
    REQUIRE(result == true);
    REQUIRE(obj.size() == 2);
    REQUIRE(obj["key1"].as<char*>() == 0);
    REQUIRE(obj["key2"].as<char*>() == 0);
  }

  SECTION("NullForKey") {
    bool result = parseJson(obj, "null:\"value\"}");
    REQUIRE(result == false);
  }

  SECTION("Input is char* NULL") {
    REQUIRE(false == parseJson(obj, static_cast<char*>(0)));
  }

  SECTION("Input is const char* NULL") {
    REQUIRE(false == parseJson(obj, static_cast<const char*>(0)));
  }
}
