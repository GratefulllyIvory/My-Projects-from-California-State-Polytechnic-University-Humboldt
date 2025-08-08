// # CS 211 Spring 2021 – Week 07 Lab
// # Henry Morgan, Kyle Filice and Daniel Desforges

//---------------------------------------------------------------
// File: Queue.cpp
// Purpose: Implementation file for a queue  
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include "Queue.h"

using namespace std;

//--------------------------------------------
// Function: Queue()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

Queue::Queue() {
    queue;
    firstPtr = NULL;
    lastPtr = NULL;
}

//--------------------------------------------
// Function: isFull()
// Purpose: Returns true is queue is full
// Side Effects: None
//--------------------------------------------

bool Queue::isFull() {
    if (queue.size() >= 10)
        return true;
    else
        return false;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Returns true if queue is empty
// Side Effects: None
//--------------------------------------------

bool Queue::isEmpty() {
    if (queue.empty() == true)
        return true;
    else
        return false;
}

//--------------------------------------------
// Function: firstEl()
// Purpose: Returns element at head of queue
// Side Effects: None
//--------------------------------------------

T Queue::firstEl() {
    if(isEmpty() == true)
        return -99999;
    return queue[0];
}

//--------------------------------------------
// Function: clearQueue()
// Purpose: Removes all items from the queue
// Side Effects: resets queue to empty
//--------------------------------------------

void Queue::clearQueue() {
    queue.clear();
    firstPtr = NULL;
    lastPtr = NULL;
}

//--------------------------------------------
// Function: enQueue(int el)
// Purpose: Returns true if element successfully added
// Side Effects: Adds element to queue
//--------------------------------------------

bool Queue::enQueue(int el) {
    queue.push_back(el);
    if(queue.back() == el) {
        firstPtr = &queue.at(0);
        lastPtr = &queue.back();
        return true;
    }
    else {
        return false;
    }
}

//--------------------------------------------
// Function: deQueue()
// Purpose: Returns element at front of queue
// Side Effects: Removes element from queue
//--------------------------------------------

T Queue::deQueue() {
    int value = queue[0];
    queue.erase(queue.begin());
    if(isEmpty() == true) {
        firstPtr = NULL;
        lastPtr = NULL;
        return -99999;
    }
    
    return value;
}

