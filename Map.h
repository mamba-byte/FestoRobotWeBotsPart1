/**
 * @file Map.h
 * @brief Declaration of the Map class.
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "Point.h"

/**
 * @class Map
 * @brief Manages a 2D grid map.
 * 
 * This class provides methods to manipulate and query a 2D grid map.
 */
class Map {
private:
    std::vector<std::vector <int> > grid; ///< 2D grid representing the map
    int dimX; ///< Number of columns in the grid
    int dimY; ///< Number of rows in the grid

public:
    /**
     * @brief Constructs a Map object with specified dimensions.
     * 
     * Initializes the grid with the given dimensions, defaulting to 10x10.
     * 
     * @param sizeX Number of columns in the grid.
     * @param sizeY Number of rows in the grid.
     */
    Map(int sizeX = 10, int sizeY = 10);

    /**
     * @brief Clears the map by setting all grid values to 0.
     */
    void clearMap();

    /**
     * @brief Inserts a point into the map.
     * 
     * Sets the grid value at the point's coordinates to 1.
     * 
     * @param point The point to be inserted.
     */
    void insertPoint(const Point& point);

    /**
     * @brief Gets the value at the specified grid coordinates.
     * 
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return int The value at the specified coordinates.
     */
    int getGrid(int x, int y) const;

    /**
     * @brief Sets the value at the specified grid coordinates.
     * 
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param value The value to set at the specified coordinates.
     */
    void setGrid(int x, int y, int value);

    /**
     * @brief Gets the number of columns in the grid.
     * 
     * @return int The number of columns.
     */
    int getNumberX() const;

    /**
     * @brief Gets the number of rows in the grid.
     * 
     * @return int The number of rows.
     */
    int getNumberY() const;

    /**
     * @brief Adds to the grid size.
     * 
     * Increases the grid dimensions by the specified deltas.
     * 
     * @param deltaX The number of columns to add.
     * @param deltaY The number of rows to add.
     */
    void addGridSize(int deltaX, int deltaY);

    /**
     * @brief Sets the grid size.
     * 
     * Resizes the grid to the specified dimensions.
     * 
     * @param sizeX The new number of columns.
     * @param sizeY The new number of rows.
     */
    void setGridSize(int sizeX, int sizeY);

    /**
     * @brief Prints information about the map.
     */
    void printInfo() const;

    /**
     * @brief Displays the map.
     * 
     * Outputs the grid to the console.
     */
    void showMap() const;
};

#endif // MAP_H