//Daniel Desforges and Skyler Kona
//CS112 FAll 2020 Lab4

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "Student.h"

using namespace std; 

void get_student_info(Student& studenttype)
{
    cout << "Enter name" << endl;
    cin >> studenttype.name ;
    cout << "Enter ID" << endl;
    cin >> studenttype.id;
    cout << "Enter 3 Grades" << endl;
    cin >> studenttype.grade[0] ;
    cin >> studenttype.grade[1] ;
    cin >> studenttype.grade[2] ;
}

void print_student_info(Student& studentType)
{
    cout << "Entered Students Name" << studentType.name << endl;
    cout << "Entered ID" << studentType.id << endl;
    cout << "Entered Grade 1" << studentType.grade[0] << endl;
    cout << "Entered Grade 2" << studentType.grade[1] << endl;
    cout << "Entered Grade 3" << studentType.grade[2] << endl;
}