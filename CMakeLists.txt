cmake_minimum_required(VERSION 3.5.1)
project(AuthenticationProgram)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules/)

include(GoogleTest)

include_directories(include)

add_executable(AuthenticationProgram src/tests.cpp src/functions.cpp)
target_link_libraries(AuthenticationProgram gtest gtest_main)
