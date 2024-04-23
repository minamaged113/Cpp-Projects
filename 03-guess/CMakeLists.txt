CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

SET(TARGET "GuessTheNumber")

PROJECT(
    ${TARGET}
    VERSION 1.0.0
    DESCRIPTION "Randomly generate a number unknown to the user. The user needs to guess what that number is."
    LANGUAGES C CXX
)

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

add_subdirectory(number)

add_executable(${TARGET}
    main.cpp
)

target_link_libraries(${TARGET}
    PUBLIC
    number
)