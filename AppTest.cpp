/**
 * @file AppTest.cpp
 * @brief Test file for the App class.
 */

#include <iostream>
#include "App.h"

/**
 * @brief Main function to test the App class.
 * 
 * This function creates an instance of the App class and runs it.
 * Note: This test might ask for input on authentication and then
 * run its main menu loop. For automated testing, you'd need to mock
 * user input or adapt the code to a test harness.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- App Test Start -----\n";

    // The App manages everything, including user authentication, etc.
    // This test, as coded, might ask for input on authentication, then
    // run its main menu loop. For automated testing, you'd need
    // to mock user input or adapt the code to a test harness.

    App application;
    application.run();

    std::cout << "----- App Test Complete -----\n";
    return 0;
}