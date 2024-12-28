/**
 * @file RobotOperator.cpp
 * @brief Implementation of the RobotOperator class.
 */

#include "RobotOperator.h"
#include <iostream>

/**
 * @brief Constructs a RobotOperator object with the given name, surname, and access code.
 * 
 * Initializes the RobotOperator object with the provided name, surname, and encrypted access code.
 * 
 * @param name The first name of the robot operator.
 * @param surname The last name of the robot operator.
 * @param code The access code for the robot operator.
 */
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int code)
    : userName(name), userSurname(surname), access(false)
{
    storedCode = encryptCode(code);
}

/**
 * @brief Gets the first name of the robot operator.
 * 
 * @return std::string The first name of the robot operator.
 */
std::string RobotOperator::getName() const {
    return userName;
}

/**
 * @brief Gets the last name of the robot operator.
 * 
 * @return std::string The last name of the robot operator.
 */
std::string RobotOperator::getSurname() const {
    return userSurname;
}

/**
 * @brief Gets the access state of the robot operator.
 * 
 * @return bool True if access is granted, false otherwise.
 */
bool RobotOperator::getAccessState() const {
    return access;
}

/**
 * @brief Encrypts the given access code.
 * 
 * This function uses the Encryption class to encrypt the provided access code.
 * 
 * @param code The access code to encrypt.
 * @return int The encrypted access code.
 */
int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code);
}

/**
 * @brief Decrypts the given access code.
 * 
 * This function uses the Encryption class to decrypt the provided access code.
 * 
 * @param code The access code to decrypt.
 * @return int The decrypted access code.
 */
int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code);
}

/**
 * @brief Checks if the provided access code matches the stored code.
 * 
 * This function compares the provided access code with the stored encrypted code.
 * 
 * @param code The access code to check.
 * @return bool True if the access code matches the stored code, false otherwise.
 */
bool RobotOperator::checkAccessCode(int code) {
    if (code == storedCode) {
        return true;
    }
    return false;
}

/**
 * @brief Prints the details of the robot operator.
 * 
 * This function prints the first name, last name, and access state of the robot operator.
 */
void RobotOperator::print() const {
    std::cout << "Operator: " << userName << " " << userSurname << "\n"
              << "Access: " << (access ? "Granted" : "Denied") << std::endl;
}