/**
 * @file Point.h
 * @brief Declaration of the Point class.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

/**
 * @class Point
 * @brief Represents a point in 2D space.
 * 
 * This class provides methods to manipulate and query a point's coordinates in 2D space.
 */
class Point {
private:
    double xVal; ///< X coordinate of the point
    double yVal; ///< Y coordinate of the point

public:
    /**
     * @brief Default constructor for the Point class.
     * 
     * Initializes the point's coordinates to (0, 0).
     */
    Point();

    /**
     * @brief Parameterized constructor for the Point class.
     * 
     * Initializes the point's coordinates to the given values.
     * 
     * @param x The X coordinate.
     * @param y The Y coordinate.
     */
    Point(double x, double y);

    /**
     * @brief Gets the X coordinate of the point.
     * 
     * @return double The X coordinate.
     */
    double getX() const;

    /**
     * @brief Gets the Y coordinate of the point.
     * 
     * @return double The Y coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the X coordinate of the point.
     * 
     * @param x The new X coordinate.
     */
    void setX(double x);

    /**
     * @brief Sets the Y coordinate of the point.
     * 
     * @param y The new Y coordinate.
     */
    void setY(double y);

    /**
     * @brief Gets the coordinates of the point.
     * 
     * This function retrieves the X and Y coordinates of the point and stores them in the provided references.
     * 
     * @param x Reference to store the X coordinate.
     * @param y Reference to store the Y coordinate.
     */
    void getPoint(double& x, double& y) const;

    /**
     * @brief Sets the coordinates of the point.
     * 
     * This function sets the X and Y coordinates of the point to the provided values.
     * 
     * @param x The new X coordinate.
     * @param y The new Y coordinate.
     */
    void setPoint(double x, double y);

    /**
     * @brief Finds the distance to another point.
     * 
     * This function calculates the Euclidean distance from the current point to another point.
     * 
     * @param other The other point.
     * @return double The distance to the other point.
     */
    double findDistanceTo(const Point& other) const;

    /**
     * @brief Finds the angle to another point.
     * 
     * This function calculates the angle in radians from the current point to another point.
     * 
     * @param other The other point.
     * @return double The angle to the other point in radians.
     */
    double findAngleTo(const Point& other) const;

    /**
     * @brief Equality operator for points.
     * 
     * This function checks if two points are equal by comparing their X and Y coordinates.
     * 
     * @param other The other point.
     * @return bool True if the points are equal, false otherwise.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Stream insertion operator for points.
     * 
     * This function inserts the point's coordinates into the output stream in the format (X, Y).
     * 
     * @param out The output stream.
     * @param point The point to be inserted into the stream.
     * @return std::ostream& The output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

#endif // POINT_H