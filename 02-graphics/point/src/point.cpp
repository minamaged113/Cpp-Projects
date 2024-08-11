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
template struct PointFactory<int>;
template struct PointFactory<float>;
template struct CartesianPointFactory<int>;
template struct CartesianPointFactory<float>;
template struct PolarRadiansPointFactory<float>;
template struct PolarDegreePointFactory<float>;

template <typename T> CartesianPoint<T>::CartesianPoint(T x, T y) {
    this->x = x;
    this->y = y;
    this->r = (T)sqrt((double)(x * x + y * y));
    this->a = (T)atan((double)(y / x)); // angle in radians
}

template <typename T> PolarDegreePoint<T>::PolarDegreePoint(T r, T a) {
    this->r = r;
    this->a = a * (M_PI / 180);
    this->__a = a;
    this->x = r * cos(this->a);
    this->y = r * sin(this->a);
}

template <typename T> PolarRadiansPoint<T>::PolarRadiansPoint(T r, T a) {
    this->r = r;
    this->a = a;
    this->__a = a * (180 / M_PI);
    this->x = r * cos(this->a);
    this->y = r * sin(this->a);
}

template <typename T>
std::unique_ptr<Point<T>> CartesianPointFactory<T>::createPoint(T x,
                                                                T y) const {
    return std::unique_ptr<Point<T>>(new CartesianPoint<T>(x, y));
}

template <typename T>
std::unique_ptr<Point<T>> PolarRadiansPointFactory<T>::createPoint(T r,
                                                                   T a) const {
    return std::unique_ptr<Point<T>>(new PolarRadiansPoint<T>(r, a));
}

template <typename T>
std::unique_ptr<Point<T>> PolarDegreePointFactory<T>::createPoint(T r,
                                                                  T a) const {
    return std::unique_ptr<Point<T>>(new PolarDegreePoint<T>(r, a));
}