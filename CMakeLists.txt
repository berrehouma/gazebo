cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(MyProject)

# Specify the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add your source files
add_executable(my_executable command.cpp)

# Link your libraries
target_link_libraries(my_executable my_library)