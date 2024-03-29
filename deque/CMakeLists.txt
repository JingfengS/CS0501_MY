CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

PROJECT(deque)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

include_directories(utils)


add_executable(main ${SOURCE_FILES})