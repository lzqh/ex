cmake_minimum_required(VERSION 3.9.1)

include_directories(transport)

file(GLOB_RECURSE CC_FILES  dispatcher/*.cc message/*.cc receiver/*.cc transmitter/*.cc)
add_library(transport SHARED ${CC_FILES})
