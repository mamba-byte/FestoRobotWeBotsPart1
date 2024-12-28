/**
 * @file SensorInterface.cpp
 * @brief Implementation of the SensorInterface class.
 */

#include "SensorInterface.h"
#include <iostream>

/**
 * @brief Method to update the sensor.
 * 
 * This function contains the logic to update the sensor.
 * It prints a message indicating that the sensor is being updated.
 */
void SensorInterface::updateSensor() {
    std::cout << "Updating sensor of type: " << sensorType << std::endl;
}

/**
 * @brief Method to get the sensor value.
 * 
 * This function returns the current value of the sensor.
 * It prints the sensor value and returns it as a string.
 * 
 * @return std::string The current value of the sensor.
 */
std::string SensorInterface::getSensorValue() {
    std::string value = "Sample Value"; // Replace with actual sensor value
    std::cout << "Sensor value: " << value << std::endl;
    return value;
}

/**
 * @brief Method to print sensor details.
 * 
 * This function prints the type and current value of the sensor.
 */
void SensorInterface::print() {
    std::cout << "Sensor Type: " << sensorType << std::endl;
    std::cout << "Sensor Value: " << getSensorValue() << std::endl;
}