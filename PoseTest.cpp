/**
 * @file PoseTest.cpp
 * @brief Test file for the Pose class.
 */

#include <iostream>
#include "Pose.h"

/**
 * @brief Main function to test the Pose class.
 * 
 * This function performs various tests on the Pose class:
 * - Tests the default and parameterized constructors.
 * - Tests the getter and setter methods.
 * - Tests the addition, subtraction, and assignment operators.
 * - Tests the distance and angle calculation methods.
 * - Tests the equality operator.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Pose Test Start -----\n";

    // 1. Constructors
    Pose p1; // default constructor
    Pose p2(1.0, 2.0, 30.0); // parameterized constructor

    // 2. Getters/Setters
    std::cout << "[Test] p1 => X: " << p1.getX() << ", Y: " << p1.getY()
              << ", Th: " << p1.getTh() << "\n";
    p1.setX(5.5);
    p1.setY(4.4);
    p1.setTh(90.0);
    std::cout << "[Test] p1 after set => X: " << p1.getX() 
              << ", Y: " << p1.getY() << ", Th: " << p1.getTh() << "\n";

    // 3. Operators
    Pose sumPose = p1 + p2;
    std::cout << "[Test] sumPose => X: " << sumPose.getX() 
              << ", Y: " << sumPose.getY()
              << ", Th: " << sumPose.getTh() << "\n";

    Pose diffPose = p1 - p2;
    std::cout << "[Test] diffPose => X: " << diffPose.getX()
              << ", Y: " << diffPose.getY()
              << ", Th: " << diffPose.getTh() << "\n";

    p1 += 5.0;
    std::cout << "[Test] p1 += 5 => X: " << p1.getX() << ", Y: " << p1.getY() << ", Th: " << p1.getTh() << "\n";

    p1 -= 2.5;
    std::cout << "[Test] p1 -= 2.5 => X: " << p1.getX() << ", Y: " << p1.getY() << ", Th: " << p1.getTh() << "\n";

    // 4. Distance & angle
    double distance = p1.findDistanceTo(p2);
    std::cout << "[Test] Distance p1->p2: " << distance << "\n";
    double angle = p1.findAngleTo(p2);
    std::cout << "[Test] Angle p1->p2 (radians): " << angle << "\n";

    // 5. Comparison
    bool eqCheck = (p1 == p2);
    std::cout << "[Test] (p1 == p2)? => " << (eqCheck ? "Yes" : "No") << "\n";

    std::cout << "----- Pose Test Complete -----\n";
    return 0;
}