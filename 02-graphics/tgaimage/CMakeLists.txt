cmake_minimum_required(VERSION 3.22)

set(TGA_IMAGE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include
    CACHE INTERNAL "TGA_IMAGE_HEADERS")

add_library(tgaimage
    SHARED
    tgaimage.cpp
)

target_include_directories(tgaimage
    PUBLIC
    include
)