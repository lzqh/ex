cmake_minimum_required(VERSION 3.9.1)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB_RECURSE CC_FILES *.cc policy/*.cc)

add_library(scheduler SHARED ${CC_FILES})
target_link_libraries(scheduler pthread)

