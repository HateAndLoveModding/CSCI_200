#include "Cube.h"
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

Cube::Cube() {
    whiteSide = new char[9] {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'};
    yellowSide = new char[9] {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'};
    redSide = new char[9] {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'};
    orangeSide = new char[9] {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'};
    blueSide = new char[9] {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'};
    greenSide = new char[9] {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'};
}

sf::Color getColor(char c) {
    switch (c) {
        case 'W': return sf::Color::White;
        case 'Y': return sf::Color::Yellow;
        case 'R': return sf::Color::Red;
        case 'O': return sf::Color(255, 165, 0); // Orange
        case 'B': return sf::Color::Blue;
        case 'G': return sf::Color::Green;
        default: return sf::Color::Black;
    }
}

void Cube::displayRubiksCube(sf::RenderWindow& window) const {
    int squareSize = 50;
    int spacing = 10;
    vector<vector<int>> positions = {{
        {3, 0}, // White (Top)
        {3, 6}, // Yellow (Bottom)
        {6, 3}, // Red (Front)
        {0, 3}, // Orange (Left)
        {9, 3}, // Blue (Right)
        {3, 3}  // Green (Back)
    }};

    char* sides[6] = {whiteSide, yellowSide, redSide, orangeSide, blueSide, greenSide};

    for (size_t side = 0; side < 6; ++side) {
        int offsetX = positions[side][0] * (squareSize + spacing) + 20;
        int offsetY = positions[side][1] * (squareSize + spacing);

        for (int i = 0; i < 9; ++i) {
            int row = i / 3;
            int col = i % 3;

            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            square.setPosition(offsetX + col * (squareSize + spacing), offsetY + row * (squareSize + spacing));
            square.setFillColor(getColor(sides[side][i]));

            window.draw(square);
        }
    }
}

string Cube::getMoves() const {
    return _moves;
}

void Cube::shiftArrayClockwise(char* arr) {
    char temp[9];
    temp[2] = arr[0]; 
    temp[8] = arr[2]; 
    temp[6] = arr[8]; 
    temp[0] = arr[6]; 
    temp[5] = arr[1];
    temp[7] = arr[5]; 
    temp[3] = arr[7]; 
    temp[1] = arr[3]; 
    temp[4] = arr[4]; 
    for (int i = 0; i < 9; ++i) {
        arr[i] = temp[i];
    }
}

void Cube::shiftArrayCounterclockwise(char* arr) {
    char temp[9];
    temp[6] = arr[0]; 
    temp[0] = arr[2]; 
    temp[2] = arr[8]; 
    temp[8] = arr[6]; 
    temp[3] = arr[1];
    temp[1] = arr[5]; 
    temp[5] = arr[7]; 
    temp[7] = arr[3]; 
    temp[4] = arr[4]; 
    for (int i = 0; i < 9; ++i) {
        arr[i] = temp[i];
    }
}

string Cube::turnSideClockwise(char* theSide) {
    return turnSideClockwise(theSide[4]);
}

string Cube::turnSideClockwise(char theSide) {
    char center= theSide;
    char temp;
    switch (center) {
        case 'W':
            _moves = _moves + "U ";
            for(int i=0; i<3; i++) {
                temp = redSide[i];
                redSide[i] = blueSide[i];
                blueSide[i] = orangeSide[i];
                orangeSide[i] = greenSide[i];
                greenSide[i] = temp;
            }
            shiftArrayClockwise(whiteSide);
            return "U ";
        case 'R':
            _moves = _moves + "R ";
            for(int j=0; j<3; j++) {
                int i = j*3+2;
                temp = whiteSide[i];
                whiteSide[i] = greenSide[i];
                greenSide[i] = yellowSide[i];
                yellowSide[i] = blueSide[6-j*3];
                blueSide[6-j*3] = temp;
            }
            shiftArrayClockwise(redSide);
            return "R ";
        case 'O':
            _moves = _moves + "L ";
            for(int j=0; j<3; j++) {
                int i = j*3;
                temp = whiteSide[i];
                whiteSide[i] = blueSide[8-i];
                blueSide[8-i] = yellowSide[i];
                yellowSide[i] = greenSide[i];
                greenSide[i] = temp;
            }
            shiftArrayClockwise(orangeSide);
            return "L ";
        case 'Y':
            _moves = _moves + "D ";
            for(int j=6; j<9; j++) {
                int i = j;
                temp = greenSide[i];
                greenSide[i] = orangeSide[i];
                orangeSide[i] = blueSide[i];
                blueSide[i] = redSide[i];
                redSide[i] = temp;
            }
            shiftArrayClockwise(yellowSide);
            return "D ";
        case 'G':
            _moves = _moves + "F ";
            for(int j=0; j<3; j++) {
                temp = whiteSide[6+j];
                whiteSide[6+j] = orangeSide[8-j*3];
                orangeSide[8-j*3] = yellowSide[2-j];
                yellowSide[2-j] = redSide[j*3];
                redSide[j*3] = temp;
            }
            shiftArrayClockwise(greenSide);
            return "F ";
        case 'B':
            _moves = _moves + "B ";
            for(int i=0; i<3; i++) {
                temp = whiteSide[i];
                whiteSide[i] = redSide[i*3+2];
                redSide[i*3+2] = yellowSide[8-i];
                yellowSide[8-i] = orangeSide[6-i*3];
                orangeSide[6-i*3] = temp;
            }
            shiftArrayClockwise(blueSide);
            return "B ";
        case 'E':
            _moves = _moves + "E ";
            for(int i=3; i<6; i++) {
                temp = greenSide[i];
                greenSide[i] = orangeSide[i];
                orangeSide[i] = blueSide[i];
                blueSide[i] = redSide[i];
                redSide[i] = temp;
            }
            return "E ";
        default:
            cout << "Invalid character." << endl;
            return "-1";
    }
}

string Cube::turnSideCounterclockwise(char* theSide) {
    return turnSideCounterclockwise(theSide[4]);
}

string Cube::turnSideCounterclockwise(char theSide) {
    char center = theSide;
    char temp;
    switch (center) {
        case 'W':
            _moves = _moves + "U' ";
            for(int i=0; i<3; i++) {
                temp = redSide[i];
                redSide[i] = greenSide[i];
                greenSide[i] = orangeSide[i];
                orangeSide[i] = blueSide[i];
                blueSide[i] = temp;
            }
            shiftArrayCounterclockwise(whiteSide);
            return "U' ";
        case 'R':
            _moves = _moves + "R' ";
            for(int j=0; j<3; j++) {
                int i = j*3+2;
                temp = whiteSide[i];
                whiteSide[i] = blueSide[6-j*3];
                blueSide[6-j*3] = yellowSide[i];
                yellowSide[i] = greenSide[i];
                greenSide[i] = temp;
            }
            shiftArrayCounterclockwise(redSide);
            return "R' ";
        case 'O':
            _moves = _moves + "L' ";
            for(int j=0; j<3; j++) {
                int i = j*3;
                temp = whiteSide[i];
                whiteSide[i] = greenSide[i];
                greenSide[i] = yellowSide[i];
                yellowSide[i] = blueSide[8-i];
                blueSide[8-i] = temp;
            }
            shiftArrayCounterclockwise(orangeSide);
            return "L' ";
        case 'Y':
            _moves = _moves + "D' ";
            for(int j=6; j<9; j++) {
                int i = j;
                temp = greenSide[i];
                greenSide[i] = redSide[i];
                redSide[i] = blueSide[i];
                blueSide[i] = orangeSide[i];
                orangeSide[i] = temp;
            }
            shiftArrayCounterclockwise(yellowSide);
            return "D' ";
        case 'G':
            _moves = _moves + "F' ";
            for(int j=0; j<3; j++) {
                temp = whiteSide[6+j];
                whiteSide[6+j] = redSide[j*3];
                redSide[j*3] = yellowSide[2-j];
                yellowSide[2-j] = orangeSide[8-j*3];
                orangeSide[8-j*3] = temp;
            }
            shiftArrayCounterclockwise(greenSide);
            return "F' ";
        case 'B':
            _moves = _moves + "B' ";
            for(int i=0; i<3; i++) {
                temp = whiteSide[i];
                whiteSide[i] = orangeSide[6-i*3];
                orangeSide[6-i*3] = yellowSide[8-i];
                yellowSide[8-i] = redSide[i*3+2];
                redSide[i*3+2] = temp;
            }
            shiftArrayCounterclockwise(blueSide);
            return "B' ";
        case 'E':
            _moves = _moves + "E' ";
            for(int i=3; i<6; i++) {
                temp = greenSide[i];
                greenSide[i] = redSide[i];
                redSide[i] = blueSide[i];
                blueSide[i] = orangeSide[i];
                orangeSide[i] = temp;
            }
            return "E' ";
        default:
            cout << "Invalid character." << endl;
            return "-1";
    }
}

bool Cube::isCubeSolved() {
    // Check each side to see if it matches the initial solved state
    for (int i = 0; i < 9; i++) {
        if (whiteSide[i] != 'W' || yellowSide[i] != 'Y' || redSide[i] != 'R' ||
            orangeSide[i] != 'O' || blueSide[i] != 'B' || greenSide[i] != 'G') {
            return false;  // If any side is not in the solved state, return false
        }
    }
    return true;  // All sides are in the solved state
}

void Cube::scrambleCube() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistr(1, 12);
    string previous = "";
    for(int i=0; i<20; i++) {
        int theCase = intDistr(mt);
        switch(theCase){
            case 1:
                if(previous=="W " || previous=="W' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(whiteSide);
                
                break;
            case 2:
                if(previous=="D " || previous=="D' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(yellowSide);
                
                break;
            case 3:
                if(previous=="R " || previous=="R' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(redSide);
                
                break;
            case 4:
                if(previous=="L " || previous=="L' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(orangeSide);
                
                break;
            case 5:
                if(previous=="F " || previous=="F' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(greenSide);
                
                break;
            case 6:
                if(previous=="B " || previous=="B' ") {
                    i--;
                    break;
                }
                previous = turnSideClockwise(blueSide);
                
                break;
            case 7:
                if(previous=="U " || previous=="U' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(whiteSide);
                
                break;
            case 8:
                if(previous=="D " || previous=="D' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(yellowSide);
                
                break;
            case 9:
                if(previous=="R " || previous=="R' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(redSide);
                
                break;
            case 10:
                if(previous=="L " || previous=="L' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(orangeSide);
                
                break;
            case 11:
                if(previous=="B " || previous=="B' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(blueSide);
                
                break;
            case 12:
                if(previous=="F " || previous=="F' ") {
                    i--;
                    break;
                }
                previous = turnSideCounterclockwise(greenSide);
                
                break;
            default:
                cout << "Invalid." << endl;
        }
    }    
    _moves = _moves + "\n";
}

void Cube::solveWhiteLayerCrossPieces(char* side1, char* side2) {
    turnSideCounterclockwise(side1);
    turnSideClockwise(whiteSide);
    turnSideCounterclockwise(side2);
    turnSideCounterclockwise(whiteSide);
}

void Cube::resetAUF() {
    for(int i=0; i<4; i++) {
        if(whiteSide[1]=='W') {
            turnSideClockwise(whiteSide);
        } else {
            break;
        }
    }
}

void Cube::solveCross() {
    if(blueSide[1]=='W') {
        solveWhiteLayerCrossPieces(blueSide, redSide);
    }
    if(orangeSide[1]=='W') {
        solveWhiteLayerCrossPieces(orangeSide, blueSide);
    }
    if(redSide[1]=='W') {
        solveWhiteLayerCrossPieces(redSide, greenSide);
    }
    if(greenSide[1]=='W') {
        solveWhiteLayerCrossPieces(greenSide, orangeSide);
    }
    resetAUF();
    while(greenSide[5]=='W' || greenSide[3]=='W' || redSide[3]=='W' || redSide[5]=='W' || blueSide[3]=='W' || blueSide[5]=='W' || orangeSide[5]=='W' || orangeSide[3]=='W') {
        if(greenSide[5]=='W') {
            turnSideClockwise(whiteSide);
            turnSideClockwise(redSide);
            turnSideCounterclockwise(whiteSide);
            resetAUF();
        } else if(redSide[3]=='W') {
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(greenSide);
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
            resetAUF();
        }
        if(redSide[5]=='W') {
            turnSideClockwise(blueSide);
            resetAUF();
        } else if(blueSide[3]=='W') {
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(whiteSide);
            resetAUF();
        }
        if(blueSide[5]=='W') {
            turnSideCounterclockwise(whiteSide);
            turnSideClockwise(orangeSide);
            turnSideClockwise(whiteSide);
            resetAUF();
        } else if(orangeSide[3]=='W') {
            turnSideCounterclockwise(blueSide);
            resetAUF();
        }
        if(orangeSide[5]=='W') {
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
            turnSideClockwise(greenSide);
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
            resetAUF();
        } else if(greenSide[3]=='W') {
            turnSideCounterclockwise(whiteSide);
            turnSideCounterclockwise(orangeSide);
            turnSideClockwise(whiteSide);
            resetAUF();
        }
    }


    if(yellowSide[1]=='W') {
        turnSideClockwise(yellowSide);
        turnSideClockwise(yellowSide);
        turnSideClockwise(blueSide);
        turnSideClockwise(blueSide);
        resetAUF();
    }
    if(yellowSide[3]=='W') {
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(blueSide);
        turnSideClockwise(blueSide);
        resetAUF();
    }
    if(yellowSide[5]=='W') {
        turnSideClockwise(yellowSide);
        turnSideClockwise(blueSide);
        turnSideClockwise(blueSide);
        resetAUF();
    }
    if(yellowSide[7]=='W') {
        turnSideClockwise(blueSide);
        turnSideClockwise(blueSide);
        resetAUF();
    }



    if(greenSide[7]=='W') {
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(orangeSide);
        turnSideCounterclockwise(blueSide);
        turnSideCounterclockwise(orangeSide);
        resetAUF();
    }
    if(redSide[7]=='W') {
        turnSideCounterclockwise(redSide);
        turnSideClockwise(blueSide);
        turnSideClockwise(redSide);
        resetAUF();
    }
    if(blueSide[7]=='W') {
        turnSideCounterclockwise(yellowSide);
        turnSideCounterclockwise(redSide);
        turnSideClockwise(blueSide);
        turnSideClockwise(redSide);
        resetAUF();
    }
    if(orangeSide[7]=='W') {
        turnSideClockwise(orangeSide);
        turnSideCounterclockwise(blueSide);
        turnSideCounterclockwise(orangeSide);
        resetAUF();
    }

    cout << _moves << endl;
    if(whiteSide[1]=='W' && whiteSide[3]=='W' && whiteSide[5]=='W' && whiteSide[7]=='W') {}
    else {solveCross();}
    bool g=false, r=false, b=false, o=false;
    while(g==false || r==false || b==false || o==false) {
        if(greenSide[1]=='G' && whiteSide[7]=='W' && g==false) {
            g=true;
            turnSideClockwise(greenSide);
            turnSideClockwise(greenSide);
        }
        if(redSide[1]=='R' && whiteSide[5]=='W' && r==false) {
            r=true;
            turnSideClockwise(redSide);
            turnSideClockwise(redSide);
        }
        if(blueSide[1]=='B' && whiteSide[1]=='W' && b==false) {
            b=true;
            turnSideClockwise(blueSide);
            turnSideClockwise(blueSide);
        }
        if(orangeSide[1]=='O' && whiteSide[3]=='W' && o==false) {
            o=true;
            turnSideClockwise(orangeSide);
            turnSideClockwise(orangeSide);
        }
        turnSideClockwise(whiteSide);
    }
    turnSideClockwise(greenSide);
    turnSideClockwise(greenSide);
    turnSideClockwise(redSide);
    turnSideClockwise(redSide);
    turnSideClockwise(blueSide);
    turnSideClockwise(blueSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(orangeSide);
    _moves = _moves + "\n";
}

void Cube::cornerHelper() {
    int turns = 0;
    while (turns<4) {
        if(yellowSide[2]=='W' || greenSide[8]=='W' || redSide[6]=='W') {
            turns = 0;
            if(yellowSide[2]=='W') {
                int AUF=0;
                if(greenSide[8]=='G') {
                    AUF=1;
                    turnSideCounterclockwise(whiteSide);
                } else if(greenSide[8]=='B') {
                    AUF=2;
                    turnSideClockwise(whiteSide);
                } else if(greenSide[8]=='O') {
                    AUF=3;
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
                turnSideCounterclockwise(redSide);
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
                turnSideClockwise(redSide);
                turnSideClockwise(yellowSide);
                turnSideCounterclockwise(redSide);
                turnSideCounterclockwise(yellowSide);
                turnSideClockwise(redSide);
                if(AUF==1) {
                    turnSideClockwise(whiteSide);
                } else if(AUF==2) {
                    turnSideCounterclockwise(whiteSide);
                } else if(AUF==3) {
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
            } else if(redSide[6]=='W') {
                int AUF=0;
                if(greenSide[8]=='O') {
                    AUF=1;
                    turnSideCounterclockwise(whiteSide);
                } else if(greenSide[8]=='R') {
                    AUF=2;
                    turnSideClockwise(whiteSide);
                } else if(greenSide[8]=='B') {
                    AUF=3;
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
                turnSideCounterclockwise(redSide);
                turnSideCounterclockwise(yellowSide);
                turnSideClockwise(redSide);
                if(AUF==1) {
                    turnSideClockwise(whiteSide);
                } else if(AUF==2) {
                    turnSideCounterclockwise(whiteSide);
                } else if(AUF==3) {
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
            } else if(greenSide[8]=='W') {
                int AUF=0;
                if(redSide[6]=='B') {
                    AUF=1;
                    turnSideClockwise(whiteSide);
                } else if(redSide[6]=='G') {
                    AUF=2;
                    turnSideCounterclockwise(whiteSide);
                } else if(redSide[6]=='O') {
                    AUF=3;
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
                turnSideCounterclockwise(yellowSide);
                turnSideCounterclockwise(redSide);
                turnSideClockwise(yellowSide);
                turnSideClockwise(redSide);
                if(AUF==1) {
                    turnSideCounterclockwise(whiteSide);
                } else if(AUF==2) {
                    turnSideClockwise(whiteSide);
                } else if(AUF==3) {
                    turnSideClockwise(whiteSide);
                    turnSideClockwise(whiteSide);
                }
            }
        } else {
            turnSideClockwise(yellowSide);
            turns++;
        }
    }
}

void Cube::solveCorners() {
    cornerHelper();
    if(whiteSide[0]!='W' || whiteSide[2]!='W' || whiteSide[6]!='W' || whiteSide[8]!='W') {
        if(whiteSide[0]!='W') {
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(yellowSide);
            turnSideClockwise(redSide);
            turnSideClockwise(yellowSide);
            turnSideClockwise(whiteSide);
            turnSideClockwise(whiteSide);
        }
        if(whiteSide[2]!='W') {
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(yellowSide);
            turnSideClockwise(redSide);
            turnSideClockwise(yellowSide);
            turnSideCounterclockwise(whiteSide);
        }
        if(whiteSide[6]!='W') {
            turnSideCounterclockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(yellowSide);
            turnSideClockwise(redSide);
            turnSideClockwise(yellowSide);
            turnSideClockwise(whiteSide);
        }
        if(whiteSide[8]!='W') {
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(yellowSide);
            turnSideClockwise(redSide);
            turnSideClockwise(yellowSide);
        }
    }
    if(whiteSide[0]=='W' && orangeSide[0]!=orangeSide[1]) {
        turnSideClockwise(whiteSide);
        turnSideClockwise(whiteSide);
        turnSideCounterclockwise(redSide);
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(redSide);
        turnSideClockwise(yellowSide);
        turnSideClockwise(whiteSide);
        turnSideClockwise(whiteSide);
    }
    if(whiteSide[2]=='W' && blueSide[0]!=blueSide[1]) {
        turnSideClockwise(whiteSide);
        turnSideCounterclockwise(redSide);
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(redSide);
        turnSideClockwise(yellowSide);
        turnSideCounterclockwise(whiteSide);
    }
    if(whiteSide[6]=='W' && redSide[0]!=redSide[1]) {
        turnSideCounterclockwise(whiteSide);
        turnSideCounterclockwise(redSide);
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(redSide);
        turnSideClockwise(yellowSide);
        turnSideClockwise(whiteSide);
    }
    if(whiteSide[8]=='W' && greenSide[0]!=greenSide[1]) {
        turnSideCounterclockwise(redSide);
        turnSideCounterclockwise(yellowSide);
        turnSideClockwise(redSide);
        turnSideClockwise(yellowSide);
    }
    cornerHelper();
    _moves = _moves + "\n";
}

int Cube::middleLayerHelper() {
    if(greenSide[7]=='R') {
        turnSideCounterclockwise('E');
        turnSideClockwise(whiteSide);
        return 0;
    } else if(greenSide[7]=='B') {
        turnSideClockwise('E');
        turnSideClockwise('E');
        turnSideCounterclockwise(whiteSide);
        turnSideCounterclockwise(whiteSide);
        return 1;
    } else if(greenSide[7]=='O') {
        turnSideClockwise('E');
        turnSideCounterclockwise(whiteSide);
        return 2;
    } else {
        return 3;
    }
}

void Cube::resetMiddleLayer(int theCase) {
    switch (theCase) {
        case 0:
            turnSideClockwise('E');
            turnSideCounterclockwise(whiteSide);
            break;
        case 1:
            turnSideClockwise('E');
            turnSideClockwise('E');
            turnSideCounterclockwise(whiteSide);
            turnSideCounterclockwise(whiteSide);
            break;
        case 2:
            turnSideCounterclockwise('E');
            turnSideClockwise(whiteSide);
            break;
        default:
            break;
    }
}

void Cube::middleLeft() {
    turnSideClockwise('Y');
    turnSideClockwise('O');
    turnSideCounterclockwise('Y');
    turnSideCounterclockwise('O');
    turnSideCounterclockwise('Y');
    turnSideCounterclockwise('G');
    turnSideClockwise('Y');
    turnSideClockwise('G');
}

void Cube::middleRight() {
    turnSideCounterclockwise('Y');
    turnSideCounterclockwise('R');
    turnSideClockwise('Y');
    turnSideClockwise('R');
    turnSideClockwise('Y');
    turnSideClockwise('G');
    turnSideCounterclockwise('Y');
    turnSideCounterclockwise('G');
}

void Cube::solveMiddleLayerEdges() {
    int theCase = 0;
    if(greenSide[5]!='Y' && redSide[3]!='Y') {
        for(int i=0; i<4; i++) {
            if(greenSide[7]=='Y' || yellowSide[1]=='Y') {
                middleRight();
                break;
            } else {
                turnSideClockwise(yellowSide);
            }
        }
    }
    if(redSide[5]!='Y' && blueSide[3]!='Y') {
        turnSideCounterclockwise('E');
        turnSideClockwise(whiteSide);
        for(int i=0; i<4; i++) {
            if(greenSide[7]=='Y' || yellowSide[1]=='Y') {
                middleRight();
                break;
            } else {
                turnSideClockwise(yellowSide);
            }
        }
        turnSideCounterclockwise(whiteSide);
        turnSideClockwise('E');
    }
    if(orangeSide[3]!='Y' && blueSide[5]!='Y') {
        turnSideCounterclockwise('E');
        turnSideClockwise(whiteSide);
        turnSideCounterclockwise('E');
        turnSideClockwise(whiteSide);
        for(int i=0; i<4; i++) {
            if(greenSide[7]=='Y' || yellowSide[1]=='Y') {
                middleRight();
                break;
            } else {
                turnSideClockwise(yellowSide);
            }
        }
        turnSideCounterclockwise(whiteSide);
        turnSideClockwise('E');
        turnSideCounterclockwise(whiteSide);
        turnSideClockwise('E');
    }
    if(greenSide[3]!='Y' && orangeSide[5]!='Y') {
        turnSideCounterclockwise(whiteSide);
        turnSideClockwise('E');
        for(int i=0; i<4; i++) {
            if(greenSide[7]=='Y' || yellowSide[1]=='Y') {
                middleRight();
                break;
            } else {
                turnSideClockwise(yellowSide);
            }
        }
        turnSideCounterclockwise('E');
        turnSideClockwise(whiteSide);
    }
    while(!(blueSide[3]=='B' && redSide[5]=='R') || !(blueSide[5]=='B' && orangeSide[3]=='O') || !(greenSide[3]=='G' && orangeSide[5]=='O') || !(redSide[3]=='R' && greenSide[5]=='G')) {
        if(!(greenSide[7]=='Y' || yellowSide[1]=='Y')) {
            theCase=middleLayerHelper();
            if(yellowSide[1]==orangeSide[4]) {
                middleLeft();
            } else if(yellowSide[1]==redSide[4]) {
                middleRight();
            }
            resetMiddleLayer(theCase);
        } else if(!(redSide[7]=='Y' || yellowSide[5]=='Y') || (blueSide[7]!='Y' && yellowSide[7]!='Y') || (orangeSide[7]!='Y' && yellowSide[3]!='Y')) {
            turnSideClockwise(yellowSide);
        } 
    }
    _moves = _moves + "\n";
}

void Cube::lastLayerCrossAlg() {
    turnSideClockwise(greenSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideCounterclockwise(greenSide);
}

void Cube::orientCrossClockwise() {
    turnSideClockwise(yellowSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
}

void Cube::orientCrossCounterclockwise() {
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(yellowSide);
}

void Cube::solveLastLayerCross() {
    int yellowOnTop=0;
    for(int i=1; i<8; i+=2) {
        if(yellowSide[i]=='Y') {yellowOnTop++;}
    }
    if(yellowOnTop==0) {
        lastLayerCrossAlg();
        lastLayerCrossAlg();
        turnSideClockwise(yellowSide);
        lastLayerCrossAlg();
    } else if(yellowOnTop==2) {
        if(yellowSide[1]=='Y' && yellowSide[7]=='Y') {
            turnSideClockwise(yellowSide);
            lastLayerCrossAlg();
        } else if(yellowSide[3]=='Y' && yellowSide[5]=='Y') {
            lastLayerCrossAlg();
        } else {
            for(int i=0; i<4; i++) {
                if(yellowSide[1]=='Y' && yellowSide[3]=='Y') {
                    lastLayerCrossAlg();
                    turnSideClockwise(yellowSide);
                    lastLayerCrossAlg();
                    break;
                } else {
                    turnSideClockwise(yellowSide);
                }
            }
        }
    }
    int solved=0;
    string theSolved="";
    while(solved!=1) {
        if(solved==4) {
            break;
        }
        solved=0;
        theSolved="";
        turnSideClockwise(yellowSide);
        if(redSide[7]==redSide[4]) {solved++; theSolved=theSolved+"R";}
        if(greenSide[7]==greenSide[4]) {solved++; theSolved=theSolved+"G";}
        if(blueSide[7]==blueSide[4]) {solved++; theSolved=theSolved+"B";}
        if(orangeSide[7]==orangeSide[4]) {solved++; theSolved=theSolved+"O";}
        if(greenSide[7]=='G' && blueSide[7]=='B' && redSide[7]=='O' && orangeSide[7]=='R') {
            turnSideClockwise(redSide);
            turnSideClockwise(redSide);
            turnSideClockwise(orangeSide);
            turnSideClockwise(orangeSide);
            turnSideClockwise(redSide);
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideClockwise(greenSide);
            turnSideClockwise(redSide);
            turnSideClockwise(redSide);
            turnSideCounterclockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(whiteSide);
            turnSideClockwise(redSide);
            turnSideClockwise(whiteSide);
            turnSideCounterclockwise(redSide);
            turnSideCounterclockwise(greenSide);
            turnSideClockwise(redSide);
            turnSideClockwise(redSide);
            turnSideClockwise(orangeSide);
            turnSideClockwise(orangeSide);
            theSolved="";
            break;
        }
    }
    if(theSolved=="R") {
        turnSideCounterclockwise(yellowSide);
        if(orangeSide[7]=='O') {
            orientCrossCounterclockwise();
        } else if(redSide[7]=='O') {
            orientCrossClockwise();
        }
        turnSideClockwise(yellowSide);
    } else if(theSolved=="B") {
        turnSideClockwise(yellowSide);
        turnSideClockwise(yellowSide);
        if(orangeSide[7]=='G') {
            orientCrossCounterclockwise();
        } else if(redSide[7]=='G') {
            orientCrossClockwise();
        }
        turnSideClockwise(yellowSide);
        turnSideClockwise(yellowSide);
    } else if(theSolved=="O") {
        turnSideClockwise(yellowSide);
        if(orangeSide[7]=='R') {
            orientCrossCounterclockwise();
        } else if(redSide[7]=='R') {
            orientCrossClockwise();
        }
        turnSideCounterclockwise(yellowSide);
    } else if(theSolved=="G") {
        if(orangeSide[7]=='B') {
            orientCrossCounterclockwise();
        } else if(redSide[7]=='B') {
            orientCrossClockwise();
        }
    }
    _moves = _moves + "\n";
}

void Cube::rotateLastLayerCorners() {
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideCounterclockwise(redSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(redSide);
    turnSideClockwise(yellowSide);
}

void Cube::isCornerCorrect(int& num, string& solved) {
    if((greenSide[8]=='G' && redSide[6]=='R' && yellowSide[2]=='Y') || (greenSide[8]=='Y' && redSide[6]=='G' && yellowSide[2]=='R') || (greenSide[8]=='R' && redSide[6]=='Y' && yellowSide[2]=='G')) {
        num++;
        solved=solved+"2";
    } 
    if((blueSide[6]=='B' && redSide[8]=='R' && yellowSide[8]=='Y') || (blueSide[6]=='R' && redSide[8]=='Y' && yellowSide[8]=='B') || (blueSide[6]=='Y' && redSide[8]=='B' && yellowSide[8]=='R')) {
        num++;
        solved=solved+"8";
    }
    if((blueSide[8]=='B' && orangeSide[6]=='O' && yellowSide[6]=='Y') || (blueSide[8]=='Y' && orangeSide[6]=='B' && yellowSide[6]=='O') || (blueSide[8]=='O' && orangeSide[6]=='Y' && yellowSide[6]=='B')) {
        num++;
        solved=solved+"6";
    }
    if((greenSide[6]=='G' && orangeSide[8]=='O' && yellowSide[0]=='Y') || (greenSide[6]=='Y' && orangeSide[8]=='G' && yellowSide[0]=='O') || (greenSide[6]=='O' && orangeSide[8]=='Y' && yellowSide[0]=='G')) {
        num++;
        solved=solved+"0";
    }
}

void Cube::lastLayerCornerHelper(int& num, string& solved) {
    if(num==0) {
        rotateLastLayerCorners();
        isCornerCorrect(num, solved);
        if(num==0) {
            rotateLastLayerCorners();
            isCornerCorrect(num, solved);
        } 
    } 
    if(num==1) {
        if(solved=="2") {
            rotateLastLayerCorners();
        } else if(solved=="8") {
            turnSideCounterclockwise(yellowSide);
            rotateLastLayerCorners();
            turnSideClockwise(yellowSide);
        } else if(solved=="6") {
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
            rotateLastLayerCorners();
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
        } else if(solved=="0") {
            turnSideClockwise(yellowSide);
            rotateLastLayerCorners();
            turnSideCounterclockwise(yellowSide);
        }
    }
}

void Cube::orientCornersAlg() {
    turnSideClockwise(orangeSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideClockwise(orangeSide);
    turnSideCounterclockwise(yellowSide);
    turnSideCounterclockwise(orangeSide);
    turnSideCounterclockwise(redSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(redSide);
    turnSideClockwise(yellowSide);
    turnSideCounterclockwise(redSide);
    turnSideClockwise(yellowSide);
    turnSideClockwise(redSide);
}

int Cube::orientCornerHelper(int& num) {
    int theCase=-1;
    if(greenSide[8]=='G' && redSide[6]=='R' && yellowSide[2]=='Y') {
        num++;
        theCase=2;
    } 
    if(blueSide[6]=='B' && redSide[8]=='R' && yellowSide[8]=='Y') {
        num++;
        theCase=8;
    }
    if(blueSide[8]=='B' && orangeSide[6]=='O' && yellowSide[6]=='Y') {
        num++;
        theCase=6;
    }
    if(greenSide[6]=='G' && orangeSide[8]=='O' && yellowSide[0]=='Y') {
        num++;
        theCase=0;
    }
    return theCase;
}

void Cube::solveLastLayerCorners() {
    int num=0;
    string solved="";
    isCornerCorrect(num, solved);
    lastLayerCornerHelper(num, solved);
    num=0;
    solved="";
    isCornerCorrect(num, solved);
    lastLayerCornerHelper(num, solved);
    num=0;
    orientCornerHelper(num);
    if(num==0) {
        if(redSide[6]==redSide[8]) {
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
            orientCornersAlg();
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
        } else if(orangeSide[6]==orangeSide[8]) {
            orientCornersAlg();
        } else if(yellowSide[2]==yellowSide[8]) {
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
            orientCornersAlg();
            orientCornersAlg();
            turnSideClockwise(yellowSide);
            turnSideClockwise(yellowSide);
        } else if(yellowSide[0]==yellowSide[6]) {
            orientCornersAlg();
            orientCornersAlg();
        } else if(greenSide[6]==greenSide[8]) {
            turnSideCounterclockwise(yellowSide);
            orientCornersAlg();
            turnSideClockwise(yellowSide);
        } else if(blueSide[6]==blueSide[8]) {
            turnSideClockwise(yellowSide);
            orientCornersAlg();
            turnSideCounterclockwise(yellowSide);
        } else if(yellowSide[2]==yellowSide[0]) {
            turnSideCounterclockwise(yellowSide);
            orientCornersAlg();
            orientCornersAlg();
            turnSideClockwise(yellowSide);
        } else if(yellowSide[6]==yellowSide[8]) {
            turnSideClockwise(yellowSide);
            orientCornersAlg();
            orientCornersAlg();
            turnSideCounterclockwise(yellowSide);
        }
        num=0;
        orientCornerHelper(num);
    } 
    if(num==1) {
        if((redSide[6]=='Y' && greenSide[6]=='Y') || (orangeSide[6]=='Y' && blueSide[6]=='Y')) {
            num=0;
            int theSolved = orientCornerHelper(num);
            if(theSolved==0) {
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
            } else if(theSolved==2) {
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideCounterclockwise(yellowSide);
            } else if(theSolved==8) {
                orientCornersAlg();
            } else if(theSolved==6) {
                turnSideCounterclockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
            }
        } else if((redSide[8]=='Y' && greenSide[8]=='Y') || (orangeSide[8]=='Y' && blueSide[8]=='Y')) {
            num=0;
            int theSolved = orientCornerHelper(num);
            if(theSolved==0) {
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideCounterclockwise(yellowSide);
            } else if(theSolved==2) {
                orientCornersAlg();
            } else if(theSolved==8) {
                turnSideCounterclockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
            } else if(theSolved==6) {
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
            }
        }
        num=0;
        orientCornerHelper(num);
    }
    bool done=true;
    if(num==2) {
        while(done) {
            done=false;
            if(redSide[6]==redSide[8] && redSide[6]=='Y') {
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
            } else if(yellowSide[2]==yellowSide[8] && yellowSide[2]=='R') {
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                orientCornersAlg();
                turnSideClockwise(yellowSide);
                turnSideClockwise(yellowSide);
            } else if(orangeSide[6]==orangeSide[8] && orangeSide[6]=='Y') {
                orientCornersAlg();
            } else if(yellowSide[0]==yellowSide[6] && yellowSide[0]=='O') {
                orientCornersAlg();
                orientCornersAlg();
            } else if(greenSide[6]==greenSide[8] && greenSide[6]=='Y') {
                turnSideCounterclockwise(yellowSide);
                orientCornersAlg();
                turnSideClockwise(yellowSide);
            } else if(yellowSide[2]==yellowSide[0] && yellowSide[2]=='G') {
                turnSideCounterclockwise(yellowSide);
                orientCornersAlg();
                orientCornersAlg();
                turnSideClockwise(yellowSide);
            } else if(blueSide[6]==blueSide[8] && blueSide[6]=='Y') {
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                turnSideCounterclockwise(yellowSide);
            } else if(yellowSide[6]==yellowSide[8] && yellowSide[6]=='B') {
                turnSideClockwise(yellowSide);
                orientCornersAlg();
                orientCornersAlg();
                turnSideCounterclockwise(yellowSide);
            } else {
                if(greenSide[8]=='Y' || blueSide[8]=='Y') {
                    turnSideClockwise(yellowSide);
                    orientCornersAlg();
                    turnSideClockwise(yellowSide);
                } else if(orangeSide[8]=='Y' || redSide[8]=='Y') {
                    orientCornersAlg();
                } else if(redSide[6]=='Y' || orangeSide[6]=='Y') {
                    orientCornersAlg();
                } else if(blueSide[6]=='Y' || greenSide[6]=='Y') {
                    turnSideClockwise(yellowSide);
                    orientCornersAlg();
                    turnSideClockwise(yellowSide);
                }
            }
        }
    }
    _moves = _moves + "\n";
}


