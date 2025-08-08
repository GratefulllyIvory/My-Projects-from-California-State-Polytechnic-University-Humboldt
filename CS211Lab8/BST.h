/* 
 Daniel Desforges and Ling Ching Liu
 Spring 2021 Lab 8

 */

#ifndef BST_H
#define BST_H

 /*-----
  classes: BSTNode and BST

  purpose: To implement a basic binary tree
  using the given BSTNode class

  Methods:
           *   BST creates a new tree object
	   *   search returns TRUE is value is found in tree
	   *   insert places a node into tree


  by: David Tuttle
  last modified: 16 Mar 2021
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;
/*-----
  class: BSTNode

  purpose: To create a BSTNode for use in for a binary tree

  by: David Tuttle
  last modified: 16 Mar 2021
-----*/

class BSTNode {
public:

    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              two pointers to "children" BSTNodes (which can
    //              also be used with the el value only)
    BSTNode() {
        leftChild = NULL;
        rightChild = NULL;
    }
    
    BSTNode(int e, BSTNode *l = NULL, BSTNode *r = NULL) {
        el = e;
        leftChild = l;
        rightChild = r;
    }
    
    // Destructor
    ~BSTNode() {
    }
    
    // Accessors
    int getEl() const {
        return el;
    }
    BSTNode *getLeftChild() const {
        return leftChild;
    }
    BSTNode *getRightChild() const {
        return rightChild;
    }
    
    // Mutators (changing the el value is not permitted :-)
    void setLeftChild(BSTNode *nodePtr) {
        leftChild = nodePtr;
    }
    void setRightChild(BSTNode *nodePtr) {
        rightChild = nodePtr;
    }
  
    
protected:
    int el;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

class BST{
public:
    // Constructor
    BST() {
        // Create an empty binary tree
        // The first insertion will place a Node at the root
        Root = NULL;
    }
    
    // Destructor
    ~BST() {
    }

    // Accessors
    bool search(int el) const; 
    bool is_leaf(int el) const;

    // Mutators
    bool insert(int el);
    bool delete_leaf(int el);
    
    // Other methods
    bool isEmpty();

protected:
    BSTNode *Root;
};

#endif /* BST_H */
