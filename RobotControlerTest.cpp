/**
 * @file RobotControlerTest.cpp
 * @brief Test file for the RobotControler class.
 */

#include <iostream>
#include "RobotControler.h"
#include "FestoRobotAPI.h"

/**
 * @brief Main function to test the RobotControler class.
 * 
 * This function performs various tests on the RobotControler class:
 * - Tests the default constructor.
 * - Tests the constructor with an API pointer.
 * - Tests the constructor with both an API pointer and an initial pose.
 * - Tests connection, movement commands, pose retrieval, and disconnection.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- RobotControler Test Start -----\n";

    // 1. Default constructor
    {
        RobotControler defaultCtrl;
        // Just verifying no crashes on creation/destruction
        std::cout << "[Test] Default constructor done.\n";
    }

    // 2. Constructor with API pointer
    {
        FestoRobotAPI* testApi = new FestoRobotAPI();
        RobotControler apiCtrl(testApi);
        std::cout << "[Test] Single-parameter constructor done.\n";
        // Attempt to connect
        bool connectResult = apiCtrl.connectRobot();
        std::cout << "[Test] Connection result: " << connectResult << "\n";

        // Movement checks (very basic)
        apiCtrl.moveForward();
        apiCtrl.moveLeft();
        apiCtrl.stop();
        std::cout << "[Test] Basic movement commands invoked.\n";

        // Pose retrieval
        Pose currentPose = apiCtrl.getPose();
        std::cout << "[Test] Retrieved Pose => X: " << currentPose.getX()
                  << " Y: " << currentPose.getY()
                  << " Th: " << currentPose.getTh() << "\n";

        // Print the controller's status
        apiCtrl.print();

        // Disconnect
        bool disconnectResult = apiCtrl.disconnectRobot();
        std::cout << "[Test] Disconnect result: " << disconnectResult << "\n";
        delete testApi;
    }

    // 3. Constructor with both API and initial Pose
    {
        FestoRobotAPI* testApi2 = new FestoRobotAPI();
        Pose initPose(1.5, 2.5, 45.0);
        RobotControler advancedCtrl(testApi2, initPose);
        // Should automatically connect if not already connected
        advancedCtrl.moveRight();
        advancedCtrl.stop();
        Pose newPose = advancedCtrl.getPose();
        std::cout << "[Test] New pose: (" << newPose.getX() << ", " 
                  << newPose.getY() << ", " << newPose.getTh() << ")\n";
    }

    std::cout << "----- RobotControler Test Complete -----\n";
    return 0;
}