cmake_minimum_required(VERSION 3.22)

set(TARGET "number")
add_library(${TARGET}
    SHARED
    src/number.cpp
)
target_include_directories(${TARGET}
    PUBLIC
    include
)

#### Gtest
# Add test executable
add_executable(${TARGET}_test
    test/number.cpp
)

# include the headers of the library to be tested
target_include_directories(${TARGET}_test
    PRIVATE
    include
)


# Link Google Test to the executable
target_link_libraries(${TARGET}_test
    PRIVATE
    ${TARGET}
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

# Add test
add_test(NAME ${TARGET}_test COMMAND ${TARGET}_test)