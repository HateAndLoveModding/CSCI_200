#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    mRoomName = "Exit Room";
    cout << "ExitRoom() called" << endl;
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}

bool ExitRoom::escapeTheRoom() {
    cout << "You found the exit!" << endl;
    return true;
}
