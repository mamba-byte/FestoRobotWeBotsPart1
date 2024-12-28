/**
 * @file Encryption.h
 * @brief Declaration of the Encryption class.
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

/**
 * @class Encryption
 * @brief Provides methods for encrypting and decrypting 4-digit codes.
 * 
 * This class contains static methods to encrypt and decrypt 4-digit integer codes
 * using a simple algorithm.
 */
class Encryption
{
public:
    /**
     * @brief Encrypts a 4-digit code using a simple algorithm.
     * 
     * This function takes a 4-digit integer code, adds 7 to each digit, 
     * takes the result modulo 10, and then swaps the first digit with the third,
     * and the second digit with the fourth.
     * 
     * @param code The 4-digit integer code to be encrypted.
     * @return int The encrypted 4-digit integer code.
     */
    static int encrypt(int code);

    /**
     * @brief Decrypts a 4-digit code using a simple algorithm.
     * 
     * This function takes a 4-digit encrypted integer code, swaps the first digit with the third,
     * and the second digit with the fourth, subtracts 7 from each digit, and then takes the result modulo 10.
     * 
     * @param code The 4-digit encrypted integer code to be decrypted.
     * @return int The original 4-digit integer code.
     */
    static int decrypt(int code);
};

#endif // ENCRYPTION_H