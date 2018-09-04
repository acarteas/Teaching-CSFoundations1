/*
Because C++ is very bare bones, we must do everything ourselves.
As you can imagine, this would waste a lot of time.  To speed up
development, we use libraries.  Libraries are code written by
someone else that give us functionality for free so we don't have
to do it.
*/
//This library allows us to write text to the screen.  It also allows
//us to read input from the keyboard.
#include <iostream>

//This library allows us to use strings in code
#include <string>

//tell C++ that we actually want to use the libraries
//that we imported
using namespace std;

/*
Unlike JS, C++ applications must have a starting point;
we cannot just start writing code.  The entry point for
ALL C++ applications is called main()
*/
int main(void)
{
    //cout is the function that puts text on the screen
    //cout << "Hello, World" << endl;

    /*
    In JS, we could write:
    var test = "Hello";
    test = 5.5;
    Meaning, variables can change type.  This is not
    allowed in C++.  All variables must have a specific,
    defined type.  Once assigned, they cannot change.
    */
    //to define variables in C++
    //<data type> <variable name>; OR
    //<data type> <variable name> = <value>;
    //int number; //define an integer variable called number
    //double decimal = 5.5; //define a decimal variable called decimal
    //string text = "Hello, World!"; //define a string variable called text
    //number = 10;

    ////output this information to the screen
    //cout << number << " " << decimal << " " << text << endl;

    ////get user input from the keyboard
    //cin >> number;

    ////output back to the screen
    //cout << number << endl;

    ////Task: obtain two numbers from the user.  
    ////Output the quotient of the two numbers.
    //int x;
    //int y;
    //cin >> x;
    //cin >> y;

    ////implicitly converts x into a decimal.  Because
    ////whenever you multiply a int by a decimal, C++
    ////converts the result into decimals
    //cout << x * 1.0 / y << endl;

    string text = "";
    cout << "What is your name?: ";
    cin >> text;
    cout << "Hello, " << text << "!" << endl;
    cout << "Your name has " << text.length() << " characters" 
         << endl;

    return 0;
}