cmake_minimum_required(VERSION 3.9.1)

file(GLOB_RECURSE CC_FILES *.cc ../ex.cc)
add_library(node SHARED ${CC_FILES})

