// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "StaticJsonBuffer.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonArray : public JsonArray {
  StaticJsonBuffer<CAPACITY> _buffer;

 public:
  StaticJsonArray() : JsonArray(&_buffer) {
    // TODO: remove !!!!!!
    // it's just here to make the old test suite pass
    _buffer.alloc(sizeof(JsonArray));
  }

  StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
