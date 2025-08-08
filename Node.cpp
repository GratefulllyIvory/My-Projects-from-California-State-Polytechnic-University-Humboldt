/*---
    CS 112 Fall 2020 - Week 14 Lab
 Linked List Implementation in C++

    David C. Tuttle
    Last Modified: 01 Dec 2020
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include <valarray>
#include "Node.h"

using namespace std;

//    Node();
//    Node(T initVal, Node *initNext);

// Constructors

const T init_value = 0;

Node::Node() {
    data = init_value;
    next = NULL;
}

Node::Node(T value, Node *nextNode) {
    data = value;
    next = nextNode;
}

// Alternate way of writing constructor
//Node::Node(): data(value), next(nextNode) {
//    
//}

// Accessors

T Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

// Mutators

void Node::setData(T newValue) {
    data = newValue;
}

void Node::setNext(Node *newNext) {
    next = newNext;
}

