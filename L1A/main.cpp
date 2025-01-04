#include <cmath>
#include <iostream>
using namespace std;

string averageAcceration() {
    //#2 Civil Engineering Average Acceleration
    //Define variables
    cout << "Eqation #2 Civil Engineering Average Acceleration" << endl;
    float initialDistance;
    float finalDistance;
    float initialTime;
    float finalTime;
    double acceleration;
    //Get input from the user about the values
    cout << "What is the initial distance value in meters? ";
    cin >> initialDistance;
    cout << "What is the final distance value in meters? ";
    cin >> finalDistance;
    cout << "What is the initial time value in seconds? ";
    cin >> initialTime;
    cout << "What is the final time value in seconds? ";
    cin >> finalTime;
    //Calculate the acceleration and output the answer
    acceleration = (finalDistance-initialDistance)/pow(finalTime-initialTime, 2);
    return "The acceleration in meters per second is: " + to_string(acceleration) + ".\n\n";
}

string universalGravitation() {
    //#4 Engineering Physics Newton's Law of Universal Gravitation
    //Define variables
    cout << "Equation #4 Engineering Physics Newton's Law of Universal Gravitation" << endl;
    double gravitationalForce;
    const double GRAVITATIONAL_CONSTANT = pow(6.674, -11);
    double mass1;
    double mass2;
    double radius;
    //Get user input
    cout << "What is the mass of object 1 in kg? ";
    cin >> mass1;
    cout << "What is the mass of object 2? in kg? ";
    cin >> mass2;
    cout << "What is the radius between the objects in meters? ";
    cin >> radius;
    //Calculate and output result
    gravitationalForce = GRAVITATIONAL_CONSTANT*mass1*mass2/pow(radius, 2);
    return "The gravitational force between the two objects is: " + to_string(gravitationalForce) + " Newtons.\n";
}


int main() {
    cout << averageAcceration();
    cout << universalGravitation();
}

