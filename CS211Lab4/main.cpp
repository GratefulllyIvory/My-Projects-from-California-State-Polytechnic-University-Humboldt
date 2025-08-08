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

int main() {
    cout << boolalpha;
    
      int n;
    cout << endl << "*** TESTING sumDownBy2 ***" << endl;
    cout << "Please enter a non-negative integer value " << endl
         << "       (enter a negative integer to exit): ";
    cin >> n;

    while (n >= 0) {
        cout << "The function sumDownBy2 returned " 
             << sumDownBy2(n) << endl << endl;
        cout << "Please enter the next integer value " << endl
             << "  (enter a negative integer to exit): ";
        cin >> n;
    }
    
    int j,k;
    cout << endl << "*** TESTING recursiveMult ***" << endl;
    cout << "Please enter two non-negative integers " << endl
         << "     (enter a negative integer to exit): ";
    cin >> j >> k;
    
    while (j >= 0 && k >= 0) {
        cout << "The function recursiveMult returned " 
             << recursiveMult(j,k) << endl << endl;
        cout << "Please enter the next two integers " << endl
             << "(enter a negative integer to exit): ";
        cin >> j >> k;
    }
    
    cout << endl << "*** TESTING geometricSum ***" << endl;
    cout << "Please enter a non-negative integer value " << endl
         << "       (enter a negative integer to exit): ";
    cin >> n;
    
    while (n >= 0) {
        cout << "The function geometricSum returned " 
             << geometricSum(n) << endl << endl;
        cout << "Please enter the next integer value " << endl
             << "  (enter a negative integer to exit): ";
        cin >> n;
    }

    return EXIT_SUCCESS;
}
