/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: David
 *
 * Created on December 1, 2020, 8:46 AM
 */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

// For purposes of flexibility, it would make sense for the
// programmer to allow this code to be a node of whatever
// data type we want to put into the "payload"

// The typedef statement map a data type to an identifier
// Similar in concept to declaring a constant identifier

// This statement allows the programmer to use "T" as the
// data type for the Node payload. "T" is the traditional
// data type identifier used in the Standard Template Library
// (as mentioned in Chapter 18 of the Savitch book!)

typedef int T;

class Node {
public:
    // constructors
    Node();
    Node(T initVal, Node *initNext);

    // accessors
    T getData() const;
    Node *getNext() const;

    // mutators
    void setData(T newValue);
    void setNext(Node *newNext);    
    
private:
    T data;
    Node *next;
};

#endif /* NODE_H */

