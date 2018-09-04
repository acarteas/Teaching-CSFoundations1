/*
C++ is very dumb by default.  By using packages, we can 
leverage code written by other people so that we don't
always have to continually reinvent the wheel.
*/
#include <iostream> //allows us to write stuff to the screen
                    //and read input from the keyboard
#include <string>   //this gives us the ability to use string
                    //variables
#include <cmath>    //contains a bunch of mathematical functions


//tells C++ that we want to use our included libraries
using namespace std;

/*
In C++ all programs must have an entry point.  
For all C++ programs, this entry point must be function
called main.  Without a main function, the program
will not run.
*///in JS <script>
int main(void)
{
    //we write with the function cout
    cout << "Hello, World!" << endl; //endl means end line

    //In JavaScript, variables were declared like:
    //var something = 5;
    //something = "other";
    //In JavaScript, variables can change types.
    //In C++, variables cannot change types.  And variable
    //types must be specified at the time the variable is
    //declared.
    //Syntax for defining a variable
    //<data type> <variable name> [(optional) = <value>];
    //valid data types:
    //int - integer (whole negative or positive number)
    //double - decimal number
    //char - A single character
    //bool - A true/false value
    //string - Text

    //example, declare an int with a value of 5
    int some_number = 5;
    string some_text = "Hello";

    //we use cin to read data from the user
    cout << "Enter your name: ";
    cin >> some_text;

    //TODO: output, "Hello, Name"
    cout << "Hello, " << some_text << endl;

    //this is a data redefinition, not allowed
    //string some_text = "sadfsf";

    //this is a reassignment.  allowed
    some_text = "sadfsf";
    
    //New task: prompt the user for 2 integers.  
    //Output the quotient 
    int x;
    int y;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter a second number: ";
    cin >> y;
    cout << x << " / " << y << " = " << x / y << endl;

    //By default dividing two integers produces an integer.
    //Sometimes this is fine.  
    //In order to perform floating point division, at least
    //one operand needs to be a double.
    //To accomplish this:
    //   1. make one of the variables a double
    //   2. multiply one variable by 1.0
    //   3. perform a data cast (conversion).  Ex: (double)x

    //working with strings.
    //strings are objects.
    string name;
    
    //Task: prompt the user for a word.  Output the length
    //(# of characters) of that word.
    cout << "Enter a word: ";
    cin >> name;
    cout << "Length: " << name.length() << endl;

    //calculate area of a circle
    double radius;
    double area;

    cout << "Enter a radius: ";
    cin >> radius;
    area = 3.14159 * pow(radius, 2);
    cout << "Area: " << area;

    //all functions must return.  We return the boring
    //number 0.
    return 0;
}
//</script>