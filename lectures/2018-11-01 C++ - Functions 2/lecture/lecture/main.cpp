#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
using namespace std;

void fillVector(vector<int>* data, int count);

int main()
{
	/*
	Agenda:
		*. Finding the smallest item in an array
		*. Calculate average of array
		*. Calculate median of array
		*. Reading all contents of a file into a vector
		*. Revisiting caesar cipher using functions
	*/
}

void fillVector(vector<int>* data, int count)
{
	for (int i = 0; i < count; i++)
	{
		(*data).push_back(rand());
	}
}