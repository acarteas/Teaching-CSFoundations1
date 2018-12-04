#include "FileOperations.h"
#include <fstream>
using namespace std;

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