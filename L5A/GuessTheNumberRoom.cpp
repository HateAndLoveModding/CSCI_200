#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;
    mRoomName = "Guess The Number Room";
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistr(1, 20);
    _secretNumber = intDistr(mt);
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    int guess;
    for(int i=0; i<5; i++) {
        cout << "Enter a number: ";
        cin >> guess;
        if(guess == _secretNumber) {
            return true;
        } else if(guess < _secretNumber) {
            cout << "Guess is too low. Try again." << endl;
        } else if(guess > _secretNumber) {
            cout << "Guess is too high. Try again." << endl;
        }
    }
    return false;
}