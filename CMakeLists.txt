cmake_minimum_required(VERSION 3.0)
project(AuthenticationProgram)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${AuthenticationProgram_SOURCE_DIR}/build)

# Check the build type and ask the user to set concrete one
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    message(WARNING "CMAKE_BUILD_TYPE is not set, forcing to RelWithDebInfo")
endif ()

# Set compiler flags
if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g3")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os")
endif ()

find_package(Qt5Widgets REQUIRED)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Source files
set(SOURCES
        main.cpp
        functions.cpp
        inputwindow.cpp
        mylineedit.cpp
        startwindow.cpp
        workwithfiles.cpp
        )


# Shared libraries
set(LIBRARIES
        Qt5::Widgets
        )

# Set target
add_executable(AuthenticationProgram ${SOURCES} ${HEADERS} ${UIC_SOURCES} ${RCC_SOURCES})

# Link with libraries
target_link_libraries(AuthenticationProgram ${LIBRARIES})
