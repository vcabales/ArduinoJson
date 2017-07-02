# Copyright Benoit Blanchon 2014-2017
# MIT License
# 
# Arduino JSON library
# https://bblanchon.github.io/ArduinoJson/
# If you like this project, please add a star!

add_executable(JsonParserTests
	nested.cpp
	nestingLimit.cpp
	parseArray.cpp
	parseObject.cpp
	parseVariant.cpp
)

target_link_libraries(JsonParserTests catch)
add_test(JsonParser JsonParserTests)
