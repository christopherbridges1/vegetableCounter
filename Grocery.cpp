/*Chris Bridges
CS 210
Southern New Hampshire University
June 19 2024*/

#include <iostream>
#include "ItemCount.h"

using namespace std;

//Displays main menu with input options
void displayMenu() {
    cout << "Menu Options:\n";
    cout << "1. Search for an item\n";
    cout << "2. Display total of all items\n";
    cout << "3. Display histogram of items\n";
    cout << "4. Exit\n";
}

//Main function
int main() {
    ItemCount produce("CS210_Project_Three_Input_File.txt");
    produce.saveCount("frequency.dat"); //Creates frequency.dat before loop begins

    //declare some variables to use in the loop
    int choice;
    string item;

    //Menu options loop
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        //Handling invalid input for menu
        if (cin.fail()) {  // Checks to see if the input is invalid
            cin.clear();  // Clears the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignores invalid input
            cout << "Invalid choice. Enter a number between 1 and 4.\n";  // Displays an  error message
            continue;  // Prompt the user again
        }

        //Switch loop for user inputs
        switch (choice) {
        
        //Case 1 Enter Item and get the count
        case 1:
            cout << "Enter the item: ";   
            cin >> item;
            
            //Forces upper because items are listed in uppercase
            if (!item.empty()) {
                item[0] = toupper(item[0]);
            }
            cout << item << " appear " << produce.getCount(item) << " times.\n";
            break;
        
        //Case 2 simply displays all with count
        case 2:
            produce.displayCount();
            break;
        
        //Case 3 displays a histogram with asterisks
        case 3:
            produce.displayHistogram();
            break;
        
        //Case 4 exits loop and program
        case 4:
            cout << "Exiting program.\n";
            break;
        
        //Invalid number option, invalid chars handled above
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
        while (choice != 4);

        return 0;   //return
}
