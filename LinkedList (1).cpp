// CS 112 Fall 2020 – Week 14 Lab
// <Daniel Desforges> and <Sergio Monterroso>
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
#include "LinkedList.h"

using namespace std;

// Constructors

LinkedList::LinkedList() {
    head = NULL;  // NOTE: in some C++ versions, NULL has
    tail = NULL;  // another name...
    size = 0;
}

// Accessors

Node* LinkedList::getHead() const {
    return head;
}

Node* LinkedList::getTail() const {
    return tail;
}

int LinkedList::getSize() const {
    return size;
}

// Mutators

void LinkedList::setHead(Node* newHead) {
    head = newHead;
}

void LinkedList::setTail(Node* newTail) {
    tail = newTail;
}

// Other methods

bool LinkedList::deleteHead() {
    
    if (head == NULL) {  // List is empty
        cout << "*** LIST IS EMPTY - HEAD NOT DELETED! ***" << endl;
        return false;
    }

    // Point head of list to the 2nd item in the list
    // Delete the 1st item - MUST BE DONE 2ND/LAST!
    Node* nodeToDelete;
    nodeToDelete = head;
    head = head->getNext();
    delete nodeToDelete;
    size--;
    return true;
}

void LinkedList::addNode(Node*& newNode) {
    if (head == NULL) {  // List is empty
        head = newNode;
        tail = newNode;
    }
    
    // Connect tail to new Node, reset tail
    tail->setNext(newNode);
    tail = newNode;
    newNode->setNext(NULL);
    size++;
}

bool LinkedList::search(int valueToSearch) const {
    Node* walkPtr;
    walkPtr = head;
    
    while (walkPtr != NULL) {
        if (walkPtr->getData() == valueToSearch)
            return true;
        walkPtr = walkPtr->getNext();
    }
    return false;
}

void LinkedList::printList() const {
    Node* walkPtr;
    walkPtr = head;
    if (walkPtr == NULL) {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }
    
    while (walkPtr != NULL) {
        cout << walkPtr->getData() << " ";
        walkPtr = walkPtr->getNext();
    }
    cout << endl;
}

// WEEK 14 LAB
// Write the deleteNode(int valueToDelete) method
// Your code needs to consider how to handle three separate cases:
// * The Node you want to delete is at the HEAD
// * The Node you want to delete is an INTERIOR Node
// * The Node you want to delete is at the TAIL

bool LinkedList::deleteNode(int valueToDelete)
{
    Node* walkPtr;
    int pos=1;
    walkPtr = head;
    if (walkPtr == NULL) {
        cout << "LIST IS EMPTY!" << endl;
        return false;
    }
    while(walkPtr != NULL)
    {
        if( valueToDelete == walkPtr->getData())
        {
            if (walkPtr == head)
            {
                Node* nodeToDelete;
                nodeToDelete = head;
                head = head->getNext();
                delete nodeToDelete;
                size--;
                return true;
            }
            else if (walkPtr == tail)
            {
                Node* curr = new Node;
                Node* prev = new Node;
                curr = head;
                while(curr->getNext() != NULL)
                {
                    prev = curr;
                    curr = curr->getNext();
                }
                tail = prev;
                prev->setNext(NULL);
                delete curr;
                size--;
                return true;
            }
            else
            {
                Node* temp;
                Node* prev;
                temp = walkPtr;
                prev = temp->getNext();
                temp = prev->getNext();
                delete temp;
                size--;
                return true;
            }
        }
        else
        {
             walkPtr = walkPtr->getNext();
             pos++;
        }
    }
    return false;
}