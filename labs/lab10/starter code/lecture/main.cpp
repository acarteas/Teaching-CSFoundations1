#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
#include <ctime> //for RNG
#include <vector> //fancy array
#include <algorithm> //for vector sorting
using namespace std;

//fill vector with random data
void fillVector(vector<int>* data, int count);

//Finding the smallest item in an array (vector)
int findSmallest(vector<int>* data);

//Calculate median of array
//const says that we cannot change the contents of data
//using const allows us to continue to benefit from the speed
//of not making a complete copy while guaranteeing that the
//function will not modify the input parameter
double findMedian(const vector<int>* data);

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

int main()
{
    //read contents of a file
    vector<string> file_data;
    readFile("kennedy.txt", &file_data);
    file_data = encodeVector(&file_data, 3);
    writeFile("kennedy_out.txt", &file_data, true);
    file_data = encodeVector(&file_data, -3);
    writeFile("kennedy_out_decode.txt", &file_data, true);
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
    char ch = input;
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