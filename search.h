#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include <cstring>
#include <map>
using namespace std;

// Search class definition
class Search {
    private: 
         map<string, int> m_products;  // map that contains product frequency data                 

    public:
        void parseFile(); // extracts data from input file into map
        void backup(); // creates the backup file 
        void singleSearch(); // option one search for product
        void allItems(); // displays all items and their frequency
        void histogram(); // display histogram for all products
};

#endif