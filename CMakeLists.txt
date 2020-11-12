cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(raytrace)
include_directories(include)
aux_source_directory(src SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SRC_LIST} )