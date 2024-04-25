cmake_minimum_required(VERSION 3.22)

set(TARGET "point")
add_library(${TARGET}
    src/point.cpp
)

# Specify the required C++ features
target_compile_features(${TARGET}
    PRIVATE
    cxx_std_14
)

target_include_directories(${TARGET}
    PUBLIC
    include
)

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

message(STATUS "${TARGET}: " ${TARGET}_test)
message(STATUS "${GTEST_BOTH_LIBRARIES}: " ${GTEST_BOTH_LIBRARIES})
# Link Google Test to the executable
target_link_libraries(${TARGET}_test
    PRIVATE
    ${TARGET}
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

# Add test
add_test(NAME ${TARGET}_test COMMAND ${TARGET}_test)