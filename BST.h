/*---
    CS 211 Spring 2021 - Programming Assignment 02
    Binary Search Trees in C++

    David C. Tuttle
    Last Modified: 26 Mar 2021
---*/

/* 
 * File:   BST.h
 * Author: David
 *
 * Created on March 26, 2021
 */

#ifndef BST_H
#define BST_H

 /*-----
  classes: BSTNode and BST

  purpose: To implement a basic binary tree
  using the given BSTNode class

  constructors: has 4 constructors:
           *   BST creates a new stack object
           *   isEmpty returns TRUE if the tree is empty
	   *   search returns TRUE is value is found in tree
	   *   insert places a node into tree


  by: David Tuttle
  last modified: 26 Mar 2021
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

typedef int T;

/*-----
  class: BSTNode

  purpose: To create a BSTNode for use in for a binary tree

  by: David Tuttle
  last modified: 12 Oct 2020
-----*/

class BSTNode {
public:

    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              two pointers to "children" BSTNodes
    BSTNode() {
        leftChild = NULL;
        rightChild = NULL;
    }

    BSTNode(T e, BSTNode *l = NULL, BSTNode *r = NULL) {
        el = e;
        leftChild = l;
        rightChild = r;
    }
    
    // Apparently, some compilers don't like specifying the
    // destructor here, whereas MinGW with NetBeans does
    // not care.  Sorry about that!
    // ~BSTNode();
    
    // Accessors
    
    T getEl() {
        return el;
    }
    BSTNode *getLeftChild() {
        return leftChild;
    }
    BSTNode *getRightChild() {
        return rightChild;
    }
    
    // Mutators
    
    void setEl(T newEl) {
        el = newEl;
    }
    void setLeftChild(BSTNode *nodePtr) {
        leftChild = nodePtr;
    }
    void setRightChild(BSTNode *nodePtr) {
        rightChild = nodePtr;
    }
    
private:
    T el;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

class BST {
public:
    // Constructor
    BST() {
        // Create an empty binary tree
        // The first insertion will place a Node at the root
        root = NULL;
    }
    
    // Destructor commented out (see BSTNode destructor above)
    // ~BST();

    // Accessors
    bool search(T el) const; 
    bool isLeaf(T el) const;
    BSTNode* getRoot() const;

    // Mutators
    bool insert(T el);
    bool deleteLeaf(T el);
    
    // Other methods
    bool isEmpty() const;
    
    void exampleTraversal() const;



private:
    BSTNode *root;
    
    // private methods go here
    void exampleTraversalPrivate(BSTNode* node) const;


};

#endif /* BST_H */

