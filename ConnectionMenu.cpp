/**
 * @file ConnectionMenu.cpp
 * @brief Implementation of the ConnectionMenu class.
 */

#include "ConnectionMenu.h"
#include <iostream>

using namespace std;

/**
 * @brief Prints the available choices for the connection menu.
 * 
 * This function outputs the choices string to the console.
 */
void ConnectionMenu::printChoice()
{
    cout << choices << endl;
}

/**
 * @brief Runs the connection menu loop.
 * 
 * This function displays the connection menu and processes user input.
 * It allows the user to connect or disconnect the robot, return to the main menu, or exit the application.
 * 
 * @return true if the user chooses to return to the main menu, false if the user chooses to exit the application.
 */
bool ConnectionMenu::run()
{
    cout << "Connection Menu\n\n";

    bool loopFlag = true;
    while (loopFlag) {
        printChoice();
        int selection;
        cin >> selection;

        switch (selection) {
            case 1:
               // Connect the robot
                if (robot->robotControler->connectRobot()) {
                    cout << "Robot connected successfully.\n\n";
                } else {
                    cout << "Failed to connect the robot.\n\n";
                }
                break;
            case 2:
                // Disconnect the robot
                if (robot->robotControler->disconnectRobot()) {
                    cout << "Robot disconnected successfully.\n\n";
                } else {
                    cout << "Failed to disconnect the robot.\n\n";
                }
                break;
            case 3:
                cout << "Returning to main menu...\n\n";
                loopFlag = false;
                break;
            case 4:
                cout << "Exiting...\n\n";
                return false;
            default:
                cout << "Invalid choice. Try again.\n\n";
                break;
        }
        return true; 
    }
    return true;
}