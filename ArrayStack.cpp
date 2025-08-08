// Daniel and Kevin Tieu Spring 2021 lab6
//---------------------------------------------------------------
// File: ArrayStack.cpp
// Purpose: Implementation file for a demonstration of a stack
//          implemented as an array.    Data type: Double
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include "ArrayStack.h"

//--------------------------------------------
// Function: ArrayStack()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayStack::ArrayStack() {
    // top is the index of the array where the top
    // of the stack is; a value of -1 means the
    // stack is empty
    top = -1;
}

ArrayStack::ArrayStack(int NEW_SIZE)
{
    theStack = new double[NEW_SIZE];
}

//--------------------------------------------
// Function: clearStack()
// Purpose: Remove all items from the stack
// Returns: void
//--------------------------------------------

void ArrayStack::clearStack() {
    top = -1; // Reset count to start over
    delete [] theStack;
    theStack = new double[MAX_SIZE];



              // NOTE: There's no need to reset
              // array values!  Just reset index
}

//--------------------------------------------
// Function: push()
// Purpose: Push an item onto the stack.
// Returns: true if push was successful
//          or false if the push failed.
//--------------------------------------------

bool ArrayStack::push(double el) {
    // Check to see if the stack if full
    if (isFull()) {
        setStack(MAX_SIZE + 5);
    }
        // Increment array index of top of stack
        top++;
        // Add the item to the stack
        theStack[top] = el;
        return true;
}

//--------------------------------------------
// Function: pop()
// Purpose: Pop an item from the Stack.
// Returns: value of item popped if pop was successful
//  or -99999.0 if the pop failed (stack empty)
//--------------------------------------------

double ArrayStack::pop() {
    double el;

    // Check for empty stack
    if (isEmpty()) return -99999.0;
    else {
        el = theStack[top]; // Get character to return
        top--;     // Decrement top index
        return el; // Return popped value
    }
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the stack is empty
// Returns: true if empty, otherwise false
//--------------------------------------------

bool ArrayStack::isEmpty() {
    // top value is -1 if the stack is empty
    return (top == -1);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the stack is full
// Returns: true if full, otherwise false
//--------------------------------------------

bool ArrayStack::isFull() {
    return (top >= MAX_SIZE);
}

int ArrayStack::getStackSize()
{
    return MAX_SIZE;
}
int ArrayStack::setStack(int NEW_SIZE)
{

    double *newStack = new double[NEW_SIZE + 5];
        for(int i = 0; i < NEW_SIZE; i++){
            newStack[i] = theStack[i];
        }
    delete [] theStack;
    NEW_SIZE = NEW_SIZE + 5;
    theStack=new double[NEW_SIZE];
}


