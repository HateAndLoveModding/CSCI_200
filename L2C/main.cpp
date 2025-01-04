/* CSCI 200: L2C
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Learn how to pass parameters by pointer
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "coordinate_conversion.h"

/**
 * @brief runs our program!
 * @return int result code signalling how our program exited
 */
int main() {
    double xCoordinate, yCoordinate, radius, angle;
    int cartesianOrPolar;
    cout << "Press 0 to convert polar coordinants to cartesian cordinants.\nPress 1 to convert cartesian coordinants to polar coordinants." << endl;
    cin >> cartesianOrPolar;
    if(cartesianOrPolar==0) {
        cout << "Enter the radius value: ";
        cin >> radius;
        cout << "Enter the angle value: ";
        cin >> angle;
        polar_to_cartesian(radius, angle, &xCoordinate, &yCoordinate);
        cout << "The x-coordinate is: " << xCoordinate << " and the y-coordinate is: " << yCoordinate << ".\n";
    } else if(cartesianOrPolar==1) {
        cout << "Enter the x coordinant: ";
        cin >> xCoordinate;
        if(xCoordinate!=0) {
            cout << "Enter the y coordinant: ";
            cin >> yCoordinate;
            cartesian_to_polar(xCoordinate, yCoordinate, &radius, &angle);
            cout << "The radius is: " << radius << " and the angle is: " << angle << ".\n";
        } else {
            cout << "X coordinate cannot be 0." << endl;
        }

    }
    return 0;
}