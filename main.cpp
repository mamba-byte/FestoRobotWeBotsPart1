/**
 * @file main.cpp
 * @brief Entry point for the application.
 */

#include <iostream>
#include "FestoRobotAPI.h"
#include "App.h"

/**
 * @brief Main function to start the application.
 * 
 * This function creates an instance of the App class and runs it.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    App primaryApp; ///< Instance of the App class
    primaryApp.run(); ///< Run the application
    return 0;
}