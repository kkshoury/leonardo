cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY USE_FOLDERS On)

# set the project name
project(Leonardo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/graphics)
add_subdirectory(src/core)
add_subdirectory(src/io)

