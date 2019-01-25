aux_source_directory(. SRC_LIST)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/CCalculatorHelper.cpp PARENT_SCOPE)

add_executable(${PROJECT_NAME} ${SRC_LIST})

