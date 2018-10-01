#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

int main(void)
{
	//Task #1: Write 10 random numbers to a user-specified
	//file
	string file_name;
	cout << "Enter a file name: ";
	cin >> file_name;

	//open the file for writing
	//ofstream output_file;
	//output_file.open(file_name);

	////initialize RNG
	//srand(time(NULL));

	////use a loop to output 10 numbers to the file
	//for (int i = 0; i < rand(); i++)
	//{
	//	output_file << rand() << endl;
	//}
	//output_file.close();

	//Task #2: Read numbers back from file, output the average
	ifstream input_file;
	input_file.open(file_name);
	ofstream corrected_file;
	corrected_file.open("corrected.txt");
	vector<int> numbers;

	//make sure the file is opened
	int total = 0;
	int counter = 0;
	if (input_file.is_open() == true)
	{
		//the .good() function returns true as long as there is
		//more stuff to read from the input file
		while(input_file.good() == true)
		{
			string next;
			input_file >> next;
			if (next.length() > 0)
			{
				//make sure that the string is a valid number
				bool input_good = true;
				for (int i = 0; i < next.length(); i++)
				{
					//next[i] will get us the Ith character
					if (next[i] < '0' || next[i] > '9')
					{
						//not a valid character
						input_good = false;
					}
				}
				if (input_good == true)
				{
					int number = stoi(next);
					total += number;
					counter++;
					corrected_file << number << endl;
					numbers.push_back(number);
				}
				
			}
		}
	}
	input_file.close();
	corrected_file.close();

	//right here, we have a bunch of numbers
	//starting at the beginning, move through the array, swap if
	//numbers[x] > numbers[x + 1].
	for (int j = 0; j < numbers.size(); j++)
	{
		for (int i = 0; i < numbers.size() - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				int temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
		}
	}
	

	cout << "Average: " 
		<< fixed << setprecision(4) 
		<< 1.0 * total / counter << endl;
}