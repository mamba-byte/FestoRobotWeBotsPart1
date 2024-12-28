/**
 * @file Point.cpp
 * @brief Implementation of the Point class.
 */

#include "Point.h"
#include <cmath>

/**
 * @brief Gets the Y coordinate of the point.
 * 
 * @return double The Y coordinate.
 */
double Point::getY() const {
    return yVal;
}

/**
 * @brief Sets the X coordinate of the point.
 * 
 * @param x The new X coordinate.
 */
void Point::setX(double x) {
    xVal = x;
}

/**
 * @brief Sets the Y coordinate of the point.
 * 
 * @param y The new Y coordinate.
 */
void Point::setY(double y) {
    yVal = y;
}

/**
 * @brief Gets the coordinates of the point.
 * 
 * This function retrieves the X and Y coordinates of the point and stores them in the provided references.
 * 
 * @param x Reference to store the X coordinate.
 * @param y Reference to store the Y coordinate.
 */
void Point::getPoint(double& x, double& y) const {
    x = xVal;
    y = yVal;
}

/**
 * @brief Sets the coordinates of the point.
 * 
 * This function sets the X and Y coordinates of the point to the provided values.
 * 
 * @param x The new X coordinate.
 * @param y The new Y coordinate.
 */
void Point::setPoint(double x, double y) {
    xVal = x;
    yVal = y;
}

/**
 * @brief Finds the distance to another point.
 * 
 * This function calculates the Euclidean distance from the current point to another point.
 * 
 * @param other The other point.
 * @return double The distance to the other point.
 */
double Point::findDistanceTo(const Point& other) const {
    double dx = other.xVal - xVal;
    double dy = other.yVal - yVal;
    return std::sqrt(dx*dx + dy*dy);
}

/**
 * @brief Finds the angle to another point.
 * 
 * This function calculates the angle in radians from the current point to another point.
 * 
 * @param other The other point.
 * @return double The angle to the other point in radians.
 */
double Point::findAngleTo(const Point& other) const {
    double dx = other.xVal - xVal;
    double dy = other.yVal - yVal;
    return std::atan2(dy, dx);
}

/**
 * @brief Equality operator for points.
 * 
 * This function checks if two points are equal by comparing their X and Y coordinates.
 * 
 * @param other The other point.
 * @return bool True if the points are equal, false otherwise.
 */
bool Point::operator==(const Point& other) const {
    return (xVal == other.xVal && yVal == other.yVal);
}

/**
 * @brief Stream insertion operator for points.
 * 
 * This function inserts the point's coordinates into the output stream in the format (X, Y).
 * 
 * @param out The output stream.
 * @param point The point to be inserted into the stream.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.xVal << ", " << point.yVal << ")";
    return out;
}