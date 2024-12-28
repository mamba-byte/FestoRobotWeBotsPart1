/**
 * @file Record.cpp
 * @brief Implementation of the Record class.
 */

#include "Record.h"
#include <iostream>

/**
 * @brief Default constructor for the Record class.
 * 
 * Initializes the Record object with an empty file name.
 */
Record::Record() : fileName("") {}

/**
 * @brief Destructor for the Record class.
 * 
 * Closes the file stream if it is open.
 */
Record::~Record() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

/**
 * @brief Opens a file with the specified name and mode.
 * 
 * This function sets the file name and opens the file stream with the given mode.
 * 
 * @param filename The name of the file to open.
 * @param mode The mode in which to open the file.
 * @return bool Returns true if the file is successfully opened, false otherwise.
 */
bool Record::openFile(const std::string& filename, std::ios::openmode mode) {
    fileName = filename;
    fileStream.open(fileName, mode);
    return fileStream.is_open();
}

/**
 * @brief Closes the file stream if it is open.
 */
void Record::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

/**
 * @brief Sets the file name for the Record object.
 * 
 * @param filename The new file name.
 */
void Record::setFileName(const std::string& filename) {
    fileName = filename;
}

/**
 * @brief Reads a line from the file stream.
 * 
 * This function reads a line from the file stream and stores it in the provided string.
 * 
 * @param line Reference to a string where the read line will be stored.
 * @return bool Returns true if a line is successfully read, false otherwise.
 */
bool Record::readLine(std::string& line) {
    if (fileStream.is_open() && std::getline(fileStream, line)) {
        return true;
    } else {
        std::cerr << "Unable to read line: File not open or read error.\n";
        return false;
    }
}

/**
 * @brief Writes a line to the file stream.
 * 
 * This function writes the provided line to the file stream.
 * 
 * @param line The line to write to the file.
 */
void Record::writeLine(const std::string& line) {
    if (fileStream.is_open()) {
        fileStream << line << std::endl;
    } else {
        std::cerr << "Write failed: file not open.\n";
    }
}

/**
 * @brief Stream insertion operator for the Record class.
 * 
 * This function inserts the contents of the file stream into the output stream.
 * 
 * @param os The output stream.
 * @param record The Record object.
 * @return std::fstream& The output stream.
 */
std::fstream& operator<<(std::fstream& os, const Record& record) {
    if (record.fileStream.is_open()) {
        os << record.fileStream.rdbuf();
    }
    return os;
}

/**
 * @brief Stream extraction operator for the Record class.
 * 
 * This function extracts a line from the input stream and stores it in the Record object.
 * 
 * @param is The input stream.
 * @param record The Record object.
 * @return std::fstream& The input stream.
 */
std::fstream& operator>>(std::fstream& is, Record& record) {
    if (record.fileStream.is_open()) {
        std::string tempLine;
        record.readLine(tempLine);
    }
    return is;
}