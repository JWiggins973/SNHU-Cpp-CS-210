/**
 * Jermaine Wiggins
 * Module 3 Projectone
 * Description: Define all functions used in main
 */
#include "ClockAppFunctions.hpp"
#include <iomanip>
#include <string>

using namespace std;

// Global variables for functions
int hours = 0; // Holds hr after set time function called
int minutes = 0; // Holds min after set time function called
int seconds = 0; // Holds sec after set time function called

// Get user input for set time function
void getTime() {
    cout << "Enter hour: ";
    hours = validationbHrs(hours);
    cout << "Enter minutes: ";
    minutes = validateMinsSecs(minutes);
    cout << "Enter seconds: ";
    seconds = validateMinsSecs(seconds);
}

// Input Validation to ensure hrs is a valid number 0 - 23
int validationbHrs(int hr) {
    cin >> hr;
    while (hr > 23) {
        cout << "Please enter an hour value between 0 and 23: ";
        cin >> hr;
    };
    return hr;
} // End validateHrs

// Input Validation to ensure min or seconds is a valid number 0 -60
int validateMinsSecs(int minSec) {
    cin >> minSec;
    while (minSec > 59) {
        cout << "Please enter an value between 0 and 59: ";
        cin >> minSec;
    };
    return minSec;
} // End validateMinsSecs

// Gets user input and validates
void menuInput(char& userInput) {
    
    cout << "Enter a menu selection: ";
    cin >> userInput;
    
    // Switch statement to add one to hr minute or seconds based on user input
        switch(userInput) {
            case '1':
                cout << "You added one hour" << endl;
                increaseHr();
                break;
            case '2':
                cout << "You added one minute" << endl;
                increaseMin();
                break;
            case '3':
                cout << "You added one second" << endl;
               increaseSec();
                break;
            case '4':
                cout << "You are exiting the program" << endl; // Ends program
                break;
            default:
                cout << "Invalid input" << endl;
        } // End switch statement
    
} // End menu Input

// Increases hours by 1 when menu option picked
void increaseHr() {
    hours += 1;
    if (hours > 23) {
        hours = 0;
    }
}

// Increases minutes  by 1 when menu option picked
void increaseMin() {
    minutes += 1;
    if (minutes > 59) {
        minutes = 0;
        increaseHr(); // Call function to handle minutes = 60
    }
}

// Increases seconds by 1 when menu option picked
void increaseSec() {
    
    seconds += 1;
    if (seconds > 59) {
        seconds = 0;
        increaseMin(); // Call function to handle secs = 60
    }
}

// Checks if time should have am or pm
string amPm(int number) {
    // am pm variable to return
    string morningNight = "";
    
    if (number < 12) {
        morningNight = "Am";
    }
    else {
        morningNight = "Pm";
    }
    
    return morningNight;
}

// Adds leading zeros to hours minutes and seconds if less than 10
string leadingZeros(int value) {
    // Leading zeros variable to return
    string newValue = "";
    
    // Adds a leading zero to each value less than 10
    if (value < 10) {
        newValue = "0" + to_string(value);
    }
    else {
        newValue = to_string(value);
    }
    return newValue;
}

// Formats 24hr time uses leading zeros function to store hours minute and sec in a string with correct format
string formatTwentyFourHr(int hr, int min, int sec) {
    // 24hr format variables
    string newHours = leadingZeros(hr); // Holds hours with leading zero if less than 10
    string newMins = leadingZeros(min); // Holds minutes with leading zero if less than 10
    string newSeconds = leadingZeros(sec); // Holds seconds with leading zero if less than 10
    string newTime = newHours + ":" + newMins + ":" + newSeconds; // Holds return value
    
    return newTime;
}

// Formats 24hr time uses leading zeros function to store hours minute and sec in a string with correct format
string formatTwelveHr(int hr, int min, int sec) {
    // 12hr format variables
    string newHours = ""; // Holds hours with leading zero if less than 9
    string newMins = ""; // Holds minutes with leading zero if less than 9
    string newSeconds = ""; // Holds seconds with leading zero if less than 9
    string timeOfDay = ""; // Set eqaul to am pm function
    string newTime = ""; // Holds return value
    int twelveHourFormatHrs = hours; // Hours variable to be converted to
    
    // Converts 24hr format to 12hr
    if (hr > 12) {
        twelveHourFormatHrs = hr - 12;
    }
    else if (hr == 0) {
        twelveHourFormatHrs = 12;
    }
    
    // Adds leading zero to hours minutes and seconds
    newHours = leadingZeros(twelveHourFormatHrs);
    newMins = leadingZeros(min);
    newSeconds = leadingZeros(sec);
    timeOfDay = amPm(hours);
    
    // Store new strings in correct format
    newTime = newHours + ":" + newMins + ":" + newSeconds + " " + timeOfDay;
    
    return newTime;
}


