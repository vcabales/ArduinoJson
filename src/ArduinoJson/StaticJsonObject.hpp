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
  Internals::StaticJsonBuffer<CAPACITY - sizeof(JsonObject)> _buffer;

 public:
  StaticJsonObject() : JsonObject(&_buffer) {}

  StaticJsonObject(const StaticJsonObject<CAPACITY>& other)
      : JsonObject(&_buffer) {
    JsonObject::operator=(other);
  }

  StaticJsonObject(const JsonObject& other) : JsonObject(&_buffer) {
    JsonObject::operator=(other);
  }

  StaticJsonObject<CAPACITY>& operator=(
      const StaticJsonObject<CAPACITY>& other) {
    _buffer.clear();
    JsonObject::operator=(other);
    return *this;
  }

  StaticJsonObject<CAPACITY>& operator=(const JsonObject& other) {
    _buffer.clear();
    JsonObject::operator=(other);
    return *this;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonObject);
  }

  Internals::StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
