//VERY important to include the following three lines
#pragma once
#ifndef STUDENT_H //rename to name of file, e.g. FILE_NAME_H
#define STUDENT_H //rename to name of file, e.g. FILE_NAME_H

#include <string>
using namespace std;

class Student
{
private: //only visible to the instance of the class

public: //visible to everyone all the time (sometimes dangerous to do)
    string name = "";
    double gpa = 0.0;
    string class_standing = "Freshman";
    int age = 18;
    string major = "Computer Science";


}; //VERY IMPORTANT to include semi-colon after }

#endif