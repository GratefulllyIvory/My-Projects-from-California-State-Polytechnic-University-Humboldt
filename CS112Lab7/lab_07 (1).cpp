
// Daniel Desforges and Karen Vargas Fall 2020 Lab7
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "lab07.h"

using namespace std;

void avg_value()
{
    string myfile;
    cout << "PLease enter the file name" <<endl;
    ifstream mystream;
    mystream.open(myfile);
    int i= 0;
    int next;
    int calc_val =0;
    int avg;
    mystream >> next;
    while (! mystream.eof())
    {
        next = calc_val + next;
        i++;
                
    }
    
    avg = (next / i);
    cout << "The Avg was: " << avg << end;
    
    mystream.close();
}    
void avg_val_array(){
    
    string myfile;
    ifstream mystream;
    mystream.open(myfile);
    int i=0;
    int x;
    int next;
    mystream >> next;
    while (! mystream.eof())
    {
        mystream >> next;
        i++;
        
    }
    
    int my_array[0];
    my_array = new int[i];
    mystream.close();
            
    mystream.open(myfile);
    i=0;
    mystream >> next;
    while(! mystream.eof())
    {
        my_array[x] = next;
        x++;
    }
    
    mystream.close();
    int value;
    int i = 0;
    double avg; 
    for(i; i <x; i++)
    {
        value= my_array[i] + value;
    }
    avg = (value / i);
    cout << "The avg val was:" << avg << endl;
    
}

// Signature: arrayFromFile: string, &array_size ->int*
// Purpose Statement:arrayFrom File: Expects String 
int *arrayFormFile(string file_name, int& array_size)
{
    ifstream mystream;
    mystream.open(file_name);
    
    int *my_array;
    my_array = new int[array_size];
    
    double >> next;
    int i = 0;
    
    while(! mystream.eof())
    {
        next = my_array[i];
        mystream >> next;
        i++;
    }
    
    return my_array;
    
}
double calculateAverage(int input_array[], int array_size)
{
    int i= 0;
    double next= 0;
    double avg;
    for(i; i < array_size; i++)
    {
        next += input_array[i];
    }
    avg= next / i;
    return avg;
}
int calculateMedian(int input_array[], int array_size)
{
    double median;
    int index;
    index = (array_size-1)/2;
    median = input_array[index];
    
    return median;
}

int calculateMode(int input_array[], int array_size)
{
    int count, index, previous = 0;
    int local_mode = 0; 
    for(int j =0; j < array_size; j++)
        {
        if(input_array[j]== previous)
        {
            count++;
            index = j;
        }
        if(previous = 0)
        {
            index = j; 
            previous = count;
        }
        if(previous < count)
        {
            index = j;
            previous= count;
        }
    }
    return input_array[j];
}

