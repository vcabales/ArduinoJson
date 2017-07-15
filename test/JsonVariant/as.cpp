// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <stdint.h>
#include <catch.hpp>

static const char* null = 0;

TEST_CASE("JsonVariant::as()") {
  StaticJsonVariant<JSON_OBJECT_SIZE(1)> variant;

  SECTION("DoubleAsBool") {
    variant = 4.2;
    REQUIRE(variant.as<bool>());
  }

  SECTION("DoubleAsCstr") {
    variant = 4.2;
    REQUIRE_FALSE(variant.as<const char*>());
  }

  SECTION("DoubleAsString") {
    variant = 4.2;
    REQUIRE(std::string("4.2") == variant.as<std::string>());
  }

  SECTION("DoubleAsLong") {
    variant = 4.2;
    REQUIRE(4L == variant.as<long>());
  }

  SECTION("DoubleAsUnsigned") {
    variant = 4.2;
    REQUIRE(4U == variant.as<unsigned>());
  }

  SECTION("DoubleZeroAsBool") {
    variant = 0.0;
    REQUIRE_FALSE(variant.as<bool>());
  }

  SECTION("DoubleZeroAsLong") {
    variant = 0.0;
    REQUIRE(0L == variant.as<long>());
  }

  SECTION("FalseAsBool") {
    variant = false;
    REQUIRE_FALSE(variant.as<bool>());
  }

  SECTION("FalseAsDouble") {
    variant = false;
    REQUIRE(0.0 == variant.as<double>());
  }

  SECTION("FalseAsLong") {
    variant = false;
    REQUIRE(0L == variant.as<long>());
  }

  SECTION("FalseAsString") {
    variant = false;
    REQUIRE(std::string("false") == variant.as<std::string>());
  }

  SECTION("TrueAsBool") {
    variant = true;
    REQUIRE(variant.as<bool>());
  }

  SECTION("TrueAsDouble") {
    variant = true;
    REQUIRE(1.0 == variant.as<double>());
  }

  SECTION("TrueAsLong") {
    variant = true;
    REQUIRE(1L == variant.as<long>());
  }

  SECTION("TrueAsString") {
    variant = true;
    REQUIRE(std::string("true") == variant.as<std::string>());
  }

  SECTION("LongAsBool") {
    variant = 42L;
    REQUIRE(variant.as<bool>());
  }

  SECTION("LongZeroAsBool") {
    variant = 0L;
    REQUIRE_FALSE(variant.as<bool>());
  }

  SECTION("PositiveLongAsDouble") {
    variant = 42L;
    REQUIRE(42.0 == variant.as<double>());
  }

  SECTION("NegativeLongAsDouble") {
    variant = -42L;
    REQUIRE(-42.0 == variant.as<double>());
  }

  SECTION("LongAsString") {
    variant = 42L;
    REQUIRE(std::string("42") == variant.as<std::string>());
  }

  SECTION("LongZeroAsDouble") {
    variant = 0L;
    REQUIRE(0.0 == variant.as<double>());
  }

  SECTION("NullAsBool") {
    variant = null;
    REQUIRE_FALSE(variant.as<bool>());
  }

  SECTION("NullAsDouble") {
    variant = null;
    REQUIRE(0.0 == variant.as<double>());
  }

  SECTION("NullAsLong") {
    variant = null;
    REQUIRE(0L == variant.as<long>());
  }

  SECTION("NullAsString") {
    variant = null;
    REQUIRE(std::string("null") == variant.as<std::string>());
  }

  SECTION("NumberStringAsBool") {
    variant = "42";
    REQUIRE(variant.as<bool>());
  }

  SECTION("NumberStringAsLong") {
    variant = "42";
    REQUIRE(42L == variant.as<long>());
  }

#if ARDUINOJSON_USE_LONG_LONG || ARDUINOJSON_USE_INT64
  SECTION("NumberStringAsInt64Negative") {
    variant = "-9223372036854775808";
    REQUIRE(-9223372036854775807 - 1 == variant.as<long long>());
  }

  SECTION("NumberStringAsInt64Positive") {
    variant = "9223372036854775807";
    REQUIRE(9223372036854775807 == variant.as<long long>());
  }
#endif

  SECTION("RandomStringAsBool") {
    variant = "hello";
    REQUIRE_FALSE(variant.as<bool>());
  }

  SECTION("RandomStringAsLong") {
    variant = "hello";
    REQUIRE(0L == variant.as<long>());
  }

  SECTION("RandomStringAsConstCharPtr") {
    variant = "hello";
    REQUIRE(std::string("hello") == variant.as<const char*>());
  }

  SECTION("RandomStringAsCharPtr") {
    variant = "hello";
    REQUIRE(std::string("hello") == variant.as<char*>());
  }

  SECTION("RandomStringAsString") {
    variant = "hello";
    REQUIRE(std::string("hello") == variant.as<std::string>());
  }

  SECTION("TrueStringAsBool") {
    variant = "true";
    REQUIRE(variant.as<bool>());
  }

  SECTION("TrueStringAsLong") {
    variant = "true";
    REQUIRE(1L == variant.as<long>());
  }

  SECTION("ObjectAsString") {
    DynamicJsonObject obj;
    obj["key"] = "value";

    variant = obj;
    REQUIRE(std::string("{\"key\":\"value\"}") == variant.as<std::string>());
  }

  SECTION("ArrayAsString") {
    DynamicJsonArray arr;
    arr.add(4);
    arr.add(2);

    variant = arr;
    REQUIRE(std::string("[4,2]") == variant.as<std::string>());
  }

  SECTION("ArrayAsJsonArray") {
    DynamicJsonArray arr;

    variant = arr;
    REQUIRE(&arr == &variant.as<JsonArray&>());
    REQUIRE(&arr == &variant.as<JsonArray>());  // <- shorthand
  }

  /* TODO: need object comparison
    SECTION("ObjectAsJsonObject") {
      DynamicJsonObject obj;

      variant = obj;
      REQUIRE(&obj == &variant.as<JsonObject&>());
      REQUIRE(&obj == &variant.as<JsonObject>());  // <- shorthand
    }*/
}
