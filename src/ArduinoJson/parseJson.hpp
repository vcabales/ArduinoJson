// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
// bool parseJson(JsonArray& destination, TString json);
// TString = const std::string&, const String&
template <typename TString>
typename TypeTraits::EnableIf<!TypeTraits::IsArray<TString>::value, bool>::type
parseJson(JsonArray &destination, const TString &json,
          uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(destination.buffer(), json, nestingLimit)
      .parseArray(destination);
}
//
//  bool parseJson(JsonArray& destination, TString json);
// TString = const char*, const char[N], const FlashStringHelper*
template <typename TString>
bool parseJson(JsonArray &destination, TString *json,
               uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(destination.buffer(), json, nestingLimit)
      .parseArray(destination);
}
//
//  bool parseJson(JsonArray& destination, TString json);
// TString = std::istream&, Stream&
template <typename TString>
bool parseJson(JsonArray &destination, TString &json,
               uint8_t nestingLimit = ARDUINOJSON_DEFAULT_NESTING_LIMIT) {
  return Internals::makeParser(destination.buffer(), json, nestingLimit)
      .parseArray(destination);
}
}
