// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

struct NoMemoryAllocator {
  void* allocate(size_t) {
    return NULL;
  }
  void deallocate(void*) {}
};

TEST_CASE("DynamicJsonBuffer no memory") {
  DynamicJsonBufferBase<NoMemoryAllocator> _jsonBuffer;

  SECTION("FixCodeCoverage") {
    // call this function to fix code coverage
    NoMemoryAllocator().deallocate(NULL);
  }

  SECTION("startString()") {
    DynamicJsonBufferBase<NoMemoryAllocator>::String str =
        _jsonBuffer.startString();
    str.append('!');
    REQUIRE(0 == str.c_str());
  }
}
