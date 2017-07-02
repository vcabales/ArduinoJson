// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Deserialization/JsonParser.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#elif defined(__GNUC__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

namespace ArduinoJson {
template <typename TDerived>
class JsonBufferBase : public JsonBuffer {
 public:
  // Generalized version of parseArray() and parseObject(), also works for
  // integral types.
  //
  // JsonVariant parse(TString);
  // TString = const std::string&, const String&
  template <typename TString>
  typename TypeTraits::EnableIf<!TypeTraits::IsArray<TString>::value,
                                JsonVariant>::type
  parse(const TString &json,
        uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
    return Internals::makeParser(that(), json, nestingLimit).parseVariant();
  }
  //
  // JsonVariant parse(TString);
  // TString = const char*, const char[N], const FlashStringHelper*
  template <typename TString>
  JsonVariant parse(TString *json,
                    uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
    return Internals::makeParser(that(), json, nestingLimit).parseVariant();
  }
  //
  // JsonVariant parse(TString);
  // TString = std::istream&, Stream&
  template <typename TString>
  JsonVariant parse(TString &json,
                    uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
    return Internals::makeParser(that(), json, nestingLimit).parseVariant();
  }

 private:
  TDerived *that() {
    return static_cast<TDerived *>(this);
  }
};
}

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
#endif
