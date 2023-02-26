#include "search.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
using namespace std;

void Search::parseFile() {

    // Open input file and create a frequency map
    ifstream inputFile;
    map<string, int> frequency;

    // opens input file
    inputFile.open("CS210_Project_Three_Input_File.txt", ios::in);

    // Check if file opened successfully
    if (inputFile.is_open()) {

        // Read in words and update frequency count in map
        string word;
        while (inputFile >> word) {
            if (frequency.count(word) > 0) {
                frequency[word] = frequency[word] + 1;
            }
            else {
                frequency[word] = 1;
            }
        }

        // Close the input file
        inputFile.close();

    } else {
        // Handle error if file can't be opened
        cout << "Error opening the file. Make sure the file is in the program directory and named \"CS210_Project_Three_Input_File.txt\"" << endl;
    }

    // Update the products map with the frequency map
    m_products = frequency;
    
}

void Search::backup() {
    // Open the file for output
    ofstream outfile("frequency.dat");

    // Check if the file was successfully opened
    if (!outfile.is_open()) {
        cout << "Error: could not open output file" << endl;
    }

    // Write output to file
    for (const auto& kv : m_products) {
        outfile << kv.first << ": " << kv.second << endl;
    }

    // Close the file
    outfile.close();
}


void Search::singleSearch() {
    string word;

    // ask user what they want to search for
    cout << "Please enter the product you wish to search for" << endl;
    cin >> word;
    cout << endl;

    // if product exists in map then print how many were sold
    if (m_products.count(word) > 0) {
        cout << word << ": " << m_products[word] << "\n" << endl; 
    }
    // catch if there are no results
    else {
        cout << "No products were sold or possibly a typo." << "\n" << endl;
    }
    
}


void Search::allItems() {
    // Print list of all products and frequency
    for (const auto& kv : m_products) {
        cout << kv.first << ": " << kv.second << endl;
    }
    cout << endl;
}

void Search::histogram() {
    // prints all products in histogram format
    for (const auto& kv : m_products) {
        cout << setw(13) << left << kv.first << ": ";
        for (int i = 0; i < kv.second; i += 1){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}


