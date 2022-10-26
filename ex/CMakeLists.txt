cmake_minimum_required(VERSION 3.9.1)

project(ex)
add_definitions("-g -std=c++11")
message("CXX_FLAGS=${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(proto)
add_subdirectory(node)
add_subdirectory(transport)
add_subdirectory(coroutine)
add_subdirectory(scheduler)
add_subdirectory(data)
add_subdirectory(common)
add_subdirectory(test)

