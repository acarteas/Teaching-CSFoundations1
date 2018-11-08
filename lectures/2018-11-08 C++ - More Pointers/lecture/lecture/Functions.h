#pragma once
//includes are required in all .h files
#include <string>
#include <vector>
using namespace std;

//determines whether or not a supplied character is a letter
bool isLetter(char ch);

//shifts character by supplied amount
char shiftChar(char input, int offset);

//endcodes the supplied text
string encode(string text, int offset);

vector<string> randomEncodeVector(const vector<string>* data, int seed);
vector<string> encodeVector(const vector<string>* data, int offset);

//splits supplied text on spaces
vector<string> split(string text);

//attempts to find needle in haystack.  If found return index of
//needle inside of haystack
int find(string needle, vector<string>* haystack);

int findOffset(const vector<string>* file_data);