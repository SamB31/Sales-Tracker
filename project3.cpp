#include "search.h"
#include <iostream>
using namespace std;

// Function to print asterick line
void AsterickLine(int num) {
    string line(num, '*'); // create a string of astericks with the desired length
    cout << line;
}

// Function to display the menu and get user input
void displayMenu(Search& market) {
    int choice;

    // Loop until the user selects the Quit option (4)
    while (choice != 4) {
        // Display the menu title and options
        AsterickLine(18); // function to print a line of asterisks
        cout << " Sales Frequency ";
        AsterickLine(18); 
        cout << endl;
        AsterickLine(53);
        cout << endl;
        // Display options for user
        cout << "1. Search specific product to see how many were sold." << endl;
        cout << "2. List all products and how many were sold." << endl;
        cout << "3. Displays a histogram of all sold items." << endl;
        cout << "4. Quit program." << endl;

        // Get user input and validate it
        if (cin >> choice) {
        } 
        else {
            // Handle invalid input by clearing the buffer and restarting the loop
            cout << "\nPlease enter a number." << "\n" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }            

        // Execute the selected menu option
        cout << endl;
        switch (choice) {
            case 1:
                market.singleSearch(); // function to search for a single product
                break;
            case 2:
                market.allItems(); // function to list all products and their sales count
                break;
            case 3:
                market.histogram(); // function to display a histogram of product sales
                break;
            case 4:
                choice = 4; // set choice to 4 to exit the loop
                break;
            default:
                cout << "Please enter a valid option. \n" << endl; // input validation to make sure option 1-4 is selected
                break;
        }        
    }
}

int main() {
    Search market;  // creates class object called market

    market.parseFile(); // calls the parseFile() function 
    market.backup(); // calls backup to create backup file.

    displayMenu(market); // displays menu for user passing class object


    return 0;
}