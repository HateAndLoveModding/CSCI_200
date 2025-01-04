#include "maze.h"
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

maze::maze(string filename) {
    _filename = filename;
}

void maze::BFS(int cellSize) {
    queue<position> queue;
    queue.push(_start);
    vector<vector<bool>> visited(_size.x, vector<bool>(_size.y, false));
    vector<vector<position>> parent(_size.x, vector<position>(_size.y, {-1, -1}));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    RenderWindow window(VideoMode(cellSize * _size.x, cellSize * _size.y), "BFS Visualization");
    bool found = false;
    position endPos = {-1, -1};
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (!queue.empty() && !found) {
            position current = queue.front();
            queue.pop();
            if (visited[current.x][current.y]) continue;
            visited[current.x][current.y] = true;
            if (_maze[current.x][current.y] == 'E') {
                found = true;
                endPos = current;
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if (nx >= 0 && nx < _size.x && ny >= 0 && ny < _size.y &&
                    (_maze[nx][ny] == '.' || _maze[nx][ny] == 'E') &&
                    !visited[nx][ny]) {
                    queue.push({nx, ny});
                    parent[nx][ny] = current;
                }
            }
        } 
        window.clear();
        for (int i = 0; i < _size.y; ++i) {
            for (int j = 0; j < _size.x; ++j) {
                RectangleShape cell(Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                if (_maze[j][i] == '#') cell.setFillColor(Color::Black);
                else if (_maze[j][i] == 'S') cell.setFillColor(Color::Green);
                else if (_maze[j][i] == 'E') cell.setFillColor(Color::Red);
                else if (visited[j][i]) cell.setFillColor(Color::Magenta);
                else cell.setFillColor(Color::White);
                window.draw(cell);
            }
        }
        if (queue.empty() && !found) {
            window.display();
            cout << "Maze could not be completed." << endl;
            sleep(milliseconds(2000));
            window.close();
            break;
        }
        std::queue<position> tempQueue = queue;
        while (!tempQueue.empty()) {
            position pos = tempQueue.front();
            tempQueue.pop();
            if (_maze[pos.x][pos.y] != 'S' && _maze[pos.x][pos.y] != 'E') {
                RectangleShape cell(Vector2f(cellSize, cellSize));
                cell.setPosition(pos.x * cellSize, pos.y * cellSize);
                cell.setFillColor(Color::Blue);
                window.draw(cell);
            }
        }
        if (found) {
            position current = endPos;
            while (current != _start) {
                if (_maze[current.x][current.y] != 'S' && _maze[current.x][current.y] != 'E') {
                    RectangleShape cell(Vector2f(cellSize, cellSize));
                    cell.setPosition(current.x * cellSize, current.y * cellSize);
                    cell.setFillColor(Color::Yellow);
                    window.draw(cell);
                    window.display();
                    sleep(milliseconds(120));
                }
                current = parent[current.x][current.y];
            }
            sleep(milliseconds(2000));
            break;
        }
        window.display();
        sleep(milliseconds(120));
    }
}

bool maze::loadMaze() {
    ifstream file(_filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << _filename << endl;
        return false;
    }
    int rows, cols;
    file >> rows >> cols;
    _size.x = cols;
    _size.y = rows;
    _maze = new char*[cols];
    for (int i = 0; i < cols; i++) {
        _maze[i] = new char[rows];
    }
    bool foundStart = false, foundEnd = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> _maze[j][i];
            if (_maze[j][i] == 'S') {
                _start.x = j;
                _start.y = i;
                foundStart = true;
            } else if (_maze[j][i] == 'E') {
                _end.x = j;
                _end.y = i;
                foundEnd = true;
            }
        }
    }

    if (!foundStart || !foundEnd) {
        cerr << "Error: Maze must contain exactly one 'S' and one 'E'." << endl;
        return false;
    }

    return true;
}

void maze::DFS(int cellSize) {
    int rows = _size.y;
    int cols = _size.x;
    RenderWindow window(VideoMode(cellSize * cols, cellSize * rows), "Maze Visualization");
    stack<position> stack;
    stack.push(_start);
    int x = _start.x, y = _start.y;
    position temp;
    vector<vector<bool>> visited(cols, vector<bool>(rows, false));
    vector<vector<position>> parent(cols, vector<position>(rows, {-1, -1}));
    vector<vector<bool>> potential(cols, vector<bool>(rows, false));
    bool foundE = false;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed || 
                (event.type == Event::KeyPressed && 
                 (event.key.code == Keyboard::Q || event.key.code == Keyboard::Escape))) {
                window.close();
                break;
            }
        }
        window.clear();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                RectangleShape cell(Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                if (_maze[j][i] == '#') {
                    cell.setFillColor(Color::Black);
                } else if (_maze[j][i] == 'S') {
                    cell.setFillColor(Color::Green);
                } else if (_maze[j][i] == 'E') {
                    cell.setFillColor(Color::Red);
                } else if (visited[j][i]) {
                    cell.setFillColor(Color::Magenta);
                } else if (potential[j][i]) {
                    cell.setFillColor(Color::Blue);
                } else {
                    cell.setFillColor(Color::White);
                }
                window.draw(cell);
            }
        }
        if (!stack.empty() && !foundE) {
            x = stack.top().x;
            y = stack.top().y;
            stack.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            potential[x][y] = false;
            if (_maze[x][y] == 'E') {
                cout << "End reached at (" << x << ", " << y << ")" << endl;
                temp = {x, y};
                foundE = true;
                continue;
            } else {
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < cols && ny >= 0 && ny < rows &&
                        (_maze[nx][ny] == '.' || _maze[nx][ny] == 'E') &&
                        !visited[nx][ny]) {
                        temp.x = nx;
                        temp.y = ny;
                        stack.push(temp);
                        if (parent[nx][ny].x == -1 && parent[nx][ny].y == -1) {
                            parent[nx][ny] = {x, y};
                        }
                        potential[nx][ny] = true;
                    }
                }
            }
        } else if (!foundE) {
            window.display();
            cout << "Maze could not be completed." << endl;
            sleep(milliseconds(2000));
            window.close();
        }
        if (foundE) {
            position current = temp;
            while (current != _start) {
                if (_maze[current.x][current.y] != 'E' && _maze[current.x][current.y] != 'S') {
                    RectangleShape cell(Vector2f(cellSize, cellSize));
                    cell.setPosition(current.x * cellSize, current.y * cellSize);
                    cell.setFillColor(Color::Yellow);
                    window.draw(cell);
                    window.display();
                    sleep(milliseconds(70));
                }
                current = parent[current.x][current.y];
            }
            sleep(milliseconds(2000));
            break;
        }
        window.display();
        sleep(milliseconds(70));
        if (foundE && stack.empty()) {
            break;
        }
    }
}

