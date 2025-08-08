// Karen Vargas and Ling Ching Liu and Daniel Desforges Spring 2021 Lab 13

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;
//constructor
MinHeap::MinHeap(){
     heapSize= 0;
     heapCapacity= DEFAULTSIZE;
     heapArray= new T[DEFAULTSIZE];
}
MinHeap::MinHeap(int capacity){
     heapSize= 0;
     heapCapacity= capacity;
     heapArray= new T[capacity];
}

//accessors
int MinHeap::getSize() const{
    return heapSize;
}
int MinHeap::getCapacity() const{
    return heapCapacity;
}
void MinHeap::printArray() const{
    for(int i=0; i<heapSize; i++){
        cout<< heapArray[i]<< "";
    }
    
}

// mutators
bool MinHeap::insertValue(T newValue ){
    int x= heapSize;
    if(heapSize<heapCapacity)
    {
        
        heapArray[heapSize]= newValue;
        heapSize++;
    }
        while(x!=0){
            if(heapArray[x]< heapArray[(x-1)/2]){
                T temp = heapArray[x];
                heapArray[x]= heapArray[(x-1)/2];
                heapArray[(x-1)/2] = temp;
                x = (x-1)/2;
            }
            if(heapArray[x]>=heapArray[(x-1)/2])
            {       
                        return true;
            }
            
        }          
        
    return false;
}
//
