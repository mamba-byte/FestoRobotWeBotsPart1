/**
 * @file MapperTest.cpp
 * @brief Test file for the Mapper class.
 */

#include <iostream>
#include "mapper.h"

/**
 * @brief Main function to test the Mapper class.
 * 
 * This function performs various tests on the Mapper class:
 * - Creates a Mapper object.
 * - Simulates Lidar data and updates the map.
 * - Displays the map.
 * - Records the map to a file.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Mapper Test Start -----\n";

    // 1. Create a Mapper
    Mapper mapper(10, 10, 5, 5);

    // 2. Simulate some lidar data
    // Each pair<int,int> => (distance, angleDegrees)
    std::vector<std::pair<int,int>> fakeData = {
        {1, 0}, {2, 90}, {3, 180}, {2, 270}
    };

    mapper.updateMap(fakeData);
    mapper.showMap();

    // 3. Record map to a file
    mapper.recordMap("testMapOutput.txt");
    std::cout << "[Test] Map recorded to testMapOutput.txt\n";

    std::cout << "----- Mapper Test Complete -----\n";
    return 0;
}