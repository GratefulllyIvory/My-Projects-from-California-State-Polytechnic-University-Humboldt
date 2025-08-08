/* 
Jacob and Daniel Desforges Spring 2021 Lab 11
 */

#ifndef BTREE_H
#define BTREE_H

 /*-----
  class: BTree

  purpose: To implement a hash table of int values

  Methods:
           *   HashTable creates a new hash table object
	   *   insertValue inserts a value into the hash table
	   *   deleteValue deletes a value from the hash table
           *   searchValue searches for a value in the hash table
           *   printTable prints the values in the hash table

  by: David Tuttle
  last modified: 06 April 2021
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

// We'll set a typedef statement here
// The type T represents the data type stored in the hash table
// For the data type stored in the hash table buckets,
// it'd be great if you used T instead of int in your code :-)

const int M = 4;   // Set BTree to order = 4 for a 2-3-4 tree
const int DEFAULTKEYVAL = -9999; // Value for an "empty" key
typedef int T;     // Data type for each key value in a BTreeNode

using namespace std;


/*-----
  class: BTreeNode

  by: David Tuttle
  last modified: 06 April 2021
-----*/

class BTreeNode {
public:

    // One constructors:
    //    BTreeNode() creates an "empty" B-Tree node

    BTreeNode() {
        leaf = true;
        keyTally = 0;
        for (int i=0; i<M; i++) {
            pointers[i] = NULL;
            if (i<M-1)
                keys[i] = DEFAULTKEYVAL;
        }
    }
    
    // Destructor
    ~BTreeNode() { }
    
    // Accessors
    bool getLeaf() const { return leaf; }
    int getKeyTally() const { return keyTally; }
    T getKey(int index) { return keys[index]; }
    BTreeNode *getPointer(int index) { return pointers[index]; }    
    
    // Mutators
    void setLeaf(bool leafVal) { leaf = leafVal; }
    void incKeyTally() { keyTally++; }  // Increment key tally for insertKey
    void decKeyTally() { keyTally--; }  // Decrement key tally for deleteKey
    void setKey(int index, T newVal)
        { keys[index] = newVal; }
    void setPointer(int index, BTreeNode *newPtr)
        { pointers[index] = newPtr; }
    
    bool splitNode(BTreeNode *currNode) {
        cout << endl;
        cout << "*** NODE DETECTED THAT NEEDS TO BE SPLIT! ***" << endl;
        cout << "Method not written yet, so value not inserted!" << endl;
        cout << endl;
        return false;
    }
    
    bool mergeNode(BTreeNode *currNode) {
        cout << endl;
        cout << "*** NODE DETECTED THAT NEEDS TO BE MERGED! ***" << endl;
        cout << "Method not written yet, so value not deleted!" << endl;
        cout << endl;
        return false;
    }
    
private:
    bool leaf;      // Set to true if the BTreeNode is a leaf
    int keyTally;   // The number of key values stored in the BTreeNode
    T keys[M-1];    // Key values stored in the BTreeNode
    BTreeNode *pointers[M];  // Child pointers in the BTreeNode
};


/*-----
  class: BTree

  by: David Tuttle
  last modified: 06 April 2021
-----*/

class BTree {
public:

    // One constructors:
    //    BTree() creates an "empty" BTree

    BTree() { root = NULL; }
    
    // Destructor
    ~BTree();
    
    // Accessors
    BTreeNode *getRoot() const { return root; }
    void printBTree() const;
    
    // Mutators
    void setRoot(BTreeNode *newRoot) { root = newRoot; }
    
    // HERE ARE THE METHODS TO BE WRITTEN FOR THIS LAB
    bool insertKey(T newKey);
    bool deleteKey(T oldKey);
    
private:
    void printBTreeRecursive(BTreeNode *currPtr) const;
    BTreeNode *root;
    
};

#endif /* BTREE_H */

