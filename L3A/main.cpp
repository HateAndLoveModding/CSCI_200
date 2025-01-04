/* CSCI 200: A2
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Create an automated ATM.
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("secretMessage.txt");
    ofstream fout("decipheredMessage.txt");
    string text;
    char currentCharacter;
    if(fin.fail()) {
        cerr << "The file could not be opened." << endl;
        return -1;
    }
    if(fout.fail()) {
        cerr << "The file could not be opened." << endl;
        return -1;
    }
    while(fin.get(currentCharacter)) {
        if(currentCharacter=='~') {
            currentCharacter=' ';
        } else if(currentCharacter=='\n') {
            currentCharacter = '\n';
        } else {
            currentCharacter = (char)(currentCharacter+1);
        }
        fout << currentCharacter;
        cout << currentCharacter;
    }
    fin.close();
    fout.close();
    return 0;
}