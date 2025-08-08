/* 
 * File:   HashTable.h
 * Author: David
 *
 * Modified on March 23, 2021
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

 /*-----
  class: HashTable

  purpose: To implement a hash table of int values

  Methods:
           *   HashTable creates a new hash table object
	   *   insertValue inserts a value into the hash table
	   *   deleteValue deletes a value from the hash table
           *   searchValue searches for a value in the hash table
           *   printTable prints the values in the hash table

  by: David Tuttle
  last modified: 23 Mar 2021
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

// We'll set a typedef statement here
// The type T represents the data type stored in the hash table
// For the data type stored in the hash table buckets,
// it'd be great if you used T instead of int in your code :-)

typedef int T;

using namespace std;
/*-----
  class: HashTable

  by: David Tuttle
  last modified: 23 Mar 2021
-----*/

class HashTable {
public:

    // One constructors:
    //    HashTable() creates an "empty" hash table

    HashTable(int size);
    
    // Destructor
    ~HashTable();
    
    // Accessors
    bool searchValue(T value) const;
    void printTable();
    
    // Mutators
    bool insertValue(T value);
    bool deleteValue(T value);
    
private:
    T hashfunc(T value) const;
    int *valArray;
    int tableSize;
    bool *flags;
};

#endif /* HASHTABLE_H */

