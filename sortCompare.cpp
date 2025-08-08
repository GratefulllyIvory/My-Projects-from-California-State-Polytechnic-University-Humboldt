//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2021 - Week 14 Lab Exercise
// A quick look at two sorting algorithms
// Insertion Sort vs Selection Sort
//
// by David C. Tuttle - Last modified 27 April 2021
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------------
// insertionSort(int [])
// Expects an integer array of size MAX_VALUE
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and moves
//---------------------------------------------------------------

void insertionSort(int data[], int size) {
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--) {
            data[j] = data[j - 1];
        }
        data[j] = tmp;
    }
}

//---------------------------------------------------------------
// selectionSort(int [])
// Expects an integer array of size MAX_VALUE
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and moves
//---------------------------------------------------------------

void selectionSort(int data[], int size) {
    int i, j, tmp, least;
    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1, least = i; j < size; j++) {
            if (data[j] < data[least]) {
                least = j;
            }
        }
        if (data[i] != data[least]) {
            tmp = data[least];
            data[least] = data[i];
            data[i] = tmp;
        }
    }
}

