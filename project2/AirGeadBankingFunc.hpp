/**
 * Jermaine Wiggins
 * Module 5 Project 2
 * Description: Header file with function declarations
 */

#ifndef AirGeadBankingFunc_hpp
#define AirGeadBankingFunc_hpp

#include <iostream>
#include <iomanip>


using namespace std;

class Banking {
public:
    // Constructors
    Banking();
    Banking(double startingBalance, double montlyDeposit, double interestRate, int numOfYears);
    
    // Setters for starting blance montly deposit and interest rate
    void setStartingBalance(double startingBalance);
    void setMontlyDeposits(double montlyDeposit);
    void setInterestRate(double interestRate);
    void setNumOfYears(int numOfYears);
    
    // Getters for starting blance montly deposit and interest rate
    double getStartingBalance() const;
    double getMonthlyDeposit() const;
    double getInterestRate() const;
    int getYears() const;

private:
    // Variables and is updated through getters and called through getterd
    double startingBalance; // holds starting balnce
    double monthlyDeposit; // holds monthly deposit
    double interestRate; // holds interest rate
    int numOfYears; // holds number of years
};

// Functions
void printMenu();
void getUserInput(Banking& userInfo, Banking& zeroDeposit, char& userInput);
double getNonZeroDouble(double value);
int getNonZeroInt(int num);
double calculateTotal(double openingBalance, Banking userInfo);
double calculateInterest(double openingBalance, Banking userInfo);
void printTable(Banking userInfo);

#endif /* AirGeadBankingFunc_hpp */
