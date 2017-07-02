// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

TEST_CASE("parseJson(JsonArray&)") {
  DynamicJsonArray arr;

  SECTION("EmptyArray") {
    bool result = parseJson(arr, "[]");

    REQUIRE(true == result);
    REQUIRE(0 == arr.size());
  }

  SECTION("MissingOpeningBracket") {
    bool result = parseJson(arr, "]");
    REQUIRE(false == result);
  }

  SECTION("ArrayWithNoEnd") {
    bool result = parseJson(arr, "[");
    REQUIRE(false == result);
  }

  SECTION("EmptyArrayWithLeadingSpaces") {
    bool result = parseJson(arr, "  []");

    REQUIRE(true == result);
    REQUIRE(0 == arr.size());
  }

  SECTION("Garbage") {
    bool result = parseJson(arr, "%*$£¤");

    REQUIRE(false == result);
  }

  SECTION("OneInteger") {
    bool result = parseJson(arr, "[42]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == 42);
  }

  SECTION("OneIntegerWithSpacesBefore") {
    bool result = parseJson(arr, "[ \t\r\n42]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == 42);
  }

  SECTION("OneIntegerWithSpaceAfter") {
    bool result = parseJson(arr, "[42 \t\r\n]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == 42);
  }

  SECTION("TwoIntegers") {
    bool result = parseJson(arr, "[42,84]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == 42);
    REQUIRE(arr[1] == 84);
  }

  SECTION("TwoDoubles") {
    bool result = parseJson(arr, "[4.2,1e2]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == 4.2);
    REQUIRE(arr[1] == 1e2);
  }

  SECTION("UnsignedLong") {
    bool result = parseJson(arr, "[4294967295]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == 4294967295UL);
  }

  SECTION("TwoBooleans") {
    bool result = parseJson(arr, "[true,false]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == true);
    REQUIRE(arr[1] == false);
  }

  SECTION("TwoNulls") {
    bool result = parseJson(arr, "[null,null]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0].as<char*>() == 0);
    REQUIRE(arr[1].as<char*>() == 0);
  }

  SECTION("TwoStringsDoubleQuotes") {
    bool result = parseJson(arr, "[ \"hello\" , \"world\" ]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("TwoStringsSingleQuotes") {
    bool result = parseJson(arr, "[ 'hello' , 'world' ]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("TwoStringsNoQuotes") {
    bool result = parseJson(arr, "[ hello , world ]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("EmptyStringsDoubleQuotes") {
    bool result = parseJson(arr, "[\"\",\"\"]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "");
    REQUIRE(arr[1] == "");
  }

  SECTION("EmptyStringSingleQuotes") {
    bool result = parseJson(arr, "[\'\',\'\']");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "");
    REQUIRE(arr[1] == "");
  }

  SECTION("EmptyStringNoQuotes") {
    bool result = parseJson(arr, "[,]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "");
    REQUIRE(arr[1] == "");
  }

  SECTION("ClosingDoubleQuoteMissing") {
    bool result = parseJson(arr, "[\"]");

    REQUIRE(false == result);
  }

  SECTION("ClosingSignleQuoteMissing") {
    bool result = parseJson(arr, "[\']");

    REQUIRE(false == result);
  }

  SECTION("StringWithEscapedChars") {
    bool result = parseJson(arr, "[\"1\\\"2\\\\3\\/4\\b5\\f6\\n7\\r8\\t9\"]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "1\"2\\3/4\b5\f6\n7\r8\t9");
  }

  SECTION("StringWithUnterminatedEscapeSequence") {
    bool result = parseJson(arr, "\"\\\0\"", 4);
    REQUIRE(false == result);
  }

  SECTION("CCommentBeforeOpeningBracket") {
    bool result = parseJson(arr, "/*COMMENT*/  [\"hello\"]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CCommentAfterOpeningBracket") {
    bool result = parseJson(arr, "[/*COMMENT*/ \"hello\"]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CCommentBeforeClosingBracket") {
    bool result = parseJson(arr, "[\"hello\"/*COMMENT*/]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CCommentAfterClosingBracket") {
    bool result = parseJson(arr, "[\"hello\"]/*COMMENT*/");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CCommentBeforeComma") {
    bool result = parseJson(arr, "[\"hello\"/*COMMENT*/,\"world\"]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("CCommentAfterComma") {
    bool result = parseJson(arr, "[\"hello\",/*COMMENT*/ \"world\"]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("CppCommentBeforeOpeningBracket") {
    bool result = parseJson(arr, "//COMMENT\n\t[\"hello\"]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CppCommentAfterOpeningBracket") {
    bool result = parseJson(arr, "[//COMMENT\n\"hello\"]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CppCommentBeforeClosingBracket") {
    bool result = parseJson(arr, "[\"hello\"//COMMENT\r\n]");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CppCommentAfterClosingBracket") {
    bool result = parseJson(arr, "[\"hello\"]//COMMENT\n");

    REQUIRE(true == result);
    REQUIRE(1 == arr.size());
    REQUIRE(arr[0] == "hello");
  }

  SECTION("CppCommentBeforeComma") {
    bool result = parseJson(arr, "[\"hello\"//COMMENT\n,\"world\"]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("CppCommentAfterComma") {
    bool result = parseJson(arr, "[\"hello\",//COMMENT\n\"world\"]");

    REQUIRE(true == result);
    REQUIRE(2 == arr.size());
    REQUIRE(arr[0] == "hello");
    REQUIRE(arr[1] == "world");
  }

  SECTION("InvalidCppComment") {
    bool result = parseJson(arr, "[/COMMENT\n]");
    REQUIRE(false == result);
  }

  SECTION("InvalidComment") {
    bool result = parseJson(arr, "[/*/\n]");
    REQUIRE(false == result);
  }

  SECTION("UnfinishedCComment") {
    bool result = parseJson(arr, "[/*COMMENT]");
    REQUIRE(false == result);
  }

  SECTION("EndsInCppComment") {
    bool result = parseJson(arr, "[//COMMENT");
    REQUIRE(false == result);
  }

  SECTION("AfterClosingStar") {
    bool result = parseJson(arr, "[/*COMMENT*");
    REQUIRE(false == result);
  }

  SECTION("DeeplyNested") {
    bool result = parseJson(
        arr, "[[[[[[[[[[[[[[[[[[[\"Not too deep\"]]]]]]]]]]]]]]]]]]]");
    REQUIRE(true == result);
  }
}
