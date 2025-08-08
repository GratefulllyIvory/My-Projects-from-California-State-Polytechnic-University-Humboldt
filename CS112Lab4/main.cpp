//Daniel Desforges and Skyler Kona
//CS112 Fall2020 Lab4

#include <cstdlib>
#include <functional>
#include <string>
#include <cmath>
#include <fstream>
#include "Student.h"

using namespace std;

int main() {
    int classSize;
    cout<< " Enter the number of student to enter info for" << endl;
    cin >> classSize;
    Student *studenttype = new Student [classSize];
    for (int i =0; i < classSize; i++)
    {
        get_student_info(studenttype[i]);       
        print_student_info(studenttype[i]);
    }
    delete [] studenttype;
    studenttype = NULL;
    return 0;
}

