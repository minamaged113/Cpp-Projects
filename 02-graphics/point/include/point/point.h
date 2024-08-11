/**
 * @file point.h
 * @author Mina Ghobrial (minamaged113@gmail.com)
 * @brief Point class implementation.
 * @version 0.1
 * @date 2024-04-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#if !defined(__POINT_H__)
#define __POINT_H__

#include <cmath>
#include <iostream>
#include <memory>

// Point abstract product
template<typename T>
struct Point {
    T x;   // x-coordinate
    T y;   // y-coordinate
    T r;   // polar radius
    T a;   // polar angle (radians)
    T __a; // polar angle (degrees)

    // Every abstract class has to have a virtual destructor (default)
    virtual ~Point() = default;
};

// CartesianPoint concrete product
template<typename T>
struct CartesianPoint : public Point<T> {
    /**
     * @brief Construct a new Cartesian Point object
     *
     * @param x coordinate
     * @param y coordinate
     */
    CartesianPoint(T x, T y) {
        this->x = x;
        this->y = y;
        this->r = (T)sqrt((double)(x * x + y * y));
        this->a = (T)atan((double)(y / x)); // angle in radians
    }
};

// PolarDegreePoint concrete product
template<typename T>
struct PolarDegreePoint : public Point<T> {
    /**
     * @brief Construct a new Polar Degree Point object
     *
     * @param r radius
     * @param a angle in degrees
     */
    PolarDegreePoint(T r, T a) {
        this->r = r;
        this->a = a * (M_PI / 180);
        this->__a = a;
        this->x = r * cos(this->a);
        this->y = r * sin(this->a);
    }
};

// PolarRadiansPoint concrete product
template<typename T>
struct PolarRadiansPoint : public Point<T> {
    /**
     * @brief Construct a new Polar Radians Point object
     *
     * @param r radius
     * @param a angle in radians
     */
    PolarRadiansPoint(T r, T a) {
        this->r = r;
        this->a = a;
        this->__a = a * (180 / M_PI);
        this->x = r * cos(this->a);
        this->y = r * sin(this->a);
    }
};

// Point abstract factory
template<typename T>
struct PointFactory {
    virtual std::unique_ptr<Point<T>> createPoint(T u, T v) const = 0;

    // Every abstract class has to have a virtual destructor
    virtual ~PointFactory() = default;
};

// CartesianPoint concrete factory
template<typename T>
struct CartesianPointFactory : public PointFactory<T> {
    /**
     * @brief Create a Point object
     *
     * @param x coordinate
     * @param y coordinate
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point<T>> createPoint(T x, T y) const override {
        return std::unique_ptr<Point<T>>(new CartesianPoint<T>(x, y));
    }
};

// PolarRadiansPoint concrete factory
template<typename T>
struct PolarRadiansPointFactory : public PointFactory<T> {
    /**
     * @brief Create a Point object
     *
     * @param r radius
     * @param a angle in radians
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point<T>> createPoint(T r, T a) const override {
        return std::unique_ptr<Point<T>>(new PolarRadiansPoint<T>(r, a));
    }
};

// PolarDegreePointFactory concrete factory
template<typename T>
struct PolarDegreePointFactory : public PointFactory<T> {
    /**
     * @brief Create a Point object
     *
     * @param r radius
     * @param a angle in degrees
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point<T>> createPoint(T r, T a) const override {
        return std::unique_ptr<Point<T>>(new PolarDegreePoint<T>(r, a));
    }
};

#endif // __POINT_H__
