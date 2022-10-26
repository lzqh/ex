cmake_minimum_required(VERSION 3.9.1)

include_directories(${PROJECT_SOURCE_DIR})

find_package(Protobuf REQUIRED)

file(GLOB NART_PROTOS *.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${NART_PROTOS})

add_library(proto SHARED ${PROTO_SRCS})
target_include_directories(proto 
PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC ${PROTOBUF_INCLUDE_DIRS} )




