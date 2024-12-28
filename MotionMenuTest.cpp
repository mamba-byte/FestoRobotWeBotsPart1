/**
 * @file MotionMenuTest.cpp
 * @brief Test file for the MotionMenu class.
 */

#include <iostream>
#include "MotionMenu.h"
#include "Robot.h"

/**
 * @brief Main function to test the MotionMenu class.
 * 
 * This function performs various tests on the MotionMenu class:
 * - Creates a Robot object and a MotionMenu object.
 * - Displays the motion menu options.
 * - Attempts to run the motion menu.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- MotionMenu Test Start -----\n";

    Robot* robotObj = new Robot();
    MotionMenu motionMenu(robotObj);

    // 1. Display the motion menu
    std::cout << "[Test] Displaying MotionMenu options:\n";
    motionMenu.printChoice();

    // 2. Attempt to run the menu (again, runs in a loop reading std::cin).
    //    For thorough testing, you'd feed simulated input or refactor for test injection.
    bool result = motionMenu.run();
    std::cout << "[Test] motionMenu.run() => " << (result ? "Continue" : "Exit") << "\n";

    delete robotObj;
    std::cout << "----- MotionMenu Test Complete -----\n";
    return 0;
}