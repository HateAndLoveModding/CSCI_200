#include "IsoscelesTriangle.h"
#include <iostream>
#include <cmath>
using namespace std;

bool IsoscelesTriangle::validate() {
    const double TOLERANCE = 1e-6;
    double length1 = sqrt(pow(verticies[0]._x - verticies[1]._x, 2) + pow(verticies[0]._y - verticies[1]._y, 2));
    double length2 = sqrt(pow(verticies[2]._x - verticies[1]._x, 2) + pow(verticies[2]._y - verticies[1]._y, 2));
    double length3 = sqrt(pow(verticies[0]._x - verticies[2]._x, 2) + pow(verticies[0]._y - verticies[2]._y, 2));
    if(abs(length1-length2)<TOLERANCE || abs(length3-length2)<TOLERANCE || abs(length1-length3)<TOLERANCE) {
        return true;
    } else {
        return false;
    }
};