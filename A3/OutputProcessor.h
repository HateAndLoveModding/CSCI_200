/* CSCI 200: A3
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Analyze a text file and output results to a new file.
 */

#ifndef OUTPUT_PROCESSOR_H
#define OUTPUT_PROCESSOR_H

#include <fstream>
#include <vector>
#include <string>

/**
 * @brief A class for analyzing a file and writing staticstics to another file.
 * 
 */
class OutputProcessor {
public:
    /**
     * @brief Construct a new Output Processor object
     * 
     */
    OutputProcessor();

    /**
     * @brief Opens a file for writing output
     * 
     * Prompts the user to input the filename and attempts to open it for writing.
     * 
     * @return true if the file is successfully opened
     * @return false if the file cannot be opened
     */
    bool openStream();

    /**
     * @brief Closes the currently open output file
     * 
     * Ensures that all data is written to the file and closes the stream.
     */
    void closeStream();

    /**
     * @brief Removes punctuation from words in a vector
     * 
     * Loops through each word in the vector and removes characters that are found in the `punctuation` string.
     * 
     * @param words Vector of strings to process
     * @param punctuation String containing punctuation characters to be removed
     */
    void analyzeWords(std::vector<std::string> words, std::string punctuation);

    /**
     * @brief Finds the index of a target string in a vector
     * 
     * Searches for the `target` string in the `vec` vector and returns the index of its first occurrence.
     * 
     * @param vec Vector of strings to search
     * @param target String to search for
     * @return int Index of the target string, or -1 if not found
     */
    int findIndex(std::vector<std::string> vec, std::string target);

    /**
     * @brief Converts a string to uppercase
     * 
     * Iterates through each character in the input string and converts it to uppercase.
     * 
     * @param str String to be converted
     * @return std::string Uppercase version of the input string
     */
    std::string toUpperCase(std::string str);

    /**
     * @brief Converts a character to uppercase
     * 
     * Converts the input character to uppercase if it is a lowercase letter.
     * 
     * @param character Char    std::vector<string> getacter to be converted
     * @return char Uppercase version of the input character
     */
    char toUpperCase(char character);

    /**
     * @brief Gets the number of digits in an integer
     * 
     * Uses `to_string()` to convert the integer to a string and returns its length.
     * 
     * @param number Integer to be analyzed
     * @return int Number of digits in the integer
     */
    int getIntLength(int number);

    /**
     * @brief Calculates word frequencies and finds the longest word
     * 
     * Loops through `newWords` to update the word frequencies in `numberUses` and also determines the length of the longest word.
     * 
     * @param numberUses Vector that stores word frequencies
     * @param longestWord Size of the longest word in the input
     */
    void calculateWordFrequencies(std::vector<int>& numberUses, size_t& longestWord);

    /**
     * @brief Calculates letter frequencies and counts total letters
     * 
     * Loops through the `newWords` vector and counts how many times each letter (A-Z) appears in the words, updating `letterUses` and tracking the total number of letters.
     * 
     * @param letterUses Vector that stores letter frequencies (A-Z)
     * @param numOfLetters Total number of letters in the words
     */
    void calculateLetterFrequencies(std::vector<int>& letterUses);

    /**
     * @brief Gets word usage statistics
     * 
     * Finds the most and least frequently used words by analyzing the `numberUses` vector and their corresponding words in `uniqueWords`.
     * 
     * @param numberUses Vector of word frequencies
     * @param highestUses Most frequent word's usage count
     * @param highestUsedWord Most frequent word
     * @param leastUses Least frequent word's usage count
     * @param leastUsedWord Least frequent word
     */
    void getWordStatistics(std::vector<int> numberUses, int& highestUses, std::string& highestUsedWord, int& leastUses, std::string& leastUsedWord);

    /**
     * @brief Gets letter usage statistics
     * 
     * Finds the most and least frequently used letters by analyzing the `letterUses` vector and tracks the associated usage counts and letters.
     * 
     * @param letterUses Vector of letter frequencies (A-Z)
     * @param highestUsedLetterNumber Most frequent letter's usage count
     * @param highestUsedLetter Most frequent letter
     * @param leastUsedLetterNumber Least frequent letter's usage count
     * @param leastUsedLetter Least frequent letter
     * @param numOfLetters Total number of letters processed
     */
    void getLetterStatistics(std::vector<int> letterUses, int& highestUsedLetterNumber, char& highestUsedLetter, int& leastUsedLetterNumber, char& leastUsedLetter, int numOfLetters);

    /**
     * @brief Main output function
     * 
     * Writes various statistics (total words, unique words, word and letter frequencies) to the output file stream.
     */
    void write(); 

    /**
     * @brief Sorts uniqueWords based on first letter then sorts all words with the same starting letter and then writes to uniqueWords
     * 
     */
    void sort();

private:
    std::string filename;
    std::ofstream fileOut;
    std::vector<std::string> allWords;
    std::vector<std::string> uniqueWords; 
    std::vector<int> wordCounts; 
    std::vector<int> letterCounts;
    unsigned int totalLetterCount;
    unsigned int totalWordCount;
};

#endif
