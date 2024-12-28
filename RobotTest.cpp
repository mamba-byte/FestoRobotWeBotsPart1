/**
 * @file RobotTest.cpp
 * @brief Test file for the Robot class.
 */

#include <iostream>
#include "Robot.h"

/**
 * @brief Main function to test the Robot class.
 * 
 * This function performs various tests on the Robot class:
 * - Instantiates a Robot object.
 * - Tests the connection and disconnection of the robot's API.
 * - Tests the connection, movement, and disconnection of the robot's controller.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Robot Test Start -----\n";

    // 1. Instantiate a Robot
    Robot myRobot;
    // Access Robot’s public members
    if(myRobot.robotAPI) {
        myRobot.robotAPI->connect();
        std::cout << "[Test] Robot's API connected.\n";
        myRobot.robotAPI->disconnect();
    }

    // 2. RobotControler usage
    if(myRobot.robotControler) {
        myRobot.robotControler->connectRobot();
        myRobot.robotControler->moveForward();
        myRobot.robotControler->stop();
        myRobot.robotControler->disconnectRobot();
    }

    std::cout << "[Test] Robot tested basic scenarios.\n";
    std::cout << "----- Robot Test Complete -----\n";
    return 0;
}