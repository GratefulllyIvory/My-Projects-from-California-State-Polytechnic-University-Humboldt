// Daniel Desforges and Karen Vargas Fall 2020 Lab7
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "lab07.h"

using namespace std;

int main() {
    cout << boolalpha;
    cout << "Test Avg Value" << endl;
            
    avg_value();
    cout << "Testing Avg Value Array:" << endl;
    avg_val_array();
    cout << "Testing Array from file" <<endl;
    int val = 5;
    int *point;
    string text = "numbers.txt";
    
    point = arrayFormFile(text, val);
    
    cout << "Testing Calculate Avg:" <<endl;
    int array[5] = {1,2,3,4,5};
    cout << calculateAverage(array, 5) << endl;
    
    cout << "Testing calculate Median" << endl;
    cout << calculateMedian(array, 5) << endl;
    
    cout << "Testing calculate Mode" << endl;
    cout<< calculateMode(array, 5) <<endl;
    
    return 0;
}

