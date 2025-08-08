// Daniel Desforges and Karen Vargas Fall 2020 Lab7
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

#ifndef LAB07_H
#define LAB07_H



void avg_value();

void avg_val_array();

int *arrayFormFile(string file_name, int& array_size);

double calculateAverage(int input_array[], int array_size);

int calculateMedian(int input_array[], int array_size);

int calculateMode(int input_array[], int array_size);


#endif /* LAB07_H */

