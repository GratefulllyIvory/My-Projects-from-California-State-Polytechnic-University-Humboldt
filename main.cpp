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
#include "Node.h"
#include "LinkedList.h"

using namespace std;

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
    
//    cout << "Result of deleting node containing 999: "
//         << myList->deleteNode(999) << endl;
//    cout << "List is now: ";
//    myList->printList();
//
//    cout << "Result of deleting node containing 6: "
//         << myList->deleteNode(6) << endl;
//    cout << "List is now: ";
//    myList->printList();
//
//    cout << "Result of deleting node containing 0: "
//         << myList->deleteNode(0) << endl;
//    cout << "List is now: ";
//    myList->printList();
//
//    cout << "Result of deleting node containing 8: "
//         << myList->deleteNode(8) << endl;
//    cout << "List is now: ";
//    myList->printList();
//
//    cout << "Result of deleting node containing 4: "
//         << myList->deleteNode(4) << endl;
//    cout << "List is now: ";
//    myList->printList();

    // Clean up what you allocate!
    
    delete nPtr, pPtr, qPtr, rPtr;
    delete myList;
    
    
    return EXIT_SUCCESS;
     
}