cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)
project(calculator)

add_subdirectory(googletest)

add_executable(calculator_test tests.cpp calc.cpp)

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)