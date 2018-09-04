#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
using namespace std;
int main()
{
    int some_int = 5;
    char some_char = 'A';
    double some_double = 1.2;
    bool some_bool = false;
    long some_long_int = 325234;
    short some_short = 32767;
    string some_string = "ABC";
    
    //this will overflow our short into negative space
    some_short += 10;
    some_bool++;
    some_bool++;

    cout << "size of INT: " << sizeof(some_int) << endl;
    cout << "size of CHAR: " << sizeof(some_char) << endl;
    cout << "size of DOUBLE: " << sizeof(some_double) << endl;
    cout << "size of BOOL: " << sizeof(some_bool) << endl;
    cout << "size of LONG INT: " << sizeof(some_long_int) << endl;
    cout << "size of SHORT: " << sizeof(some_short) << endl;
    cout << "size of STRING: " << sizeof(some_string) << endl;

    //Variable scope defined: They lifetime of a given variable.  
    //When a variable "dies" (no longer accessible) it is said to have
    //gone out of scope.
    //Scope in C++ is defined by curly braces.
    {
        int foo = 5;
        cout << foo << endl;
        cout << some_int << endl;
    }
    //does not work
    //cout << foo << endl;

    //This is important because it means that all functions, logical blocks,
    //and loops have their own scope.
    while (some_int > 5)
    {
        some_int--;
        int foo = 5; 
    }
    //again, foo does not live out of its scope
    //cout << foo;
}