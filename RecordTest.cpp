/**
 * @file RecordTest.cpp
 * @brief Test file for the Record class.
 */

#include <iostream>
#include "Record.h"

/**
 * @brief Main function to test the Record class.
 * 
 * This function performs various tests on the Record class:
 * - Opens a file for writing and writes lines to it.
 * - Re-opens the file for reading and reads lines from it.
 * - Attempts to read from an unopened file to test edge cases.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    std::cout << "----- Record Test Start -----\n";

    Record recObj;

    // 1. Open a file for writing
    if (!recObj.openFile("testRecord.txt", std::ios::out)) {
        std::cerr << "[Error] Could not open file for writing.\n";
    } else {
        recObj.writeLine("Line 1: Hello Record!");
        recObj.writeLine("Line 2: Another line here.");
        recObj.closeFile();
        std::cout << "[Test] Wrote lines to testRecord.txt\n";
    }

    // 2. Re-open the file for reading
    if (!recObj.openFile("testRecord.txt", std::ios::in)) {
        std::cerr << "[Error] Could not open file for reading.\n";
    } else {
        std::string line;
        while (recObj.readLine(line)) {
            std::cout << "[Read] " << line << "\n";
        }
        recObj.closeFile();
    }

    // 3. Edge: attempt to read from unopened file
    std::string dummy;
    bool readResult = recObj.readLine(dummy);
    std::cout << "[Test] Attempt to read from closed file => " << (readResult ? "Success" : "Fail") << "\n";

    std::cout << "----- Record Test Complete -----\n";
    return 0;
}