/**
 * @file Authentication.h
 * @brief Declaration of the Authentication class.
 */

#pragma once

#include "RobotOperator.h"
#include "Encryption.h"
#include <iostream>

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

/**
 * @class Authentication
 * @brief Coordinates user credential verification.
 */
class Authentication {
private:
    RobotOperator internalOperator; ///< Operator object for internal operations
    Encryption encryptService;      ///< Service for encrypting access codes

public:
    /**
     * @brief Default constructor loading a preset operator.
     * 
     * Initializes the internal operator with preset credentials.
     */
    Authentication()
        : internalOperator("Levent", "Avcı", 1234) {}

    /**
     * @brief Prompts and validates user credentials (name, surname, access code).
     * 
     * This function prompts the user to enter their first name, last name, and access code.
     * It then checks the provided access code against an internally stored encrypted code.
     * 
     * @return True if verified, otherwise false.
     */
    bool authenticate();
};

#endif // AUTHENTICATION_H