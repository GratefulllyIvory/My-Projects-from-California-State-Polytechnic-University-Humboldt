/*
 * Daniel Desforges and Skyler Kona
 * Lab 3
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "pass_by_ref_display.h"

using namespace std;

void pass_by_ref_display(int &intref)
{
    cout << "Passed Integer: " <<intref<< "at location" << &intref<<endl;
}
void pass_by_ref_display(double &doubleref)
{
    cout << "Passed Double: " <<doubleref<< "at location" << &doubleref<<endl;
}
void pass_by_ref_display(char &charref)
{
    cout << "Passed Char: " <<charref<< "at location" << &charref<<endl;
}
void pass_by_ref_display(bool &boolref)
{
    cout << "Passed Bool: " <<boolref<< "at location" << &boolref<<endl;
}