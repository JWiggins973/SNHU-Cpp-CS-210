/**
 * Jermaine Wiggins
 * Module 5 Project 2: Airgead Banking App
 * Description: Program that will calculate year end balances and interest earned with montly contributions
 * and with zero montly contributiuon\s
 */

#include <iostream>
#include <iomanip>
#include "AirGeadBankingFunc.hpp"

using namespace std;

int main() {
    
    // Variables
    Banking newUser; // new Banking object
    Banking zeroDepositUser; // new Banking object for zero deposit
    char userInput = ' '; // user input to control while loop and print tables
    
    // Pring Menu and get user input
    do {
        printMenu();
        getUserInput(newUser, zeroDepositUser, userInput);
        
        if (userInput == 'q') {
            cout << "Exiting Airgead Banking App" << endl;
        }
        
        else {
            //Print tables
            printTable(newUser);
            printTable(zeroDepositUser);
        }
    } while (userInput != 'q');
    
    return 0;
} // End main
