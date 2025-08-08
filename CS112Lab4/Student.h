#ifndef STUDENT_H
#define STUDENT_H
//Daniel Desforges and Skyler Kona
//CS112 Fall2020 Lab4

/* 
 * File:   Student.h
 * Author: djbb1
 *
 * Created on September 18, 2020, 11:26 AM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

/*** PLACE THIS CODE IN YOUR Student.h FILE ***/
 struct Student
 {
 string name;
 int id;
 int grade[3];
 };
 /*********************************************/
 void get_student_info(Student&);
 
 void print_student_info(Student&);
 // How to declare a Student and set its member variables to values:

// Student fred;
// fred.name = "Fred Flintstone";
// fred.id = 12345;
// fred.grade[0] = 89;
// fred.grade[1] = 75;
// fred.grade[2] = 92;
#endif /* STUDENT_H */

