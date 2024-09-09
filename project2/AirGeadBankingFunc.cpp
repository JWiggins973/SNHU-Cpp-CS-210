/**
 * Jermaine Wiggins
 * Module 5 Project two
 * Description: Define all functions used in main
 */

#include <iostream>
#include <iomanip>
#include "AirGeadBankingFunc.hpp"

using namespace std;


// Default Constructor
Banking::Banking(){
    startingBalance = 0.0;
    monthlyDeposit = 0.0;
    interestRate = 0.0;
    numOfYears = 0;
}
    
// Detailed Constructor
Banking::Banking(double startingBalance, double montlyDeposit, double interestRate, int numOfYears){
    this -> startingBalance = startingBalance;
    this -> monthlyDeposit = montlyDeposit;
    this -> interestRate = interestRate;
    this -> numOfYears = numOfYears ;
}
    
// Getters to get starting balancr montly deposit interest rate and years
double Banking::getStartingBalance() const{
    return startingBalance;
}
double Banking::getMonthlyDeposit() const {
    return monthlyDeposit;
}
double Banking::getInterestRate() const {
    return interestRate;
}
int Banking::getYears() const {
    return numOfYears;
}
    
// Setters to set starting balancr montly deposit interest rate and years
void Banking::setStartingBalance(double startingBalance) {
    this -> startingBalance = startingBalance;
}
void Banking::setMontlyDeposits(double montlyDeposit) {
    this -> monthlyDeposit = montlyDeposit;
}
void Banking::setInterestRate(double interestRate) {
    this -> interestRate = interestRate;
}
void Banking::setNumOfYears(int numOfYears) {
    this -> numOfYears = numOfYears;
}
    

// Prints menu title
void printMenu() {
    // Variable
    const int BORDER_HEIGHT = 2; // border height
    const int BORDER_LENGTH = 33; // border length
    char menuBorder = '-'; //  menu border
    string appName = "Airgead Banking"; // app name
    int i = 0; // loop variable
    int j = 0; // loop varaible
    
    for (i = 0; i < BORDER_HEIGHT; i++ ) {
        for (j = 0; j < BORDER_LENGTH; j++) {
            
            // Prints top border
            if (i == 0) {
            cout << menuBorder;
            }
            
            // Prints side borders
            else if (j < 9 or j > 21) {
                cout << menuBorder;
            }
            
            // Print app name
            else {
                cout << appName;
                j += 14; // skips characters in app name
            }
            
        } // End inner loop
        
        // Print new line
        cout << endl;
    } // End outer loop
}// End PrintMenu

// Get user input for private variables
void getUserInput(Banking& userInfo, Banking& zeroDeposit, char& userInput) {
    // Variable to set values in class
    double startingBalance = 0.0;
    double montlyDesposits = 0.0;
    double interest = 0.0;
    int yr = 0;
    
    // Gets user input for starting balnce montly deposits interest and yrs
    cout << "Enter starting balance: ";
    startingBalance = getNonZeroDouble(startingBalance);
    userInfo.setStartingBalance(startingBalance);
    zeroDeposit.setStartingBalance(startingBalance);
    
    // Gets user input for montly deposits
    cout << "Enter montly desposits: ";
    montlyDesposits = getNonZeroDouble(montlyDesposits);
    userInfo.setMontlyDeposits(montlyDesposits);
    zeroDeposit.setMontlyDeposits(0.0);
    
    // Gets user input for interest rate
    cout << "Enter interest rate: ";
    interest = getNonZeroDouble(interest);
    userInfo.setInterestRate(interest);
    zeroDeposit.setInterestRate(interest);
    
    // Gets user input for years
    cout << "Enter total years: ";
    yr = getNonZeroInt(yr);
    userInfo.setNumOfYears(yr);
    zeroDeposit.setNumOfYears(yr);
    
    // Continue on key press while not q
    cout << "Press q to quit or any other character to get report: ";
    cin >> userInput; // updates input in main pass by reference to controlm while loop
    cout << endl;
    //cin.ignore();
    //cin.get();
    //cout << endl;
} // End getUserInput

// Input Validation to ensure non zero and valid type
double getNonZeroDouble(double value) {
    cin >> value;
    while (value <= 0 || cin.fail()) {
        // Handles cin if not number
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid input please eneter a double: ";
            cin >> value;
        }
        // Handles cin if less than or equal to zero
        else if ( value <= 0) {
            cout << "Please enter a positive double: ";
            cin >> value;
        }
    }
    
    return value;
} // End getNonZeroDouble

// Input Validation to ensure non zero and valid type
int getNonZeroInt(int num) {
    cin >> num;
    while (num <= 0 || cin.fail()) {
        // Handles cin if not number
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input please eneter a double: ";
            cin >> num;
        }
        // Handles cin if less than or equal to zero
        else if (num <= 0){
            cout << "Please enter a positive double; ";
            cin >> num;
        }
    }
    return num;
} // End getNonZeroInt

// Calculate total montly deposit and opeing balance
double calculateTotal(double openingBalance, Banking userInfo) {
    double total = 0.0;
    
    return total = openingBalance + userInfo.getMonthlyDeposit();
} // End calculateTotal

// Calculate total interest earned
double calculateInterest(double openingBalance, Banking userInfo) {
    double totalInterest = 0.0;
    return totalInterest = calculateTotal(openingBalance, userInfo) * ((userInfo.getInterestRate()/100)/12);
} // End calculateInterest

// Print table
void printTable(Banking userInfo) {
    // Variables
    const int MONTHS_IN_YEAR = 12;
    const int TABLE_WIDTH = 50; // width of table
    int i = 0; // loop variable
    int j = 0; // loop variable
    char tableBorder = '-'; // char to print table
    double openingAmount = userInfo.getStartingBalance(); //  set opening balace to class initial investment value
    double closingAmount = 0.0; // holds closing amount variable
    double interestEarned = 0.0;
    
    
    // Print table header borders
    cout  << setw(28) << "Balance and Intrest With $" << fixed << setprecision(2)<< userInfo.getMonthlyDeposit() << " Montly Deposits";
    cout << endl;
    for (i = 0; i < TABLE_WIDTH; i++ ){
        cout << tableBorder;
    }
    cout << endl;
    
    // Print table columns
    cout << setw(10) << "Years";
    cout << setw(20) << "EOY Balance";
    cout << setw(20) << "EOY Interest";
    cout << endl;
    
    // Print table lines
    for (i = 0; i < TABLE_WIDTH; i++ ){
        cout << tableBorder;
    }
    cout << endl;
    
    // Print contents of table
    for (i = 0; i < userInfo.getYears(); i++) {
        cout << setw(5) << i + 1;
        
        // Inner loop to calculate monthly interet and all 12 closing montly values per yr
        for (j = 0; j < MONTHS_IN_YEAR; j++) {
            // Calculate variables for end of year (EOY) values
            closingAmount = calculateTotal(openingAmount, userInfo) + calculateInterest(openingAmount, userInfo); // calculates total with interst earned
            interestEarned += calculateInterest(openingAmount, userInfo); // calculates monthly interest earned
            openingAmount = closingAmount; // sets opening amount to closing to update each month
        }
        
        // Print values
        cout << fixed << setprecision(2) << setw(20) << closingAmount;
        cout << fixed << setprecision(2) << setw(20) << interestEarned;
        
        // Print new row
        cout << endl;
    }
    
    // Print newline between tables
    cout << endl;
    cout << endl;
    
} // End Print table

