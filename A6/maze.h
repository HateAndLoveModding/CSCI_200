#ifndef MAZE
#define MAZE
#include <string>

class maze {
    private:
    struct position {
        int x, y;
        bool operator==(const position& other) const {
            return x == other.x && y == other.y;
        }

        // Inequality operator
        bool operator!=(const position& other) const {
            return !(*this == other);
        }
        bool operator<(const position& other) const {
            if (x != other.x)
                return x < other.x; // Compare x first
            return y < other.y;     // Compare y if x is equal
        }
    };
    char** _maze;
    position _start;
    position _end;
    position _size;
    std::string _filename;

    public:
    maze(std::string);
    void DFS(int);
    void BFS(int);
    bool loadMaze();
};

#endif