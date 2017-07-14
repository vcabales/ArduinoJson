// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Deserialization/JsonParser.hpp"

namespace ArduinoJson {
// bool parseJson(TDestination& destination, TString json);
// TDestination = JsonArray, JsonObject, JsonVariant
// TString = const std::string&, const String&
template <typename TDestination, typename TString>
typename TypeTraits::EnableIf<!TypeTraits::IsArray<TString>::value, bool>::type
parseJson(TDestination &destination, const TString &json,
          uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(&destination.buffer(), json, nestingLimit)
      .parse(destination);
}
//
// bool parseJson(TDestination& destination, TString json);
// TDestination = JsonArray, JsonObject, JsonVariant
// TString = const char*, const char[N], const FlashStringHelper*
template <typename TDestination, typename TString>
bool parseJson(TDestination &destination, TString *json,
               uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(&destination.buffer(), json, nestingLimit)
      .parse(destination);
}
//
// bool parseJson(TDestination& destination, TString json);
// TDestination = JsonArray, JsonObject, JsonVariant
// TString = std::istream&, Stream&
template <typename TDestination, typename TString>
bool parseJson(TDestination &destination, TString &json,
               uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(&destination.buffer(), json, nestingLimit)
      .parse(destination);
}
}
