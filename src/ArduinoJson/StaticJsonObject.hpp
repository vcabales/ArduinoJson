// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/StaticJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonObject : public JsonObject {
  StaticJsonBuffer<CAPACITY - sizeof(JsonObject)> _buffer;

 public:
  StaticJsonObject() : JsonObject(&_buffer) {}

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonObject);
  }

  StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
