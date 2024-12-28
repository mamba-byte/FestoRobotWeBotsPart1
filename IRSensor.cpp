/**
 * @file IRSensor.cpp
 * @brief Implementation of the IRSensor class.
 */

#include "IRSensor.h"

/**
 * @brief Default constructor for the IRSensor class.
 * 
 * Initializes the robot interface to nullptr and sets all IR sensor readings to 0.0.
 */
IRSensor::IRSensor() : robotInterface(nullptr)
{
    for (int i = 0; i < 9; ++i) {
        readings[i] = 0.0;
    }
}

/**
 * @brief Parameterized constructor for the IRSensor class.
 * 
 * Initializes the robot interface with the provided FestoRobotAPI pointer and sets all IR sensor readings to 0.0.
 * 
 * @param api Pointer to the FestoRobotAPI object.
 */
IRSensor::IRSensor(FestoRobotAPI* api) : robotInterface(api)
{
    for (int i = 0; i < 9; ++i) {
        readings[i] = 0.0;
    }
}

/**
 * @brief Updates the IR sensor readings.
 * 
 * This function updates the readings array with the latest IR sensor values from the robot interface.
 * If the robot interface is not set, the function returns without updating the readings.
 */
void IRSensor::update() {
    if (!robotInterface) return;
    for (int i = 0; i < 9; ++i) {
        readings[i] = robotInterface->getIRRange(i);
    }
}

/**
 * @brief Gets the IR sensor reading at the specified index.
 * 
 * This function returns the IR sensor reading at the given index.
 * If the index is out of bounds (not between 0 and 8), the function returns -1.0.
 * 
 * @param index The index of the IR sensor reading to retrieve.
 * @return double The IR sensor reading at the specified index, or -1.0 if the index is out of bounds.
 */
double IRSensor::getRange(int index) const {
    if (index >= 0 && index < 9) {
        return readings[index];
    }
    return -1.0;
}

/**
 * @brief Overloaded subscript operator to get the IR sensor reading at the specified index.
 * 
 * This function returns the IR sensor reading at the given index using the subscript operator.
 * 
 * @param i The index of the IR sensor reading to retrieve.
 * @return double The IR sensor reading at the specified index.
 */
double IRSensor::operator[](int i) const {
    return getRange(i);
}