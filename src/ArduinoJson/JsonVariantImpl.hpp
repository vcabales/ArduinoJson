// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#pragma once

#include "Configuration.hpp"
#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "JsonVariant.hpp"
#include "Polyfills/isFloat.hpp"
#include "Polyfills/isInteger.hpp"
#include "Polyfills/parseFloat.hpp"
#include "Polyfills/parseInteger.hpp"

#include <string.h>  // for strcmp

namespace ArduinoJson {

inline JsonVariant &JsonVariant::operator=(const JsonArray &array) {
  if (!array.success()) goto fail;

  _content.asArray = new (_buffer) JsonArray(_buffer);
  if (!_content.asArray) goto fail;

  _content.asArray->operator=(array);

  _type = Internals::JSON_ARRAY;
  return *this;

fail:
  _type = Internals::JSON_UNDEFINED;
  return *this;
}

inline JsonVariant &JsonVariant::operator=(const JsonObject &object) {
  if (!object.success()) goto fail;

  _content.asObject = new (_buffer) JsonObject(_buffer);
  if (!_content.asObject) goto fail;

  _content.asObject->operator=(object);

  _type = Internals::JSON_OBJECT;
  return *this;

fail:
  _type = Internals::JSON_UNDEFINED;
  return *this;
}

template <typename T>
inline JsonVariant &JsonVariant::operator=(const JsonVariantBase<T> &variant) {
  return operator=(variant.template as<JsonVariant>());
}

inline JsonVariant &JsonVariant::operator=(const JsonVariant &variant) {
  using namespace Internals;
  if (variant.is<JsonArray>()) return operator=(variant.as<JsonArray>());
  if (variant.is<JsonObject>()) return operator=(variant.as<JsonObject>());
  if (variant.is<char *>()) {
    const char *str = variant.as<char *>();
    if (variant._buffer != _buffer && variant._buffer->owns(str)) {
      str = _buffer->strdup(str);
    }
    _type = JSON_STRING;
    _content.asString = str;
  } else {
    _content = variant._content;
    _type = variant._type;
  }
  return *this;
}

inline JsonArray &JsonVariant::variantAsArray() const {
  if (_type == Internals::JSON_ARRAY) return *_content.asArray;
  return JsonArray::invalid();
}

inline JsonObject &JsonVariant::variantAsObject() const {
  if (_type == Internals::JSON_OBJECT) return *_content.asObject;
  return JsonObject::invalid();
}

template <typename T>
inline T JsonVariant::variantAsInteger() const {
  using namespace Internals;
  switch (_type) {
    case JSON_UNDEFINED:
      return 0;
    case JSON_POSITIVE_INTEGER:
    case JSON_BOOLEAN:
      return T(_content.asInteger);
    case JSON_NEGATIVE_INTEGER:
      return T(~_content.asInteger + 1);
    case JSON_STRING:
    case JSON_UNPARSED:
      return Polyfills::parseInteger<T>(_content.asString);
    default:
      return T(_content.asFloat);
  }
}

inline const char *JsonVariant::variantAsString() const {
  using namespace Internals;
  if (_type == JSON_UNPARSED && _content.asString &&
      !strcmp("null", _content.asString))
    return NULL;
  if (_type == JSON_STRING || _type == JSON_UNPARSED) return _content.asString;
  return NULL;
}

template <typename T>
inline T JsonVariant::variantAsFloat() const {
  using namespace Internals;
  switch (_type) {
    case JSON_UNDEFINED:
      return 0;
    case JSON_POSITIVE_INTEGER:
    case JSON_BOOLEAN:
      return static_cast<T>(_content.asInteger);
    case JSON_NEGATIVE_INTEGER:
      return -static_cast<T>(_content.asInteger);
    case JSON_STRING:
    case JSON_UNPARSED:
      return Polyfills::parseFloat<T>(_content.asString);
    default:
      return static_cast<T>(_content.asFloat);
  }
}

inline bool JsonVariant::variantIsBoolean() const {
  using namespace Internals;
  if (_type == JSON_BOOLEAN) return true;

  if (_type != JSON_UNPARSED || _content.asString == NULL) return false;

  return !strcmp(_content.asString, "true") ||
         !strcmp(_content.asString, "false");
}

inline bool JsonVariant::variantIsInteger() const {
  using namespace Internals;

  return _type == JSON_POSITIVE_INTEGER || _type == JSON_NEGATIVE_INTEGER ||
         (_type == JSON_UNPARSED && Polyfills::isInteger(_content.asString));
}

inline bool JsonVariant::variantIsFloat() const {
  using namespace Internals;

  return _type == JSON_FLOAT || _type == JSON_POSITIVE_INTEGER ||
         _type == JSON_NEGATIVE_INTEGER ||
         (_type == JSON_UNPARSED && Polyfills::isFloat(_content.asString));
}

#if ARDUINOJSON_ENABLE_STD_STREAM
inline std::ostream &operator<<(std::ostream &os, const JsonVariant &source) {
  return source.printTo(os);
}
#endif

}  // namespace ArduinoJson
