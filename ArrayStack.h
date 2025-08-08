/*
 Daniel Desforges and Kevin Tieu Spring 2021 lab6*/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

/*-----
  class: ArrayStack

  purpose: To implement a Stack object using a C++ array

  constructors: has 4 methods:
           *   ArrayStack is a constructor for a new stack object
           *   clearStack resets a stack object to an empty state
           *   isEmpty returns TRUE if the stack is empty
           *   isFull returns TRUE is the stack has reached capacity
                   as defined by MAX_SIZE

  getters: pop - removes topmost item from the stack and returns its value

  setters: push - expects a value of type double,
                     returns a Boolean indicating success or faiure,
                     and has the side-effect of inserting the value
                     at the top of the stack

  by: David Tuttle
  last modified: 02 March 2021
  Adapted from code written and posted by Dr. Rick Coleman,
          University of Alabama-Huntsville, 2002
-----*/

#include <iostream>
using namespace std;


#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

const int MAX_SIZE = 10;         // Define maximum number of items in the stack

class ArrayStack {
  public:
    ArrayStack();             // Class constructor
    ArrayStack(int NEW_SIZE);

    void clearStack();        // Remove all items from the stack
    bool isEmpty();           // Return true if stack is empty
    bool isFull();            // Return true if stack is full

    int getStackSize();
    int setStack(int NEW_SIZE);

    bool push(double el);     // Push an item onto the stack,
    double pop();             // Pop an item from the stack


  private:
    int top;
    int MAX_SIZE;                    // Index to top of stack
    double *theStack;  // The stack itself

};


#endif // End of stack header


#endif /* ARRAYSTACK_H */

