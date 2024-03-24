cmake_minimum_required(VERSION 3.27)
project(stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(stack ackerman)

add_subdirectory(Google_tests)
add_subdirectory(stack)
add_subdirectory(ackerman)

add_executable(main
        main.cpp)

target_link_libraries(main acker)
