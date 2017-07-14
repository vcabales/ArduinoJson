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
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonObject() : JsonObject(&_buffer) {}
  DynamicJsonObject(size_t initalCapacity)
      : JsonObject(&_buffer), _buffer(initalCapacity) {}

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
