/*---
    CS 112 Fall 2020 - Week 15 Lecture 1
 Linked List Implementation in C++
 * ALSO, EXCEPTION HANDLING IN C++

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
#include "Node.h"
#include "LinkedList.h"

using namespace std;

//double simpleDivide(double num, double denom) {
//    if (denom == 0.0) {
//        cout << "Hey, that's not good!" << endl;
//        return 0.0;
//    }
//    return num / denom;
//}

// Let's use exception handling!
// In exception handling, we think of an "exception"
// as being "thrown" to the system/compiler, either
// in the form of an execution ERROR or as a situation
// to be handled specially

// An "exception" is "thrown" in a way that we can "catch" it!
// We create a "try" block!  A try block is designed to let us
// catch exceptions instead of sending them to the system

double simpleDivide(double numer, double denom) {
    double result;
    try {
        if (denom == 0.0) {
            throw numer;
        }
        result = numer / denom;
    }
    
    catch(double e) {
        cout << "Hey, that's not good!" << endl
             << "Numerator is " << e << endl;
        result = e;
    }
    return result;
}

// Not demonstrated today -- you can catch errors based on
// the type of execution error that occurs

int main() {
    cout << boolalpha;
    
    // Node* p,q,r; // THIS IS WRONG SYNTAX!
    
    Node *pPtr, *qPtr, *rPtr;
    
    pPtr = new Node;
    
    qPtr = new Node(4, pPtr);
    
    rPtr = new Node(6, qPtr);
    
    // Now we DO have a LinkedList class to take care
    // of the list, we'll do it using the methods!
    
    // First, create the list
    
    LinkedList* myList;
    myList = new LinkedList;
    
    // Print the current list
    cout << "WALKING THROUGH THE NEW EMPTY LIST" << endl;
    
    myList->printList();
    
    myList->addNode(pPtr);
    myList->addNode(qPtr);
    myList->addNode(rPtr);

    // Now, let's insert a new Node nPtr into the list
    // First, declare and allocate a new Node
    Node *nPtr;
    nPtr = new Node(8, NULL);
    myList->addNode(nPtr);
        
    // Now let's "walk" through the list
    
    cout << "WALKING THROUGH THE LIST AFTER INSERTIONS AT TAIL" << endl;
    
    myList->printList();
    
   
    // WEEK 14 LAB - the removeNode method
    // The removeNode method will "walk" through the list to 
    // find a node with a particular value, then remove that
    // node from the list.  NOTE: This node could be at the
    // head, or in the interior of the list, or at the tail!
    
    // Uncomment this code to perform your tests
    
    cout << "Result of deleting node containing 999: "
         << myList->deleteNode(999) << endl;
    cout << "List is now: ";
    myList->printList();

    cout << "Result of deleting node containing 6: "
         << myList->deleteNode(6) << endl;
    cout << "List is now: ";
    myList->printList();

    cout << "Result of deleting node containing 0: "
         << myList->deleteNode(0) << endl;
    cout << "List is now: ";
    myList->printList();

    cout << "Result of deleting node containing 8: "
         << myList->deleteNode(8) << endl;
    cout << "List is now: ";
    myList->printList();

    cout << "Result of deleting node containing 4: "
         << myList->deleteNode(4) << endl;
    cout << "List is now: ";
    myList->printList();

    // Clean up what you allocate!
    
    // delete nPtr, pPtr, qPtr, rPtr;
    delete myList;
    
    // EXCEPTION HANDLING IN C++
    // We know that sometimes our code executes in a way
    // that causes an "execution error"
    // It turns out that we have the ability to handle
    // when some types of exceptions occur in our code!
    
    // Savitch, Chapter 16 "Exception-Handling Basics"
        
    cout << "3 divided by 0" << endl;
    // Generating a value of "inf" for the result
    cout << simpleDivide(3.0, 0.0);
    // BUT I don't want that tp happen!  I want to
    // "catch" this and return something else!
    
    return EXIT_SUCCESS;
     
}