// C++ Power func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//This program computes and outputs a random integer
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int result;

// using namespace std;
// driver function
int GeoSeq(int a, int r, int n)
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a;
        a = a * r;
    }
    return sum;

}

int main()
{
    int a = 2;
    int r = 12;
    int n;
    cout << "Ya motha a whore: ";
    cin >> n;
    cout << GeoSeq(a, r, n);

}
