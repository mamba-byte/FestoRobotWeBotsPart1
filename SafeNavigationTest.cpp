/**
 * @file SafeNavigationTest.cpp
 * @brief Test file for the SafeNavigation class.
 */

#include <iostream>
#include "SafeNavigation.h"
#include "FestoRobotAPI.h"

/**
 * @brief Main function to test the SafeNavigation class.
 * 
 * This function performs various tests on the SafeNavigation class:
 * - Sets up the necessary components (API, controller, IR sensor).
 * - Tests safe forward and backward movement.
 * - Tests edge cases with missing IR sensor and robot controller.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- SafeNavigation Test Start -----\n";

    // 1. Setup
    FestoRobotAPI* api = new FestoRobotAPI();
    RobotControler* ctrl = new RobotControler(api);
    IRSensor* ir = new IRSensor(api);
    SafeNavigation safeNav(ir, ctrl);

    ctrl->connectRobot();

    // 2. Attempt safe forward/backward
    safeNav.moveForwardSafe();
    safeNav.moveBackwardSafe();
    ctrl->stop();
    ctrl->disconnectRobot();

    // 3. Edge cases: 
    // - No IRSensor
    SafeNavigation safeNav2(nullptr, ctrl);
    safeNav2.moveForwardSafe();
    safeNav2.moveBackwardSafe();
    ctrl->stop();
    ctrl->disconnectRobot();

    // - No RobotControler
    SafeNavigation safeNav3(ir, nullptr);
    safeNav3.moveForwardSafe();
    safeNav3.moveBackwardSafe();
    ctrl->stop();
    ctrl->disconnectRobot();

    std::cout << "----- SafeNavigation Test Complete -----\n";
    return 0;
}