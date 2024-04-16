cmake_minimum_required(VERSION 3.22)

set(LINE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include
    CACHE INTERNAL "LINE_HEADERS")

add_library(line
    SHARED
    line.cpp
)

target_link_libraries(line
    PUBLIC
    tgaimage
)

target_include_directories(line
    PUBLIC
    ${LINE_HEADERS}
    ${TGA_IMAGE_HEADERS}
)