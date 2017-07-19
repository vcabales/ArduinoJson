// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/StaticJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonArray : public JsonArray {
  Internals::StaticJsonBuffer<CAPACITY - sizeof(JsonArray)> _buffer;

 public:
  StaticJsonArray() : JsonArray(&_buffer) {}

  StaticJsonArray(const StaticJsonArray<CAPACITY>& other)
      : JsonArray(&_buffer) {
    JsonArray::operator=(other);
  }

  StaticJsonArray<CAPACITY>& operator=(const StaticJsonArray<CAPACITY>& other) {
    _buffer.clear();
    JsonArray::operator=(other);
    return *this;
  }

  StaticJsonArray<CAPACITY>& operator=(const JsonArray& other) {
    _buffer.clear();
    JsonArray::operator=(other);
    return *this;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonArray);
  }

  Internals::StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
