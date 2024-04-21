CMAKE_MINIMUM_REQUIRED(VERSION 3.27)
PROJECT(Tree)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(includes)
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

add_executable(google_tests testBinaryTree.cpp testHeap.cpp testSiblingTree.cpp)
target_link_libraries(google_tests
        PUBLIC
        Tree
        PRIVATE
        gtest_main
        gtest
)
add_test(NAME PROJECT_TEST COMMAND google_tests)
#********* Add Google tests dependencies*************

find_package(Boost 1.75.0 REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main
PUBLIC
Boost::boost
)
