function SerializingProgram() {

  var _root, _sizeRecipe, _prg;

  function createJsonBuffer() {
    var sizeExpression = _sizeRecipe.getExpression();
    _prg.addLine('const size_t bufferSize = ' + sizeExpression + ';');
    _prg.addLine('DynamicJsonBuffer jsonBuffer(bufferSize);');
    _prg.addEmptyLine();
  }

  function addArray(parentName, arrayName, array, key) {
    if (countMembers(array) >= 2)
      _prg.addEmptyLine();
    if (parentName === undefined)
      _prg.addLine('JsonArray& root = jsonBuffer.createArray();');
    else if (key === undefined)
      _prg.addLine('JsonArray& ' + arrayName + ' = ' + parentName +
                   '.createNestedArray();');
    else
      _prg.addLine('JsonArray& ' + arrayName + ' = ' + parentName +
                   '.createNestedArray(' + JSON.stringify(key) + ');');
    for (var i = 0; i < array.length; i++)
      addArrayValue(arrayName, i, array[i]);
  }

  function addObject(parentName, objectName, object, key) {
    if (countMembers(object) >= 2)
      _prg.addEmptyLine();
    if (parentName === undefined)
      _prg.addLine('JsonObject& root = jsonBuffer.createObject();');
    else if (key === undefined)
      _prg.addLine('JsonObject& ' + objectName + ' = ' + parentName +
                   '.createNestedObject();');
    else
      _prg.addLine('JsonObject& ' + objectName + ' = ' + parentName +
                   '.createNestedObject(' + JSON.stringify(key) + ');');
    for (var key in object)
      setObjectValue(objectName, key, object[key]);
  }

  function addArrayLiteral(arrayName, value) {
    _prg.addLine(arrayName + '.add(' + JSON.stringify(value) + ');');
  }

  function addObjectLiteral(objectName, key, value) {
    _prg.addLine(objectName + '["' + key + '"] = ' + JSON.stringify(value) +
                 ';');
  }

  function addArrayValue(arrayName, index, value) {
    var valueName = arrayName + '_' + index;
    if (value instanceof Array) {
      addArray(arrayName, valueName, value);
    } else if (value instanceof Object) {
      addObject(arrayName, valueName, value);
    } else {
      addArrayLiteral(arrayName, value);
    }
  }

  function setObjectValue(objectName, key, value) {
    var valueName = objectName == 'root' ? sanitizeName(key)
                                         : objectName + '_' + sanitizeName(key);
    if (value instanceof Array) {
      addArray(objectName, valueName, value, key);
    } else if (value instanceof Object) {
      addObject(objectName, valueName, value, key);
    } else {
      addObjectLiteral(objectName, key, value);
    }
  }

  function countMembers(obj) {
    var count = 0;
    if (obj instanceof Array) {
      for (var i = 0; i < obj.length; i++)
        count += 1 + countMembers(obj[i]);
    } else if (obj instanceof Object) {
      for (var k in obj)
        count += 1 + countMembers(obj[k]);
    }
    return count;
  }

  function jumpLineIfBig(obj) {
    if (obj.length >= 2)
      _prg.addEmptyLine();
  }

  this.setJson = function(obj) { _root = obj; };

  this.setSize = function(sizeRecipe) { _sizeRecipe = sizeRecipe; };

  this.toString = function() {
    _prg = new ProgramWriter();

    createJsonBuffer();
    if (_root instanceof Array) {
      addArray(undefined, 'root', _root);
    } else if (_root instanceof Object) {
      addObject(undefined, 'root', _root);
    } else {
      _prg.addLine('JsonVariant root = ' + JSON.stringify(_root) + ';');
    }
    _prg.addEmptyLine();
    _prg.addLine('root.printTo(Serial);');

    return _prg.toString();
  }
}