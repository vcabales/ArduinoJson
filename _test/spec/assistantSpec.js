describe("Assistant", function() {
  var player;
  var song;

  describe("generateParser()", function() {
    function stripHtml(html) {
      var tmp = document.createElement("DIV");
      tmp.innerHTML = html;
      return tmp.textContent || tmp.innerText || "";
    }

    function verify(input, expectedOutput) {
      var recipe = new Recipe();
      scanJson(recipe, JSON.parse(input));
      var actualOutput = stripHtml(generateParser(input, recipe.getExpression()));
      expect(actualOutput).toEqual(expectedOutput);
    }

    it("should accept empty array", function() {
      verify("[]",
          "const size_t bufferSize = JSON_ARRAY_SIZE(0);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"[]\";\n\n" +
          "JsonArray& root = jsonBuffer.parseArray(json);\n");
    });

    it("should accept empty object", function() {
      verify("{}",
          "const size_t bufferSize = JSON_OBJECT_SIZE(0);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"{}\";\n\n" +
          "JsonObject& root = jsonBuffer.parseObject(json);\n");
    });

    it("should accept array with one integer", function() {
      verify("[42]",
          "const size_t bufferSize = JSON_ARRAY_SIZE(1);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"[42]\";\n\n" +
          "JsonArray& root = jsonBuffer.parseArray(json);\n\n" +
          "int root_0 = root[0]; // 42\n");
    });

    it("should accept object with one element", function() {
      verify("{\"hello\":\"world\"}",
          "const size_t bufferSize = JSON_OBJECT_SIZE(1);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"{\\\"hello\\\":\\\"world\\\"}\";\n\n" +
          "JsonObject& root = jsonBuffer.parseObject(json);\n\n" +
          "const char* hello = root[\"hello\"]; // \"world\"\n");
    });

    it("should set nesing limit when above 10", function() {
      verify("[[[[[[[[[[[]]]]]]]]]]]",
          "const size_t bufferSize = JSON_ARRAY_SIZE(0) + 10*JSON_ARRAY_SIZE(1);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"[[[[[[[[[[[]]]]]]]]]]]\";\n\n" +
          "JsonArray& root = jsonBuffer.parseArray(json, 11);\n");
    });
  });
});
