# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/problem04_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/problem04_autogen.dir/ParseCache.txt"
  "problem04_autogen"
  )
endif()
