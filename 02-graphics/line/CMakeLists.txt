cmake_minimum_required(VERSION 3.22)

set(TARGET "line")
set(LINE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include
    CACHE INTERNAL "LINE_HEADERS")

add_library(${TARGET}
    SHARED
    src/line.cpp
)

target_link_libraries(${TARGET}
    PUBLIC
    point
    tgaimage
)

target_include_directories(${TARGET}
    PUBLIC
    ${POINT_HEADERS}
    ${LINE_HEADERS}
    ${TGA_IMAGE_HEADERS}
)

#### Gtest
# Add test executable
add_executable(${TARGET}_test
    test/line.cpp
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