/**
 * @file FestoRobotAPITest.cpp
 * @brief Test file for the FestoRobotAPI class.
 */

#include <iostream>
#include "FestoRobotAPI.h"

/**
 * @brief Main function to test the FestoRobotAPI class.
 * 
 * This function creates an instance of the FestoRobotAPI class and performs various tests:
 * - Connects to the robot
 * - Moves the robot forward and stops it
 * - Checks IR sensor values
 * - Retrieves and prints the robot's pose (X, Y, Theta)
 * - Retrieves and prints Lidar sensor readings
 * - Disconnects from the robot
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- FestoRobotAPI Test Start -----\n";

    // 1. Create instance
    FestoRobotAPI robotApi;

    // 2. Connect
    robotApi.connect();
    std::cout << "[Test] Robot connected.\n";

    // 3. Movement tests
    robotApi.move(FORWARD);
    robotApi.stop();
    std::cout << "[Test] Moved forward and stopped.\n";

    // 4. Check IR values
    for(int i = 0; i < 9; i++) {
        double rangeVal = robotApi.getIRRange(i);
        std::cout << " IR[" << i << "] => " << rangeVal << "\n";
    }

    // 5. Pose
    double x, y, th;
    robotApi.getXYTh(x, y, th);
    std::cout << "[Test] Pose => X: " << x << " Y: " << y << " Th: " << th << "\n";

    // 6. Lidar
    int num = robotApi.getLidarRangeNumber();
    float* ranges = new float[num];
    robotApi.getLidarRange(ranges);
    std::cout << "[Test] Lidar readings => \n";
    for(int i = 0; i < num; i++) {
        std::cout << i << " => " << ranges[i] << "\n";
    }
    delete[] ranges;

    // 7. Disconnect
    robotApi.disconnect();
    std::cout << "[Test] Robot disconnected.\n";

    std::cout << "----- FestoRobotAPI Test Complete -----\n";

    return 0;
}