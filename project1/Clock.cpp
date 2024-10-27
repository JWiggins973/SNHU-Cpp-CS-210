/**
 * Jermaine Wiggins
 * Module 3 Projectone
 * Description: Get time from user then dispalys time in 12hr format and 24hr format
 * allow user to update time and dispaly both times side by side in terminal
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "ClockAppFunctions.hpp"

using namespace std

int main() {
    // Variables
    char userInput = ' '; // Stores userInput for menu options and used for while loop
    
    // Get user input for set time function
    getTime();
    
    // Menu loop
    do {
        displayMenu(); // Calls menu function
        menuInput(userInput); // Gets menu input and validates user input
        
        if (userInput != '4') {
            // Print clock if user input isnt 4
            printClock();
        } // Ends if
        
    }while (userInput != '4'); // End do while loop when user input is 4
    
    return 0;
}
