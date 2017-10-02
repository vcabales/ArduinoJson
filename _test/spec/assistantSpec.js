describe("Assistant", function() {
  var player;
  var song;

  describe("generateParser()", function() {
    function gen(json) {
      var recipe = new Recipe();
      scanJson(recipe, JSON.parse(json));
      return generateParser(json, recipe.getExpression());
    }

    it("should accept empty array", function() {
      var prog = gen("[]");

      expect(prog).toEqual(
          "const size_t bufferSize = JSON_ARRAY_SIZE(0);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"[]\";\n\n" +
          "JsonArray& root = jsonBuffer.parseArray(json);\n");
    });

    it("should accept empty object", function() {
      var prog = gen("{}");

      expect(prog).toEqual(
          "const size_t bufferSize = JSON_OBJECT_SIZE(0);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"{}\";\n\n" +
          "JsonObject& root = jsonBuffer.parseObject(json);\n");
    });

    it("should accept array with one integer", function() {
      var prog = gen("[42]");

      expect(prog).toEqual(
          "const size_t bufferSize = JSON_ARRAY_SIZE(1);\n" +
          "DynamicJsonBuffer jsonBuffer(bufferSize);\n\n" +
          "const char* json = \"[42]\";\n\n" +
          "JsonArray& root = jsonBuffer.parseArray(json);\n\n" +
          "int root_0 = root[0]; // 42\n");
    });
  });
});
