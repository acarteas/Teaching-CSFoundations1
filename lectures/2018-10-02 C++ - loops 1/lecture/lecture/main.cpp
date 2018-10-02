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
        *. Introduce PA #4
		*. Practice algorithm #1:
				Until the user enters a negative number:
					prompt the user for a number
					If this number is postive, add to a "running total".
                    If negative, stop the loop, output the total
        *. Finding the largest and smallest number in a file
		*. How many 'a' characters are in a string?
		*. Convert all characters in a string to lower case
		*. Add 1 to every value in a sequence
		*. Sorting (selection sort & bubble sort)
		*. 
	*/

    /*
    	*. Practice algorithm #1:
			Until the user enters a negative number:
				prompt the user for a number
				If this number is postive, add to a "running total".
                If negative, stop the loop, output the total
    */
    /*int user_input = 0;
    int total = 0;
    while (user_input > -1)
    {
        total += user_input;
        cout << "Enter a number: ";
        cin >> user_input;
    }
    cout << "Total: " << total << endl;*/
    
    //*.Finding the largest and smallest number in a file
    //open the file
    //for each number in the file:
        //if number is larger than the lagest we've seen, remember that number
        //if number is smaller than the smalleset we've seen, remembver that number
    //output largest and smallest
    //int largest = INT_MIN;
    //int smallest = INT_MAX;
    //ifstream input_file;
    //input_file.open("input.txt");

    ////was C++ able to open this file?
    //if (input_file.is_open() == true)
    //{
    //    //loop through the file
    //    while (input_file.good() == true)
    //    {
    //        //grab the next number
    //        int temp = 0;
    //        input_file >> temp;
    //        if (temp > largest)
    //        {
    //            largest = temp;
    //        }
    //        if (temp < smallest)
    //        {
    //            smallest = temp;
    //        }
    //    }
    //}
    //cout << "Largest: " << largest << endl;
    //cout << "Smallest: " << smallest << endl;


    //*.How many 'a' characters are in a string ?
    /*int counter = 0;
    string input;
    cout << "Enter a word: ";
    cin >> input;
    char backspace = 8;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            counter++;
        }
    }
    cout << "Number of 'a' in string: " << counter << endl;*/

    //*.Convert all characters in a string to lower case
    /*string input;
    cout << "Enter a word: ";
    cin >> input;
    char to_lower = 'a' - 'A';
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += to_lower;
        }
    }
    cout << "lower case: " << input << endl;*/

    //*. Add 1 to every value in a sequence
    vector<int> numbers = {1, 2, 3, 4, 5, 0, -1, -2, -3};
    srand(time(NULL));

    //random number between -100 and 100
    numbers.push_back((rand() % 201) - 100);
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i]++;
        cout << numbers[i] << endl;
    }
}
