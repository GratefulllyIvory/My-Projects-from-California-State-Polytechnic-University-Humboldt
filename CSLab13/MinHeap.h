// Karen Vargas and Ling Ching Liu and Daniel Desforges Spring 2021 Lab 13

#ifndef MINHEAP_H
#define MINHEAP_H

 /*-----
  class: MinHeap

  purpose: To implement a MinHeap

  Methods:
           *   MinHeap creates a new MinHeap object
	   *   getSize returns the MinHeap's current size
	   *   getCapacity returns the MinHeap's total capacity
           *   insertValue adds a new value to the MinHeap
           *   printArray prints the array used to hold the MinHeap
           *   printHeap prints the heap in a multi-line format


-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

const int DEFAULTSIZE = 31;  // For the zero-argument constructor

// We'll set a typedef statement here
// The type T represents the data type stored in the MinHeap.
// it'd be great if you used T instead of int in your code :-)

typedef int T;     // Data type for each key value in a MinHeap

using namespace std;


class MinHeap {
public:

    // Constructors

    MinHeap();
    MinHeap(int capacity);
    
    // Desctructor
    ~MinHeap();
    
    // Accessors
    int getSize() const;
    int getCapacity() const;
    void printArray() const;
    //void printHeap() const;
    
    // Mutators
    
    bool insertValue(T newValue); 
    
 private:
     int heapSize;
     int heapCapacity;
     T *heapArray;
};

#endif /* MINHEAP_H */


