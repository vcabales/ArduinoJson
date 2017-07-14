// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "JsonArray.hpp"
#include "JsonArraySubscript.hpp"
#include "JsonObject.hpp"

namespace ArduinoJson {

inline JsonArray &JsonArray::createNestedArray() {
  JsonArray *array = new (_buffer) JsonArray(_buffer);
  if (!array) return JsonArray::invalid();
  add(*array);
  return *array;
}

inline JsonObject &JsonArray::createNestedObject() {
  JsonObject *object = new (_buffer) JsonObject(_buffer);
  if (!object) return JsonObject::invalid();
  add(*object);
  return *object;
}
}
