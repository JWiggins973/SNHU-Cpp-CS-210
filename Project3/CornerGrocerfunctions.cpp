/**
 * Jermaine Wiggins
 * Module 7 Project 3: Corner Grocers App
 * Description: File with function definition
 */


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <stdexcept>
#include "CornerGrocerfunctions.hpp"

using namespace std;

void openFiles(ifstream& inputFile, const string& INFILE, ofstream& outputFile, const string& OUTFILE) {
    
    // Open file if unsuccessful exit and print error message
    inputFile.open(INFILE);
    if (!inputFile.is_open()) {
        cerr << "Error opening " << INFILE << endl;
        inputFile.close();
        exit(1);
    }
    
    // Open file if unsuccessful exit and print error message
    outputFile.open(OUTFILE);
    if (!outputFile.is_open()) {
        cerr << "Error opening " << OUTFILE << endl;
        outputFile.close();
        exit(1);
    }
} // end openFiles

void copyToNewFile(ifstream& inputFile, ofstream& outputFile, GroceryItem& produce) {
    
    string groceryItemName = ""; // hold read file name
    
    // Copys original file to temp variable and creates key in map
    while(inputFile >> groceryItemName) {
        produce.addItem(groceryItemName);
    }
    
    // Error handling
    if (inputFile.fail() && !inputFile.eof()) {
        cerr << "Error reading from file." << endl;
        inputFile.close();
        outputFile.close();
        exit(1); // Exiting with an error code
        }
    
    // Copies from map to new .dat file
    for (const auto& item : produce.GroceryList) {
        outputFile << item.first << " " << item.second << endl;
        }
    
    // Close input and outputfiles
    inputFile.close();
    outputFile.close();
} // end copyToNewFile

void printMenu() {
    // Variables
    const int BORDER_LENGTH = 35; // length of borders
    const char BORDER_CHAR = '*'; // char used to print border
    const string MENU_NAME = "Corner Grocers Menu"; // app name
    string border(BORDER_LENGTH, BORDER_CHAR); // string to print border
    
    
    // Print Menu
    cout << border << endl;
    cout << setw(BORDER_LENGTH - static_cast<int>(MENU_NAME.size()) / 2) << MENU_NAME << endl;
    cout << border << endl;
    cout << "Press 1 for item frequency" << endl;
    cout << "Press 2 for item name and frequency" << endl;
    cout << "Press 3 for histogram" << endl;
    cout << "Press 4 to exit" << endl;
} // end printMenu

void getUserInput(int& userInput) {
    cin.exceptions(ios::failbit | ios::badbit); // sets exception handling for cin
    
    cout << "Enter your selection: ";
    do {
        // try catch block for input validation
        try {
           // get user input
            cin >> userInput;
            
            // throws out of bound exception
            if (userInput < 1 || userInput > 4){
                throw out_of_range("Please enter a int between 1 and 4");
            }
            
        }
        // catches mismatch exceptions
        catch (ios_base::failure&) {
            cin.clear(); // clear buffer
            cin.ignore(100, '\n'); // ignores next 100 char up to new line
            
            cout << "Please enter an interger: ";
        }
        // catch out of bound exception
        catch (out_of_range) {
            cin.ignore(100, '\n'); // ignores next 100 char up to new line
            
            cout << "Please enter a int between 1 and 4: ";
        }
    }while (userInput < 1 || userInput > 4);
    cout << endl;
} // end getUserInput

void menuInput(int& userInput, GroceryItem& produce) {

        switch(userInput) {
            case 1:
            case 2:
            case 3:
                produce.printMenuOptions(userInput); //prints different option depending on user input
                break;
            case 4:
                cout << "You are exiting the program" << endl; // Ends program
                break;
            default:
                break;
        } // end switch statement
    
} // end menuInput

// Default constructor
GroceryItem::GroceryItem(){
    itemName = " ";
    itemFrequency = 0;
}

// Contructor to initialize name only
GroceryItem::GroceryItem(string itemName){
    this-> itemName = itemName;
}

// Detailed constructor to initilize name and item frequency
GroceryItem::GroceryItem(string itemName, int itemFrequency){
    this-> itemName = itemName;
    this-> itemFrequency = itemFrequency;
}

// Add item name to map and increments for each instance found
void GroceryItem::addItem(string& itemName) {
    GroceryList[itemName]++;
}

 // Deletes grocery item from map
void GroceryItem::deleteItem(string itemName, int itemFrequency) {
    GroceryList.erase(itemName);
}

// Get item name
string GroceryItem::getItemName() const {
    return itemName;
}

// Get item frequency
int GroceryItem::getItemFrequency() const {
    return itemFrequency;
}

// Set item name
void GroceryItem::setItemName(string itemName) {
    this-> itemName = itemName;
}

// Set item frequency
void GroceryItem::setItemFrequency(int itemFrequency) {
    this-> itemFrequency = itemFrequency;
}

// Prints all menu options depending on input
void GroceryItem::printMenuOptions(int& userInput) {
    string searchFor = ""; // gets user input for input selection 1
    
    if (userInput == 1) {
        cout << "Enter Grocery item name: ";
        // If user input not in map remprompt user
        do {
            cin >> searchFor;
            searchFor[0] = toupper(searchFor[0]); // capitilize user input first character
            
            if (GroceryList.find(searchFor) == GroceryList.end()) {
                cout << searchFor << " not found, please enter a valid name: ";
            }
        } while (GroceryList.find(searchFor) == GroceryList.end());
        // Print menu option 1 name and frequency from map
        cout << searchFor << " " << GroceryList[searchFor] << endl;
    }
    
    else if (userInput == 2) {
        // Loop through map and print each key and value
        for (const auto& pair : GroceryList) {
            cout << pair.first << " " << pair.second << endl;
        }
        
    }
    
    else if (userInput == 3) {
        // Loop through map and print each key
        for (const auto& pair : GroceryList) {
            string histogramStars(pair.second, '*'); // string to print stars
            cout << pair.first << " " << histogramStars << endl;
        }
    }
    // newline to seperate inputs
    cout << endl;
} // end print menu options
    
