set (CMAKE_CXX_STANDARD 20)


add_executable(CliProject
    "src/main.cpp"
)

target_link_libraries(CliProject PUBLIC
    CommonCode
)

message(STATUS "include directory ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(CliProject PUBLIC
    # self root reference
    "${CMAKE_CURRENT_SOURCE_DIR}"

    # I do know how to do these?
    "${CommonCodeIncludeDir}"
)