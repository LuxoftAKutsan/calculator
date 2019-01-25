cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)
project(calculator)

add_subdirectory(googletest)

set(SOURCES calculator.cc calcExceptions.h OperationDivide.cc
    OperationMinus.cc OperationPlus.cc OperationMultiply.cc IOperation.h
    calculatorHelper.cc calculatorConstants.h)

add_executable(calculator_test calculator_test.cc ${SOURCES})

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)
