/**
 * @file Authentication.cpp
 * @brief Implementation of the Authentication class.
 */

#include "Authentication.h"

/**
 * @brief Authenticates a user by verifying their access code.
 * 
 * This function prompts the user to enter their first name, last name, and access code.
 * It then checks the provided access code against an internally stored encrypted code.
 * 
 * @return true if the access code is valid, false otherwise.
 */
bool Authentication::authenticate()
{
    std::string userName, userSurname;
    unsigned int code;

    std::cout << "Enter your first name: ";
    std::cin >> userName;
    std::cout << "Enter your last name: ";
    std::cin >> userSurname;
    std::cout << "Enter access code: ";
    std::cin >> code;

    // Compare provided code with the internal encrypted one
    if(!internalOperator.checkAccessCode(encryptService.encrypt(code))) {
        std::cout << "Access Denied. Invalid code.\n";
        return false;
    } else {
        std::cout << "Access Granted! Welcome, " << userName << " " << userSurname << "!\n";
        return true;
    }
}