/**
 * @file ConnectionMenuTest.cpp
 * @brief Test file for the ConnectionMenu class.
 */

#include <iostream>
#include "ConnectionMenu.h"
#include "Robot.h"

/**
 * @brief Main function to test the ConnectionMenu class.
 * 
 * This function creates an instance of the ConnectionMenu class and runs various tests.
 * It prints the available choices and simulates user input to test the menu functionality.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- ConnectionMenu Test Start -----\n";

    Robot* testRobot = new Robot();
    ConnectionMenu menu(testRobot);

    // 1. Print available choices
    std::cout << "[Test] Printing ConnectionMenu choices:\n";
    menu.printChoice();

    // 2. Test menu.run() with invalid input
    std::cout << "[Test] Running menu.run() with invalid input:\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cin.rdbuf()->in_avail();
   


    bool result = menu.run();
    std::cout << "[Test] menu.run() => " << (result ? "Continue" : "Exit") << "\n";

    delete testRobot;
    std::cout << "----- ConnectionMenu Test Complete -----\n";
    return 0;
}