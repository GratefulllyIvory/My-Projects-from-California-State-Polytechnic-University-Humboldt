/*---
 Daniel Desforges and Ling Liu
 Spring 2021 Lab 8
  
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

int main() {
    cout << boolalpha;
    
    // Create a binary search tree to start playing with
    
    BST *theTree = new BST();

    // To build a test tree quickly, you can use this code to make:
    //               +----20----+
    //           +--10--+    +--30--+
    //           5     15    25    35

    cout << "*** Building test tree *** \n";
    theTree->insert(20);
    theTree->insert(10);
    theTree->insert(30);
    theTree->insert(5);
    theTree->insert(15);
    theTree->insert(25);
    theTree->insert(35);

    // INSERT VALUES INTO THE TREE
    cout << "*** INSERT VALUES *** \n";
    
    int insertValue = 99999;
    bool insertResult = false;

    // User enters values, one at a time, to be inserted into tree
    // Entering a 99999 ends inserts

    cout << "Enter the first value to insert into the tree (99999 to end): ";
    cin >> insertValue;

    while (insertValue != 99999) {
        insertResult = theTree->insert(insertValue);
        if (insertResult)
            cout << "Value " << insertValue << " inserted! \n";
        else
            cout << "Value " << insertValue << " NOT inserted \n";
        cout << "Enter the next value to insert (99999 to end): ";
        cin >> insertValue;
    }
    cout << "Done value inserting! \n";

    // SEARCH FOR VALUES IN THE TREE
    cout << "*** VALUE SEARCH *** \n";
    
    int searchValue = 99999;
    bool searchResult = false;

    // User now enters values to search for in tree
    // Entering a 99999 ends searches

    cout << "Enter a value to search for in the tree: (99999 to end): ";
    cin >> searchValue;

    while (searchValue != 99999) {
        
        // *****************************************************
        // UNCOMMENT THIS CODE TO RUN YOUR SEARCH METHOD
        searchResult = theTree->search(searchValue);

        if (searchResult)
            cout << "The value " << searchValue
                 << " was found in the tree! \n";
        else
            cout << "The value " << searchValue
                 << " was NOT found in the tree! \n";
        // *****************************************************

        cout << "Enter the next value to search for (99999 to end): ";
        cin >> searchValue;
    }
    cout << "Done value searching! \n";

   
    // SEARCH FOR LEAF VALUES IN THE TREE
    cout << "*** LEAF SEARCH *** \n";
    
    searchValue = 99999;
    bool leafFound = false;

    // User now enters values to find leaf
    // Entering a 99999 ends searches

    cout << "Enter a value for leaf search in the tree: (99999 to end): ";
    cin >> searchValue;

    while (searchValue != 99999) {
        
        // *****************************************************
        // UNCOMMENT THIS CODE TO RUN YOUR LEAF SEARCH METHOD
        leafFound = theTree->is_leaf(searchValue);

        if (leafFound)
            cout << "The value " << searchValue
                 << " was found in a leaf! \n";
        else
            cout << "The value " << searchValue
                 << " was NOT found in a leaf! \n";
        // *****************************************************

        cout << "Enter the next value for leaf search (99999 to end): ";
        cin >> searchValue;
    }

    cout << "Done leaf searching! \n";
    
    // DELETE LEAF VALUES IN THE TREE
    cout << "*** LEAF DELETE *** \n";
    
    searchValue = 99999;
    bool leafDeleted = false;

    // User now enters leaf values to delete from the tree
    // Entering a 99999 ends searches

    cout << "Enter a value for leaf delete in the tree: (99999 to end): ";
    cin >> searchValue;

    while (searchValue != 99999) {
        
        // *****************************************************
        // UNCOMMENT THIS CODE TO RUN YOUR LEAF DELETE METHOD
        leafDeleted = theTree->delete_leaf(searchValue);

        if (leafDeleted)
            cout << "That leaf was deleted from the tree! \n";
        else
            cout << "that leaf was not deleted from the tree. \n";
        // *****************************************************

        cout << "Enter the next value for leaf delete (99999 to end): ";
        cin >> searchValue;
    }

    cout << "Done leaf deleting! \n";
    
    cout << "Done testing! \n";
    
    return EXIT_SUCCESS;
}
