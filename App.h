/**
 * @file App.h
 * @brief Declaration of the App class.
 */

#ifndef APP_H
#define APP_H

#include <string>
#include "Authentication.h"
#include "ConnectionMenu.h"
#include "SensorMenu.h"
#include "MotionMenu.h"

/**
 * @class App
 * @brief The main application class that manages the overall program flow.
 */
class App {
private:
    std::string menuContent = "1. Connection\n"
                              "2. Motion\n"
                              "3. Sensor\n"
                              "4. Quit\n"; ///< Menu content displayed to the user

    Authentication authManager;            ///< Manages user verification
    ConnectionMenu* connectionMenu;        ///< Menu for connection operations
    SensorMenu* sensorMenu;                ///< Menu for sensor-related options
    MotionMenu* motionMenu;                ///< Menu for movement-related operations
    Robot* mainRobot;                      ///< Core robot object

public:
    /**
     * @brief Constructor for the App class.
     * 
     * Initializes the main robot object and the various menus.
     */
    App() : authManager() {
        mainRobot = new Robot();
        connectionMenu = new ConnectionMenu(mainRobot);
        sensorMenu = new SensorMenu(mainRobot);
        motionMenu = new MotionMenu(mainRobot);
    }

    /**
     * @brief Runs the main application loop.
     * 
     * This function verifies user credentials and then enters a loop
     * where it displays a menu and processes user choices.
     */
    void run();
};

#endif // APP_H