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
struct Point {
    float x;   // x-coordinate
    float y;   // y-coordinate
    float r;   // polar radius
    float a;   // polar angle (radians)
    float __a; // polar angle (degrees)

    // Every abstract class has to have a virtual destructor (default)
    virtual ~Point() = default;
};

// CartesianPoint concrete product
struct CartesianPoint : public Point {
    /**
     * @brief Construct a new Cartesian Point object
     *
     * @param x coordinate
     * @param y coordinate
     */
    CartesianPoint(float x, float y);
};

// PolarDegreePoint concrete product
struct PolarDegreePoint : public Point {
    /**
     * @brief Construct a new Polar Degree Point object
     *
     * @param r radius
     * @param a angle in degrees
     */
    PolarDegreePoint(float r, float a);
};

// PolarRadiansPoint concrete product
struct PolarRadiansPoint : public Point {
    /**
     * @brief Construct a new Polar Radians Point object
     *
     * @param r radius
     * @param a angle in radians
     */
    PolarRadiansPoint(float r, float a);
};

// Point abstract factory
struct PointFactory {
    virtual std::unique_ptr<Point> createPoint(float u, float v) const = 0;

    // Every abstract class has to have a virtual destructor
    virtual ~PointFactory() = default;
};

// CartesianPoint concrete factory
struct CartesianPointFactory : public PointFactory {
    /**
     * @brief Create a Point object
     *
     * @param x coordinate
     * @param y coordinate
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point> createPoint(float x, float y) const override;
};

// PolarRadiansPoint concrete factory
struct PolarRadiansPointFactory : public PointFactory {
    /**
     * @brief Create a Point object
     *
     * @param r radius
     * @param a angle in radians
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point> createPoint(float r, float a) const override;
};

// PolarDegreePointFactory concrete factory
struct PolarDegreePointFactory : public PointFactory {
    /**
     * @brief Create a Point object
     *
     * @param r radius
     * @param a angle in degrees
     * @return std::unique_ptr<Point>
     */
    std::unique_ptr<Point> createPoint(float r, float a) const override;
};

#endif // __POINT_H__
