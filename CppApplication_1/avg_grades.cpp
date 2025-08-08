/*
//CS112 Fall2020 Lab2
// Daniel Desforges and Gramm Drew
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream> 

using namespace std;


double avg_grades(double my_grades[], int size)
{
    double sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum += my_grades[i];
    }
    
    // now determine the average (safely)
    
    if (size != 0)
    {
        return sum / size;
    }
    else
    {
        // size is 0! Just return 0 in that case
        
        return 0;
    }
}