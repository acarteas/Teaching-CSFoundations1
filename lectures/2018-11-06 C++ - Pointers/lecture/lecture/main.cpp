#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
#include <algorithm> //for vector sorting
using namespace std;

//Reading all contents of a file into a vector
void readFile(string file_name, vector<string>* result);

//write all contents of a vector to a file
void writeFile(string file_name, const vector<string>* data, bool add_new_line = false);

//determines whether or not a supplied character is a letter
bool isLetter(char ch);

//shifts character by supplied amount
char shiftChar(char input, int offset);

//endcodes the supplied text
string encode(string text, int offset);

vector<string> encodeVector(const vector<string>* data, int offset);

//splits supplied text on spaces
vector<string> split(string text);

//attempts to find needle in haystack.  If found return index of
//needle inside of haystack
int find(string needle, vector<string>* haystack);

int findOffset(const vector<string>* file_data);

int main()
{
	/*
	AGENDA:
		Pointer workhseet
		Separating code into multiple files
		Creating a random caesar cipher
		"Naked" arrays in C++
			Passing arrays to functions
			using sizeof() to loop through arrays
	*/
}

int findOffset(const vector<string>* file_data)
{
	vector<string> dictionary;
	readFile("words.txt", &dictionary);

	for (int i = 1; i < 26; i++)
	{
		int match_counter = 0;
		string decode_attempt = encode((*file_data)[0], i);
		vector<string> words = split(decode_attempt);
		for (int j = 0; j < words.size(); j++)
		{
			if (find(words[j], &dictionary) > -1)
			{
				match_counter++;
			}
		}
		if (1.0 * match_counter / words.size() > .66)
		{
			return i;
		}
	}
	return -1;
}

void fillVector(vector<int>* data, int count)
{
	for (int i = 0; i < count; i++)
	{
		(*data).push_back(rand());
	}
}

//Finding the smallest item in an array (vector)
int findSmallest(vector<int>* data)
{
	int smallest = INT_MAX;
	//(*data).size() is the same as data->size();
	for (int i = 0; i < (*data).size(); i++)
	{
		if ((*data)[i] < smallest)
		{
			smallest = (*data)[i];
		}
	}
	return smallest;
}

//Assumption: data is pre-sorted
double findMedian(const vector<int>* data)
{
	//median is middlemost value in an odd length set
	//or average of two middle numbers in an even set
	int size = (*data).size();
	if (size % 2 == 1)
	{
		return (*data)[size / 2];
	}
	else
	{
		int middle = size / 2;
		double average = ((*data)[middle] + (*data)[middle - 1]) / 2.0;
		return average;
	}
}

//Reading all contents of a file into a vector
void readFile(string file_name, vector<string>* result)
{
	ifstream input_file;
	input_file.open(file_name);
	if (input_file.is_open() == true)
	{
		while (input_file.good() == true)
		{
			string line;
			getline(input_file, line);
			(*result).push_back(line);
		}
	}
	input_file.close();
}

//write all contents of a vector to a file
void writeFile(
	string file_name,
	const vector<string>* data,
	bool add_new_line
)
{
	ofstream output_file;
	output_file.open(file_name);
	if (output_file.is_open() == true)
	{
		for (int i = 0; i < (*data).size(); i++)
		{
			output_file << (*data)[i];
			if (add_new_line == true)
			{
				output_file << endl;
			}
		}
	}
	output_file.close();
}

//determines whether or not the supplied character is a letter
bool isLetter(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return true;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//shifts character by supplied amount
char shiftChar(char input, int offset)
{
	int ch = input;
	offset = offset % 26;
	if (ch >= 'a' && ch <= 'z')
	{
		ch += offset;
		if (ch > 'z')
		{
			ch -= 26;
		}
		else if (ch < 'a')
		{
			ch += 26;
		}
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		ch += offset;
		if (ch > 'Z')
		{
			ch -= 26;
		}
		else if (ch < 'A')
		{
			ch += 26;
		}
	}
	return ch;
}

//endcodes the supplied text
string encode(string text, int offset)
{
	string result;
	for (int i = 0; i < text.length(); i++)
	{
		if (isLetter(text[i]))
		{
			result += shiftChar(text[i], offset);
		}
		else
		{
			result += text[i];
		}
	}
	return result;
}

vector<string> encodeVector(const vector<string>* data, int offset)
{
	vector<string> result;
	for (int i = 0; i < (*data).size(); i++)
	{
		result.push_back(encode((*data)[i], offset));
	}
	return result;
}

//splits supplied text on spaces
vector<string> split(string text)
{
	//split up decode_attempt into individual words
	vector<string> words;
	string temp;
	for (int j = 0; j < text.length(); j++)
	{
		if (text[j] == ' ')
		{
			//end of word
			words.push_back(temp);
			temp = "";
		}
		else
		{
			//continuation of word
			temp += text[j];
		}
	}
	return words;
}

//attempts to find needle in haystack.  If found return index of
//needle inside of haystack
int find(string needle, vector<string>* haystack)
{
	for (int i = 0; i < (*haystack).size(); i++)
	{
		if (needle == (*haystack)[i])
		{
			return i;
		}
	}
	return -1;
}