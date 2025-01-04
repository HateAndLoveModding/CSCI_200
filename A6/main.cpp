/* CSCI 200: A6
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Implement BFS and DFS to solve a maze.
 */

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "maze.h"
using namespace std;

int main(int argc, char* argv[]) {
    string filename;
    if (argc > 1) {
        filename = argv[1];
    } else {
        cout << "Enter maze file name: ";
        cin >> filename;
    }
    maze theMaze(filename);

    if(!theMaze.loadMaze()) {
        return 1;
    }
    bool bfsOrDfs = true;
    cout << "Press 1 for DFS and 0 for BFS." << endl;
    cin >> bfsOrDfs;
    if(bfsOrDfs) {
        theMaze.DFS(25);
    } else {
        theMaze.BFS(25);
    }

    return 0;
}
