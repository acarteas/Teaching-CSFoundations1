#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
#include <algorithm> //for vector sorting

//to import all the functions inside functions.h, we do another include
#include "FileOperations.h"
#include "Student.h"
using namespace std;

//searches data for supplied pattern, returns matches as a new vector
vector<Student> search(string pattern, vector<Student>* data);
void displayStudent(vector<Student>* data);

int main()
{
	/*
	AGENDA:
		Introduce C++ Classes - Replicate student records from yesterday's JS lecture
         Create Student class
         Read student records in from file
         Build "pretty" student list using setw
         Search for specific students
         Add new students
         Delete existing students
         ???
      (If we have time, if not next lecture!) Introduction to recursion
         Writing a counting function 
         Writing fibonacci sequence using recursion
         Binary search using recursion
	*/

    //Example defining a student
    /*Student my_student;
    my_student.name = "Adam";
    my_student.class_standing = "Sophomore";
    cout << "Name: " << my_student.name << endl;
    cout << "Standing: " << my_student.class_standing << endl;
    cout << "Class Standing: " << my_student.major << endl;*/
    
    //Task: read student data from file into a vector of students
    vector<string> student_data;
    readFile("students.txt", &student_data);
    vector<Student> students;
    for (int i = 0; i < student_data.size(); i += 5)
    {
        Student some_student;
        some_student.name = student_data[i];
        some_student.gpa = stod(student_data[i + 1]);
        some_student.class_standing = student_data[i + 2];
        some_student.age = stoi(student_data[i + 3]);
        some_student.major = student_data[i + 4];
        students.push_back(some_student);
    }

    string search_pattern;
    while (search_pattern != "-1")
    {
        cout << endl;
        cout << "Enter search criteria: ";
        getline(cin, search_pattern);
        system("cls");

        //decision point: did we get a number or a string?
        if (search_pattern.length() > 0 && search_pattern[0] >= '0'
            && search_pattern[0] <= '9')
        {
            //number entered, delete student
        }
        else
        {
            //filter requested
            vector<Student> matches = search(search_pattern, &students);
            displayStudent(&matches);
        }

        
    }
    
}

vector<Student> search(string pattern, vector<Student>* data)
{
    vector<Student> result;

    //match based on start of string
    for (int i = 0; i < (*data).size(); i++)
    {
        //is this a match?
        if (pattern == (*data)[i].name.substr(0, pattern.size()))
        {
            result.push_back((*data)[i]);
        }
    }
    return result;
}
void displayStudent(vector<Student>* data)
{
    cout << (char)201;
    for (int i = 0; i < 88; i++)
    {
        cout << (char)205;
    }
    cout << (char)187;
    cout << endl;
    for (int i = 0; i < (*data).size(); i++)
    {
        cout << (char)186 << " " << right << setw(4) << i + 1 << ". ";
        //output name as left justified with a padding of 20 characters
        cout << left << setw(20) << (*data)[i].name;
        cout << right << setprecision(4) << setw(4) << (*data)[i].gpa;
        cout << setw(7) << " ";
        cout << left << setw(20) << (*data)[i].class_standing;
        cout << right << setw(2) << (*data)[i].age;
        cout << setw(7) << " ";
        cout << left << setw(20) << (*data)[i].major;
        cout << " " << (char)186;
        cout << endl;
    }
    cout << (char)200;
    for (int i = 0; i < 88; i++)
    {
        cout << (char)205;
    }
    cout << (char)188;
}