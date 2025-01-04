#include <iostream>
#include <cmath>
using namespace std;

string averageAcceration() {
    //#2 Civil Engineering Average Acceleration
    //Define variables
    float initialDistance;
    float finalDistance;
    float initialTime;
    float finalTime;
    double acceleration;
    //Get input from the user about the values
    cout << "What is the initial distance value in meters?" << endl;
    cin >> initialDistance;
    cout << "What is the final distance value in meters?" << endl;
    cin >> finalDistance;
    cout << "What is the initial time value in seconds?" << endl;
    cin >> initialTime;
    cout << "What is the final time value in seconds?" << endl;
    cin >> finalTime;
    //Calculate the acceleration and output the answer
    acceleration = (finalDistance-initialDistance)/pow(finalTime-initialTime, 2);
    return "The acceleration in meters per second is: " + to_string(acceleration) + ".\n";
}

string volume() {
    //#6 Math Volume of a sphere
    //Define variables
    double volume;
    float radius;
    const double pi = M_PI;
    //Get values
    cout << "What is the radius in meters?" << endl;
    cin >> radius;
    //Calculate volume and output answer
    volume = (4*pi*pow(radius, 3))/3;
    return "The volume of a sphere is: " + to_string(volume) + " meters^3.\n";
}

string ohmsLaw() {
    //#3 Electrical Engineering Ohm's Law 
    //Define variables
    double current;
    float resistance;
    float voltage;
    //Get user input
    cout << "What is the resistance?" << endl;
    cin >> resistance;
    cout << "What is the voltage?" << endl;
    cin >> voltage;
    //Calculate current and output answer
    current = voltage/resistance;
    return "The current is: " + to_string(current) + " amps.\n";
}

string universalGravitation() {
    //#4 Engineering Physics Newton's Law of Universal Gravitation
    //Define variables
    double gravitationalForce;
    double gravitationalConstant = pow(6.674, -11);
    double mass1;
    double mass2;
    double radius;
    //Get user input
    cout << "What is the mass of object 1 in kg?" << endl;
    cin >> mass1;
    cout << "What is the mass of object 2? in kg" << endl;
    cin >> mass2;
    cout << "What is the radius between the objects in meters?" << endl;
    cin >> radius;
    //Calculate and output result
    gravitationalForce = gravitationalConstant*mass1*mass2/pow(radius, 2);
    return "The gravitational force between the two objects is: " + to_string(gravitationalForce) + " Newtons.\n";
}

string distance() {
    //#5 Math distance
    //Define variables
    float x;
    float y;
    double distance;
    //Get user input 
    cout << "What is the x value?" << endl;
    cin >> x;
    cout << "What is the y value?" << endl;
    cin >> y;
    //Calculate and output result
    distance = pow(pow(x,2)+pow(y,2), 1/2);
    return "The distance is: " + to_string(distance) + ".\n";
}

string deflection() {
    //#7 Mechanical Engineering Deflection
    //Define variables
    float uniformLoad;
    float length;
    float elasticity;
    float inertia;
    double deflection;
    //Get user input
    cout << "What is the uniform load (w) in N/m?" << endl;
    cin >> uniformLoad;
    cout << "What is the length in meters?" << endl;
    cin >> length;
    cout << "What is the elasticity in N/m^2?" << endl;
    cin >> elasticity;
    cout << "What is the inertia in m^4?" << endl;
    cin >> inertia;
    //Calculate and output result
    deflection = uniformLoad*pow(length,3)/3/elasticity/inertia;
    return "The deflection is: " + to_string(deflection) + " meters.\n";
}

string heatTransfer() {
    //#8 Mechanical Engineering Heat Transfer
    //Define variables
    double rateTransfer;
    float coefficient;
    float surfaceArea;
    float temperatureChange;
    //Get user input
    cout << "What is the coefficient in w/(m^2*k)?" << endl;
    cin >> coefficient;
    cout << "What is the surface area in meters squared?" << endl;
    cin >> surfaceArea;
    cout << "What is the change in temperature in K?" << endl;
    cin >> temperatureChange;
    //Calculate and output result
    rateTransfer = coefficient*surfaceArea*temperatureChange;
    return "The rate of heat transfew in watts is: " + to_string(rateTransfer) + ".\n";
}

string stress() {
    //#9 Mechanical Engineering Stress
    //Define variables
    double stress;
    float force;
    float area;
    //Get user input
    cout << "What is the force in newtons?" << endl;
    cin >> force;
    cout << "What is the area in meters squared?" << endl;
    cin >> area;
    //Calculate and output result
    stress = force/area;
    return "The stress in N/m^2 is: " + to_string(stress) + ".\n";
}

int main() {
    cout << averageAcceration();
    cout << volume();
    cout << ohmsLaw();
    cout << universalGravitation();
    cout << distance();
    cout << deflection();
    cout << heatTransfer();
    cout << stress(); 
}

