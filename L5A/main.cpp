#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <chrono>
#include <iostream>
#include <random>
using namespace std;

ARoom* go_to_next_room(int randRoomChoice) {
    switch(randRoomChoice) {
    case 7:     return new ExitRoom();
    default:    return new GuessTheNumberRoom();
    }
}

int main() {
    mt19937 mt( chrono::steady_clock::now().time_since_epoch().count() );
    uniform_int_distribution<int> dist(1, 10);

    ARoom* currentRoom;

    do {    
        currentRoom = go_to_next_room( dist(mt) );
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while( !currentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}