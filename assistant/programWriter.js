function ProgramWriter() {
  var lines = [];
  var indent = 1;

  this.addLine = function(line) {
    lines.push(Array(indent).join(" ") + line);
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