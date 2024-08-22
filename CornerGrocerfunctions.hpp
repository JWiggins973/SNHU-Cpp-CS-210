/**
 * Jermaine Wiggins
 * Module 7 Project 3: Corner Grocers App
 * Description: header file with function declarations
 */

#ifndef CornerGrocerfunctions_hpp
#define CornerGrocerfunctions_hpp

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

const string INFILE = "GrocerList.txt"; // input file name
const string OUTFILE = "frequency.dat"; // outputfile name

class GroceryItem {
public:
    // Initilize map
    map <string, int> GroceryList;
    
    // Constructors
    GroceryItem();
    GroceryItem(string itemName);
    GroceryItem(string itemName, int itemFrequency);
    
    // Adds or deletes item from mapp and updates frequency
    void addItem(string& itemName);
    void deleteItem(string itemName, int itemFrequency);
    
    // Getters
    string getItemName() const;
    int getItemFrequency() const;
    
    // Setters
    void setItemName(string itemName);
    void setItemFrequency(int itemFrequency);
    
    // Prints menu options
    void printMenuOptions(int& userInput); // prints menu options
    
private:
    string itemName = ""; // used to store grocery item name
    int itemFrequency = 0; // used to store and update item frequency
};

// Opens and copies files
void openFiles(ifstream& inputFile, const string& INFILE, ofstream& outputFile, const string& OUTFILE);
void copyToNewFile(ifstream& inputFile, ofstream& outputFile, GroceryItem& produce);

// Prints menu and gets user input
void printMenu();
void getUserInput(int& userInput);
void menuInput(int& userInput, GroceryItem& produce);


#endif /* CornerGrocerfunctions_hpp */
