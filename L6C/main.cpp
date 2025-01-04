/* CSCI 200: L6C
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Draw a maze
 */

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string filename;
    if (argc > 1) {
        filename = argv[1];
    } else {
        cout << "Enter maze file name: ";
        cin >> filename;
    }
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
    }
    int rows, cols, cellSize=15;
    file >> rows >> cols;
    file.ignore();
    char** maze = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        maze[i]=new char[cols];
        for(int j=0; j<cols; j++) {
            file>>maze[i][j];
        }
    }
    sf::RenderWindow window(sf::VideoMode(cellSize * cols, cellSize * rows), "Maze Visualization");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);

                switch (maze[i][j]) {
                    case '#':
                        cell.setFillColor(sf::Color::Black);
                        break;
                    case '.':
                        cell.setFillColor(sf::Color::White);
                        break;
                    case 'S':
                        cell.setFillColor(sf::Color::Green);
                        break;
                    case 'E':
                        cell.setFillColor(sf::Color::Red);
                        break;
                }
                window.draw(cell);
            }
        }
        window.display();
    }
    return 0;
}
