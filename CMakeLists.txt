cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(OfflineRayTracer)

# Add these projects from most relied upon to least relied upon
add_subdirectory(Math)
add_subdirectory(Renderer)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-std=c++11)

set(SOURCE_FILES
    main.cpp)

add_executable(OfflineRayTracer ${SOURCE_FILES})

target_link_libraries(OfflineRayTracer Math)
target_link_libraries(OfflineRayTracer Renderer)

target_include_directories(OfflineRayTracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Math/include)
target_include_directories(OfflineRayTracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Renderer/include)