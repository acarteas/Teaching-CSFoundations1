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
        *. Bowling Night Friday @ 6!
		*. Mid-semester check-in
            Come up with a "starter package" for each language
            What about a debugging assignment?
            What are language-specific commands doing (e.g. #include)
		*. Fibonacci Sequence
		*. Sorting 
		*. Convert every first letter in a phrase to upper case
		*.		same as above, but this time ignore common words
		*. Drawing a tree (book 6.5.1)
		*. Code cracker (all permutations of a N-digit string)
		*. 
	*/


    //Fibonacci Sequence
    //0, 1, 1, 2, 3, 5, 8, 13, 21
    //to solve, we need to know the current number and the prior two numbers
    /*int n = 1;
    int n_minus_one = 0;
    int num_iterations = 0;
    cout << "How many iterations for the Fibonacci sequence: ";
    cin >> num_iterations;
    for (int i = 2; i < num_iterations; i++)
    {
        int temp = n + n_minus_one;
        n_minus_one = n;
        n = temp;
    }
    if (num_iterations == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << n << endl;
    }*/

    //*.Sorting
    srand(time(NULL)); //ensures every run is random
    vector<int> numbers{};
    for (int i = 0; i < 100; i++)
    {
        numbers.push_back(rand());
    }

    //selection sort: partition array into two chunks:
    //sorted section and unsorted section.
    //Until sorted:
        //find smallest element in unsorted section, add to 
        //add to right-most portion of sorted section.
    //int smallest_index = 0;
    //for (int unsorted_marker = 0; unsorted_marker < numbers.size(); unsorted_marker++)
    //{

    //    //finds the smallest item in the unsorted section
    //    smallest_index = unsorted_marker;
    //    for (int i = unsorted_marker; i < numbers.size(); i++)
    //    {
    //        if (numbers[smallest_index] > numbers[i])
    //        {
    //            smallest_index = i;
    //        }
    //    }

    //    int temp = numbers[smallest_index];
    //    numbers[smallest_index] = numbers[unsorted_marker];
    //    numbers[unsorted_marker] = temp;
    //}

    //bubble sort
    //until sorted:
    //if numbers[i] > numbers[i+1], swap
    bool made_swap = true;
    int counter = 1;
    while (made_swap == true)
    {
        made_swap = false;
        for (int i = 0; i < numbers.size() - counter; i++)
        {
            //is i more than i + 1?  If so, swap
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                made_swap = true;
            }
        }
        counter++;
    }
}
