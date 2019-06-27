#include <iostream>
#include <string>
#include "mallib.h"

using namespace std;
//Prints out a given type to the command line
//STL String
void mrd::print(string output, bool newLine)
{
	newLine ? cout << output << "\n" : cout << output;
}
//C String
void mrd::print(char* output, bool newLine)
{
	newLine ? cout << output << "\n" : cout << output;
}
//Integer
void mrd::print(int output, bool newLine)
{
	newLine ? cout << output << "\n" : cout << output;
}
//Character
void mrd::print(char output, bool newLine)
{
	newLine ? cout << int(output) << "\n" : cout << output;
}
//2D Square Array
void mrd::print(int* output, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; i < arraySize; j++)
		{
			cout << output[j + (10 * i)] << " ";
		}
		cout << "\n";
	}
}
//Takes a user input from the command line and returns it
string mrd::input()
{
	string foo;
	cin >> foo;
	return foo;
}
//Repeated square of a number
float mrd::pow(float num, float power)
{
	float foo = num;
	for (int i = 2; i <= power; i++)
	{
		foo *= num;
	}
	return foo;
}
