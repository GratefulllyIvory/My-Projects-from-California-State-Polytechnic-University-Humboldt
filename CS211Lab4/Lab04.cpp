/*---
 CS 211 Morgan Plants and Daniel Desforges spring 21 lab 4
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "Lab04.h"

using namespace std;

int sumDownBy2(unsigned int n){
    if(n <=1){
        return 0; 
    }
    else {
        return n + sumDownBy2(n-2);
    }
}

int recursiveMult(unsigned int j, unsigned int k){
        if(j < k){
        return recursiveMult(k,j);
    }
    else if(k !=0) {
        return (j + recursiveMult(j, k-1));         
    }
    else 
        return 0;
}

double geometricSum(unsigned int n){
    int top;
    if(n == 0){
        return 1;
    }
    else{
       return (geometricSum(n-1)/2) + 1;
    }
    
}

    

