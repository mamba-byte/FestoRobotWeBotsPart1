/**
 * @file SafeNavigation.h
 * @brief Declaration of the SafeNavigation class.
 */

#pragma once

#include "IRSensor.h"
#include "RobotControler.h"

/**
 * @enum SAFE_STATE
 * @brief Represents the navigation state of the robot.
 */
enum SAFE_STATE { 
    NAV_MOVING, ///< The robot is moving
    NAV_STOP ///< The robot is stopped
};

/**
 * @class SafeNavigation
 * @brief Manages safe navigation for the robot using IR sensors.
 * 
 * This class provides methods to move the robot forward and backward safely by checking IR sensor readings.
 */
class SafeNavigation {
private:
    IRSensor* sensorModule; ///< Pointer to the IR sensor module
    RobotControler* robotCtrl; ///< Pointer to the robot controller
    SAFE_STATE navState; ///< Current navigation state of the robot

public:
    /**
     * @brief Constructs a SafeNavigation object.
     * 
     * Initializes the SafeNavigation object with the provided sensor and robot controller.
     * 
     * @param sensor Pointer to the IRSensor object.
     * @param ctrl Pointer to the RobotControler object.
     */
    SafeNavigation(IRSensor* sensor, RobotControler* ctrl);

    /**
     * @brief Moves the robot forward safely.
     * 
     * This function checks the front IR sensor and moves the robot forward if the path is clear.
     * If an obstacle is detected within the threshold distance, the robot stops.
     */
    void moveForwardSafe();

    /**
     * @brief Moves the robot backward safely.
     * 
     * This function checks the rear IR sensor and moves the robot backward if the path is clear.
     * If an obstacle is detected within the threshold distance, the robot stops.
     */
    void moveBackwardSafe();
};