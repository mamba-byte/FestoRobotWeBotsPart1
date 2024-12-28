/**
 * @file Pose.cpp
 * @brief Implementation of the Pose class.
 */

#include "Pose.h"
#include <cmath>

/**
 * @brief Default constructor for the Pose class.
 * 
 * Initializes the pose with coordinates (0, 0) and orientation 0.
 */
Pose::Pose() : px(0), py(0), pth(0) {}

/**
 * @brief Parameterized constructor for the Pose class.
 * 
 * Initializes the pose with the given coordinates and orientation.
 * 
 * @param x The X coordinate.
 * @param y The Y coordinate.
 * @param th The orientation (theta).
 */
Pose::Pose(double x, double y, double th) : px(x), py(y), pth(th) {}

/**
 * @brief Gets the X coordinate of the pose.
 * 
 * @return double The X coordinate.
 */
double Pose::getX() { return px; }

/**
 * @brief Sets the X coordinate of the pose.
 * 
 * @param x The new X coordinate.
 */
void Pose::setX(double x) { px = x; }

/**
 * @brief Gets the Y coordinate of the pose.
 * 
 * @return double The Y coordinate.
 */
double Pose::getY() { return py; }

/**
 * @brief Sets the Y coordinate of the pose.
 * 
 * @param y The new Y coordinate.
 */
void Pose::setY(double y) { py = y; }

/**
 * @brief Gets the orientation (theta) of the pose.
 * 
 * @return double The orientation (theta).
 */
double Pose::getTh() { return pth; }

/**
 * @brief Sets the orientation (theta) of the pose.
 * 
 * @param th The new orientation (theta).
 */
void Pose::setTh(double th) { pth = th; }

/**
 * @brief Equality operator for poses.
 * 
 * This function checks if two poses are equal by comparing their coordinates and orientation.
 * 
 * @param other The other pose.
 * @return bool True if the poses are equal, false otherwise.
 */
bool Pose::operator==(const Pose& other) {
    return (px == other.px && py == other.py && pth == other.pth);
}

/**
 * @brief Addition operator for poses.
 * 
 * This function adds the coordinates and orientation of two poses.
 * 
 * @param other The other pose.
 * @return Pose The resulting pose after addition.
 */
Pose Pose::operator+(const Pose& other) {
    return Pose(px + other.px, py + other.py, pth + other.pth);
}

/**
 * @brief Subtraction operator for poses.
 * 
 * This function subtracts the coordinates and orientation of another pose from the current pose.
 * 
 * @param other The other pose.
 * @return Pose The resulting pose after subtraction.
 */
Pose Pose::operator-(const Pose& other) {
    return Pose(px - other.px, py - other.py, pth - other.pth);
}

/**
 * @brief Addition assignment operator for poses.
 * 
 * This function adds a value to the coordinates and orientation of the current pose.
 * 
 * @param val The value to be added.
 * @return Pose& The current pose after addition.
 */
Pose& Pose::operator+=(const double& val) {
    px += val; 
    py += val; 
    pth += val;
    return *this;
}

/**
 * @brief Subtraction assignment operator for poses.
 * 
 * This function subtracts a value from the coordinates and orientation of the current pose.
 * 
 * @param val The value to be subtracted.
 * @return Pose& The current pose after subtraction.
 */
Pose& Pose::operator-=(const double& val) {
    px -= val;
    py -= val;
    pth -= val;
    return *this;
}

/**
 * @brief Less-than operator for poses.
 * 
 * This function compares two poses based on their coordinates and orientation.
 * 
 * @param other The other pose.
 * @return bool True if the current pose is less than the other pose, false otherwise.
 */
bool Pose::operator<(const Pose& other) {
    if (px < other.px) return true;
    if (px == other.px && py < other.py) return true;
    if (px == other.px && py == other.py && pth < other.pth) return true;
    return false;
}

/**
 * @brief Gets the coordinates and orientation of the pose.
 * 
 * This function retrieves the X, Y coordinates and orientation (theta) of the pose and stores them in the provided references.
 * 
 * @param _x Reference to store the X coordinate.
 * @param _y Reference to store the Y coordinate.
 * @param _th Reference to store the orientation (theta).
 */
void Pose::getPose(double& _x, double& _y, double& _th) {
    _x = px;
    _y = py;
    _th = pth;
}

/**
 * @brief Sets the coordinates and orientation of the pose.
 * 
 * This function sets the X, Y coordinates and orientation (theta) of the pose to the provided values.
 * 
 * @param _x The new X coordinate.
 * @param _y The new Y coordinate.
 * @param _th The new orientation (theta).
 */
void Pose::setPose(double _x, double _y, double _th) {
    px = _x;
    py = _y;
    pth = _th;
}

/**
 * @brief Finds the distance to another pose.
 * 
 * This function calculates the Euclidean distance from the current pose to another pose.
 * 
 * @param pos The other pose.
 * @return double The distance to the other pose.
 */
double Pose::findDistanceTo(const Pose& pos) {
    double dx = pos.px - px;
    double dy = pos.py - py;
    return sqrt(dx*dx + dy*dy);
}

/**
 * @brief Finds the angle to another pose.
 * 
 * This function calculates the angle in radians from the current pose to another pose.
 * 
 * @param pos The other pose.
 * @return double The angle to the other pose in radians.
 */
double Pose::findAngleTo(const Pose& pos) {
    double dx = pos.px - px;
    double dy = pos.py - py;
    return atan2(dy, dx);
}