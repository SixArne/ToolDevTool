# Gather all files

set (CMAKE_CXX_STANDARD 20)

message(STATUS "include directory ${CMAKE_CURRENT_SOURCE_DIR}")

# Define library
add_library(CommonCode STATIC
    # files here
    src/OBJParser.cpp
    src/OBJParser.h
)

target_include_directories(CommonCode PUBLIC
    # self root reference
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(CommonCodeIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)