#pragma once
#include <cmath>

/**
 * @class Pose
 * @brief Represents a pose with X, Y coordinates and orientation (theta).
 */
class Pose {
private:
    double px;  ///< X coordinate
    double py;  ///< Y coordinate
    double pth; ///< Orientation (theta) in degrees

public:
    /**
     * @brief Default constructor for the Pose class.
     * 
     * Initializes the pose with coordinates (0, 0) and orientation 0.
     */
    Pose();

    /**
     * @brief Parameterized constructor for the Pose class.
     * 
     * Initializes the pose with the given coordinates and orientation.
     * 
     * @param x The X coordinate.
     * @param y The Y coordinate.
     * @param th The orientation (theta).
     */
    Pose(double x, double y, double th);

    /**
     * @brief Gets the X coordinate of the pose.
     * 
     * @return double The X coordinate.
     */
    double getX();

    /**
     * @brief Sets the X coordinate of the pose.
     * 
     * @param x The new X coordinate.
     */
    void setX(double x);

    /**
     * @brief Gets the Y coordinate of the pose.
     * 
     * @return double The Y coordinate.
     */
    double getY();

    /**
     * @brief Sets the Y coordinate of the pose.
     * 
     * @param y The new Y coordinate.
     */
    void setY(double y);

    /**
     * @brief Gets the orientation (theta) of the pose.
     * 
     * @return double The orientation (theta).
     */
    double getTh();

    /**
     * @brief Sets the orientation (theta) of the pose.
     * 
     * @param th The new orientation (theta).
     */
    void setTh(double th);

    /**
     * @brief Equality operator for poses.
     * 
     * This function checks if two poses are equal by comparing their coordinates and orientation.
     * 
     * @param other The other pose.
     * @return bool True if the poses are equal, false otherwise.
     */
    bool operator==(const Pose& other);

    /**
     * @brief Addition operator for poses.
     * 
     * This function adds the coordinates and orientation of two poses.
     * 
     * @param other The other pose.
     * @return Pose The resulting pose after addition.
     */
    Pose operator+(const Pose& other);

    /**
     * @brief Subtraction operator for poses.
     * 
     * This function subtracts the coordinates and orientation of another pose from the current pose.
     * 
     * @param other The other pose.
     * @return Pose The resulting pose after subtraction.
     */
    Pose operator-(const Pose& other);

    /**
     * @brief Addition assignment operator for poses.
     * 
     * This function adds a value to the coordinates and orientation of the current pose.
     * 
     * @param val The value to be added.
     * @return Pose& The current pose after addition.
     */
    Pose& operator+=(const double& val);

    /**
     * @brief Subtraction assignment operator for poses.
     * 
     * This function subtracts a value from the coordinates and orientation of the current pose.
     * 
     * @param val The value to be subtracted.
     * @return Pose& The current pose after subtraction.
     */
    Pose& operator-=(const double& val);

    /**
     * @brief Less-than operator for poses.
     * 
     * This function compares two poses based on their coordinates and orientation.
     * 
     * @param other The other pose.
     * @return bool True if the current pose is less than the other pose, false otherwise.
     */
    bool operator<(const Pose& other);

    /**
     * @brief Gets the coordinates and orientation of the pose.
     * 
     * This function retrieves the X, Y coordinates and orientation (theta) of the pose and stores them in the provided references.
     * 
     * @param _x Reference to store the X coordinate.
     * @param _y Reference to store the Y coordinate.
     * @param _th Reference to store the orientation (theta).
     */
    void getPose(double& _x, double& _y, double& _th);

    /**
     * @brief Sets the coordinates and orientation of the pose.
     * 
     * This function sets the X, Y coordinates and orientation (theta) of the pose to the provided values.
     * 
     * @param _x The new X coordinate.
     * @param _y The new Y coordinate.
     * @param _th The new orientation (theta).
     */
    void setPose(double _x, double _y, double _th);

    /**
     * @brief Finds the distance to another pose.
     * 
     * This function calculates the Euclidean distance from the current pose to another pose.
     * 
     * @param pos The other pose.
     * @return double The distance to the other pose.
     */
    double findDistanceTo(const Pose& pos);

    /**
     * @brief Finds the angle to another pose.
     * 
     * This function calculates the angle in radians from the current pose to another pose.
     * 
     * @param pos The other pose.
     * @return double The angle to the other pose in radians.
     */
    double findAngleTo(const Pose& pos);
};