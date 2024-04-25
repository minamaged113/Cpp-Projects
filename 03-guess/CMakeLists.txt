CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

SET(TARGET "GuessTheNumber")

PROJECT(
    ${TARGET}
    VERSION 1.0.0
    DESCRIPTION "Randomly generate a number unknown to the user. The user needs to guess what that number is."
    LANGUAGES C CXX
)

add_subdirectory(number)

add_executable(${TARGET}
    main.cpp
)

target_link_libraries(${TARGET}
    PUBLIC
    number
)