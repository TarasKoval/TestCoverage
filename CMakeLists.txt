cmake_minimum_required(VERSION 3.5.1)
project(AuthenticationProgram)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build.
#This adds the following targets: gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

include_directories("${gtest_SOURCE_DIR}/include"
        "${gmock_SOURCE_DIR}/include")

# Now simply link your own targets against gtest, gmock and etc. as appropriate
add_executable(AuthenticationProgram src/tests.cpp)
target_link_libraries(AuthenticationProgram gtest gtest_main)
