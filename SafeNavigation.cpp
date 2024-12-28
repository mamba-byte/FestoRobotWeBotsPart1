/**
 * @file SafeNavigation.cpp
 * @brief Implementation of the SafeNavigation class.
 */

#include "SafeNavigation.h"
#include <iostream>

#define THRESHOLD_DISTANCE 0.5 ///< Threshold distance for safe navigation

/**
 * @brief Constructs a SafeNavigation object.
 * 
 * Initializes the SafeNavigation object with the provided sensor and robot controller.
 * 
 * @param sensor Pointer to the IRSensor object.
 * @param ctrl Pointer to the RobotControler object.
 */
SafeNavigation::SafeNavigation(IRSensor* sensor, RobotControler* ctrl)
    : sensorModule(sensor), robotCtrl(ctrl), navState(NAV_STOP)
{
}

/**
 * @brief Moves the robot forward safely.
 * 
 * This function checks the front IR sensor and moves the robot forward if the path is clear.
 * If an obstacle is detected within the threshold distance, the robot stops.
 */
void SafeNavigation::moveForwardSafe() {
    if (sensorModule->getRange(0) > THRESHOLD_DISTANCE) {
        robotCtrl->moveForward();
        navState = NAV_MOVING;
        std::cout << "Safe forward motion started.\n";
    } else {
        robotCtrl->stop();
        navState = NAV_STOP;
        std::cout << "Obstacle detected, halting.\n";
    }
}

/**
 * @brief Moves the robot backward safely.
 * 
 * This function checks the rear IR sensor and moves the robot backward if the path is clear.
 * If an obstacle is detected within the threshold distance, the robot stops.
 */
void SafeNavigation::moveBackwardSafe() {
    if (sensorModule->getRange(1) > THRESHOLD_DISTANCE) {
        robotCtrl->moveBackward();
        navState = NAV_MOVING;
        std::cout << "Safe backward motion.\n";
    } else {
        robotCtrl->stop();
        navState = NAV_STOP;
        std::cout << "Obstacle behind, stopping.\n";
    }
}