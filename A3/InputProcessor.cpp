#include "InputProcessor.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

InputProcessor::InputProcessor() {
    filename = "example.txt";
    fileIn.open(filename);
    allWords = {};
}

bool InputProcessor::openStream() {
    cout << "What is the name of the file you want to open?" << endl;
    cin >> filename;
    fileIn.close();
    fileIn.open(filename);
    return !fileIn.fail();
}

void InputProcessor::closeStream() {
    fileIn.close();
}

void InputProcessor::read() {
    string line;
    cout << "Reading from file: " << filename << endl;
    allWords.clear();
    while (getline(fileIn, line)) {
        allWords.push_back(line);
    }
}

vector<string> InputProcessor::getAllWords() {
    vector<string> words;
    for (string line : allWords) {
        string currentWord = "";
        for (char letter : line) {
            if (isspace(letter)) {
                if (!currentWord.empty()) {
                    words.push_back(currentWord);
                    currentWord = "";
                }
            } else {
                currentWord += letter;
            }
        }
        if (!currentWord.empty()) {
            words.push_back(currentWord);
        }
    }
    return words;
}
