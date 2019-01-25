add_subdirectory(googletest)

add_executable(calculator_test calculator_test.cc ${SOURCES})

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)
