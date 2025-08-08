// Fall 2020 CS112 Daniel Desforges and Sergio Monterrosso Lab 14

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include "Node.h"

// A Linked List will use the Node class as its elements in the
// list, so we will add "Node.h" to the #include list

// A Linked List will keep track of the Head of the list, the
// Tail of the list, perhaps the Size of the list?  It may
// be important to know when the list is empty (size = 0)

class LinkedList {
public:
    
    // Constructor
    LinkedList();
    
    // Accessors
    Node* getHead() const;
    Node* getTail() const;
    int getSize() const;
    
    // Mutators
    void setHead(Node* newHead);
    void setTail(Node* newTail);
    // Do we need a mutator for size?  Probably not...
    // void setSize(int newSize);
    
    // Other methods
    // We will only add Nodes to the List at its tail!
    void addNode(Node*& newNode);
    bool deleteHead();
    bool search(int valueToSearch) const;
    void printList() const;
    
    // WEEK 14 LAB
    // Write the deleteNode(int valueToDelete) method
    // Your code needs to consider how to handle these cases:
    // * The Node you want to delete is at the HEAD
    // * The Node you want to delete is an INTERIOR Node
    // * The Node you want to delete is at the TAIL
    
    bool deleteNode(int valueToDelete);
 
private:
    
    Node* head;
    Node* tail;
    int size;
    
};

#endif /* LINKEDLIST_H */

