#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
using namespace std;
int main()
{
    
    //define an array of integers for a known sequence
    //less common
    int sequence[] = { 1, -5, 2, 3, 5, 7 };
    cout << sequence[0] << endl; //should be 1
    cout << sequence[2] << endl; //should be 2

    //define an array of 100 integers
    int numbers[100];
    numbers[0] = 50;
    numbers[1] = -1;

    //Arrays are commonly used to group like data.  E.g.
    string class_roster[5];
    class_roster[0] = "Sam";
    class_roster[1] = "Adam";
    class_roster[2] = "Betty";

    cout << "Size of numbers: " << sizeof(numbers) << endl; //400 bytes total

    //NOTE: do not access array elements in this way.  This was done
    //in order to show that values are keyed as an offset from the 0th element.
    cout << *class_roster << endl; //should be Sam
    cout << *(class_roster + 1) << endl; //should be Adam
    cout << *(class_roster + 2) << endl; //should be betty;

    //proper way to access an element:
    cout << class_roster[0] << endl;

    //prompt user for to integers.  Write sum to the file.
    int x;
    int y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter 2nd number: ";
    cin >> y;

    //open output file ofstream -> Output File Stream (steam means file)
    ofstream output{"output.txt"};

    //once open, files work just like cout.
    output << x + y << endl;

    //read two numbers from an input file and write the result
    //to an output file
    ifstream input{ "input.txt" };

    //ifstream works just like cin
    input >> x;
    input >> y;
    output << x * y << endl;

    //ALWAYS remember to close files
    output.close();
    input.close();

    //Pointers are defined using the *
    int* x_ptr; //defined a pointer to an integer value
                //the variable name is x_ptr;
    double* other_ptr;

    //have x_ptr point to x
    x_ptr = &x;

    //use * to modify x_ptr
    *x_ptr = 7;
}