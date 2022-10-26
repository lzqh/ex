cmake_minimum_required(VERSION 3.9.1)

file(GLOB_RECURSE CC_FILES *.cc)
add_library(receiver SHARED ${CC_FILES})
