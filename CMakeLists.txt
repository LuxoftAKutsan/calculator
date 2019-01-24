cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)
project(calculator_polish)

add_subdirectory(googletest)

add_executable(calculator_test calculator_test.cc
                               calculator.cc
                               expression.cc
                               operation.cc
                               plus.cc
                               minus.cc
                               multiply.cc
                               divide.cc)

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)
