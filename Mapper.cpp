/**
 * @file Mapper.cpp
 * @brief Implementation of the Mapper class.
 */

#include "mapper.h"
#include <fstream>
#include <cmath>  

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
Mapper::Mapper(int gridSizeX, int gridSizeY, int startX, int startY)
    : localMap(gridSizeX, gridSizeY), robotX(startX), robotY(startY)
{
}

/**
 * @brief Updates the local map with Lidar data.
 * 
 * This function processes Lidar data, calculates the coordinates of detected points,
 * and inserts them into the local map.
 * 
 * @param lidarData Vector of pairs containing distance and angle readings from the Lidar sensor.
 */
void Mapper::updateMap(const std::vector<std::pair<int, int>>& lidarData) {
    for (auto& reading : lidarData) {
        int dist = reading.first;
        int angleDeg = reading.second;

        int xCoord = robotX + static_cast<int>(dist * cos(angleDeg * M_PI / 180.0));
        int yCoord = robotY + static_cast<int>(dist * sin(angleDeg * M_PI / 180.0));

        if (xCoord >= 0 && xCoord < localMap.getNumberX() &&
            yCoord >= 0 && yCoord < localMap.getNumberY()) 
        {
            localMap.insertPoint(Point(xCoord, yCoord));
        }
    }
}

/**
 * @brief Records the current state of the local map to a file.
 * 
 * This function writes the grid values of the local map to a specified file.
 * 
 * @param filename The name of the file to which the map will be recorded.
 */
void Mapper::recordMap(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < localMap.getNumberY(); ++i) {
            for (int j = 0; j < localMap.getNumberX(); ++j) {
                outFile << localMap.getGrid(j, i) << " ";
            }
            outFile << "\n";
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for map recording.\n";
    }
}

/**
 * @brief Displays the local map.
 * 
 * This function outputs the local map to the console.
 */
void Mapper::showMap() const {
    // Implementation of showMap function
}