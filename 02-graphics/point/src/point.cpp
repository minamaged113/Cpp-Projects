/**
 * @file point.cpp
 * @author Mina Ghobrial (minamaged113@gmail.com)
 * @brief Point class implementation.
 * @version 0.1
 * @date 2024-04-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "point/point.h"

CartesianPoint::CartesianPoint(float x, float y) {
    this->x = x;
    this->y = y;
    this->r = (float)sqrt((double)(x * x + y * y));
    this->a = (float)atan((double)(y / x)); // angle in radians
}

PolarDegreePoint::PolarDegreePoint(float r, float a) {
    this->r = r;
    this->a = a * (M_PI / 180);
    this->__a = a;
    this->x = r * cos(this->a);
    this->y = r * sin(this->a);
}

PolarRadiansPoint::PolarRadiansPoint(float r, float a) {
    this->r = r;
    this->a = a;
    this->__a = a * (180 / M_PI);
    this->x = r * cos(this->a);
    this->y = r * sin(this->a);
}

std::unique_ptr<Point> CartesianPointFactory::createPoint(float x,
                                                          float y) const {
    return std::unique_ptr<Point>(new CartesianPoint(x, y));
}

std::unique_ptr<Point> PolarRadiansPointFactory::createPoint(float r,
                                                             float a) const {
    return std::unique_ptr<Point>(new PolarRadiansPoint(r, a));
}

std::unique_ptr<Point> PolarDegreePointFactory::createPoint(float r,
                                                            float a) const {
    return std::unique_ptr<Point>(new PolarDegreePoint(r, a));
}