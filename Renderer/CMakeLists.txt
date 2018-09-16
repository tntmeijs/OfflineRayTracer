cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(Renderer)

set(SOURCE_FILES
    source/Thirdparty/Nothings/stb_image_write.cpp
	source/Ray.cpp)

set(HEADER_FILES
    include/Thirdparty/Nothings/stb_image_write.h
	include/Renderer/Ray.hpp)

add_library(Renderer STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Renderer Math)

target_include_directories(Renderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Renderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Math/include)