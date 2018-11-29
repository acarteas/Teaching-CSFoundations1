#pragma once
//includes are required in all .h files
#include <string>
#include <vector>
using namespace std;

//function declarations go here
//Reading all contents of a file into a vector
void readFile(string file_name, vector<string>* result);

//write all contents of a vector to a file
void writeFile(string file_name, const vector<string>* data, bool add_new_line = false);
