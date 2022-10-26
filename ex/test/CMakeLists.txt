cmake_minimum_required(VERSION 3.9.1)

set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${PROJECT_SOURCE_DIR})

find_package(Protobuf REQUIRED)
find_package(glog REQUIRED)

add_executable(example example.cc)
target_link_libraries(example glog proto protobuf node data transport coroutine scheduler common)

add_executable(example1 example1.cc)
target_link_libraries(example1 glog proto protobuf node data transport coroutine scheduler common)
