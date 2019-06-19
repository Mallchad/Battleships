#include <iostream>
#include <string>

using namespace std;
//Converts 2D array location to fake 1D index
inline char arric(char arri0, char arri1, char arrRowSize)
{	return arri1 + (arrRowSize * arri0);
}
//Prints out a given type to the command line
//STL String
void print(string output, bool newLine = true)
{	newLine ? cout << output <<"\n" : cout << output; 
}
//C String
void print(char* output, bool newLine = true)
{	newLine ? cout << output <<"\n" : cout << output;
}
//Integer
void print(int output, bool newLine = true)
{	newLine ? cout << output <<"\n" : cout << output;
}
//Character
void print(char output, bool newLine = true)
{	newLine ? cout << int(output) <<"\n" : cout << output;
}
//2D Square Array
void print(int* output, int arraySize)
{	for (int i=0; i<arraySize; i++)
	{	for (int j=0; i<arraySize; j++)
		{	cout << output[j + (10 * i)] << " ";
		}
		cout << "\n";
	}
}
//Takes a user input from the command line and returns it
string input()
{	string foo;
	cin >> foo;
	return foo;
}
inline float sqr(float num)
{
	return num*num;
}
float pow(float num, float power)
{	float foo = num;
	for (int i=2; i<=power; i++)
	{	foo *= num;
	}
	return foo;
}
