# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appPiklemaMqttTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appPiklemaMqttTest_autogen.dir/ParseCache.txt"
  "appPiklemaMqttTest_autogen"
  )
endif()
