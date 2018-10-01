#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;
int main(void)
{
	//Task #1: Prompt the user for a file.  Write 10
	//random numbers to that file
	
	//1.a: prompt user for file name
	string file_name;
	cout << "Enter file name: ";
	cin >> file_name;

	//1.b: open file
	//ofstream output_file;
	//output_file.open(file_name);

	////1.c: set up our RNG
	//srand(time(NULL));

	////1.d: place 10 random number into the file
	//for (int i = 0; i < rand(); i++)
	//{
	//	output_file << rand() << endl;
	//}
	//output_file.close();

	//Task #2: Open output file, print numbers to the screen
	//1.a: open the file
	ifstream input_file;
	input_file.open(file_name);
	vector<int> numbers;

	//Was C++ able to open the input file
	if (input_file.is_open() == true)
	{
		//The .good() function tells us when there is no
		//more content to read from the file
		double mean = 0;
		int counter = 0;
		while (input_file.good() == true)
		{
			string item;
			input_file >> item;

			//make sure we have a valid value to process
			if (item.length() > 0)
			{
				//check to see if the item is a valid number
				//(each digit in the number ranges between 0 and 9)
				bool check = true;
				for (int i = 0; i < item.length(); i++)
				{
					//item[i] is the ith character in the string
					if (item[i] < '0' || item[i] > '9')
					{
						//Not a valid number
						check = false;
					}
				}
				if (check == true)
				{
					int number = stoi(item);
					mean += number;
					counter++;
					numbers.push_back(number);
				}
				
			}
		}
		mean = mean / counter;

		//print every 10th number in our numbers vector
		for (int i = 0; i < numbers.size(); i += 10)
		{
			cout << numbers[i] << endl;
		}

		//fixed and precision allow us to output a standardized
		//decimal format
		cout << "Mean of sequence: " << fixed << 
			setprecision(2) << mean << endl;

		//we have a sorted and unsorted section of the array
		//until the sorted section size matches the array size, 
		//find the 
		//smallest item in the unsorted section, put it at
		//sorted section + 1
		int sorted_section = -1;
		int unsorted_section = 0;
		while (sorted_section > numbers.size())
		{
			int smallest = numbers[unsorted_section];
			for (int i = unsorted_section + 1; 
				i < numbers.size(); 
				i++)
			{
				//find the smallest
				if (numbers[i] < smallest)
				{
					smallest = numbers[i];
				}
			}
		}
	}

	input_file.close();

	return 0;
}