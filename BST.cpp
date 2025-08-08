/*---
    CS 211 Spring 2021 - Programming Assignment 02
    Binary Search Trees in C++

    David C. Tuttle
    Last Modified: 26 Mar 2021
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
// Function: insert(T)
// Purpose: insert a node into a binary tree
// Returns: void
//--------------------------------------------

bool BST::insert(int el) {
    // Pointers to keep track of where we are in descending
    // through the tree to find an insertion point
    BSTNode *ptr = root;
    BSTNode *prev = NULL;
    T currVal;

    // If tree is empty, then insert the first node

    if (this->isEmpty()) {
        root = new BSTNode(el);
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
        currVal = ptr->getEl();
        if (el < currVal)
            ptr = ptr->getLeftChild();
        else if (el > currVal)
            ptr = ptr->getRightChild();
        else {
            // If the value matches one already in the tree, we
            // DON'T add it to the tree and simply return
            cout << "Value NOT inserted - already in the tree! \n";
            return false;
        }
    }

    // If we get here, we've found the place to attach the new node
    // Create the new node and attach it to the node that prev
    // is pointing to

    if (el < prev->getEl()) {
        prev->setLeftChild(new BSTNode(el));
    }
    else {
        prev->setRightChild(new BSTNode(el));
    }
    return true;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() const {
    return (root == NULL);
}

//--------------------------------------------
// Function: search(T)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::search(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *ptr = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (ptr != NULL) {
        
        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = ptr->getEl();
        if (el < currVal)
            ptr = ptr->getLeftChild();
        else if (el > currVal)
            ptr = ptr->getRightChild();
        else
            // Value found!  Return true
            return true;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding anything.  Return false
    return false;
}

//--------------------------------------------
// Function: isLeaf(T)
// Purpose: search for a value in a leaf of a
// binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::isLeaf(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *ptr = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (ptr != NULL) {
        
        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = ptr->getEl();
        if (el < currVal)
            ptr = ptr->getLeftChild();
        else if (el > currVal)
            ptr = ptr->getRightChild();
        // if el == currVal, then we found the value!
        // If it's a leaf, return true, else return false
        else if (ptr->getLeftChild() == NULL &&
                 ptr->getRightChild() == NULL)
                return true;
        else
            return false;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

//--------------------------------------------
// Function: deleteLeaf(T)
// Purpose: delete node from tree if it's a leaf
// Returns: a boolean - true is deleted, false if not
//--------------------------------------------
bool BST::deleteLeaf(int el) {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    // Also keep track of the previous (parent) node of the current node
    BSTNode *ptr = root;
    BSTNode *prev = NULL;
    T currVal;

    // Descend the tree to search for the given input value
    while (ptr != NULL) {
        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = ptr->getEl();
        if (el < currVal) {
            prev = ptr;
            ptr = ptr->getLeftChild();
        }
        else if (el > currVal) {
            prev = ptr;
            ptr = ptr->getRightChild();
        }
        // If el == currVal, then we found the value!
        // If it's a leaf, we can delete node and return true
        else if (isLeaf(el)) {
            // FIRST, check: is this the only node in the tree?
            // If so, we have to handle this special case!
            if (prev == NULL)
                root = NULL;
            // Don't forget to reset pointer on parent node!
            // But which way did we go to get here?
            else if (currVal < prev->getEl())
                // current node is the left child of prev
                prev->setLeftChild(NULL);
            else
                // current node is the right child of prev
                prev->setRightChild(NULL);
            // We've "chopped" the leaf off the tree - OK to delete
            delete ptr;
            return true;
        }
        else {
            // We found the value, but it's not a leaf, so it stays
            return false;
        }
    }   

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

// An accessor method to get the BST's root pointer

BSTNode* BST::getRoot() const {
    return root;
}

// ****************************************************************
// EXAMPLE of using a recursive private method to perform recursion
// ****************************************************************

void BST::exampleTraversal() const {
    // Public method calls private recursive method that passes
    // pointer to current node
    exampleTraversalPrivate(root);
}

void BST::exampleTraversalPrivate(BSTNode* node) const {
    T currVal;
    
    if (node == NULL)
        return;    

    if (node->getLeftChild() != NULL) 
        exampleTraversalPrivate(node->getLeftChild());
    
    // Mark leaf nodes with a * - it helps with debugging!
    currVal = node->getEl();
    cout << currVal;
    if (isLeaf(currVal))
        cout << "*";
    cout << " ";
    
    if (node->getRightChild() != NULL) 
        exampleTraversalPrivate(node->getRightChild());   
}

