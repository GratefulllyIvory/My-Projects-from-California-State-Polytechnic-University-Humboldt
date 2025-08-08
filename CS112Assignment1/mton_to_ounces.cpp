//Daniel Desforges Assignment 1 Fall 2020 

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "mton_to_ounces.h"

using namespace std;

double mton_convert(double mton){
    
    for (int i=0;i>=0;i++)  
    {
        cout <<"Enter a number of tons to convert to ounces: " << endl;
        cin >> mton;
        
        while(mton >0)
        {
        double ounces = mton*352733.92;
        cout << "Conversion: " << ounces << endl;
        return i;
        } 
        cout << "Entered Number <= 0" << endl;
    }
 return mton;
}