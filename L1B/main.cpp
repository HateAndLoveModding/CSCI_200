#include <cfloat>
#include <chrono>
#include <iostream>
#include <random>
using namespace std;

int main() {
    //Define variables for minimum and maximum
    float minimum;
    float maximum;
    char playing = 'Y';
    //Get user input for minimum and maximum values
    cout << "Enter the minimum value: ";
    cin >> minimum;
    cout << "Enter the maximum value: ";
    cin >> maximum;
    //Check if minimum is greater than maximum and if it is, exit programm
    if (minimum > maximum) {exit(0);}
    do {
        //Generate random number and set it equal to variable
        mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_real_distribution<float> floatDistr(minimum, nextafter(maximum, numeric_limits<float>::max()));
        float randomNumber = floatDistr(mt);
        //Define quartile ranges
        float range = maximum - minimum;
        float quartile = range/4;
        //Output random number
        cout << "The random number is: " << randomNumber << endl;
        //Check what quartile the random number is in
        if (randomNumber <= (minimum+quartile)) {
            cout << "The random number is in the first quartile." << endl;
        } else if (randomNumber <= (minimum+quartile*2)) {
            cout << "The random number is in the second quartile." << endl;
        } else if (randomNumber <= (minimum+quartile*3)) {
            cout << "The random number is in the third quartile." << endl;
        } else {
            cout << "The random number is in the fourth quartile." << endl;
        }
        //Ask the user whether they want to generate another random number
        cout << "Do you want another random value? (Y/N) ";
        cin >> playing;
    } 
    //If user input is Y then loop again and if input is N then exit loop
    while (playing == 'Y');
    //Have a nice day.
    cout << "Have a nice day!" << endl;
    return 0;
}