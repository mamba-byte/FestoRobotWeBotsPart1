/**
 * @file ConnectionMenu.h
 * @brief Declaration of the ConnectionMenu class.
 */

#pragma once

#include "Menus.h"

/**
 * @class ConnectionMenu
 * @brief Manages the connection menu for the robot.
 * 
 * This class provides options to connect or disconnect the robot, return to the main menu, or exit the application.
 */
class ConnectionMenu : public Menus {
private:
    std::string choices = "1. Connect Robot\n"
                          "2. Disconnect Robot\n"
                          "3. Back\n"
                          "4. Quit\n"; ///< Menu choices displayed to the user

public:
    /**
     * @brief Prints the available choices for the connection menu.
     * 
     * This function outputs the choices string to the console.
     */
    void printChoice() override;

    /**
     * @brief Runs the connection menu loop.
     * 
     * This function displays the connection menu and processes user input.
     * It allows the user to connect or disconnect the robot, return to the main menu, or exit the application.
     * 
     * @return true if the user chooses to return to the main menu, false if the user chooses to exit the application.
     */
    bool run() override;
};