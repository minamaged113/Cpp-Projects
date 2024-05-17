cmake_minimum_required(VERSION 3.22)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -g -pg -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(
    graphics_tiny_renderer
    VERSION 1.0.0
    LANGUAGES C CXX
)

add_subdirectory(point)
add_subdirectory(line)
add_subdirectory(tgaimage)
add_subdirectory(model)

add_executable(
    graphics_tiny_renderer
    main.cpp
)

target_link_libraries(graphics_tiny_renderer
    PUBLIC
    tgaimage
    model
    line
    point
)

target_include_directories(graphics_tiny_renderer
    PUBLIC
    ${TGA_IMAGE_HEADERS}
    ${LINE_HEADERS}
    model
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/wavefront_obj DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)