/**
 * @file MapTest.cpp
 * @brief Test file for the Map class.
 */

#include <iostream>
#include "Map.h"

/**
 * @brief Main function to test the Map class.
 * 
 * This function performs various tests on the Map class:
 * - Tests the default constructor and prints the map information.
 * - Inserts a point into the map and displays the map.
 * - Tests the getGrid and setGrid methods.
 * - Enlarges the grid size and prints the updated map information.
 * - Clears the map and displays the map.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Map Test Start -----\n";

    // 1. Default constructor
    Map defaultMap;
    defaultMap.printInfo();
    defaultMap.showMap();

    // 2. Insert a point
    defaultMap.insertPoint(Point(2.0, 2.0));
    defaultMap.showMap();

    // 3. getGrid & setGrid
    int val = defaultMap.getGrid(2, 2);
    std::cout << "[Test] Grid(2,2) => " << val << "\n";

    defaultMap.setGrid(0, 0, 1);
    std::cout << "[Test] After setGrid(0,0,1):\n";
    defaultMap.showMap();

    // 4. addGridSize
    defaultMap.addGridSize(5, 5);
    std::cout << "[Test] After enlarging grid (5,5):\n";
    defaultMap.printInfo();

    // 5. Clear map
    defaultMap.clearMap();
    defaultMap.showMap();

    std::cout << "----- Map Test Complete -----\n";
    return 0;
}