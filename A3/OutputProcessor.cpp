#include "OutputProcessor.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

OutputProcessor::OutputProcessor() {
    filename = "exampleOutput.txt";
    fileOut.open(filename);
    allWords = {};
    uniqueWords = {}; 
    wordCounts = {}; 
    letterCounts = {};
    totalLetterCount = 0;
    totalWordCount = 0;
}

bool OutputProcessor::openStream() {
    cout << "What is the name of the file you want to open?" << endl;
    cin >> filename;
    fileOut.close();
    fileOut.open(filename);
    return !fileOut.fail();
}

void OutputProcessor::analyzeWords(vector<string> words, string punctuation) {
    for (string word : words) {
        string cleanedWord;
        for (char c : word) {
            if (punctuation.find(c) == string::npos) {
                cleanedWord += c;
            }
        }
        allWords.push_back(cleanedWord);
    }
}

int OutputProcessor::findIndex(vector<string> vec, string target) {
    for (string::size_type i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}

string OutputProcessor::toUpperCase(string str) {
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}

char OutputProcessor::toUpperCase(char character) {
    return (character >= 'a' && character <= 'z') ? character - 32 : character;
}

int OutputProcessor::getIntLength(int number) {
    return to_string(number).length();
}

void OutputProcessor::calculateWordFrequencies(vector<int>& numberUses1, size_t& longestWord) {
    for (string word : allWords) {
        int index = findIndex(uniqueWords, toUpperCase(word));
        if (index == -1) {
            uniqueWords.push_back(toUpperCase(word));
            numberUses1.push_back(1);
        } else {
            numberUses1[index]++;
        }
        longestWord = max(longestWord, word.length());
    }
}

void OutputProcessor::calculateLetterFrequencies(vector<int>& letterUses) {
    for (string word : allWords) {
        for (char letter : word) {
            int letterIndex = toUpperCase(letter) - 'A';
            if (letterIndex >= 0 && letterIndex < 26) {
                letterUses[letterIndex]++;
                totalLetterCount++;
            }
        }
    }
}

void OutputProcessor::getWordStatistics(std::vector<int> numberUses1, int& highestUses, std::string& highestUsedWord, int& leastUses, std::string& leastUsedWord) {
    highestUses = 0;
    leastUses = totalWordCount;

    for (std::string::size_type i = 0; i < numberUses1.size(); i++) {
        if (numberUses1[i] > highestUses) {
            highestUses = numberUses1[i];
            highestUsedWord = uniqueWords[i];
        }

        if (numberUses1[i] < leastUses) {
            leastUses = numberUses1[i];
            leastUsedWord = uniqueWords[i];
        }
    }
}

void OutputProcessor::getLetterStatistics(vector<int> letterUses, int& highestUsedLetterNumber, char& highestUsedLetter, int& leastUsedLetterNumber, char& leastUsedLetter, int numOfLetters) {
    highestUsedLetterNumber = 0;
    leastUsedLetterNumber = numOfLetters;

    for (int i = 0; i < 26; i++) {
        if (letterUses[i] > highestUsedLetterNumber) {
            highestUsedLetterNumber = letterUses[i];
            highestUsedLetter = 'A' + i;
        }
        if (letterUses[i] < leastUsedLetterNumber) {
            leastUsedLetterNumber = letterUses[i];
            leastUsedLetter = 'A' + i;
        }
    }
}

void OutputProcessor::sort() {
    vector<vector<string>> sortedWords(26);
    vector<vector<int>> sortedNumbers(26);
    vector<string> finalVectorWords;
    vector<int> finalVectorNumbers;
    for (size_t i = 0; i < uniqueWords.size(); i++) {
        sortedWords[uniqueWords[i][0] - 'A'].push_back(uniqueWords[i]);
        sortedNumbers[uniqueWords[i][0] - 'A'].push_back(wordCounts[i]);
    }
    for (size_t i = 0; i < sortedWords.size(); ++i) {
        if (sortedWords[i].empty()) continue;
        bool swapped;
        do {
            swapped = false;
            for (size_t j = 0; j < sortedWords[i].size() - 1; j++) {
                if (sortedWords[i][j] > sortedWords[i][j + 1]) {
                    swap(sortedWords[i][j], sortedWords[i][j + 1]);
                    swap(sortedNumbers[i][j], sortedNumbers[i][j + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }
    for (size_t i = 0; i < sortedWords.size(); i++) {
        for (size_t j = 0; j < sortedWords[i].size(); j++) {
            finalVectorWords.push_back(sortedWords[i][j]);
            finalVectorNumbers.push_back(sortedNumbers[i][j]);
        }
    }
    uniqueWords = finalVectorWords;
    wordCounts = finalVectorNumbers;
}


void OutputProcessor::write() {
    letterCounts.assign(26, 0);
    totalWordCount = allWords.size();
    totalLetterCount = 0;
    size_t longestWord = 0;
    int highestUsedLetterNumber, leastUsedLetterNumber, highestUses, leastUses;
    char highestUsedLetter, leastUsedLetter;
    string highestUsedWord, leastUsedWord;

    calculateWordFrequencies(wordCounts, longestWord);
    calculateLetterFrequencies(letterCounts);
    sort();
    getWordStatistics(wordCounts, highestUses, highestUsedWord, leastUses, leastUsedWord);
    getLetterStatistics(letterCounts, highestUsedLetterNumber, highestUsedLetter, leastUsedLetterNumber, leastUsedLetter, totalLetterCount);

    size_t width = max(highestUsedWord.length(), leastUsedWord.length());
    size_t width2 = max(getIntLength(highestUses), getIntLength(leastUses));
    size_t width1 = getIntLength(max(highestUsedLetterNumber, leastUsedLetterNumber));

    fileOut << "Read in " << totalWordCount << " words\n";
    fileOut << "Encountered " << uniqueWords.size() << " unique words\n";

    for (string::size_type i = 0; i < uniqueWords.size(); i++) {
        fileOut << left << setw(longestWord + 1) << uniqueWords[i] << ":" << right << setw(width2 + 1) << wordCounts[i] << endl;
    }

    fileOut << " Most Frequent Word: " << left << setw(width + 1) << highestUsedWord << right << setw(width2) << highestUses << " ( " << setw(6) << fixed << setprecision(3) << ((float)(highestUses) / totalWordCount * 100) << "%)\n";
    fileOut << "Least Frequent Word: " << left << setw(width + 1) << leastUsedWord << right << setw(width2) << leastUses << " ( " << setw(6) << fixed << setprecision(3) << ((float)(leastUses) / totalWordCount * 100) << "%)\n";

    for (int i = 0; i < 26; i++) {
        fileOut << char('A' + i) << ':' << right << setw(width1 + 1) << letterCounts[i] << endl;
    }

    fileOut << " Most Frequent Letter: " << highestUsedLetter << right << setw(width1 + 1) << highestUsedLetterNumber << " ( " << setw(6) << fixed << setprecision(3) << ((float)(highestUsedLetterNumber) / totalLetterCount * 100) << "%)\n";
    fileOut << "Least Frequent Letter: " << leastUsedLetter << right << setw(width1 + 1) << leastUsedLetterNumber << " ( " << setw(6) << fixed << setprecision(3) << ((float)(leastUsedLetterNumber) / totalLetterCount * 100) << "%)\n";
}

void OutputProcessor::closeStream() {
    fileOut.close();
}
