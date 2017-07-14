// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/DynamicJsonBuffer.hpp"
#include "JsonArray.hpp"

namespace ArduinoJson {

class DynamicJsonArray : public JsonArray {
  Internals::DynamicJsonBuffer _buffer;

 public:
  DynamicJsonArray() : JsonArray(&_buffer) {}

  Internals::DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
