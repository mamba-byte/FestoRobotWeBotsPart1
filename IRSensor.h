/**
 * @file IRSensor.h
 * @brief Declaration of the IRSensor class.
 */

#pragma once

#include "FestoRobotAPI.h"

/**
 * @class IRSensor
 * @brief Manages the IR sensor readings from the robot.
 * 
 * This class provides methods to update and retrieve IR sensor readings from the robot.
 */
class IRSensor {
private:
    FestoRobotAPI* robotInterface; ///< Pointer to the robot interface for accessing sensor data
    double readings[9]; ///< Array to store the IR sensor readings

public:
    /**
     * @brief Default constructor for the IRSensor class.
     * 
     * Initializes the robot interface to nullptr and sets all IR sensor readings to 0.0.
     */
    IRSensor();

    /**
     * @brief Parameterized constructor for the IRSensor class.
     * 
     * Initializes the robot interface with the provided FestoRobotAPI pointer and sets all IR sensor readings to 0.0.
     * 
     * @param api Pointer to the FestoRobotAPI object.
     */
    IRSensor(FestoRobotAPI* api);

    /**
     * @brief Updates the IR sensor readings.
     * 
     * This function updates the readings array with the latest IR sensor values from the robot interface.
     * If the robot interface is not set, the function returns without updating the readings.
     */
    void update();

    /**
     * @brief Gets the IR sensor reading at the specified index.
     * 
     * This function returns the IR sensor reading at the given index.
     * If the index is out of bounds (not between 0 and 8), the function returns -1.0.
     * 
     * @param index The index of the IR sensor reading to retrieve.
     * @return double The IR sensor reading at the specified index, or -1.0 if the index is out of bounds.
     */
    double getRange(int index) const;

    /**
     * @brief Overloaded subscript operator to get the IR sensor reading at the specified index.
     * 
     * This function returns the IR sensor reading at the given index using the subscript operator.
     * 
     * @param i The index of the IR sensor reading to retrieve.
     * @return double The IR sensor reading at the specified index.
     */
    double operator[](int i) const;
};