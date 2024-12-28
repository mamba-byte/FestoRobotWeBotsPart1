/**
 * @file SensorInterface.h
 * @brief Declaration of the SensorInterface class.
 */

#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

/**
 * @class SensorInterface
 * @brief Abstract base class for sensor interfaces.
 * 
 * This class provides a common interface for different types of sensors.
 */
class SensorInterface {
protected:
    std::string sensorType; ///< Type of the sensor

public:
    /**
     * @brief Constructs a SensorInterface object with the specified sensor type.
     * 
     * @param _sensorType The type of the sensor.
     */
    SensorInterface(std::string _sensorType) : sensorType(_sensorType) {}

    /**
     * @brief Virtual method to update the sensor.
     * 
     * This method should be overridden by derived classes to implement sensor-specific update logic.
     */
    virtual void updateSensor() = 0;

    /**
     * @brief Gets the type of the sensor.
     * 
     * @return std::string The type of the sensor.
     */
    std::string getSensorType() { return sensorType; }

    /**
     * @brief Virtual method to get the sensor value.
     * 
     * This method should be overridden by derived classes to return the current value of the sensor.
     * 
     * @return std::string The current value of the sensor.
     */
    virtual std::string getSensorValue() = 0;

    /**
     * @brief Virtual method to print sensor details.
     * 
     * This method should be overridden by derived classes to print the type and current value of the sensor.
     */
    virtual void print() = 0;
};

#endif // SENSORINTERFACE_H