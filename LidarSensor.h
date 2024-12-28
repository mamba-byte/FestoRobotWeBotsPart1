/**
 * @file LidarSensor.h
 * @brief Declaration of the LidarSensor class.
 */

#pragma once
#include "FestoRobotAPI.h"

/**
 * @class LidarSensor
 * @brief Manages the Lidar sensor readings from the robot.
 * 
 * This class provides methods to update and retrieve Lidar sensor readings from the robot.
 */
class LidarSensor {
private:
    double* data; ///< Array to store the Lidar sensor readings
    int dataCount; ///< Number of ranges in the data array
    FestoRobotAPI* robotInterface; ///< Pointer to the robot interface for accessing sensor data

public:
    /**
     * @brief Constructs a LidarSensor object.
     * 
     * Initializes the LidarSensor with a pointer to the FestoRobotAPI object and the number of ranges.
     * Allocates memory for the data array and initializes all values to 0.0.
     * 
     * @param api Pointer to the FestoRobotAPI object.
     * @param numRanges Number of ranges to be stored in the data array.
     */
    LidarSensor(FestoRobotAPI* api, int numRanges);

    /**
     * @brief Destructor for the LidarSensor class.
     * 
     * Deallocates the memory allocated for the data array.
     */
    ~LidarSensor();

    /**
     * @brief Updates the Lidar sensor readings.
     * 
     * This function updates the data array with the latest Lidar sensor values from the robot interface.
     * If the robot interface is not set, the function throws a runtime error.
     * 
     * @throws std::runtime_error if the robot interface is not available.
     */
    void update();

    /**
     * @brief Gets the Lidar sensor reading at the specified index.
     * 
     * This function returns the Lidar sensor reading at the given index.
     * If the index is out of bounds, the function throws an out_of_range exception.
     * 
     * @param index The index of the Lidar sensor reading to retrieve.
     * @return double The Lidar sensor reading at the specified index.
     * @throws std::out_of_range if the index is out of bounds.
     */
    double getRange(int index) const;

    /**
     * @brief Gets the minimum Lidar sensor reading and its index.
     * 
     * This function iterates through the data array to find the minimum Lidar sensor reading and its index.
     * 
     * @param index Reference to an integer where the index of the minimum reading will be stored.
     * @return double The minimum Lidar sensor reading.
     */
    double getMin(int& index) const;

    /**
     * @brief Gets the maximum Lidar sensor reading and its index.
     * 
     * This function iterates through the data array to find the maximum Lidar sensor reading and its index.
     * 
     * @param index Reference to an integer where the index of the maximum reading will be stored.
     * @return double The maximum Lidar sensor reading.
     */
    double getMax(int& index) const;

    /**
     * @brief Overloaded subscript operator to get the Lidar sensor reading at the specified index.
     * 
     * This function returns the Lidar sensor reading at the given index using the subscript operator.
     * 
     * @param i The index of the Lidar sensor reading to retrieve.
     * @return double The Lidar sensor reading at the specified index.
     */
    double operator[](int i) const;

    /**
     * @brief Gets the angle corresponding to the specified index.
     * 
     * This function returns the angle in degrees corresponding to the given index.
     * 
     * @param i The index for which to retrieve the angle.
     * @return double The angle in degrees corresponding to the specified index.
     */
    double getAngle(int i) const;
};