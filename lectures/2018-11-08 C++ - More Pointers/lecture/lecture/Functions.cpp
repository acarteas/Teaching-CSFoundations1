//the CPP file should always include its corresponding .h file
#include "Functions.h" //note we include with quotes "" NOT equality signs <>

//we also need to include all the standard library stuff
#include <fstream>
#include <vector>
#include <string>
#include "FileOperations.h"
using namespace std;

//implementations for function prototypes in the .h file go below...

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

vector<string> randomEncodeVector(const vector<string>* data, int seed)
{
    srand(seed);
    vector<string> result;
    for (int i = 0; i < (*data).size(); i++)
    {
        result.push_back(encode((*data)[i], rand()));
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