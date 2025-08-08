#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// CS 112 Fall 2020 – Week 13 Lab
// <Daniel Desforges>, <Ian lee>, <Michael Gonzalez>



void reverseString()
{
	int size;
	
	string array[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter Value" << endl;
		cin >> array[i];
	}
	cout << "Enter array size" << endl;
	cin >> size;
	for (int i = size; i >= 0; i--)
	{
		cout << array[i] << endl;
	}
	
}
	
void reverseStringVector()
{
	
	vector<string> vector;
	for (int i = 0; i < 10; i++) {
		cout << "Enter Value" << endl;
		cin >> vector[i];
	}
	
	
	for (int i = vector.size(); i >= 0; i--)
	{
		cout << vector[i] << endl;
	}
	
}