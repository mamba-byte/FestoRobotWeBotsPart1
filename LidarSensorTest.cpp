/**
 * @file LidarSensorTest.cpp
 * @brief Test file for the LidarSensor class.
 */

#include <iostream>
#include "LidarSensor.h"
#include "FestoRobotAPI.h"

/**
 * @brief Main function to test the LidarSensor class.
 * 
 * This function performs various tests on the LidarSensor class:
 * - Tests the constructor with a FestoRobotAPI object and update method.
 * - Retrieves and prints Lidar sensor readings.
 * - Tests edge cases for invalid index access.
 * - Retrieves and prints the minimum and maximum Lidar sensor readings and their indices.
 * - Demonstrates the getAngle method.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- LidarSensor Test Start -----\n";

    // 1. Create instance with API
    FestoRobotAPI* testApi = new FestoRobotAPI();
    LidarSensor lidar(testApi, 360); // Assuming 360 ranges for a full circle
    std::cout << "[Test] LidarSensor constructed with API.\n";

    // 2. Update and read values
    try {
        lidar.update();
        for(int i = 0; i < 10; ++i) {
            std::cout << " Lidar range [" << i << "]: " << lidar.getRange(i) << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "[Error] " << e.what() << "\n";
    }

    // 3. Edge case: out-of-bounds index
    try {
        lidar.getRange(500);
    } catch (const std::exception& e) {
        std::cout << "[Test] Out-of-bounds read: " << e.what() << "\n";
    }

    // 4. Min/Max
    int minIndex, maxIndex;
    double minVal = lidar.getMin(minIndex);
    double maxVal = lidar.getMax(maxIndex);
    std::cout << "[Test] Min range: " << minVal << " at index: " << minIndex << "\n";
    std::cout << "[Test] Max range: " << maxVal << " at index: " << maxIndex << "\n";

    // 5. getAngle demonstration
    for(int i = 0; i < 10; ++i) {
        std::cout << " Angle for i=" << i << ": " << lidar.getAngle(i) << " deg\n";
    }

    delete testApi;
    std::cout << "----- LidarSensor Test Complete -----\n";
    return 0;
}