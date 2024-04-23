#include "number/number.h"
#include <gtest/gtest.h>

TEST(number, init_number_default_ctor) {
    Number::Number number{};
    EXPECT_EQ(number.value, 0);
    EXPECT_EQ(number.min, 0);
    EXPECT_EQ(number.max, 100);
}

TEST(number, init_number_value_ctor) {
    Number::Number number{3};
    EXPECT_EQ(number.value, 3);
    EXPECT_EQ(number.min, 0);
    EXPECT_EQ(number.max, 3);
}

TEST(number, init_number_min_max_ctor) {
    Number::Number randnum{-1,20};
    EXPECT_EQ(randnum.min, -1);
    EXPECT_EQ(randnum.max, 20);
    EXPECT_GE(randnum.value, randnum.min);
    EXPECT_GE(randnum.max, randnum.value);
}
