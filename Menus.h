/**
 * @file Menus.h
 * @brief Declaration of the Menus class.
 */

#pragma once

#include <string>
#include "Robot.h"

#ifndef MENUS_H
#define MENUS_H

/**
 * @class Menus
 * @brief Base class for various menu types in the application.
 * 
 * This class provides a common interface for different menus that interact with the robot.
 */
class Menus {
protected:
    std::string connectWarning = "Please connect to the robot before proceeding!"; ///< Warning message for connection status
    Robot* robot; ///< Pointer to the Robot object

public:
    /**
     * @brief Constructs a Menus object with a given Robot pointer.
     * 
     * @param _robot Pointer to the Robot object.
     */
    Menus(Robot* _robot) : robot(_robot) {}

    /**
     * @brief Virtual function to print menu choices.
     * 
     * This function should be overridden by derived classes to print specific menu choices.
     */
    virtual void printChoice() { }

    /**
     * @brief Virtual function to run the menu.
     * 
     * This function should be overridden by derived classes to implement specific menu logic.
     * 
     * @return bool Returns false by default.
     */
    virtual bool run() { return false; }
};

#endif // MENUS_H