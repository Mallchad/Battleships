/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
 */

#ifndef MALLIB_H
#define MALLIB_H
#include <string>
namespace mrd
{
	void print(std::string output, bool newLine = true);
	void print(char* output, bool newLine = true);
	void print(int output, bool newLine = true);
	void print(char output, bool newLine = true);
	void print(int* output, int arraySize);
	std::string input();
	float pow(float num, float power);
	//Inline Functions
	//Converts 2D array location to fake 1D index
	inline char arric(char arri0, char arri1, char arrRowSize)
	{
		return arri1 + (arrRowSize * arri0);
	}
	//Squares a number
	inline float sqr(float num)
	{
		return num * num;
	}
}

#endif
