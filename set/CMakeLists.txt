CMAKE_MINIMUM_REQUIRED(VERSION 3.27)
# This file set the standard configuration for the whole project

PROJECT(ArraySet)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "./prefix")

add_subdirectory(src)
add_subdirectory(tests)


