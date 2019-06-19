#pragma once
#ifndef MALLIB_H
#define MALLIB_H
#include <string>
typedef std::string String;
void print(String output , bool newLine = true);
void print(char* output, bool newLine = true);
void print(int output, bool newLine = true);
String input();
bool coinToss();
float sqr(float num);
inline char arric(char arri0, char arri1, char arrRowSize);
#endif