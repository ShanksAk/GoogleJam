#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ---- HEADER

// Helpers
void PrintArray(char Array[], int NumPancakes);

// Problem
string Problem(int Argument1, int* Argument2);

// ---- IMPLEMENTATION

int main() {
	int NumTests;
	cin >> NumTests;
	int Argument1;
	int* Argument2;
	for (int Index1 = 1; Index1 <= NumTests; ++Index1)
	{
		cin >> Argument1;
		Argument2 = new int[Argument1];
		for (int Index2 = 0; Index2 < Argument1; ++Index2)
		{
			cin >> Argument2[Index2];
		}
		cout << "Case #" << Index1 << ": ";
		cout << Problem(Argument1, Argument2) << endl;
	}
	return 0;
}

string Problem(int Length, int* Array)
{
	for (int Index = 1; Index < Length - 1; ++Index)
	{
		if ((Array[Index] > Array[Index - 1] && Array[Index] > Array[Index + 1])
			&& (Length <= Index + 2 || Array[Index + 2] > Array[Index]))
		{
			return to_string(Index);
		}
	}
	return "OK";
}

// ---- HELPERS

void PrintArray(char Array[], int Length)
{
	for (int Index = 0; Index < Length; ++Index)
	{
		cout << Array[Index];
	}
	cout << endl;
}