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
        *. Announcement: no lab on Friday :(
		*. Insertion sort 
		*. Convert every first letter in a phrase to upper case
		*.		same as above, but this time ignore common words (e.g. "this", "and", etc.)
		*. Drawing a tree (book 6.5.1)
		*. Code cracker (all permutations of a N-digit string)
		*. 
	*/

    //*.Insertion sort
    //srand(time(NULL)); //ensures every run is random
    //vector<int> numbers{};
    //for (int i = 0; i < 100; i++)
    //{
    //    numbers.push_back(rand());
    //}

    ////i represents the barrier between the sorted and unsorted section
    //for (int i = 1; i < numbers.size(); i++)
    //{
    //    for (int j = i; j > 0; j--)
    //    {
    //        //is the current item at j smaller than adjacent item (j - 1)
    //        if (numbers[j] < numbers[j - 1])
    //        {
    //            //if so, swap
    //            int temp = numbers[j];
    //            numbers[j] = numbers[j - 1];
    //            numbers[j - 1] = temp;
    //        }
    //        else
    //        {
    //            //item is in the correct spot
    //            break; //immediately terminates the closes nested loop
    //        }
    //    }
    //}

    //*. Convert every first letter in every word of a phrase to upper case
    string user_input;
    string titled;
    vector<string> common_words{ "A", "Are", "The", "This", "In", "Or", "Is", "For", "Into", "Of", "An" };
    int to_upper = -32;
    cout << "Enter something: ";
    getline(cin, user_input);
    
    //considerations:
    /*What is a word? - alphabetical characters surrounded by spaces
     *First word doesn't have a space in front of it
    */
    string current_word;
    bool ended_in_punctuation = false;
    for (int i = 0; i < user_input.length(); i++)
    {
        if ((user_input[i] >= 'a' && user_input[i] <= 'z')
            || (user_input[i] >= 'A' && user_input[i] <= 'Z'))
        {
            if (user_input[i] >= 'A' && user_input[i] <= 'Z')
            {
                user_input[i] -= to_upper;
            }
            current_word.push_back(user_input[i]);
        }
        else
        {
            //capatalize word
            if (current_word[0] >= 'a' && current_word[0] <= 'z')
            {
                current_word[0] += to_upper;
            }

            //process current word
            for (int j = 0; j < common_words.size(); j++)
            {
                if (current_word == common_words[j])
                {
                    //we know not to upper case this word
                    current_word[0] -= to_upper;
                }
            }

            //capatalize next word after punctuation
            if (ended_in_punctuation == true && current_word.length() > 0)
            {
                if (current_word[0] >= 'a' && current_word[0] <= 'z')
                {
                    current_word[0] += to_upper;
                }
                ended_in_punctuation = false;
            }

            titled += current_word;
            titled.push_back(user_input[i]);

            //mark punctuation for next word
            if (user_input[i] == '.')
            {
                ended_in_punctuation = true;
            }

            //reset current word
            current_word = "";
        }
    }
    if (titled[0] >= 'a' && titled[0] <= 'z')
    {
        titled[0] += to_upper;
    }
    cout << titled << endl;
}