// Function Definitions
void displayMenu() {
    // Display menu Variables
    const int MENU_WIDTH = 26; // Menu border
    const int MENU_HIEGHT = 6; // Menu border
    int i = 0; // Loop varaible
    int j = 0; // Loop variable
    
    // Display menu loop
    for (i = 0; i < MENU_HIEGHT; i++) {
        for (j = 0; j < MENU_WIDTH; j++) {
            if ((i == 0) || (i == MENU_HIEGHT - 1)) {
                // print top and bottom border
                cout << '*';
            }
            // print left and right border
            else if ((j == 0) || (j == MENU_WIDTH - 1)) {
                cout << '*';
            }
            // prints option 1
            else if ((i == 1) && (j == 1)) {
                cout << " 1-Add One Hour";
                j += 14; // skip printed charcters
            }
            // print option 2
            else if ((i == 2) && (j == 1)) {
                cout << " 2-Add One Minute";
                j += 16; // skip printed charcters
            }
            // print option 3
            else if ((i == 3) && (j == 1)) {
                cout << " 3-Add One Second";
                j += 16; // skips printed characters
            }
            // print option 4
            else if ((i == 4) && (j == 1)) {
                cout << " 4-Exit program";
               j += 14; // skips printed characters
            }
            else {
                cout << " ";
            }
        } // inner loop6
        cout << endl; // print newline after each line
    } // outer loop
   
} // End displayMenu

// Prints 12hr and 24hr clocks
void printClock() {
    // Print clock function variables
    int i = 0; // loop variable
    int j = 0; // loop variable
    const int CLOCK_HIEGHT = 4; // Clock height
    const int CLOCK_WIDTH = 26; // Clock width
    const int SPACE_BETWEEN_CLOCKS = 3; // Space between clocks
    const int TWENTY_FOUR_HOUR = 8; // Length of 24hr time string
    const int TWELVE_HOUR = 11; // Length of 12hr time string
    string clockTwelve = "12-HR Clock"; // 24 hr Clock title
    string clockTwentyFour = "24-HR Clock"; // 24hr clock title
    int padding = 0; // Hold padding calculations
    
    // Loop to print clock
    for (i = 0; i < CLOCK_HIEGHT; i++ ) {
        for (j = 0; j < (CLOCK_WIDTH * 2) + SPACE_BETWEEN_CLOCKS; j ++) {
            if ((i == 0) || (i == CLOCK_HIEGHT - 1)) {
                // Prints top and bottom borders
                cout << '*';
                if ((j > CLOCK_WIDTH) && (j < CLOCK_WIDTH + SPACE_BETWEEN_CLOCKS)) {
                    // Prints spaces between clocks
                    cout << ' ';
                }
            }
            else if (i == 1) {
                if ((j == 0) || (j == CLOCK_WIDTH + (SPACE_BETWEEN_CLOCKS / 2))
                    || (j == (CLOCK_WIDTH * 2) + SPACE_BETWEEN_CLOCKS - 1)){
                    // Prints borders
                    cout << '*';
                    
                }
                if (j == 1) {
                    // Prints 12 hr clock title
                    padding = static_cast<int>(CLOCK_WIDTH - clockTwelve.size())/ 2;
                    cout << setw(static_cast<int>(padding + clockTwelve.size())) << clockTwelve;
                    j += clockTwelve.size() + padding - 1; // Skip printed characters
                    
                }
                if (j == CLOCK_WIDTH + SPACE_BETWEEN_CLOCKS) {
                    // Prints 24hr clock title
                    padding = static_cast<int>(CLOCK_WIDTH  - clockTwentyFour.size())/ 2;
                    cout << setw(static_cast<int>(padding + clockTwentyFour.size())) << clockTwentyFour;
                    j += clockTwentyFour.size() + padding; // Skip printed characters
                }
                else {
                    // Prints spaces in rows
                    cout << ' ';
                }
                
            }
            else if (i == 2) {
                if ((j == 0) || (j == CLOCK_WIDTH + (SPACE_BETWEEN_CLOCKS / 2))
                    || (j == (CLOCK_WIDTH * 2)+ SPACE_BETWEEN_CLOCKS - 1)){
                    // Prints borders on second row
                    cout << '*';
                }
                if (j == 1) {
                    // Prints 12 hr time
                    padding = (CLOCK_WIDTH - TWELVE_HOUR) / 2;
                    cout << setw(padding + TWELVE_HOUR ) << formatTwelveHr(hours, minutes, seconds);
                    j += TWELVE_HOUR + padding - 1; // Skip printed characters
                }
                if (j == CLOCK_WIDTH + SPACE_BETWEEN_CLOCKS) {
                    padding = (CLOCK_WIDTH - TWENTY_FOUR_HOUR) / 2;
                    // Prints 24 hr time
                    cout << setw(padding + TWENTY_FOUR_HOUR) << formatTwentyFourHr(hours, minutes, seconds);
                    j += TWENTY_FOUR_HOUR + padding; // Skip printed characters
                    
                }
                else {
                    // Prints spaces in row
                    cout << ' ';
                }
                
            }
            
        } // End inner loop
        cout << endl; // Prints new line with each i++
    } // End outer loop
    
}

