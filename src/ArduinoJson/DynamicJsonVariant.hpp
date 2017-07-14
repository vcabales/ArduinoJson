// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Data/DynamicJsonBuffer.hpp"
#include "JsonVariant.hpp"

namespace ArduinoJson {

class DynamicJsonVariant : public JsonVariant {
  DynamicJsonBuffer _buffer;

 public:
  DynamicJsonBuffer& buffer() {
    return _buffer;
  }
};
}
