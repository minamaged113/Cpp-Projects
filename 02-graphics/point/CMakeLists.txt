cmake_minimum_required(VERSION 3.22)

set(TARGET "point")
set(POINT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include
CACHE INTERNAL "POINT_HEADERS")

#### Gtest
# Add test executable
add_executable(${TARGET}_test
test/point.cpp
)

# include the headers of the library to be tested
target_include_directories(${TARGET}_test
PRIVATE
include
)

# Link Google Test to the executable
message(STATUS "TARGET: " ${TARGET})
target_link_libraries(${TARGET}_test
PRIVATE
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

# Add test
add_test(NAME ${TARGET}_test COMMAND ${TARGET}_test)