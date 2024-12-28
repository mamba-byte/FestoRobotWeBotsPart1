/**
 * @file MotionMenu.cpp
 * @brief Implementation of the MotionMenu class.
 */

#include "MotionMenu.h"
#include <iostream>
using namespace std;

/**
 * @brief Prints the available choices for the motion menu.
 * 
 * This function outputs the motion choices string to the console.
 */
void MotionMenu::printChoice()
{
    cout << motionChoices << endl;
}

/**
 * @brief Runs the motion menu loop.
 * 
 * This function displays the motion menu and processes user input.
 * It allows the user to control the robot's movements, such as moving forward, turning left, and turning right.
 * 
 * @return bool Returns true if the user chooses to return to the main menu, false if the user chooses to exit the application.
 */
bool MotionMenu::run() {
    cout << "Motion Menu\n";
    bool continueMenu = true;

    while (continueMenu) {
        printChoice();
        int userPick;
        cin >> userPick;

        switch (userPick) {
            case 1:
                if (robot->robotControler) {
                    // robot->robotControler->moveForward(); // for example
                } else {
                    cout << connectWarning << "\n\n";
                }
                break;
            case 2:
                if (robot->robotControler) {
                    // safe movement if implemented
                }
                break;
            case 3:
                if (robot->robotControler) {
                    // robot->robotControler->turnLeft();
                } else {
                    cout << connectWarning << "\n\n";
                }
                break;
            case 4:
                if (robot->robotControler) {
                    // robot->robotControler->turnRight();
                } else {
                    cout << connectWarning << "\n\n";
                }
                break;
            case 7:
                continueMenu = false;
                cout << "Returning to main menu...\n\n";
                break;
            case 8:
                continueMenu = false;
                cout << "Exiting...\n";
                return false;
            default:
                cout << "Please pick a valid option!\n\n";
                break;
        }
        return true;  
    }
    return true;
}