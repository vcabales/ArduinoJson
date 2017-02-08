(function() {
  function Recipe() {
    var arrays = [];
    var objects = [];
    var extraBytes = 0;

    this.addJsonArray = function(size) {
      if (arrays[size])
        arrays[size]++;
      else
        arrays[size] = 1;
    }

    this.addJsonObject = function(size) {
      if (objects[size])
        objects[size]++;
      else
        objects[size] = 1;
    }

    this.addString = function(size) {
      extraBytes += size;
    }

    this.getExpression = function() {
      var elements = [];
      for (var size in arrays) {
        var count = arrays[size];
        if (count > 1)
          elements.push(count + "*JSON_ARRAY_SIZE("+size+")");
        else
          elements.push("JSON_ARRAY_SIZE("+size+")");
      }
      for (var size in objects) {
        var count = objects[size];
        if (count > 1)
          elements.push(count + "*JSON_OBJECT_SIZE("+size+")");
        else
          elements.push("JSON_OBJECT_SIZE("+size+")");
      }
      return elements.join(" + ");
    }

    this.getExtraBytes = function() {
      return extraBytes;
    }

    this.computeSize = function(arch) {
      var totalBytes = 0;
      for (var size in arrays) {
        var count = arrays[size];
        totalBytes += count*(arch.array.base + size*arch.array.item);
      }
      for (var size in objects) {
        var count = objects[size];
        totalBytes += count*(arch.object.base + size*arch.object.item);
      }
      return totalBytes;
    }
  }

  function scanJson(recipe, obj) {
    if (obj instanceof Array) {
      recipe.addJsonArray(obj.length);
      for (var i = 0; i<obj.length; i++)
        scanJson(recipe, obj[i]);
    }
    else if (obj instanceof Object) {
      recipe.addJsonObject(Object.keys(obj).length);
      for (var key in obj) {
        recipe.addString(key.length + 1);
        scanJson(recipe, obj[key]);
      }
    } else if (obj === null) {
      recipe.addString(5);
    } else {
      recipe.addString(obj.toString().length + 1);
    }
  }

  function analyseInput() {
    results.style.display = 'none';
    error.style.visibility = 'hidden';
    $parserDiv.style.display = 'none';

    var parsedJson;
    try {
      parsedJson = JSON.parse(input.value);
    }
    catch (ex) {
      error.innerText = "ERROR: " + ex.message;
      error.style.visibility = 'visible';
      return;
    }

    var recipe = new Recipe();
    scanJson(recipe, parsedJson);

    var extraSize = recipe.getExtraBytes();

    $result_expr.innerText = recipe.getExpression();
    $extra_bytes.innerText = extraSize;

    for (var i=0; i<architectures.length; i++) {
      var arch = architectures[i];
      var size = recipe.computeSize(arch);
      var row = $result_table.rows[i] || $result_table.insertRow(i);
      var name_cell = row.cells[0] || row.insertCell(0);
      var size_cell = row.cells[1] || row.insertCell(1);
            name_cell.innerHTML = arch.name;
      size_cell.innerHTML = "<code>" + (size + extraSize) + "</code>";
    }
    results.style.display = 'block';

    extraSize = Math.ceil(extraSize / 9) * 10;

    $parserPre.innerText = generateParser(input.value, recipe.getExpression() + " + " + extraSize);
    $parserDiv.style.display = 'block';
  }

  input.addEventListener('input', analyseInput);

  function setJsonInput(obj) {
    input.value = JSON.stringify(obj, undefined, 2);
    analyseInput();
  }

  setJsonInput(examples.arduinoJson);

  $wundergroundAnchor.onclick = function(e) {
    setJsonInput(examples.wunderground);
    e.preventDefault();
  }

  $openweathermapAnchor.onclick = function(e) {
    setJsonInput(examples.openweathermap);
    e.preventDefault();
  }
})();
