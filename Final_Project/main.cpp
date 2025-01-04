/* CSCI 200: FP
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Solve a rubik's cube
 */

#include "Cube.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Cube theCube;
    // cout << "Welcome to the program that will solve a Rubik's Cube using the beginner method for humans. Select a number based on what you want to do." << endl;
    // cout << "Press the space bar to perform the next step. Once the cube is solved, press the space bar one more time to exit the program." << endl;
    // theCube.scrambleCube();

    // bool proceedToNextStep = false;
    // bool crossSolved = false, cornersSolved=false, middleLayerSolved=false, lastLayerCrossSolved=false, lastLayerCornersSolved=false;
    // sf::RenderWindow window(sf::VideoMode(1900, 800), "Rubik's Cube Solver");
    // sf::Font font;
    // if (!font.loadFromFile("arial.ttf")) {
    //     std::cerr << "Error loading font\n";
    //     return -1;
    // }
    // sf::Text text;
    // text.setFont(font);
    // text.setString("Press Space to solve the next step.");
    // text.setCharacterSize(18);
    // text.setFillColor(sf::Color::White);
    // text.setPosition(20, 540);

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed) {
    //             window.close();
    //         }
    //         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
    //             proceedToNextStep = true;
    //         }
    //     }
    //     text.setString(theCube.getMoves());
    //     window.clear();
    //     theCube.displayRubiksCube(window);
    //     window.draw(text);
    //     window.display();
    //     if (proceedToNextStep && crossSolved==false) {
    //         theCube.solveCross();
    //         proceedToNextStep = false;
    //         crossSolved=true;
    //     } else if(proceedToNextStep && cornersSolved==false) {
    //         theCube.solveCorners();
    //         proceedToNextStep=false;
    //         cornersSolved=true;
    //     } else if (proceedToNextStep && middleLayerSolved==false) {
    //         theCube.solveMiddleLayerEdges();
    //         middleLayerSolved=true;
    //         proceedToNextStep=false;
    //     } else if(proceedToNextStep && lastLayerCrossSolved==false) {
    //         theCube.solveLastLayerCross();
    //         lastLayerCrossSolved=true;
    //         proceedToNextStep=false;
    //     } else if(proceedToNextStep && lastLayerCornersSolved==false) {
    //         theCube.solveLastLayerCorners();
    //         lastLayerCornersSolved=true;
    //         proceedToNextStep=false;
    //         if(!theCube.isCubeSolved()) {
    //             crossSolved = false, cornersSolved=false, middleLayerSolved=false, lastLayerCrossSolved=false, lastLayerCornersSolved=false;
    //         }
    //     } else if(proceedToNextStep) {
    //         ofstream fout("solution.txt");
    //         if(!fout) {return -1;}
    //         fout << theCube.getMoves();
    //         break;
    //     }
    // }
    for(int i=0; i<100; i++) {
        Cube theCube;
        theCube.scrambleCube();
        theCube.solveCross();
        theCube.solveCorners();
        theCube.solveMiddleLayerEdges();
        theCube.solveLastLayerCross();
        theCube.solveLastLayerCorners();
        if(!theCube.isCubeSolved()) {
            cout << "Failed." << endl;
            cout << i << endl;
            break;
        }
    }
    return 1;
}