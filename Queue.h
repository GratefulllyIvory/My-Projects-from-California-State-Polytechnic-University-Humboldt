// # CS 211 Spring 2021 – Week 07 Lab
// # Henry Morgan, Kyle Filice and Daniel Desforges

#ifndef QUEUE_H
#define QUEUE_H

/*-----
  class: Queue

  purpose: To implement a queue

  constructors: has 1 method:
           *   Queue is a constructor for a new queue object

  getters: isFull() - returns true if queue is empty
           isEmpty() - return true if queue is empty
           firstEl() - return element at front of queue
      
  setters: clearQueue() - clears queue
           enQueue(int) - adds element to back of queue
           deQueue() - removes element from front of queue

  by: David Tuttle
  last modified: 09 March 2021
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

typedef int T;

class Queue {
public:

    Queue();

    bool isFull();
    bool isEmpty();
    T firstEl();

    void clearQueue();
    bool enQueue(int);
    T deQueue();
    
private:
    vector<int> queue;
    int *firstPtr;
    int *lastPtr;
};

#endif /* QUEUE_H */

