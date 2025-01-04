/* CSCI 200: A3
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Analyze a text file and output results to a new file.
 */

#ifndef INPUT_PROCESSOR_H
#define INPUT_PROCESSOR_H

#include <string>
#include <vector>
#include <fstream>

/**
 * @brief A class for handling input from a file, reading lines, and extracting words.
 * 
 */
class InputProcessor {
public:
    /**
     * @brief Construct a new Input Processor object
     * 
     */
    InputProcessor();

    /**
     * @brief Opens a file stream for reading.
     * 
     * Prompts the user to enter the filename and attempts to open the file.
     * @return true if the file is successfully opened, false otherwise.
     */
    bool openStream();

    /**
     * @brief Closes the file stream.
     * 
     * Closes the input file if it was opened.
     */
    void closeStream();

    /**
     * @brief Reads all lines from the file into a vector.
     * 
     * This method reads each line of the file and stores it in the `lines` vector.
     */
    void read();

    /**
     * @brief Extracts all words from the lines read from the file.
     * 
     * This method splits the lines stored in the `lines` vector into words, where words are separated by spaces or other whitespace characters.
     * @return A vector containing all the words from the file.
     */
    std::vector<std::string> getAllWords();

private:
    std::string filename;              ///< The name of the file to be opened.
    std::ifstream fileIn;                 ///< Input file stream for reading from the file.
    std::vector<std::string> allWords;    ///< Vector to store each line read from the file.
};

#endif // INPUT_PROCESSOR_H
