/*---
    CS 211 Spring 2021 - Week 09 Lab
    Hash Tables in C++

    David C. Tuttle
    Last Modified: 23 Mar 2021
---*/

//----------------------------------------------------
// File: HashTable.cpp
// Purpose: Implementation file for a hash table class
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "HashTable.h"

using namespace std;

//--------------------------------------------
// Private function hashfunc
//--------------------------------------------

T HashTable::hashfunc(T value) const {
    return (value * value) % tableSize;
}

//--------------------------------------------
// Constructor
//--------------------------------------------

HashTable::HashTable(int size) {
    tableSize = size;
    valArray = new T[tableSize];
    flags = new bool[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        valArray[i] = 0;
        flags[i] = false;
    }
}

//--------------------------------------------
// Function: insertValue(int value)
// Purpose: insert a value into the hash table
// Returns: true if successful insert
//--------------------------------------------

bool HashTable::insertValue(T value) {
    bool bucketFilled = false;
    T tempPos = hashfunc(value);
    for (int i = tempPos; i < tableSize; i++) {
        if (valArray[i] == 0 || flags[i] == true) {
            valArray[i] = value;
            bucketFilled = true;
            flags[i] = false;
            return bucketFilled;
        }
    }
    for (int i = 0; i < tempPos; i++) {
        if (valArray[i] == 0) {
            valArray[i] = value;
            bucketFilled = true;
            flags[i] = false;
            return bucketFilled;
        }
    }
    return bucketFilled;
}

//--------------------------------------------
// Function: deleteValue(int value)
// Purpose: delete a value from the hash table
// Returns: true if successful deletion
//--------------------------------------------

bool HashTable::deleteValue(T value) {
    bool bucketFilled = false;
    int tempPos = hashfunc(value);
    for (int i = tempPos; i < tableSize; i++) {
        if (value == valArray[i] || flags[i] == false) {
            flags[i] = true;
            return true;
        }
    }
    for (int i = 0; i < tempPos; i++) {
        if (valArray[i] == 0 || flags[i] == false) {
            flags[i] = true;
            return true;
        }
    }
    return false;
}

//--------------------------------------------
// Function: searchValue(int value)
// Purpose: searchs for a value in the hash table
// Returns: true is value is found
//--------------------------------------------

bool HashTable::searchValue(T value) const {
    T tempPos = hashfunc(value);
    for (int i = tempPos; i < tableSize; i++) {
        if (valArray[i] == value || flags[i] == false) {
            return true;
        }
    }
    for (int i = 0; i < tempPos; i++) {
        if (valArray[i] == value || flags[i] == false) {
            return true;
        }
    }
    return false;
}

//--------------------------------------------
// Function: printTable()
// Purpose: prints the contents of the hash table
// Returns: nothing
//--------------------------------------------

    void HashTable::printTable() {
        for (int i = 0; i < tableSize; i++) {
            if (valArray[i] != 0 || flags[i == false]) {
                cout << valArray[i] << " ";
            } else {
                cout << "X" << " ";
            }
        }
    }