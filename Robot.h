/**
 * @file Robot.h
 * @brief Declaration of the Robot class.
 */

#pragma once

#include "RobotControler.h"
#include "FestoRobotAPI.h"
#include "IRSensor.h"
#include "LidarSensor.h"

/**
 * @class Robot
 * @brief Represents a robot with various sensors and control mechanisms.
 * 
 * This class provides an interface to interact with the robot's API and control mechanisms.
 */
class Robot {
public:
    FestoRobotAPI* robotAPI; ///< Pointer to the robot's API interface
    RobotControler* robotControler; ///< Pointer to the robot's control mechanism

    /**
     * @brief Constructs a Robot object.
     * 
     * Initializes the Robot object by creating instances of FestoRobotAPI and RobotControler.
     */
    Robot();
};