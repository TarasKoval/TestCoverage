cmake_minimum_required(VERSION 3.5.1)
project(tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules/)

include(GoogleTest)

include_directories(include)

add_executable(${PROJECT_NAME} src/tests.cpp src/functions.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
