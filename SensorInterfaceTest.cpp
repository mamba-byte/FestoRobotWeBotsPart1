/**
 * @file SensorInterfaceTest.cpp
 * @brief Test file for the SensorInterface class.
 */

#include <iostream>
#include "SensorInterface.h"

/**
 * @class MockSensor
 * @brief Mock implementation of the SensorInterface class for testing purposes.
 * 
 * This class provides a mock implementation of the SensorInterface class to test the default and overridden methods.
 */
class MockSensor : public SensorInterface {
public:
    /**
     * @brief Constructs a MockSensor object with the specified sensor type.
     * 
     * @param type The type of the sensor.
     */
    MockSensor(const std::string& type) : SensorInterface(type) {}

    /**
     * @brief Updates the sensor.
     * 
     * This function prints a message indicating that the sensor is being updated.
     */
    void updateSensor() override {
        std::cout << "[MockSensor] updateSensor() called on " << sensorType << "\n";
    }

    /**
     * @brief Gets the sensor value.
     * 
     * This function returns a mock value for the sensor.
     * 
     * @return std::string The mock value of the sensor.
     */
    std::string getSensorValue() override {
        return "Mock Value";
    }

    /**
     * @brief Prints the sensor details.
     * 
     * This function prints the type and mock value of the sensor.
     */
    void print() override {
        std::cout << "[MockSensor] Type: " << sensorType
                  << ", Value: " << getSensorValue() << "\n";
    }
};

/**
 * @brief Main function to test the SensorInterface class.
 * 
 * This function performs various tests on the SensorInterface class using the MockSensor class:
 * - Instantiates a MockSensor object.
 * - Calls the updateSensor method.
 * - Retrieves and prints the sensor value.
 * - Prints the sensor details.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- SensorInterface Test Start -----\n";

    // 1. Instantiate a derived class
    MockSensor mock("TestSensor");
    mock.updateSensor();
    std::string val = mock.getSensorValue();
    std::cout << "MockSensor getSensorValue() => " << val << "\n";
    mock.print();

    std::cout << "----- SensorInterface Test Complete -----\n";
    return 0;
}