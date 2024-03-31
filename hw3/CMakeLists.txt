CMAKE_MINIMUM_REQUIRED(VERSION 3.27)
PROJECT(hw3)

set(CMAKE_CXX_STANDARD 14)

#********* Add Google tests dependencies*************
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(google_tests testDeque.cpp testSimulator.cpp)
target_link_libraries(google_tests simulator)
target_link_libraries(google_tests gtest_main gtest)
add_test(NAME PROJECT_TEST COMMAND google_tests)
#********* Add Google tests dependencies*************


include_directories(headers utils)
add_subdirectory(headers)
add_subdirectory(utils)
add_executable(main main.cpp)
target_link_libraries(main simulator)
