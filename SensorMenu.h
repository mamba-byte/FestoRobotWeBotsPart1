/**
 * @file SensorMenu.h
 * @brief Declaration of the SensorMenu class.
 */

#pragma once

#include <string>
#include "Menus.h"
#include "SensorInterface.h"
#include "LidarSensor.h"
#include "IRSensor.h"

/**
 * @class SensorMenu
 * @brief Manages the sensor information menu for the robot.
 * 
 * This class provides options to view details of IR and Lidar sensors, return to the main menu, or exit the application.
 */
class SensorMenu : public Menus {
private:
    int placeholder1 = 0; ///< Placeholder variable 1
    int placeholder2 = 1; ///< Placeholder variable 2
    std::string sensorChoices = "1. IR Sensor Info\n"
                                "2. Lidar Sensor Info\n"
                                "3. Back\n"
                                "4. Quit\n"; ///< Menu choices displayed to the user

public:
    /**
     * @brief Constructs a SensorMenu object with a given Robot pointer.
     * 
     * @param robot Pointer to the Robot object.
     */
    SensorMenu(Robot* robot) : Menus(robot) {}

    /**
     * @brief Prints the available choices for the sensor menu.
     * 
     * This function outputs the sensor choices string to the console.
     */
    void printChoice() override;

    /**
     * @brief Runs the sensor menu loop.
     * 
     * This function displays the sensor menu and processes user input.
     * It allows the user to view details of IR and Lidar sensors, return to the main menu, or exit the application.
     * 
     * @return bool Returns true if the user chooses to return to the main menu, false if the user chooses to exit the application.
     */
    bool run() override;
};