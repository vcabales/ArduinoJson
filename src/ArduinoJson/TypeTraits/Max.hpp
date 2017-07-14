// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace TypeTraits {

// A meta-function that returns the highest value
template <size_t X, size_t Y, bool MaxIsX = (X > Y)>
struct Max {};

template <size_t X, size_t Y>
struct Max<X, Y, true> {
  static const size_t value = X;
};

template <size_t X, size_t Y>
struct Max<X, Y, false> {
  static const size_t value = Y;
};
}
}
