// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

class DynamicJsonArray : public JsonArray {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonArray() : JsonArray(&_buffer) {}

  DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
