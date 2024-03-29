project(google_test)

add_executable(google_tests test.cpp)
target_link_libraries(google_tests gtest_main gtest)
add_test(NAME PROJECT_TEST COMMAND google_tests)