/*---
  Jacob and Daniel Desforges Spring 2021 Lab 11
---*/

//----------------------------------------------------
// File: HashTable.cpp
// Purpose: Implementation file for a hash table class
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BTree.h"

using namespace std;

//--------------------------------------------
// Function: insertKey(T newKey)
// Purpose: insert newValue into the BTree
// Returns: true if successful insert
//--------------------------------------------

bool BTree::insertKey(T newKey) {
    cout << "*** insertKey CALLED *** " << endl;
    //Inserting rules:
    //Node must be leaf
    //Inserted into nodes pointer[] array in ascending order
    //Increment key tally with node->incKeyTally()
        //Calls and returns split function when node would have 4 keys
    //Successful insert returns true
    BTreeNode *curNodePtr = root;
    bool inserted = false;
    
    while(inserted = false);
    {
        if(curNodePtr->getLeaf() = true)
        {
            //this is the leaf
            if(curNodePtr->getKeyTally() >= 3)  //check if we're splitting
                inserted = curNodePtr->splitNode();
            for(T index = 0; index < curNodePtr->getKeyTally()+1; index++)
            {
                if(newKey < curNodePtr->getPointer(index))  //Key will become first in node
                {
                    curNodePtr->incKeyTally();
                    for(T index2 = 1; index2 < curNodePtr->getKeyTally()+1; index2++)
                    {
                        
                    }
                }
            }
        }
    }
    return inserted;
}

//--------------------------------------------
// Function: deleteKey(T oldKey)
// Purpose: delete oldValue from the BTree
// Returns: true if successful deletion
//--------------------------------------------

bool BTree::deleteKey(T oldKey) {
    cout << "*** deleteKey CALLED *** " << endl;
    return false;  // DELETE THESE LINES
}

//--------------------------------------------
// Function: printBTree()
// Purpose: prints the contents of the BTree
//          using an inorder traversal
// Returns: nothing
//--------------------------------------------

void BTree::printBTree() const {
    // Navigate the BTree in inorder to print the sorted key values
    // This is done RECURSIVELY using BTreeNode instances
    this->printBTreeRecursive(this->getRoot());
    cout << endl;
}

//--------------------------------------------
// Function: printBTreeRecursive(BTreeNode*)
// Purpose: prints the values in the current node
//          and each of its children nodes
// Returns: nothing
//--------------------------------------------

void BTree::printBTreeRecursive(BTreeNode *currPtr) const {
    BTreeNode *childPtr;
    
    // If the currPtr is null, then no node here, so return right away
    if (currPtr == NULL) return;

    cout << " : ";
    // Print the values of the current BTreeNode, visiting the children as well
    int currNodeKeyTally = currPtr->getKeyTally();
    
    for (int currIndex=0; currIndex<currNodeKeyTally+1; currIndex++) {
        
        // Is there a child BTreeNode before the current key?
        // Traverse the BTreeNode at that child Node if it exists
        
        childPtr = currPtr->getPointer(currIndex);
        if (childPtr != NULL) {
            printBTreeRecursive(childPtr);
        }
        
        // Print current index value (skipping last value in the for loop
        // since there's one fewer key values than child pointers in the node
        
        if (currIndex<currNodeKeyTally)
            cout << currPtr->getKey(currIndex) << " ";
    }
    cout << " : ";

    // We're done with this node!
    return;
}

