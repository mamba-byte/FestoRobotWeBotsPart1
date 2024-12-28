/**
 * @file LidarSensor.cpp
 * @brief Implementation of the LidarSensor class.
 */

#include "LidarSensor.h"
#include <stdexcept>
#include <limits>
#undef max

/**
 * @brief Constructs a LidarSensor object.
 * 
 * Initializes the LidarSensor with a pointer to the FestoRobotAPI object and the number of ranges.
 * Allocates memory for the data array and initializes all values to 0.0.
 * 
 * @param api Pointer to the FestoRobotAPI object.
 * @param numRanges Number of ranges to be stored in the data array.
 */
LidarSensor::LidarSensor(FestoRobotAPI* api, int numRanges)
    : robotInterface(api), dataCount(numRanges)
{
    data = new double[dataCount];
    for (int i = 0; i < dataCount; i++) {
        data[i] = 0.0;
    }
}

/**
 * @brief Destructor for the LidarSensor class.
 * 
 * Deallocates the memory allocated for the data array.
 */
LidarSensor::~LidarSensor() {
    delete[] data;
}

/**
 * @brief Updates the Lidar sensor readings.
 * 
 * This function updates the data array with the latest Lidar sensor values from the robot interface.
 * If the robot interface is not set, the function throws a runtime error.
 * 
 * @throws std::runtime_error if the robot interface is not available.
 */
void LidarSensor::update() {
    if (!robotInterface) {
        throw std::runtime_error("No API available for LidarSensor.");
    }
    float tempVal = 0.0f;
    for (int i = 0; i < dataCount; ++i) {
        robotInterface->getLidarRange(&tempVal);
        data[i] = static_cast<double>(tempVal);
    }
}

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
double LidarSensor::getRange(int index) const {
    if (index < 0 || index >= dataCount) {
        throw std::out_of_range("Invalid index in LidarSensor::getRange");
    }
    return data[index];
}

/**
 * @brief Gets the minimum Lidar sensor reading and its index.
 * 
 * This function iterates through the data array to find the minimum Lidar sensor reading and its index.
 * 
 * @param index Reference to an integer where the index of the minimum reading will be stored.
 * @return double The minimum Lidar sensor reading.
 */
double LidarSensor::getMin(int& index) const {
    double minimum = std::numeric_limits<double>::infinity();
    index = -1;
    for (int i = 0; i < dataCount; i++) {
        if (data[i] < minimum) {
            minimum = data[i];
            index = i;
        }
    }
    return minimum;
}