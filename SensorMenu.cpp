/**
 * @file SensorMenu.cpp
 * @brief Implementation of the SensorMenu class.
 */

#include "SensorMenu.h"
#include <iostream>
using namespace std;

/**
 * @brief Prints the available choices for the sensor menu.
 * 
 * This function outputs the sensor choices string to the console.
 */
void SensorMenu::printChoice() {
    cout << sensorChoices << endl;
}

/**
 * @brief Runs the sensor menu loop.
 * 
 * This function displays the sensor menu and processes user input.
 * It allows the user to view details of IR and Lidar sensors, return to the main menu, or exit the application.
 * 
 * @return bool Returns true if the user chooses to return to the main menu, false if the user chooses to exit the application.
 */
bool SensorMenu::run() {
    cout << "Sensor Menu\n";
    bool keepRunning = true;

    while (keepRunning) {
        printChoice();
        int inputVal;
        cin >> inputVal;

        switch (inputVal) {
            case 1:
                if (robot->robotControler) {
                    // IR sensor details
                } else {
                    cout << "Connect first!\n";
                }
                break;
            case 2:
                if (robot->robotControler) {
                    // Lidar sensor details
                } else {
                    cout << "Connect first!\n";
                }
                break;
            case 3:
                keepRunning = false;
                cout << "Returning to main menu...\n\n";
                break;
            case 4:
                cout << "Exiting app...\n\n";
                return false;
            default:
                cout << "Not a valid option.\n\n";
                break;
        }
        return true;  
    }
    return true;
}