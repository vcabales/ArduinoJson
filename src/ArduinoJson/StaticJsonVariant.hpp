// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "JsonVariant.hpp"
#include "StaticJsonBuffer.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonVariant : public JsonVariant {
  StaticJsonBuffer<CAPACITY> _buffer;

 public:
  StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
