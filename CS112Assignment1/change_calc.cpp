//Daniel Desforges Assignment 1 Fall 2020 

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "change_calc.h"

using namespace std;

double sum; 

double change_calc(int quartr, int dime, int nikl, int penny)
{
    sum = (quartr*.25)+(dime*.10)+(nikl*.05)+(penny*.01);
    
    return sum;
   
}

