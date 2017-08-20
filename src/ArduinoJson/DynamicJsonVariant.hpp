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
  Internals::DynamicJsonBuffer _buffer;

 public:
  DynamicJsonVariant() : JsonVariant(&_buffer) {}

  DynamicJsonVariant(const DynamicJsonVariant& other) : JsonVariant(&_buffer) {
    JsonVariant::operator=(other);
  }

  template <typename T>
  DynamicJsonVariant(const T& value) : JsonVariant(&_buffer) {
    JsonVariant::operator=(value);
  }

  template <typename T>
  DynamicJsonVariant(const T* value) : JsonVariant(&_buffer) {
    JsonVariant::operator=(value);
  }

  DynamicJsonVariant& operator=(const DynamicJsonVariant& other) {
    _buffer.clear();
    JsonVariant::operator=(other);
    return *this;
  }

  template <typename T>
  DynamicJsonVariant& operator=(const T& value) {
    _buffer.clear();
    JsonVariant::operator=(value);
    return *this;
  }

  template <typename T>
  DynamicJsonVariant& operator=(const T* value) {
    _buffer.clear();
    JsonVariant::operator=(value);
    return *this;
  }

  Internals::DynamicJsonBuffer& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonVariant);
  }
};
}
