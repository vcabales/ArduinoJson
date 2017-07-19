// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/DynamicJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

class DynamicJsonObject : public JsonObject {
  Internals::DynamicJsonBuffer _buffer;

 public:
  DynamicJsonObject() : JsonObject(&_buffer) {}

  DynamicJsonObject(size_t initalCapacity)
      : JsonObject(&_buffer), _buffer(initalCapacity) {}

  DynamicJsonObject(const DynamicJsonObject& other) : JsonObject(&_buffer) {
    JsonObject::operator=(other);
  }

  DynamicJsonObject(const JsonObject& other) : JsonObject(&_buffer) {
    JsonObject::operator=(other);
  }

  DynamicJsonObject& operator=(const DynamicJsonObject& other) {
    _buffer.clear();
    JsonObject::operator=(other);
    return *this;
  }

  DynamicJsonObject& operator=(const JsonObject& other) {
    _buffer.clear();
    JsonObject::operator=(other);
    return *this;
  }

  Internals::DynamicJsonBuffer& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonObject);
  }
};
}
