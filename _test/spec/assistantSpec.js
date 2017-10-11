describe('Assistant', function() {
  describe('ParsingProgram', function() {
    function verify(input, expectedProgram) {
      var recipe = new Recipe();
      scanJson(recipe, JSON.parse(input));
      var program = new ParsingProgram();
      program.setInput(input);
      program.setSize(recipe);
      expect(program.toString()).toEqual(expectedProgram);
    }

    it('should accept empty array', function() {
      verify('[]', 'const size_t bufferSize = JSON_ARRAY_SIZE(0);\n' +
                       'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                       'const char* json = "[]";\n\n' +
                       'JsonArray& root = jsonBuffer.parseArray(json);\n');
    });

    it('should accept empty object', function() {
      verify('{}', 'const size_t bufferSize = JSON_OBJECT_SIZE(0);\n' +
                       'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                       'const char* json = "{}";\n\n' +
                       'JsonObject& root = jsonBuffer.parseObject(json);\n');
    });

    it('should accept array with one integer', function() {
      verify('[42]', 'const size_t bufferSize = JSON_ARRAY_SIZE(1) + 10;\n' +
                         'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                         'const char* json = "[42]";\n\n' +
                         'JsonArray& root = jsonBuffer.parseArray(json);\n\n' +
                         'int root_0 = root[0]; // 42\n');
    });

    it('should accept object with one element', function() {
      verify('{"hello":"world"}',
             'const size_t bufferSize = JSON_OBJECT_SIZE(1) + 20;\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'const char* json = "{\\"hello\\":\\"world\\"}";\n\n' +
                 'JsonObject& root = jsonBuffer.parseObject(json);\n\n' +
                 'const char* hello = root["hello"]; // "world"\n');
    });

    it('should set nesing limit when above 10', function() {
      verify(
          '[[[[[[[[[[[]]]]]]]]]]]',
          'const size_t bufferSize = JSON_ARRAY_SIZE(0) + 10*JSON_ARRAY_SIZE(1);\n' +
              'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
              'const char* json = "[[[[[[[[[[[]]]]]]]]]]]";\n\n' +
              'JsonArray& root = jsonBuffer.parseArray(json, 11);\n');
    });
  });

  describe('SerializingProgram', function() {
    function verify(ouput, expectedProgram) {
      var recipe = new Recipe();
      var obj = JSON.parse(ouput);
      scanJson(recipe, obj);
      var program = new SerializingProgram();
      program.setJson(obj);
      program.setSize(recipe);
      expect(program.toString()).toEqual(expectedProgram);
    }

    it('should serialize empty array', function() {
      verify('[]', 'const size_t bufferSize = JSON_ARRAY_SIZE(0);\n' +
                       'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                       'JsonArray& root = jsonBuffer.createArray();\n\n' +
                       'root.printTo(Serial);');
    });

    it('should serialize empty object', function() {
      verify('{}', 'const size_t bufferSize = JSON_OBJECT_SIZE(0);\n' +
                       'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                       'JsonObject& root = jsonBuffer.createObject();\n\n' +
                       'root.printTo(Serial);');
    });

    it('should serialize array with one integer', function() {
      verify('[42]', 'const size_t bufferSize = JSON_ARRAY_SIZE(1);\n' +
                         'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                         'JsonArray& root = jsonBuffer.createArray();\n' +
                         'root.add(42);\n\n' +
                         'root.printTo(Serial);');
    });

    it('should serialize array with one string', function() {
      verify('["hello"]', 'const size_t bufferSize = JSON_ARRAY_SIZE(1);\n' +
                              'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                              'JsonArray& root = jsonBuffer.createArray();\n' +
                              'root.add("hello");\n\n' +
                              'root.printTo(Serial);');
    });

    it('should serialize array with one integer', function() {
      verify('{"answer":42}',
             'const size_t bufferSize = JSON_OBJECT_SIZE(1);\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'JsonObject& root = jsonBuffer.createObject();\n' +
                 'root["answer"] = 42;\n\n' +
                 'root.printTo(Serial);');
    });

    it('should serialize array with one object', function() {
      verify(
          '[{"answer":42}]',
          'const size_t bufferSize = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1);\n' +
              'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
              'JsonArray& root = jsonBuffer.createArray();\n' +
              'JsonObject& root_0 = root.createNestedObject();\n' +
              'root_0["answer"] = 42;\n\n' +
              'root.printTo(Serial);');
    });

    it('should serialize object with one array', function() {
      verify(
          '{"answers":[42]}',
          'const size_t bufferSize = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1);\n' +
              'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
              'JsonObject& root = jsonBuffer.createObject();\n' +
              'JsonArray& answers = root.createNestedArray("answers");\n' +
              'answers.add(42);\n\n' +
              'root.printTo(Serial);');
    });

    it('should serialize object with one object', function() {
      verify('{"message":{"status":"ok"}}',
             'const size_t bufferSize = 2*JSON_OBJECT_SIZE(1);\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'JsonObject& root = jsonBuffer.createObject();\n' +
                 'JsonObject& message = root.createNestedObject("message");\n' +
                 'message["status"] = "ok";\n\n' +
                 'root.printTo(Serial);');
    });

    it('should serialize array with two arrays', function() {
      verify('[[1,2],[3,4]]',
             'const size_t bufferSize = 3*JSON_ARRAY_SIZE(2);\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'JsonArray& root = jsonBuffer.createArray();\n\n' +
                 'JsonArray& root_0 = root.createNestedArray();\n' +
                 'root_0.add(1);\n' +
                 'root_0.add(2);\n\n' +
                 'JsonArray& root_1 = root.createNestedArray();\n' +
                 'root_1.add(3);\n' +
                 'root_1.add(4);\n\n' +
                 'root.printTo(Serial);');
    });

    it('should serialize 3 levels of nested objects', function() {
      verify('{"A":{"B":{"C":"D"}}}',
             'const size_t bufferSize = 3*JSON_OBJECT_SIZE(1);\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'JsonObject& root = jsonBuffer.createObject();\n\n' +
                 'JsonObject& A = root.createNestedObject("A");\n' +
                 'JsonObject& A_B = A.createNestedObject("B");\n' +
                 'A_B["C"] = "D";\n\n' +
                 'root.printTo(Serial);');
    });

    it('should serialize 3 levels of nested arrays', function() {
      verify('[[[42]]]',
             'const size_t bufferSize = 3*JSON_ARRAY_SIZE(1);\n' +
                 'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
                 'JsonArray& root = jsonBuffer.createArray();\n\n' +
                 'JsonArray& root_0 = root.createNestedArray();\n' +
                 'JsonArray& root_0_0 = root_0.createNestedArray();\n' +
                 'root_0_0.add(42);\n\n' +
                 'root.printTo(Serial);');
    });

    it('should handle names containing spaces', function() {
      verify(
          '{"hello world":[42]}',
          'const size_t bufferSize = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1);\n' +
              'DynamicJsonBuffer jsonBuffer(bufferSize);\n\n' +
              'JsonObject& root = jsonBuffer.createObject();\n' +
              'JsonArray& hello_world = root.createNestedArray("hello world");\n' +
              'hello_world.add(42);\n\n' +
              'root.printTo(Serial);');
    });
  });
});
