/*
 CS112 Fall2020 Lab2
 Daniel Desforges and Gramm Drew*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "avg_grades.h"

using namespace std;
double difference;

double grade_range(double students[], int size)
{
    double highest=0;
    double lowest=100;
   
    for(int i=0; i<size;i++)
    {
        if(students[i]>highest)
        {
            highest = students[i];  
        }
        if(students[i]<lowest)
        {
            lowest = students[i];
        }
        difference = highest-lowest;
    }
    return difference;
}