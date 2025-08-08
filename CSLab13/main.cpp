// Karen Vargas and Ling Ching Liu and Daniel Desforges Spring 2021 Lab 13

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;


int main() {

    cout<< boolalpha; 
    
    int heap_nodes[8]={8,4,5,6,52,41,7,3};
    MinHeap *h_1 = new MinHeap();
    for(int i=0; i < 7; i++ ){
        h_1->insertValue(heap_nodes[i]);  
    }
     h_1->printArray();
    return EXIT_SUCCESS;
}

