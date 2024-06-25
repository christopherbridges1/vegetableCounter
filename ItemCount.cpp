/*Chris Bridges
CS 210
Southern New Hampshire University
June 19 2024*/

#include "ItemCount.h"
#include <iostream>
#include <fstream>

using namespace std;

//Method to read file
void ItemCount::readFile(const string& fileName) {
    ifstream inputFile(fileName);
    
    //Displays error if file cannot be opened
    if (!inputFile) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    //Reads items from file and updates the frequnecy it appears
    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }
    inputFile.close();  //close file
}
//Itemcount constructor with file data
ItemCount::ItemCount(const string& fileName) {
    readFile(fileName); 
}
//Gets the amount and returns it
int ItemCount::getCount(const string& item) {
    return itemFrequency[item];
}
//Displays all counts
void ItemCount::displayCount() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}
//Method for histogram display
void ItemCount::displayHistogram() {
    for (const auto& pair : itemFrequency) {    //iterates over list
        cout << pair.first << " ";  //displays produce name
        for (int i = 0; i < pair.second; ++i) { //increments count
            cout << "*";    //Asterisk for displaying count
        }
        cout << endl;
    }
}
//Method to save counts to an output file
void ItemCount::saveCount(const string& fileName) {
    ofstream outputFile(fileName);
    
    //Error message if failure to open
    if (!outputFile) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }
    
    //Writes to output file
    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    
    //Output file close
    outputFile.close();
}
