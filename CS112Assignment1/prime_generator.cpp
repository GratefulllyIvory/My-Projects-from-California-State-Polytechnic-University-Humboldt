//Daniel Desforges Assignment 1 Fall 2020

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

int primary_generator(int primeCheck){
    bool isPrime = true;
    int i;
     cout << "Enter number to find if its prime and write to prime file" << endl;
     cin >> primeCheck; 
    if (primeCheck == 1 || primeCheck == 0)
    {
        isPrime= false;
    }
    else
    {
        for(i== 2; i <= primeCheck/2; i++)
        {
            if(primeCheck % 1 == 0)
            {
                isPrime == false;
                break;
            }
            else
            {
            ofstream createdfile;
            createdfile.open("prime.txt");
            createdfile << primeCheck;
            cout<< "Number is prime and written to file" << endl;
            createdfile.close();
            }  
            return 0;
         }
    return i;       
    }
    return 0;  
}