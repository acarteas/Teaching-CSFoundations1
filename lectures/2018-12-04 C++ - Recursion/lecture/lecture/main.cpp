#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
#include <algorithm> //for vector sorting
#include <cstdlib>

//to import all the functions inside functions.h, we do another include
#include "FileOperations.h"

using namespace std;

void count(int n);
void countIter(int n);
int factorialRec(int n);
int factorialIter(int n);
int fibIter(int n);
int fibRec(int n);
int binarySearch(vector<int>* data, int low_value, int high_value, int to_find);

int main()
{
	/*
	AGENDA:
      Introduction to recursion (CH 10.5 in book)
         Background, definition, structure 
         Writing a counting function (iteraction vs recursion)
         Writing a factorial function
         Writing fibonacci sequence using recursion
         Binary search using recursion
         Greatest common divisor (book listing 10.8)
	*/

	//Recursion replaces one or more loops with function calls.
	//A function is said to be recursive if it calls itself again at some
	//point in its execution.

	//Example: counting down to zero
	countIter(10);
	count(10);

	//factorial
	cout << factorialIter(5);
	cout << endl;
	cout << factorialRec(5) << endl;

	//fibonacci
	cout << fibIter(8) << endl;
	cout << fibRec(8) << endl;

	//binary search
	vector<int> numbers{};
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		numbers.push_back(rand());
	}
	numbers.push_back(12345);
	sort(numbers.begin(), numbers.end());
	binarySearch(&numbers, 0, numbers.size(), -5);
}

//Use recursion to print the numbers from N to 0
void count(int n)
{
	//base case is the first instance of seeing what we don't want to see.
	//In our case, when N = -1
	if (n == -1)
	{
		cout << endl;
		return;
	}
	cout << n << " ";
	count(n - 1);
}

//Use loop to print the numbers from N to 0
void countIter(int n)
{
	for (int i = n; i >= 0; i--)
	{
		cout << i << " ";
	}
	cout << endl;
}

int factorialRec(int n)
{
	//base case of 1 because anything below 1 would result in a zero'd number
	if (n == 1)
	{
		return 1;
	}
	return n * factorialRec(n - 1);
}
int factorialIter(int n)
{
	/*
	1! = 1
	2! = 2 *1
	3! = 3 * 2 * 1
	4! = 4 * 3 * 2 *1...
	*/
	int result = n;
	for (int i = n - 1; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

//Fibonacci sequence:
//1, 1, | 2, 3, 5, 8, 13, 21, 34...
int fibIter(int n)
{
	int prev_prev = 1;
	int prev = 1;
	int result = 1;
	for (int i = 2; i < n; i++)
	{
		result = prev + prev_prev;
		prev_prev = prev;
		prev = result;
	}
	return result;
}
int fibRec(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fibRec(n - 1) + fibRec(n - 2);
}

int binarySearch(vector<int>* data, int low_value, int high_value, int to_find)
{
	int guess = (high_value + low_value) / 2;
	if ((*data)[guess] == to_find)
	{
		return guess;
	}
	else if (low_value == high_value)
	{
		return -1;
	}
	else if ((*data)[guess] > to_find)
	{
		return binarySearch(data, low_value, guess, to_find);
	}
	else if ((*data)[guess] < to_find)
	{
		return binarySearch(data, guess, high_value, to_find);
	}
}