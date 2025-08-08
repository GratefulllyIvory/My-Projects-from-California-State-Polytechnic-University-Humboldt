/*
 * Daniel Desforges and Skyler Kona
 * Lab 3
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "pass_by_ptr_display.h"

using namespace std;

void pass_by_ptr_display(int *intref)
{
    cout << "Passed Integer: " <<*intref<< "at location" << intref<<endl;
}
void pass_by_ptr_display(double *doubleref)
{
    cout << "Passed Integer: " <<*doubleref<< "at location" << doubleref<<endl;
}
void pass_by_ptr_display(char *charref)
{
    cout << "Passed Integer: " <<*charref<< "at location" << charref<<endl;
}
void pass_by_ptr_display(bool *boolref)
{
    cout << "Passed Integer: " <<*boolref<< "at location" << boolref<<endl;
}

