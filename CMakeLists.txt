cmake_minimum_required(VERSION 3.5.1)
project(tests)

option(CodeCoverage "CodeCoverage" ON)

set(CMAKE_CXX_FLAGS "-std=c++11 ")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules/)

include(GoogleTest)

include_directories(include)

add_executable(${PROJECT_NAME} src/tests.cpp src/functions.cpp src/test2.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

if (CodeCoverage MATCHES ON)
    set(CMAKE_CXX_FLAGS "-std=c++11 -O0 -g -fprofile-arcs -ftest-coverage ")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage tests coverage)
endif ()
