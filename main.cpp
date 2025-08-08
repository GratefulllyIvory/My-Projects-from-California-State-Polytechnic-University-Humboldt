/*---
    CS 111 - Week 14 Lecture 2 - intro to arrays!
    (and void functions!) (continued)

    by: Sharon Tuttle
    modified by: David Tuttle
    last modified: 2020-09-03
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>   // ADD THIS to do file input and/or output

using namespace std;

/*
 * signature: show_grades: double[] int -> void 
 * purpose: expects an array of grades and its size,
 *     and has the side-effect of printing those
 *     grades to the screen, one per line,
 *     and returns NOTHING.
 * tests:
 *     if you have:
 * 
 *     double quiz1[3] = {99.9, 88.8, 91.7};
 *
 *     and I call:
 *      
 *     show_grades(quiz1, 3);
 * 
 *     the following should be printed to screen:
99.9
88.8
91.7
 * 
 *     if you have:
 * 
 *     double final_exams[4] = {100, 100, 100, 100};
 * 
 *     show_grades(final_exams, 4);
 * 
 * the following should be printed to screen:
100
100
100
100
 * 
 ===*/

void show_grades(double grades[], int size)
{
    // int i = 0;
    
    // print to the screen each grade in grades,
    //     on its own line

    // while (i < size)
    
    for(int i=0; i<size; i++)
    {
        cout << grades[i] << endl;
        
        // i++;
    }
}

/*
 * signature: avg_grades: double[] int -> double
 * purpose: expects an array of grades and its size,
 *     and returns the average of the grades in that
 *     array
 * tests:
 *     if you have:
 *         double quizzes[5] = {98.5, 67.2, 73, 34.8, 92.7};
 * 
 *         avg_grades(quizzes, 5) == 
 *              (98.5 + 67.2 + 73 + 34.8 + 92.7)/5
 * 
 *     if you have:
 *         double labs[3] = {0, 50, 100};
 * 
 *         avg_grades(labs, 3) == 50 
 * 
 *         avg_grades(labs, 0) == 0
 *          
 */

double avg_grades(double my_grades[], int size)
{
    double sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum += my_grades[i];
    }
    
    // now determine the average (safely)
    
    if (size != 0)
    {
        return sum / size;
    }
    else
    {
        // size is 0! Just return 0 in that case
        
        return 0;
    }
}



int main()
{
    cout << boolalpha;

    // testing show_grades
    
    cout << endl;
    cout << "*** Testing show_grades ***" << endl;

    double quiz1[3] = {99.9, 88.8, 91.7};
    
    cout << "SHOULD see 99.9, 88.8, 91.7: " << endl;
    show_grades(quiz1, 3);
    
    double final_exams[4] = {100, 100, 100, 100};
    
    cout << "SHOULD see four 100s: " << endl;
    show_grades(final_exams, 4);
    
    cout << "*** Testing avg_grades ***" << endl;
    double quizzes[5] = {98.5, 67.2, 73, 34.8, 92.7};
 
    cout << (avg_grades(quizzes, 5) == 
              (98.5 + 67.2 + 73 + 34.8 + 92.7)/5) << endl;
    
    double labs[3] = {0, 50, 100};
    
    cout << (avg_grades(labs, 3) == (0.0 + 50.0 + 100.0)/3) << endl;
       
    // playing further with arrays
    
    const int NUM_STUDENTS = 5;
    double quiz_grades[NUM_STUDENTS];
    
    int index = 0;

    cout << endl;
    cout << "Please enter the quiz grades of all "
         << NUM_STUDENTS << " students: " << endl;
    cout << endl;

    // ask the user to enter NUM_STUDENTS' quiz grades,
    //     and store them in the array quiz_grades

    while (index < NUM_STUDENTS)
    {
        cout << "enter next grade: ";
        cin >> quiz_grades[index];
        index = index + 1;
    }
    
    cout << endl;
    cout << "Thanks! you entered: " << endl;
    show_grades(quiz_grades, NUM_STUDENTS);
    
    cout << endl;
    cout << "The average of these grades is: "
         << avg_grades(quiz_grades, NUM_STUDENTS)
         << endl;
    
//    // I want to save these grades for later
//    
//    ofstream my_out_stream;
//    my_out_stream.open("looky.txt");
//    
//    for (int i=0; i < NUM_STUDENTS; i++)
//    {
//        my_out_stream << quiz_grades[i] << endl; 
//    }
//    
//    my_out_stream.close();
//    
//    // I want to read the file's contents
//    
//    ifstream my_in_stream;
//    my_in_stream.open("looky.txt");
//    
//    // safer way: try to read the first thing
//    
//    double grade_seen;
//    my_in_stream >> grade_seen;
//    
//    // and while you don't FAIL, keep reading
//    // (method eof returns true of you failed to read
//    //    because you hit the end of file)
//    
//    while (my_in_stream.eof() == false)
//    {
//        cout << "I read: " << grade_seen << endl;
//        
//        my_in_stream >> grade_seen;
//    }
//
//    my_in_stream.close();
//    
//    cout << endl;
    
    return EXIT_SUCCESS;
}