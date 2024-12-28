/**
 * @file MotionMenu.h
 * @brief Declaration of the MotionMenu class.
 */

#pragma once
#include <string>
#include "Menus.h"

#ifndef MOTIONMENU_H
#define MOTIONMENU_H

/**
 * @class MotionMenu
 * @brief Manages the motion control menu for the robot.
 * 
 * This class provides options to control the robot's movements, such as moving forward, turning left, and turning right.
 */
class MotionMenu : public Menus {
private:
    std::string motionChoices = 
        "1. Move Robot\n"
        "2. Safe Move Robot\n"
        "3. Turn Left\n"
        "4. Turn Right\n"
        "5. Backward\n"
        "6. Get Info\n"
        "7. Back\n"
        "8. Quit\n"; ///< Menu choices displayed to the user

public:
    /**
     * @brief Constructs a MotionMenu object with a given Robot pointer.
     * 
     * @param robot Pointer to the Robot object.
     */
    MotionMenu(Robot* robot) : Menus(robot) {}

    /**
     * @brief Prints the available choices for the motion menu.
     * 
     * This function outputs the motion choices string to the console.
     */
    void printChoice() override;

    /**
     * @brief Runs the motion menu loop.
     * 
     * This function displays the motion menu and processes user input.
     * It allows the user to control the robot's movements, such as moving forward, turning left, and turning right.
     * 
     * @return bool Returns true if the user chooses to return to the main menu, false if the user chooses to exit the application.
     */
    bool run() override;
};

#endif // MOTIONMENU_H