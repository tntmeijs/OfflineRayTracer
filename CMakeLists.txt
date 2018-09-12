cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(OfflineRayTracer)

set(SOURCE_FILES
    source/Main.cpp
    source/Thirdparty/Nothings/stb_image_write.cpp)

set(HEADER_FILES
    include/Thirdparty/Nothings/stb_image_write.h)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-std=c++11)

add_executable(OfflineRayTracer ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(OfflineRayTracer PRIVATE include)