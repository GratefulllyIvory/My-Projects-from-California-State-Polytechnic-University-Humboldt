/*
 * Daniel Desforges CS211 Spring2021 Assignment#3
 */

/* 
 * File:   BST.h
 * Author: djbb1
 *
 * Created on May 6, 2021, 3:02 PM
 */

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

typedef int T;


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
    bool isNode(T el) const;
    BSTNode* getRoot() const;

    // Mutators
    bool insert(T el);
    bool deleteLeaf(T el);
    
    // Other methods
    bool isEmpty() const;
    bool isLeaf(int el) const;
    void exampleTraversal() const;



private:
    BSTNode *root;
    
    void exampleTraversalPrivate(BSTNode* node) const;
    
    void leftRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);
    
    void rightRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);

};

#endif /* BST_H */
