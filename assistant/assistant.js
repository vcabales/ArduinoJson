function analyseInput() {
  results.style.display = 'none';
  error.style.visibility = 'hidden';
  $parserDiv.style.display = 'none';

  var parsedJson;
  try {
    parsedJson = JSON.parse($input.value);
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

  $parserPre.innerText = generateParser($input.value, recipe.getExpression() + " + " + extraSize);
  $parserDiv.style.display = 'block';
}

$input.addEventListener('input', analyseInput);

function setJsonInput(obj) {
  $input.value = JSON.stringify(obj, undefined, 2);
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