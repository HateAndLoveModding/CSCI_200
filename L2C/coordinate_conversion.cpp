#include "coordinate_conversion.h"

#include <cmath>
#include <iostream>
using namespace std;

void polar_to_cartesian(double radius, double angle, double* xCoordinate, double* yCoordinate) {
    *xCoordinate = radius*cos(angle);
    *yCoordinate = radius*sin(angle);
}

void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle) {
    *radius = pow(pow(xCoordinate, 2) + pow(yCoordinate, 2), 0.5);
    *angle = atan(yCoordinate/xCoordinate);
}