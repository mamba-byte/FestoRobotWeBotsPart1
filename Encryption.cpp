/**
 * @file Encryption.cpp
 * @brief Implementation of the Encryption class.
 */

#include "Encryption.h"
#include <utility>

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
int Encryption::encrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = (code % 10 + 7) % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int result = 0;
    for (int i = 0; i < 4; ++i) {
        result = result * 10 + digits[i];
    }
    return result;
}

/**
 * @brief Decrypts a 4-digit code using a simple algorithm.
 * 
 * This function takes a 4-digit encrypted integer code, swaps the first digit with the third,
 * and the second digit with the fourth, subtracts 7 from each digit, and then takes the result modulo 10.
 * 
 * @param code The 4-digit encrypted integer code to be decrypted.
 * @return int The original 4-digit integer code.
 */
int Encryption::decrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = code % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int original = 0;
    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10;
        original = original * 10 + digits[i];
    }
    return original;
}