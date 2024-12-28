/**
 * @file Mapper.h
 * @brief Declaration of the Mapper class.
 */

#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include <vector>
#include <string>

/**
 * @class Mapper
 * @brief Manages the mapping functionality using Lidar data.
 * 
 * This class provides methods to update a local map with Lidar data, record the map to a file, and display the map.
 */
class Mapper {
private:
    Map localMap; ///< Local map object to store the grid data
    int robotX; ///< X-coordinate of the robot's position
    int robotY; ///< Y-coordinate of the robot's position

public:
    /**
     * @brief Constructs a Mapper object with specified grid size and starting coordinates.
     * 
     * Initializes the Mapper with a local map of given dimensions and sets the robot's starting position.
     * 
     * @param gridSizeX Number of columns in the local map.
     * @param gridSizeY Number of rows in the local map.
     * @param startX Initial x-coordinate of the robot.
     * @param startY Initial y-coordinate of the robot.
     */
    Mapper(int gridSizeX, int gridSizeY, int startX = 0, int startY = 0);

    /**
     * @brief Updates the local map with Lidar data.
     * 
     * This function processes Lidar data, calculates the coordinates of detected points,
     * and inserts them into the local map.
     * 
     * @param lidarData Vector of pairs containing distance and angle readings from the Lidar sensor.
     */
    void updateMap(const std::vector<std::pair<int, int>>& lidarData);

    /**
     * @brief Records the current state of the local map to a file.
     * 
     * This function writes the grid values of the local map to a specified file.
     * 
     * @param filename The name of the file to which the map will be recorded.
     */
    void recordMap(const std::string& filename) const;

    /**
     * @brief Displays the local map.
     * 
     * This function outputs the local map to the console.
     */
    void showMap() const;
};

#endif // MAPPER_H