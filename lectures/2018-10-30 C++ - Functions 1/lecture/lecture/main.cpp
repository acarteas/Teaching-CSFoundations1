#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
using namespace std;

//function syntax in C++
/*<return data type> <function name>(<zero or more input parameters>)
{

}

examples:
int doMath(int x, int y)
{
    
}

//void means that we're not returning any data
void outputItem(double x)
{

}

Functions can't see other functions defined below it.
void foo()
{
   //DOESN'T WORK!
   bar();
}

void bar()
{
}

To get around this, we declare functions twice.  Once as a
"prototype" and once as a definition.  Prototypes go at the
top of the program.  Definitions come after main.

void foo(); //semicolon means function prototype

//main is here

void foo() //no semicolon and curly braces means function definition
{
}

*/

//Write a function that finds the maximum of two integers
int findMax(int x, int y);

//Write a RNG dice roller
int rollDie(int number_of_sides);

//Write a square root function
double findSquareRoot(double number);

//Write a function that prompts a user for a number
int getNumber(string prompt);

//Swapping values
void swapNumbers(int* x, int* y);

//Fills a vector with random numbers
void fillVector(vector<int>* data, int count);

int main()
{
    /*
	Agenda: 
		*. Calendar just says CH8 in book.  Also look at CH9.
        *. Discuss basic function syntax in C++
			Putting function prototype above main
			Putting function definition after main
		*. Write a function that finds the maximum of two integers
		*. Write a RNG dice roller
		*. Write a square root function
		*. Write a function that prompts a user for a number
			Include error checking
		*. Review: pointers and references
        Three ways to pass parameters:
            Value - give the function a copy of an actual value
            Pointer - give the function a memory address that points to an
                      actual value.  This is used to allow the function
                      to change values of variables that exist in a different
                      scope.
            Reference - nearly identical to pointers but with slightly nicer
                        syntax.
		*. Swapping values using pass by pointer
		*. Passing objects by reference (skipped)
		*. Filling a vector with random numbers
		*. Finding the smallest item in an array
	*/

    //testing our findMax function
    int larger = findMax(3, 5);
    cout << larger << endl;
    cout << findMax(1, -1) << endl;

    //test dice roller
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        cout << rollDie(6) << endl;
    }

    //test square root function
    cout << findSquareRoot(4) << endl;
    cout << findSquareRoot(2) << endl;
    cout << findSquareRoot(100) << endl;

    //test user input prompt
    //int result = getNumber("Enter a number: ");
    //int age = getNumber("What is your age:? ");

    int x = 5;
    int y = 2;

    //to send the memory address instead of the value of a variable
    //we ues the &
    swapNumbers(&x, &y);
    cout << "x: " << x << " y: " << y;

    //test vector fill
    vector<int> numbers{};
    fillVector(&numbers, 10);
}

//Write a function that finds the maximum of two integers
int findMax(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

//Write a RNG dice roller
int rollDie(int number_of_sides)
{
    int roll = rand() % number_of_sides + 1;
    return roll;
}

//Write a square root function
double findSquareRoot(double number)
{
    /*
    Result from class discussion:
    If you find all the divisors from 1..n/2 and then
    start from the product whose result times itself most
    closely matches the original number, you will probably
    cut down on the number of iterations.
    */
    double result = 0.0;
    double tolerance = 0.001;
    while (result * result + tolerance < number)
    {
        result += 0.01;
    }
    return result;
}

//Write a function that prompts a user for a number
int getNumber(string prompt)
{
    string user_input;
    bool valid_user_input = false;
    int result = 0;
    while (valid_user_input == false)
    {
        cout << prompt;
        getline(cin, user_input);
        try
        {
            result = stoi(user_input);
            valid_user_input = true;
        }
        catch (...)
        {
            cout << "Invalid input." << endl;
        }
    }
    return result;
}

//Swapping values
//pointer types are declared by <type>*
void swapNumbers(int* x, int* y)
{
    //x alone is a memory address, NOT a value
    //if we want to get the value AT that memory address, we use another *
    //x -> memory address
    //*x -> value at memory address

    int temp = *x;
    *x = *y;
    *y = temp;
}

void fillVector(vector<int>* data, int count)
{
    for (int i = 0; i < count; i++)
    {
        (*data).push_back(rand());
    }
}