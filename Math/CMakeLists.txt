cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(Math)

set(SOURCE_FILES
    source/vector3.cpp)

set(HEADER_FILES
    include/Math/vector3.hpp)

add_library(Math STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(Math PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)