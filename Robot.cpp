/**
 * @file Robot.cpp
 * @brief Implementation of the Robot class.
 */

#include "Robot.h"

/**
 * @brief Constructs a Robot object.
 * 
 * Initializes the Robot object by creating instances of FestoRobotAPI and RobotControler.
 */
Robot::Robot() {
    robotAPI = new FestoRobotAPI();
    robotControler = new RobotControler(robotAPI);
}