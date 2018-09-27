#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
using namespace std;
int main()
{
    /*
	Agenda: 
        1. No office hours today
        2. Cover PA #3
        3. Determining if a character is also a number
	    4. Using an array, input 3 numbers from the user, output in sorted order
        5. Introduction to loops
        6. Finding the average of a series of numbers
        7. Finding the average of a series of numbers in a file
        8. Finding the largest and smallest number in a file
	*/
    
    //Determining if a character is also a number
    //char ch;
    //cout << "Enter a character: ";
    //cin >> ch;

    ////we can compare characters.  Characters in C++ use single quote '
    ////whereas strings use double quote ".  
    //if (ch >= '0' && ch <= '9') //48 is '0' and 57 is '9'
    //{
    //    cout << "You entered a number" << endl;
    //}

    //Using an array, input 3 numbers from the user, output in sorted order
    /*int numbers[3];
    cout << "Enter 3 numbers:" << endl;
    cin >> numbers[0];
    cin >> numbers[1];
    cin >> numbers[2];*/

    /*test cases
    2,3,1 //ELSE
    1,3,2 //1st IF check
    3,1,2 //2nd IF check
    2,5,2
    */
    //if (numbers[0] < numbers[1] && numbers[0] < numbers[2])
    //{
    //    //numbers[0] does not need to be swapped
    //    if (numbers[2] < numbers[1])
    //    {
    //        int temp = numbers[1];
    //        numbers[1] = numbers[2];
    //        numbers[2] = temp;
    //    }
    //}
    ////element 0 is either greater than element 1 or element 2
    //else if(numbers[1] < numbers[0] && numbers[1] < numbers[2])
    //{
    //    //swap 0 with 1
    //    int temp = numbers[0];
    //    numbers[0] = numbers[1];
    //    numbers[1] = temp;

    //    //numbers[0] does not need to be swapped
    //    if (numbers[2] < numbers[1])
    //    {
    //        int temp = numbers[1];
    //        numbers[1] = numbers[2];
    //        numbers[2] = temp;
    //    }
    //}
    //else
    //{
    //    //2 is the smallest
    //    int temp = numbers[0];
    //    numbers[0] = numbers[2];
    //    numbers[2] = temp;

    //    //numbers[0] does not need to be swapped
    //    if (numbers[2] < numbers[1])
    //    {
    //        int temp = numbers[1];
    //        numbers[1] = numbers[2];
    //        numbers[2] = temp;
    //    }
    //}
    //cout << numbers[0] << "; " << numbers[1] << "; " << numbers[2] << endl;

    /*
    5. Introduction to loops

    Loop allow us to conditionally execute the same code multiple times.
    This means we can be lazy!

    How many times we loop is dependent on a logical expression.  The
    logical expression is EXACTLY the SAME as IF statements!

    The most basic loop is the WHILE loop.  Format:
    while(<expression>)
    {
        //this code will execute as long as <expression> is TRUE
    }
    Sometimes, while loops are called sentinel control loops

    6. Finding the average of a series of numbers
    */
    /*int total = 0;
    int counter = 0;
    cout << "Enter 4 numbers:" << endl;
    while (counter < 4)
    {
        int temp = 0;
        cin >> temp;
        total += temp;
        counter++;
    }
    cout << total / 4.0 << endl;*/

    /*
    The more common loop is the FOR loop.
    Format for a FOR loop:
    for(<variable setup>; <expression>; <increment>)
    {
        //do work until <expression> is false
    }
    FOR loop are really nice when we know how many times we want
    to loop.
    //example FOR loop that loops 4 times
    for(int i = 0; i < 4; i++)
    {
        //do work
        //after all work, i++ automatically happens.
    }
    */
    //Use a FOR loop to generate 10 random numbers and put them in an array
    srand(time(NULL)); // seeds the RNG
    /*int numbers[10];
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = rand() % 101;
        for (int j = 0; j < 10; j++)
        {
            cout << numbers[j] << endl;
        }
    }*/
    vector<int> numbers{}; 
    numbers.resize(10);
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = rand() % 101;
        cout << numbers[i] << endl;
    }

}