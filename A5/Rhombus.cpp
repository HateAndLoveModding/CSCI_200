#include "Rhombus.h"
#include <cmath>
#include <iostream>
using namespace std;

bool Rhombus::validate() {
    const double TOLERANCE = 1e-4;
    double length1 = sqrt(pow(verticies[0]._x - verticies[1]._x, 2) + pow(verticies[0]._y - verticies[1]._y, 2));
    double length2 = sqrt(pow(verticies[2]._x - verticies[1]._x, 2) + pow(verticies[2]._y - verticies[1]._y, 2));
    double length3 = sqrt(pow(verticies[0]._x - verticies[2]._x, 2) + pow(verticies[0]._y - verticies[2]._y, 2));
    
    double length4 = sqrt(pow(verticies[0]._x - verticies[2]._x, 2) + pow(verticies[0]._y - verticies[2]._y, 2));
    double length5 = sqrt(pow(verticies[3]._x - verticies[2]._x, 2) + pow(verticies[3]._y - verticies[2]._y, 2));
    double length6 = sqrt(pow(verticies[0]._x - verticies[3]._x, 2) + pow(verticies[0]._y - verticies[3]._y, 2));
    if(abs(length1-length2)<TOLERANCE || abs(length3-length2)<TOLERANCE || abs(length1-length3)<TOLERANCE) {
        if(abs(length4-length5)<TOLERANCE || abs(length6-length5)<TOLERANCE || abs(length4-length6)<TOLERANCE) {
            if(abs(length1-length2)<TOLERANCE && abs(length2-length5)<TOLERANCE && abs(length5-length6)<TOLERANCE && abs(length6-length1)<TOLERANCE) {
                return true;
            }
        }
    }
    return false;
};