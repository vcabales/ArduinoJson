// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

static void eraseString(std::string &str) {
  char *p = const_cast<char *>(str.c_str());
  while (*p) *p++ = '*';
}

TEST_CASE("std::string") {
  SECTION("JsonBuffer") {
    DynamicJsonBuffer jb;

    SECTION("JsonBuffer_strdup") {
      std::string original("hello");
      char *copy = jb.strdup(original);
      original[0] = 'w';
      REQUIRE(std::string("hello") == copy);
    }
  }

  SECTION("JsonObject") {
    DynamicJsonObject object;

    SECTION("JsonBuffer_ParseObject") {
      std::string json("{\"hello\":\"world\"}");
      REQUIRE(parseJson(object, json));
      eraseString(json);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_Subscript") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") == object[std::string("key")]);
    }

    SECTION("JsonObject_ConstSubscript") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") == object[std::string("key")]);
    }

    SECTION("JsonObject_SetKey") {
      std::string key("hello");
      object.set(key, "world");
      eraseString(key);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_SetValue") {
      std::string value("world");
      object.set("hello", value);
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_SetKeyValue") {
      std::string key("hello");
      std::string value("world");
      object.set(key, value);
      eraseString(key);
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_SetToArraySubscript") {
      DynamicJsonArray arr;
      arr.add("world");

      object.set(std::string("hello"), arr[0]);

      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_SetToObjectSubscript") {
      DynamicJsonObject obj;
      obj.set("x", "world");

      object.set(std::string("hello"), obj["x"]);

      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_Get") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") ==
              object.get<const char *>(std::string("key")));
    }

    SECTION("JsonObject_GetT") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") ==
              object.get<const char *>(std::string("key")));
    }

    SECTION("JsonObject_IsT") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(true == object.is<const char *>(std::string("key")));
    }

    SECTION("JsonObject_CreateNestedObject") {
      std::string key = "key";
      char json[64];
      object.createNestedObject(key);
      eraseString(key);
      object.printTo(json, sizeof(json));
      REQUIRE(std::string("{\"key\":{}}") == json);
    }

    SECTION("JsonObject_CreateNestedArray") {
      std::string key = "key";
      char json[64];
      object.createNestedArray(key);
      eraseString(key);
      object.printTo(json, sizeof(json));
      REQUIRE(std::string("{\"key\":[]}") == json);
    }

    SECTION("JsonObject_ContainsKey") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(true == object.containsKey(std::string("key")));
    }

    SECTION("JsonObject_Remove") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(1 == object.size());
      object.remove(std::string("key"));
      REQUIRE(0 == object.size());
    }

    SECTION("JsonObjectSubscript_SetKey") {
      std::string key("hello");
      object[key] = "world";
      eraseString(key);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObjectSubscript_SetValue") {
      std::string value("world");
      object["hello"] = value;
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObject_PrintTo") {
      object["key"] = "value";
      std::string json;
      object.printTo(json);
      REQUIRE(std::string("{\"key\":\"value\"}") == json);
    }

    SECTION("JsonObject_PrettyPrintTo") {
      object["key"] = "value";
      std::string json;
      object.prettyPrintTo(json);
      REQUIRE(std::string("{\r\n  \"key\": \"value\"\r\n}") == json);
    }

    SECTION("JsonBuffer_GrowWhenAddingNewKey") {
      std::string key1("hello"), key2("world");

      object[key1] = 1;
      size_t sizeBefore = object.buffer().size();
      object[key2] = 2;
      size_t sizeAfter = object.buffer().size();

      REQUIRE(sizeAfter - sizeBefore >= key2.size());
    }

    SECTION("JsonBuffer_DontGrowWhenReusingKey") {
      std::string key("hello");

      object[key] = 1;
      size_t sizeBefore = object.buffer().size();
      object[key] = 2;
      size_t sizeAfter = object.buffer().size();

      REQUIRE(sizeBefore == sizeAfter);
    }
  }

  SECTION("JsonArray") {
    DynamicJsonArray array;

    SECTION("JsonBuffer_ParseArray") {
      std::string json("[\"hello\"]");
      REQUIRE(parseJson(array, json));
      eraseString(json);
      REQUIRE(std::string("hello") == array[0]);
    }

    SECTION("JsonArray_Add") {
      std::string value("hello");
      array.add(value);
      eraseString(value);
      REQUIRE(std::string("hello") == array[0]);
    }

    SECTION("JsonArray_Set") {
      std::string value("world");
      array.add("hello");
      array.set(0, value);
      eraseString(value);
      REQUIRE(std::string("world") == array[0]);
    }

    SECTION("JsonArraySubscript") {
      std::string value("world");
      array.add("hello");
      array[0] = value;
      eraseString(value);
      REQUIRE(std::string("world") == array[0]);
    }

    SECTION("JsonArray_PrintTo") {
      array.add(4);
      array.add(2);
      std::string json;
      array.printTo(json);
      REQUIRE(std::string("[4,2]") == json);
    }

    SECTION("JsonArray_PrettyPrintTo") {
      array.add(4);
      array.add(2);
      std::string json;
      array.prettyPrintTo(json);
      REQUIRE(std::string("[\r\n  4,\r\n  2\r\n]") == json);
    }
  }
}
