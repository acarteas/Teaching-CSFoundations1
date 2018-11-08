#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
#include <algorithm> //for vector sorting

//to import all the functions inside functions.h, we do another include
#include "Functions.h"
#include "FileOperations.h"
using namespace std;

int main()
{
	/*
	AGENDA:
		More pointer questions 
		Decoding a Caesar Cipher
		"Naked" arrays in C++
			Passing arrays to functions
			using sizeof() to loop through arrays
		Connect 4 game
	*/
    vector<string> data;
    readFile("kennedy.txt", &data);
    data = randomEncodeVector(&data, 5);
    int offset = findOffset(&data);
}
