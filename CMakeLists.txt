cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CppProjects)

# Enable testing
enable_testing()
# Add Google Test
find_package(GTest REQUIRED)
# Add include directories
include_directories(${GTEST_INCLUDE_DIRS})

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()

add_subdirectory(02-graphics)
add_subdirectory(03-guess)
add_subdirectory(04-timer)