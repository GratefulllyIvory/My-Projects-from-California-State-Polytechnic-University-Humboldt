/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Daniel Desforges and Skyler Kona
 * Created on September 11, 2020, 11:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "pass_by_ref_display.h"
#include "pass_by_ptr_display.h"

using namespace std;

string emp_name = "Bob";
int emp_age= 23;
double emp_wage= 3.6;
bool emp_exempt = false;
    
void get_employee_info()
{
    cout << "Please enter an employee's name" << endl;
    getline(cin, emp_name);
    cout << "Please enter an employee's age" << endl;
    cin >> emp_age;
    cout << "Please enter employees wage" << endl;
    cin >> emp_wage;
    cout << "Please enter employees expempt status" << endl;
    cin >> emp_exempt;
}



int main(int argc, char** argv) {

    int a = 3;
    double b = 5.4;
    char c = 'B';
    bool d = true;
    pass_by_ref_display(a);
    pass_by_ref_display(b);
    pass_by_ref_display(c);
    pass_by_ref_display(d);
    
    cout << endl;
    
    pass_by_ptr_display(a);
    pass_by_ptr_display(b);
    pass_by_ptr_display(c);
    pass_by_ptr_display(d);
    cout<<endl;
    
    get_employee_info();
    
    cout << "The employes's name is "<< emp_name << endl;
    cout << "There age is"<< emp_age << endl;
    cout << "Their wage is" << emp_wage << endl;
    if (emp_exempt == 0)
    {
        cout << "They are not exempt from overtime pay." << endl;
        
    }
    else if (emp_exempt == 1)
    {
        cout <<"They are exempt from " << endl;
    }
    return 0;
}

