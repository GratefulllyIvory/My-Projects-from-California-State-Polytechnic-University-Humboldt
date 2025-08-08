//Daniel Desforges Assignment 1 Fall 2020 

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "change_calc.h"
#include "mton_to_ounces.h"
#include "prime_generator.h"

using namespace std;


    
int main() {
    int a = 3;
    int b = 4;
    int c = 6;
    int d = 50;
    double x;
    int y;
    
    cout << "Change Calculation: " << change_calc(a,b,c,d) << endl;
    cout << "Change Calculation2: " << change_calc(5,6,7,23) << endl;
    
    mton_convert(x);
    prime_generator(y);
    return 0;
}

