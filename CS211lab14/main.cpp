//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2021 - Week 14 Lab Exercise
// A quick look at two sorting algorithms
// Insertion Sort vs Selection Sort
//
// by David C. Tuttle - Last modified 27 APril 2021
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include "sortCompare.h"

using namespace std;

const int ARRAY_SIZE=10000; // Size of the array to be sorted
const int MAX_VALUE=100000; // Values range from 0 to MAX_VALUE-1
int SMALL_SIZE=6;

int main() {
    
    int insertionSortArray[ARRAY_SIZE];
    int selectionSortArray[ARRAY_SIZE];
    int i;
   

    // Call sorts with RANDOM data
    
    // Seed the pseudo-random number generator
    // NOTE: This is written for NetBeans - other IDEs may require
    //       that this code be changed in some way
    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert random number into array[i]
        insertionSortArray[i] = rand() % MAX_VALUE;
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "Starting insertion sort on random array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Starting selection sort on random array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    
    // Call sorts with ALREADY SORTED data
    

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        insertionSortArray[i] = i * 5;
        selectionSortArray[i] = insertionSortArray[i];
    }
    
    cout << "\n";

    cout << "Starting insertion sort on sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Starting selection sort on sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    
    cout << "\n";

    cout << "Starting insertion sort on sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Starting selection sort on sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "\n";
//almost
     for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        if(i%100 == 0){
            insertionSortArray[i]= i+9;
        }
        selectionSortArray[i] = insertionSortArray[i];
    }
    
    cout << "Insertion Sort for Almost \n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Selection Sort for Almost \n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout<< "\n";
//reverse
     for (i = 0; i < ARRAY_SIZE; i++) {
        insertionSortArray[i] = ARRAY_SIZE - i;
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "Starting insertion sort on reverse sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Starting selection sort on reverse sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
  //duplicate
       int T ; 
      for (i = 0; i < ARRAY_SIZE; i++) {
        // insert random number into array[i]
        T = rand() % MAX_VALUE;
        insertionSortArray[i] = T % 3;  
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout<< "\n";
    cout << "Insertion Sort for Duplicate \n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "Selection Sort for Duplicate \n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout<< "\n";
    
    return EXIT_SUCCESS;
}
