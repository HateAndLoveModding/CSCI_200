#include "Triangle.h"
#include <iostream>
using namespace std;
Triangle::Triangle() {
    numVerticies = 3;
    verticies = new Coordinate[3];
}

// bool Triangle::validate() {
//     return true;
// }