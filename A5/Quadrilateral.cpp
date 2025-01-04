#include "Quadrilateral.h"
#include <iostream>
using namespace std;

Quadrilateral::Quadrilateral() {
    numVerticies = 4;
    verticies = new Coordinate[4];
}

// bool Quadrilateral::validate() {
//     return true;
// }