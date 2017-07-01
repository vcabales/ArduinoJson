// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

class DynamicJsonObject : public JsonObject {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonObject() : JsonObject(&_buffer) {}

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
