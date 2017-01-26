function ProgramWriter() {
  var lines = [];
  var indent = 1;


  this.addLine = function(line) {
    lines.push(Array(indent).join("  ") + line);
  }

  this.addEmptyLine = function() {
    if (lines.length > 0 && lines[lines.length-1] != "")
      lines.push("");
  }

  this.indent = function() {
    indent++;
  }

  this.unindent = function() {
    indent--;
  }

  this.toString = function() {
    return lines.join("\n");
  }
}

function sanitizeName(name) {
  return name.replace(/[^a-z0-9]+/gi, "_");
}

function makeVariableName(prefix, suffix) {
  if (prefix === undefined || suffix === undefined) return prefix || suffix || "root";
  if (typeof suffix == "number") return prefix + suffix;
  return prefix + "_" + suffix;
}

function getCppTypeFor(value) {
  switch (typeof value) {
    case "string":
      return "const char*";

    case "number":
      if (value % 1 !== 0) return "float";
      else if (value < 32000 && value > -32000) return "int";
      return "long";

    case "boolean":
      return "bool";
    }
}

function extractValue(prg, value, member, prefix)
{
  if (value instanceof Array) {
    prg.addEmptyLine();
    for (var i=0; i<Math.min(4, value.length); i++) {
      extractValue(prg, value[i], member + "[" + i + "]", makeVariableName(prefix, i));
    }
    prg.addEmptyLine();
  }
  else if (value instanceof Object) {
    prg.addEmptyLine();
    if (prefix && Object.keys(value).length > 2) {
      var objName = makeVariableName(prefix);
      prg.addLine("JsonObject& "+ objName + " = " + member + ";")
      for (var key in value) {
        extractValue(prg, value[key], objName + "[\"" + key + "\"]", makeVariableName(prefix, sanitizeName(key)));
      }
    }
    else {
      for (var key in value) {
        extractValue(prg, value[key], member + "[\"" + key + "\"]", makeVariableName(prefix, sanitizeName(key)));
      }
    }
    prg.addEmptyLine();
  } else {
    var type = getCppTypeFor(value);
    if (type)
      prg.addLine(type + " " + prefix + " = " + member + "; // " + JSON.stringify(value));
  }
}

function generateParser(jsonString, expression) {
  var prg = new ProgramWriter();
  var root = JSON.parse(jsonString);

  prg.addLine('const size_t bufferSize = ' + expression + ';');
  prg.addLine('DynamicJsonBuffer jsonBuffer(bufferSize);');
  prg.addEmptyLine();
  prg.addLine('char json[] = "'+ JSON.stringify(root).replace(/"/g, '\\"') + '";');
  prg.addEmptyLine();
  if (root instanceof Array) {
    prg.addLine('JsonArray& root = jsonBuffer.parseArray(json);');
  } else if (root instanceof Object) {
    prg.addLine('JsonObject& root = jsonBuffer.parseObject(json);');
  } else {
    prg.addLine('JsonVariant root = jsonBuffer.parse(json);');
  }

  extractValue(prg, root, "root");

  return prg.toString();
}

