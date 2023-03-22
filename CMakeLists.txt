cmake_minimum_required(VERSION 3.10)

project(ToolDevProject VERSION 1.0.0)


set(Author "Six Arne")
set(Project "Tool dev")

add_subdirectory(JUCE)
add_subdirectory(CommonCode)
add_subdirectory(GUIProject)
add_subdirectory(CLIProject)