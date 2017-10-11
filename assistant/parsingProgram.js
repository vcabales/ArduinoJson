function ParsingProgram() {

  function extractValue(prg, value, member, prefix) {
    if (value instanceof Array) {
      prg.addEmptyLine();
      if (prefix && value.length > 2) {
        var arrayName = makeVariableName(prefix);
        prg.addLine("JsonArray& " + arrayName + " = " + member + ";");
        for (var i = 0; i < Math.min(4, value.length); i++) {
          extractValue(prg, value[i], arrayName + "[" + i + "]",
                       makeVariableName(prefix, i));
        }
      } else {
        for (var i = 0; i < value.length; i++) {
          extractValue(prg, value[i], member + "[" + i + "]",
                       makeVariableName(prefix, i));
        }
      }
      prg.addEmptyLine();
    } else if (value instanceof Object) {
      prg.addEmptyLine();
      if (prefix && Object.keys(value).length > 2) {
        var objName = makeVariableName(prefix);
        prg.addLine("JsonObject& " + objName + " = " + member + ";");
        for (var key in value) {
          extractValue(prg, value[key], objName + "[\"" + key + "\"]",
                       makeVariableName(prefix, sanitizeName(key)));
        }
      } else {
        for (var key in value) {
          extractValue(prg, value[key], member + "[\"" + key + "\"]",
                       makeVariableName(prefix, sanitizeName(key)));
        }
      }
      prg.addEmptyLine();
    } else {
      var type = getCppTypeFor(value);
      if (type)
        prg.addLine(type + " " + prefix + " = " + member + "; // " +
                    JSON.stringify(value));
    }
  }

  function measureNesting(obj) {
    if (obj instanceof Object === false)
      return 0;
    var innerNesting = 0;
    for (var key in obj) {
      innerNesting = Math.max(innerNesting, measureNesting(obj[key]));
    }
    return 1 + innerNesting;
  }

  this.generate = function(jsonString, sizeRecipe) {
    var prg = new ProgramWriter();
    var root = JSON.parse(jsonString);

    var sizeExpression = sizeRecipe.getExpression();
    if (sizeRecipe.getExtraBytes()) {
      sizeExpression += " + " + Math.ceil(sizeRecipe.getExtraBytes() / 9) * 10;
    }
    prg.addLine('const size_t bufferSize = ' + sizeExpression + ';');
    prg.addLine('DynamicJsonBuffer jsonBuffer(bufferSize);');
    prg.addEmptyLine();
    prg.addLine('const char* json = "' +
                JSON.stringify(root).replace(/"/g, '\\"') + '";');
    prg.addEmptyLine();
    var nesting = measureNesting(root);
    var argsToParse = "json";
    if (nesting > 10)
      argsToParse = argsToParse + ", " + nesting;
    if (root instanceof Array) {
      prg.addLine('JsonArray& root = jsonBuffer.parseArray(' + argsToParse +
                  ');');
      extractValue(prg, root, "root", "root_");
    } else if (root instanceof Object) {
      prg.addLine('JsonObject& root = jsonBuffer.parseObject(' + argsToParse +
                  ');');
      extractValue(prg, root, "root");
    } else {
      prg.addLine('JsonVariant root = jsonBuffer.parse(' + argsToParse + ');');
    }

    return prg.toString();
  }
}