/**
 * @file SensorMenuTest.cpp
 * @brief Test file for the SensorMenu class.
 */

#include <iostream>
#include "SensorMenu.h"
#include "Robot.h"

/**
 * @brief Main function to test the SensorMenu class.
 * 
 * This function performs various tests on the SensorMenu class:
 * - Instantiates a Robot object and a SensorMenu object.
 * - Prints the sensor menu choices.
 * - Attempts to run the sensor menu.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- SensorMenu Test Start -----\n";

    Robot* testRobot = new Robot();
    SensorMenu menu(testRobot);

    // 1. Print menu
    menu.printChoice();

    // 2. Try run() (with manual or mocked input)
    bool runResult = menu.run();
    std::cout << "[Test] SensorMenu run() => " << (runResult ? "Continue" : "Quit") << "\n";

    delete testRobot;
    std::cout << "----- SensorMenu Test Complete -----\n";
    return 0;
}