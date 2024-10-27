/**
 * Jermaine Wiggins
 * Module 7 Project 3: Corner Grocers App
 * Description: Program that will analyze a .txt file to determine the amount of times an item waa purchaced
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




int main() {
    // variables
    ifstream inputFile; // read file
    ofstream outputFile; // write to and read to print menu option
    int userInput = 0; // controls while loop
    
    GroceryItem produce; // create grocery item object
    
    // copy grocerylist.text with frequency to new file
    openFiles(inputFile, INFILE, outputFile, OUTFILE);
    copyToNewFile(inputFile, outputFile, produce);
    
    // menu loop
    do {
        printMenu();
        getUserInput(userInput);
        menuInput(userInput, produce);
    }while (userInput != 4);
    
    return 0;
    
}

