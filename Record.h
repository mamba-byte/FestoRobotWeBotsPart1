/**
 * @file Record.h
 * @brief Declaration of the Record class.
 */

#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

/**
 * @class Record
 * @brief Manages file operations such as reading and writing lines.
 * 
 * This class provides methods to open, close, read from, and write to a file.
 */
class Record {
private:
    std::fstream fileStream; ///< File stream for reading and writing
    std::string fileName; ///< Name of the file

public:
    /**
     * @brief Default constructor for the Record class.
     * 
     * Initializes the Record object with an empty file name.
     */
    Record();

    /**
     * @brief Destructor for the Record class.
     * 
     * Closes the file stream if it is open.
     */
    ~Record();

    /**
     * @brief Opens a file with the specified name and mode.
     * 
     * This function sets the file name and opens the file stream with the given mode.
     * 
     * @param filename The name of the file to open.
     * @param mode The mode in which to open the file.
     * @return bool Returns true if the file is successfully opened, false otherwise.
     */
    bool openFile(const std::string& filename, std::ios::openmode mode);

    /**
     * @brief Closes the file stream if it is open.
     */
    void closeFile();

    /**
     * @brief Sets the file name for the Record object.
     * 
     * @param filename The new file name.
     */
    void setFileName(const std::string& filename);

    /**
     * @brief Reads a line from the file stream.
     * 
     * This function reads a line from the file stream and stores it in the provided string.
     * 
     * @param line Reference to a string where the read line will be stored.
     * @return bool Returns true if a line is successfully read, false otherwise.
     */
    bool readLine(std::string& line);

    /**
     * @brief Writes a line to the file stream.
     * 
     * This function writes the provided line to the file stream.
     * 
     * @param line The line to write to the file.
     */
    void writeLine(const std::string& line);

    /**
     * @brief Stream insertion operator for the Record class.
     * 
     * This function inserts the contents of the file stream into the output stream.
     * 
     * @param os The output stream.
     * @param record The Record object.
     * @return std::fstream& The output stream.
     */
    friend std::fstream& operator<<(std::fstream& os, const Record& record);

    /**
     * @brief Stream extraction operator for the Record class.
     * 
     * This function extracts a line from the input stream and stores it in the Record object.
     * 
     * @param is The input stream.
     * @param record The Record object.
     * @return std::fstream& The input stream.
     */
    friend std::fstream& operator>>(std::fstream& is, Record& record);
};

#endif // RECORD_H