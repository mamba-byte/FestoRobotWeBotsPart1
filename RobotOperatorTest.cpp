/**
 * @file RobotOperatorTest.cpp
 * @brief Test file for the RobotOperator class.
 */

#include <iostream>
#include "RobotOperator.h"

/**
 * @brief Main function to test the RobotOperator class.
 * 
 * This function performs various tests on the RobotOperator class:
 * - Tests the creation of a RobotOperator object.
 * - Tests the encryption of an access code.
 * - Tests the verification of an encrypted access code.
 * - Prints the details of the RobotOperator object.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- RobotOperator Test Start -----\n";

    // 1. Basic creation
    RobotOperator op("Jane", "Doe", 4321);
    std::cout << "Operator Name: " << op.getName()
              << " " << op.getSurname() << "\n";

    // 2. Check encryption
    int tempEncrypted = op.encryptCode(4321);
    std::cout << "Encrypt(4321) => " << tempEncrypted << "\n";

    // 3. checkAccessCode
    bool valid = op.checkAccessCode(tempEncrypted);
    std::cout << "Provided encrypted code matched? => " << (valid ? "Yes" : "No") << "\n";

    // 4. Print
    op.print();

    std::cout << "----- RobotOperator Test Complete -----\n";
    return 0;
}