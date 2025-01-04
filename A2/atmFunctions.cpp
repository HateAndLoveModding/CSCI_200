#include <iostream>
#include <iomanip>
#include "atmFunctions.h"
using namespace std;

void start_atm() {
    int dollars = 0, cents = 0;
    bool isUserUsing = true;
    cout << "Welcome to the Infinite ATM!" << endl;
    while(isUserUsing) {
        print_menu();
        char userInput = get_user_selection();
        if(userInput=='1') {
            print_balance(dollars, cents);
        } else if(userInput=='2') {
            deposit_money(dollars, cents);
        } else if(userInput=='3') {
            withdraw_money(dollars, cents);
        } else if(userInput=='Q' or userInput=='4') {
            cout << "Thank you for using the Infinite ATM!" << endl;
            isUserUsing = false;
        } else {
            cout << "It is not clear what you are trying to do." << endl;
        }
    }
}

void print_menu() {
    cout << "Please make a selection:\n(1) Print Current Balance\n(2) Deposit\n(3) Withdraw\n(Q) Quit\n";
}

char get_user_selection() {
    char userInput;
    cout << "Choice: ";
    cin >> userInput;
    return userInput;
}

void print_balance(int dollars, int cents) {
    cout << "You currently have $" << dollars << "." << std::setw(2) << std::setfill('0') << cents << ".\n";
}

int get_dollars(bool isDeposit) {
    int dollars;
    cout << "How many dollars would you like to " << (isDeposit ? "deposit" : "withdraw") << "? ";
    cin >> dollars;
    if (dollars < 0) {
        cout << "Amount cannot be negative." << endl;
        return -1;
    }
    return dollars;
}

int get_cents(int& modDollars, bool isDeposit) {
    int cents;
    cout << "How many cents would you like to " << (isDeposit ? "deposit" : "withdraw") << "? ";
    cin >> cents;
    if (cents < 0) {
        cout << "Cents cannot be negative." << endl;
        return -1;
    }
    modDollars += cents / 100;
    cents %= 100;
    return cents;
}


void update_balance(int& dollars, int& cents, int modDollars, int modCents, bool isDeposit) {
    if (isDeposit) {
        dollars += modDollars;
        cents += modCents;
        if (cents >= 100) {
            dollars += cents / 100;
            cents %= 100;
        }
        cout << "Deposited successfully! New balance: $" << dollars << "." << setw(2) << setfill('0') << cents << ".\n";
    } else {
        int totalCents = dollars * 100 + cents;
        int withdrawalTotalCents = modDollars * 100 + modCents;
        if (withdrawalTotalCents > totalCents) {
            cout << "Insufficient funds.\n";
        } else {
            totalCents -= withdrawalTotalCents;
            dollars = totalCents / 100;
            cents = totalCents % 100;
            cout << "Withdrawal successful! New balance: $" << dollars << "." << setw(2) << setfill('0') << cents << ".\n";
        }
    }
}

void deposit_money(int& dollars, int& cents) {
    int modDollars = get_dollars(true);
    if (modDollars == -1) return;

    int modCents = get_cents(modDollars, true);
    if (modCents == -1) return;

    cout << "You deposited $" << modDollars << "." << setw(2) << setfill('0') << modCents << ".\n";
    update_balance(dollars, cents, modDollars, modCents, true);
}

void withdraw_money(int& dollars, int& cents) {
    int modDollars = get_dollars(false);
    if (modDollars == -1) return;

    int modCents = get_cents(modDollars, false);
    if (modCents == -1) return;

    cout << "You withdrew $" << modDollars << "." << setw(2) << setfill('0') << modCents << ".\n";
    update_balance(dollars, cents, modDollars, modCents, false);
}