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
    int comp=0;
    int moves=0;
    for (i = 1; i < size; i++) {
        tmp = data[i];
        comp++;
        for (j = i; j > 0 && tmp < data[j-1]; j--) {
            data[j] = data[j - 1];
            moves++;
        }
        data[j] = tmp;        
    }
    cout << "Insertion Sort Num Comparison:" << comp << endl;
    cout << "Insertion Sort Num Move:"<< moves<< endl;
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
    int comp=0, moves=0; 
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1, least = i; j < size; j++) {
             comp++;
            if (data[j] < data[least]) {
                least = j;
              
            } 
        }
            comp++;
            if (data[i] != data[least]) {
                tmp = data[least];
                data[least] = data[i];
                moves++; 
                data[i] = tmp;
                moves++;           
        }
        comp++;
    }
        cout << "Selection Sort Num Comparison:" << comp << endl;
        cout << "Selection Sort Num Move:"<< moves << endl;
}
