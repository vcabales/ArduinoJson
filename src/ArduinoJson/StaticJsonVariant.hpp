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
  Internals::StaticJsonBuffer<CAPACITY - sizeof(JsonVariant)> _buffer;

 public:
  StaticJsonVariant() : JsonVariant(&_buffer) {}

  StaticJsonVariant(const StaticJsonVariant& other) : JsonVariant(&_buffer) {
    JsonVariant::operator=(other);
  }

  template <typename T>
  StaticJsonVariant(const T& value) : JsonVariant(&_buffer) {
    JsonVariant::operator=(value);
  }

  StaticJsonVariant& operator=(const StaticJsonVariant& copy) {
    _buffer.clear();
    JsonVariant::operator=(copy);
    return *this;
  }

  template <typename T>
  StaticJsonVariant& operator=(const T& value) {
    _buffer.clear();
    JsonVariant::operator=(value);
    return *this;
  }

  template <typename T>
  StaticJsonVariant& operator=(const T* value) {
    _buffer.clear();
    JsonVariant::operator=(value);
    return *this;
  }

  Internals::StaticJsonBufferBase& buffer() {
    return _buffer;
  }

  size_t memoryUsage() const {
    return _buffer.size() + sizeof(JsonVariant);
  }
};
}
