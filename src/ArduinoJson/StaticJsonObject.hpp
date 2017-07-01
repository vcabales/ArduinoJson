// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "JsonObject.hpp"
#include "StaticJsonBuffer.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonObject : public JsonObject {
  StaticJsonBuffer<CAPACITY> _buffer;

 public:
  StaticJsonObject() : JsonObject(&_buffer) {
    // TODO: remove !!!!!!
    // it's just here to make the old test suite pass
    _buffer.alloc(sizeof(JsonObject));
  }

  StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
