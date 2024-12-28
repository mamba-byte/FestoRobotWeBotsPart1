/**
 * @file RobotControler.h
 * @brief Declaration of the RobotControler class.
 */

#pragma once
#include <iostream>
#include "Pose.h"
#include "FestoRobotAPI.h"

/**
 * @class RobotControler
 * @brief Manages the control of the robot.
 * 
 * This class provides methods to control the robot's movements and manage its connection status.
 */
class RobotControler {
private:
    FestoRobotAPI* robotAPI; ///< Pointer to the robot's API interface
    Pose* position; ///< Pointer to the robot's current position
    bool connected; ///< Connection status of the robot

public:
    /**
     * @brief Default constructor for the RobotControler class.
     * 
     * Initializes the RobotControler object with default values.
     */
    RobotControler();

    /**
     * @brief Constructs a RobotControler object with a given API.
     * 
     * Initializes the RobotControler object with the provided FestoRobotAPI pointer.
     * 
     * @param api Pointer to the FestoRobotAPI object.
     */
    RobotControler(FestoRobotAPI* api);

    /**
     * @brief Constructs a RobotControler object with a given API and initial pose.
     * 
     * Initializes the RobotControler object with the provided FestoRobotAPI pointer and initial pose.
     * 
     * @param api Pointer to the FestoRobotAPI object.
     * @param initialPose The initial pose of the robot.
     */
    RobotControler(FestoRobotAPI* api, const Pose& initialPose);

    /**
     * @brief Destructor for the RobotControler class.
     * 
     * Cleans up the dynamically allocated position object.
     */
    ~RobotControler();

    /**
     * @brief Turns the robot left.
     * 
     * This function sends a command to the robot API to rotate the robot to the left.
     */
    void turnLeft();

    /**
     * @brief Turns the robot right.
     * 
     * This function sends a command to the robot API to rotate the robot to the right.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     * 
     * This function sends a command to the robot API to move the robot forward.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     * 
     * This function sends a command to the robot API to move the robot backward.
     */
    void moveBackward();

    /**
     * @brief Moves the robot left.
     * 
     * This function sends a command to the robot API to move the robot to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the robot right.
     * 
     * This function sends a command to the robot API to move the robot to the right.
     */
    void moveRight();

    /**
     * @brief Stops the robot.
     * 
     * This function sends a command to the robot API to stop the robot.
     */
    void stop();

    /**
     * @brief Gets the current pose of the robot.
     * 
     * This function retrieves the current X, Y coordinates and orientation (theta) of the robot from the API.
     * 
     * @return Pose The current pose of the robot.
     */
    Pose getPose();

    /**
     * @brief Prints the current status and pose of the robot.
     * 
     * This function prints the connection status and the current pose (X, Y, theta) of the robot.
     */
    void print();

    /**
     * @brief Connects to the robot.
     * 
     * This function establishes a connection to the robot using the API.
     * 
     * @return bool Returns true if the connection is successful, false otherwise.
     */
    bool connectRobot();

    /**
     * @brief Disconnects from the robot.
     * 
     * This function terminates the connection to the robot using the API.
     * 
     * @return bool Returns true if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();
};