/**
 * Jermaine Wiggins
 * Module 3 Projectone
 * Description: Header file with function declarations
 */

#ifndef ClockAppFunctions_hpp
#define ClockAppFunctions_hpp

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function declarations
void getTime();
int validationbHrs(int hr);
int validateMinsSecs(int minSec);
void menuInput(char& userInput);
void increaseHr();
void increaseMin();
void increaseSec();
string amPm(int number);
string leadingZeros(int value);
string formatTwentyFourHr(int hr, int min, int sec);
string formatTwelveHr(int hr, int min, int sec);
void displayMenu();
void printClock();



#endif /* ClockAppFunctions_hpp */
