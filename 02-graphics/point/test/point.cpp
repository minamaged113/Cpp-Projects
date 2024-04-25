#include "point/point.h"
#include <gtest/gtest.h>

TEST(point, create_point_w_CartesianPointFactory) {
    float epsilon = 0.0001;
    std::unique_ptr<PointFactory> pointFactory(new CartesianPointFactory());
    std::unique_ptr<Point> point = pointFactory->createPoint(1., 1.);
    EXPECT_NEAR(point->x, 1.0, epsilon);
    EXPECT_NEAR(point->y, 1.0, epsilon);
    EXPECT_NEAR(point->r, 1.41421356237, epsilon);
    EXPECT_NEAR(point->a, 0.78539816339, epsilon);
}

TEST(point, create_point_w_PolarRadiansPoint) {
    float epsilon = 0.0001;
    std::unique_ptr<PointFactory> pointFactory(new PolarRadiansPointFactory());
    std::unique_ptr<Point> point = pointFactory->createPoint(1., 1.);
    EXPECT_NEAR(point->x, 0.54030230586, epsilon);
    EXPECT_NEAR(point->y, 0.8414709848, epsilon);
    EXPECT_NEAR(point->r, 1., epsilon);
    EXPECT_NEAR(point->a, 1., epsilon);
}

TEST(point, create_point_w_PolarDegreePoint) {
    float epsilon = 0.0001;
    std::unique_ptr<PointFactory> pointFactory(new PolarDegreePointFactory());
    // 30 degrees == 0.5235987756 radians
    std::unique_ptr<Point> point = pointFactory->createPoint(1., 30.);
    EXPECT_NEAR(point->x, 0.86602540378, epsilon);
    EXPECT_NEAR(point->y, 0.5, epsilon);
    EXPECT_NEAR(point->r, 1., epsilon);
    EXPECT_NEAR(point->a, 0.5235987756, epsilon);
}