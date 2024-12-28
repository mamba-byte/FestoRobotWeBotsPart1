/**
 * @file IRSensorTest.cpp
 * @brief Test file for the IRSensor class.
 */

#include <iostream>
#include "IRSensor.h"
#include "FestoRobotAPI.h"

/**
 * @brief Main function to test the IRSensor class.
 * 
 * This function performs various tests on the IRSensor class:
 * - Tests the default constructor and update method.
 * - Tests the constructor with a FestoRobotAPI object and update method.
 * - Retrieves and prints IR sensor readings.
 * - Tests edge cases for invalid index access.
 * - Tests the overloaded subscript operator.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- IRSensor Test Start -----\n";

    // 1. Default constructor
    IRSensor sensorDefault;
    sensorDefault.update();  // With no API, should gracefully do nothing
    std::cout << "[Test] Default IRSensor constructed, update() called.\n";

    // 2. Constructor with API
    FestoRobotAPI* testApi = new FestoRobotAPI();
    IRSensor sensorWithApi(testApi);
    sensorWithApi.update();
    std::cout << "[Test] IRSensor with API update() called.\n";
    for(int i = 0; i < 9; i++) {
        double rangeVal = sensorWithApi.getRange(i);
        std::cout << " IR Sensor [" << i << "]: " << rangeVal << "\n";
    }

    // 3. Edge case: invalid index
    double outOfBoundsVal = sensorWithApi.getRange(999);
    std::cout << "[Test] Out-of-bounds getRange(999) => " << outOfBoundsVal << "\n";

    // 4. Operator[] usage
    double idx0Val = sensorWithApi[0];
    std::cout << "[Test] sensorWithApi[0] => " << idx0Val << "\n";

    delete testApi;
    std::cout << "----- IRSensor Test Complete -----\n";
    return 0;
}