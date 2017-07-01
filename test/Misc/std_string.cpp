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

  SECTION("parseJson(JsonObject&, std::string)") {
    DynamicJsonObject object;
    std::string json("{\"hello\":\"world\"}");
    REQUIRE(parseJson(object, json));
    eraseString(json);
    REQUIRE(std::string("world") == object["hello"]);
  }

  SECTION("parseJson(JsonArray&, std::string)") {
    DynamicJsonArray array;
    std::string json("[\"hello\"]");
    REQUIRE(parseJson(array, json));
    eraseString(json);
    REQUIRE(std::string("hello") == array[0]);
  }

  SECTION("JsonObject") {
    DynamicJsonObject object;

    SECTION("operator[](std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") == object[std::string("key")]);
    }

    SECTION("operator[](std::string) const") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      const JsonObject &obj = object;
      REQUIRE(std::string("value") == obj[std::string("key")]);
    }

    SECTION("set(std::string, const char*)") {
      std::string key("hello");
      object.set(key, "world");
      eraseString(key);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("set(const char*, std::string)") {
      std::string value("world");
      object.set("hello", value);
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("set(std::string,std::string)") {
      std::string key("hello");
      std::string value("world");
      object.set(key, value);
      eraseString(key);
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("set(std::string, JsonArraySubscript&)") {
      DynamicJsonArray arr;
      arr.add("world");

      object.set(std::string("hello"), arr[0]);

      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("set(std::string, JsonObjectSubscript&)") {
      DynamicJsonObject obj;
      obj.set("x", "world");

      object.set(std::string("hello"), obj["x"]);

      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("get(std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") ==
              object.get<const char *>(std::string("key")));
    }

    SECTION("get<T>(std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(std::string("value") ==
              object.get<const char *>(std::string("key")));
    }

    SECTION("is<T>(std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(true == object.is<const char *>(std::string("key")));
    }

    SECTION("createNestedObject(std::string)") {
      std::string key = "key";
      char json[64];
      object.createNestedObject(key);
      eraseString(key);
      object.printTo(json, sizeof(json));
      REQUIRE(std::string("{\"key\":{}}") == json);
    }

    SECTION("createNestedArray(std::string)") {
      std::string key = "key";
      char json[64];
      object.createNestedArray(key);
      eraseString(key);
      object.printTo(json, sizeof(json));
      REQUIRE(std::string("{\"key\":[]}") == json);
    }

    SECTION("containsKey(std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(true == object.containsKey(std::string("key")));
    }

    SECTION("remove(std::string)") {
      char json[] = "{\"key\":\"value\"}";
      REQUIRE(parseJson(object, json));
      REQUIRE(1 == object.size());
      object.remove(std::string("key"));
      REQUIRE(0 == object.size());
    }

    SECTION("JsonObjectSubscript<std::string>::operator=(const char*)") {
      std::string key("hello");
      object[key] = "world";
      eraseString(key);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("JsonObjectSubscript<const char*>::operator=(std::string)") {
      std::string value("world");
      object["hello"] = value;
      eraseString(value);
      REQUIRE(std::string("world") == object["hello"]);
    }

    SECTION("printTo(std::string)") {
      object["key"] = "value";
      std::string json;
      object.printTo(json);
      REQUIRE(std::string("{\"key\":\"value\"}") == json);
    }

    SECTION("prettyPrintTo(std::string)") {
      object["key"] = "value";
      std::string json;
      object.prettyPrintTo(json);
      REQUIRE(std::string("{\r\n  \"key\": \"value\"\r\n}") == json);
    }

    SECTION("buffer grows when adding new keys") {
      std::string key1("hello"), key2("world");

      object[key1] = 1;
      size_t sizeBefore = object.buffer().size();
      object[key2] = 2;
      size_t sizeAfter = object.buffer().size();

      REQUIRE(sizeAfter - sizeBefore >= key2.size());
    }

    SECTION("buffer doesn't grow when reusing keys") {
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

    SECTION("add(std::string)") {
      std::string value("hello");
      array.add(value);
      eraseString(value);
      REQUIRE(std::string("hello") == array[0]);
    }

    SECTION("set(int,std::string)") {
      std::string value("world");
      array.add("hello");
      array.set(0, value);
      eraseString(value);
      REQUIRE(std::string("world") == array[0]);
    }

    SECTION("JsonArraySubscript::operator=(std::string)") {
      std::string value("world");
      array.add("hello");
      array[0] = value;
      eraseString(value);
      REQUIRE(std::string("world") == array[0]);
    }

    SECTION("printTo(std::string)") {
      array.add(4);
      array.add(2);
      std::string json;
      array.printTo(json);
      REQUIRE(std::string("[4,2]") == json);
    }

    SECTION("prettyPrintTo(std::string)") {
      array.add(4);
      array.add(2);
      std::string json;
      array.prettyPrintTo(json);
      REQUIRE(std::string("[\r\n  4,\r\n  2\r\n]") == json);
    }
  }
}
