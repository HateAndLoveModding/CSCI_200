/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 */

#include <chrono>
#include <iostream>
#include <random>
using namespace std;

//Function to randomly generate a number from 0 to 4 and convert that number to a letter corresponding to rock, paper, scissors, lizard, or spock
char computerChoice() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistr(0, 4);
    int choice = intDistr(mt);
    if(choice==0) {
        return 'P';
    } else if(choice==1) {
        return 'S';
    } else if(choice==2) {
        return 'R';
    } else if(choice==3) {
        return 'L';
    } else if(choice==4) {
        return 'K';
    }
    return '0';
}

//A function to determine what things beat what
int winner(char choice1, char choice2) {
    if(choice1=='R' || choice2=='R') {
        if(choice1=='L' || choice2=='L') {
            cout << "Rock beats Lizard." << endl;
        } else if(choice1=='S' || choice2=='S') {
            cout << "Rock beats Scissors." << endl;
        }
    } if(choice1=='L' || choice2=='L') {
        if(choice1=='K' || choice2=='K') {
            cout << "Lizard beats Spock." << endl;
        } else if(choice1=='P' || choice2=='P') {
            cout << "Lizard beats Paper." << endl;
        }
    } if(choice1=='K' || choice2=='K') {
        if(choice1=='S' || choice2=='S') {
            cout << "Spock beats Scissors." << endl;
        } else if(choice1=='R' || choice2=='R') {
            cout << "Spock beats Rock." << endl;
        }
    } if(choice1=='S' || choice2=='S') {
        if(choice1=='L' || choice2=='L') {
            cout << "Scissors beats Lizard." << endl;
        } else if(choice1=='P' || choice2=='P') {
            cout << "Scissors beats Paper." << endl;
        }
    } if(choice1=='P' || choice2=='P') {
        if(choice1=='R' || choice2=='R') {
            cout << "Paper beats Rock." << endl;
        } else if(choice1=='K' || choice2=='K') {
            cout << "Paper beats Spock." << endl;
        }
    } if(choice1==choice2) {
        cout << "It's a tie!" << endl;
    }
    return 1;
}

int main() {
    char theComputerChoice = '0';
    char thePlayerChoice = '0';
    int won = 0;
    int lost = 0;
    int tied = 0;
    char playing = 'Y';
    cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << endl;

    while(playing=='Y' || playing=='y') {
        //Get user input and convert to uppercase
        cout << endl << "Press P for Paper, S for Scissors, R for Rock, L for Lizard, and K for Spock.\nPlayer one: ";
        cin >> thePlayerChoice;

        //Output the player choice
        if(thePlayerChoice=='S' || thePlayerChoice=='s') {
            thePlayerChoice = 'S';
            cout << endl << "You chose Scissors!" << endl;
        } else if(thePlayerChoice=='P' || thePlayerChoice=='p') {
            thePlayerChoice = 'P';
            cout << endl << "You chose Paper!" << endl;
        } else if(thePlayerChoice=='R' || thePlayerChoice=='r') {
            thePlayerChoice = 'R';
            cout << endl << "You chose Rock!" << endl;
        } else if(thePlayerChoice=='K' || thePlayerChoice=='k') {
            thePlayerChoice = 'K';
            cout << endl << "You chose Spock!" << endl;
        } else if(thePlayerChoice=='L' || thePlayerChoice=='l') {
            thePlayerChoice = 'L';
            cout << endl << "You chose Lizard" << endl;
        }

        theComputerChoice = computerChoice();

        //Output computer choice
        if(theComputerChoice=='S') {
            cout << "The computer chose Scissors!" << endl << endl;
        } else if(theComputerChoice=='P') {
            cout << "The computer chose Paper!" << endl << endl;
        } else if(theComputerChoice=='R') {
            cout << "The computer chose Rock!" << endl << endl;
        } else if(theComputerChoice=='K') {
            cout << "The computer chose Spock!" << endl << endl;
        } else if(theComputerChoice=='L') {
            cout << "The computer chose Lizard" << endl << endl;
        }

        winner(thePlayerChoice, theComputerChoice);

        //Determine winner and update points
        if((theComputerChoice=='S' && (thePlayerChoice=='P' || thePlayerChoice=='L')) ||
        (theComputerChoice=='P' && (thePlayerChoice=='R' || thePlayerChoice=='K')) || 
        (theComputerChoice=='R' && (thePlayerChoice=='S' || thePlayerChoice=='L')) ||
        (theComputerChoice=='L' && (thePlayerChoice=='P' || thePlayerChoice=='K')) ||
        (theComputerChoice=='K' && (thePlayerChoice=='S' || thePlayerChoice=='R'))) {
            lost+=1;
            cout << "The computer wins!" << endl;
        } else if ((thePlayerChoice=='S' && (theComputerChoice=='P' || theComputerChoice=='L')) ||
        (thePlayerChoice=='P' && (theComputerChoice=='R' || theComputerChoice=='K')) || 
        (thePlayerChoice=='R' && (theComputerChoice=='S' || theComputerChoice=='L')) ||
        (thePlayerChoice=='L' && (theComputerChoice=='P' || theComputerChoice=='K')) ||
        (thePlayerChoice=='K' && (theComputerChoice=='S' || theComputerChoice=='R'))) {
            won+=1;
            cout << "You won!" << endl;
        } else if(thePlayerChoice==theComputerChoice) {
            tied++;
        }
        //Get user input if they want to keep playing.
        cout << endl << "Do you want to keep playing? (Y/N): ";
        cin >> playing;
    }
    
    //Output score
    cout << "You won " << won << " games, lost " << lost << " games, and tied " << tied << " games." << endl;
    return 0;
}