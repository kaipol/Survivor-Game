# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Survivor-Game-Main_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Survivor-Game-Main_autogen.dir\\ParseCache.txt"
  "Survivor-Game-Main_autogen"
  )
endif()
