// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/StaticJsonBuffer.hpp"
#include "JsonVariant.hpp"

namespace ArduinoJson {

template <size_t CAPACITY>
class StaticJsonVariant : public JsonVariant {
  Internals::StaticJsonBuffer<CAPACITY> _buffer;

 public:
  Internals::StaticJsonBufferBase& buffer() {
    return _buffer;
  }
};
}
