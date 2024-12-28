/**
 * @file AuthenticationTest.cpp
 * @brief Test file for the Authentication class.
 */

#include <iostream>
#include "Authentication.h"

/**
 * @brief Main function to test the Authentication class.
 * 
 * This function creates an instance of the Authentication class and runs the authentication process.
 * It prompts the user for their first name, last name, and access code, and then checks the authentication result.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Authentication Test Start -----\n";

    // 1. Basic instance
    Authentication authObj;

    // 2. Run authentication (prompts user for name, surname, code).
    //    For unit testing, you’d typically feed mock input or check logic differently.
    bool result = authObj.authenticate();
    std::cout << "[Test] Authentication result => " << (result ? "Success" : "Fail") << "\n";

    std::cout << "----- Authentication Test Complete -----\n";
    return 0;
}