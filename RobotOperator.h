/**
 * @file RobotOperator.h
 * @brief Declaration of the RobotOperator class.
 */

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

/**
 * @class RobotOperator
 * @brief Manages the robot operator's credentials and access control.
 * 
 * This class provides methods to handle the robot operator's name, surname, access code, and access state.
 */
class RobotOperator {
private:
    std::string userName; ///< First name of the robot operator
    std::string userSurname; ///< Last name of the robot operator
    unsigned int storedCode; ///< Encrypted access code
    bool access; ///< Access state of the robot operator

public:
    /**
     * @brief Constructs a RobotOperator object with the given name, surname, and access code.
     * 
     * Initializes the RobotOperator object with the provided name, surname, and encrypted access code.
     * 
     * @param name The first name of the robot operator.
     * @param surname The last name of the robot operator.
     * @param code The access code for the robot operator.
     */
    RobotOperator(const std::string& name, const std::string& surname, unsigned int code);

    /**
     * @brief Gets the first name of the robot operator.
     * 
     * @return std::string The first name of the robot operator.
     */
    std::string getName() const;

    /**
     * @brief Gets the last name of the robot operator.
     * 
     * @return std::string The last name of the robot operator.
     */
    std::string getSurname() const;

    /**
     * @brief Gets the access state of the robot operator.
     * 
     * @return bool True if access is granted, false otherwise.
     */
    bool getAccessState() const;

    /**
     * @brief Encrypts the given access code.
     * 
     * This function uses the Encryption class to encrypt the provided access code.
     * 
     * @param code The access code to encrypt.
     * @return int The encrypted access code.
     */
    int encryptCode(int code);

    /**
     * @brief Decrypts the given access code.
     * 
     * This function uses the Encryption class to decrypt the provided access code.
     * 
     * @param code The access code to decrypt.
     * @return int The decrypted access code.
     */
    int decryptCode(int code);

    /**
     * @brief Checks if the provided access code matches the stored code.
     * 
     * This function compares the provided access code with the stored encrypted code.
     * 
     * @param code The access code to check.
     * @return bool True if the access code matches the stored code, false otherwise.
     */
    bool checkAccessCode(int code);

    /**
     * @brief Prints the details of the robot operator.
     * 
     * This function prints the first name, last name, and access state of the robot operator.
     */
    void print() const;
};

#endif // ROBOTOPERATOR_H