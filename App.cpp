/**
 * @file App.cpp
 * @brief Implementation of the App class.
 */

#include "App.h"
#include <iostream>

using namespace std;

/**
 * @brief Runs the main application loop.
 * 
 * This function verifies user credentials and then enters a loop
 * where it displays a menu and processes user choices.
 */
void App::run() 
{
    // Verify user credentials first
    if (!authManager.authenticate()) {
        return;  // Terminate if authentication fails
    }

    bool keepGoing = true;
    while (keepGoing) {
        cout << menuContent << endl;
        int userChoice;
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                keepGoing = connectionMenu->run();
                break;
            case 2:
                keepGoing = motionMenu->run();
                break;
            case 3:
                keepGoing = sensorMenu->run();
                break;
            case 4:
                cout << "\nExiting application...\n";
                keepGoing = false;
                break;
            default:
                cout << "Invalid choice! Please select 1, 2, 3, or 4.\n\n";
                break;
        }
    }
}