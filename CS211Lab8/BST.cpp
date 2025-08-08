/*---
    /*---
 Daniel Desforges and Ling Ching Liu
 Spring 2021 Lab 8

    ---*/

//----------------------------------------------------
// File: BST.cpp
// Purpose: Implementation file for a demonstration
// of a basic binary tree
//
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

//--------------------------------------------
// Function: insert(int)
// Purpose: insert a node into a binary tree
// Returns: void
//--------------------------------------------

bool BST::insert(int el) {
    // Pointers to keep track of where we are in descending
    // through the tree to find an insertion point
    BSTNode *ptr = Root;
    BSTNode *prev = NULL;

    // If tree is empty, then insert the first node

    if (this->isEmpty()) {
        Root = new BSTNode(el);
        return true;
    }

    // Descend the tree for a proper place to put the input value
    // The input value will become a new leaf on the tree
    // NOTE: This does NOT perform any tree balancing!

    while (ptr != NULL) {
        // prev remembers where we were, so when ptr becomes
        // NULL, prev will point to the node where we will
        // attach the new value as a child

        prev = ptr;

        // Descend the tree until we hit a leaf - go left if value
        // is less than current node, go right if greater

        if (el < ptr->getEl()) {
            ptr = ptr->getLeftChild();
        }
        else if (el > ptr->getEl()) {
            ptr = ptr->getRightChild();
        }
        else {
            // If the value matches one already in the tree, we
            // DON'T add it to the tree and simply return
            cout << "Value NOT inserted - it is already in the tree! \n";
            return false;
        }
    }

    // Create the new node and attach it to the node that prev
    // is pointing to

    if (el < prev->getEl())
        
        prev->setLeftChild(new BSTNode(el));
    else
        prev->setRightChild(new BSTNode(el));

    return true;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() {
    return (Root == NULL);
}

//--------------------------------------------
// Function: search(int)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

// CODE FOR search METHOD GOES HERE
bool BST::search(int el)const{
    BSTNode *ptr = Root;
    while(ptr != NULL){
        if (el < ptr ->getEl()){
            ptr = ptr->getLeftChild();
        }
        else if (el > ptr->getEl()){
            ptr = ptr->getRightChild();
        }
        else {
            return true;
        } 
    }
    return false;
}

//--------------------------------------------
// Function: is_leaf(int)
// Purpose: search for a value in a leaf of a
// binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

// CODE FOR is_leaf METHOD GOES HERE
bool BST::is_leaf(int el)const{
    BSTNode *ptr = Root;
    while(ptr != NULL){
        if (el < ptr ->getEl()){
            ptr = ptr->getLeftChild();
            
        }
        else if (el > ptr->getEl()){
            ptr = ptr->getRightChild();
        }
        else {
            if((ptr->getLeftChild()== NULL) && (ptr->getRightChild()==NULL)){
            return true;
        }
            else{
                cout<<"value  is an interior node!"<<endl;
                return false;
        }
        } 
    }
    return 0;
}
//--------------------------------------------
// Function: delete_leaf(int)
// Purpose: delete node from tree if it's a leaf
// Returns: a boolean - true is deleted, false if not
//--------------------------------------------

// CODE FOR delete_leaf METHOD GOES HERE
bool BST::delete_leaf(int el){
    BSTNode *ptr = Root;
    BSTNode *prev = NULL;
    while(ptr != NULL){
        if (el < ptr ->getEl()){      
            ptr = ptr->getLeftChild();
            
        }
        else if (el > ptr->getEl()){
            ptr = ptr->getRightChild();
        }
        else {
            if((ptr->getLeftChild()== NULL) && (ptr->getRightChild()==NULL)){
            prev = ptr;
            delete &ptr;
            return true;
        }
            else{   
                cout<<"value  is an interior node!"<<endl;
                return false;
        }
        } 
    }
    return 0;
}
