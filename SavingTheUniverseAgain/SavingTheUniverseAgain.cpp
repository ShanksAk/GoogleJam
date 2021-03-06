#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;  // since cin and cout are both in namespace std, this saves some text

					  // ---- HEADER

					  // Constants
const char Charge = 'C';
const char Shoot = 'S';
const int ShootDamage = 1;

// Helpers
void PrintArray(char Array[], int NumPancakes);

// Problem
string Problem(int Argument1, string Argument2);
bool CanShieldHold(char* RobotInstructions, int NumInstructions, int Shield);
bool bPerformHack(char* RobotInstructions, int NumInstructions);

// ---- IMPLEMENTATION

int main() {
	int NumTests;
	cin >> NumTests;
	int Argument1;
	string Argument2;
	for (int Index = 1; Index <= NumTests; ++Index) {
		cin >> Argument1 >> Argument2;
		cout << "Case #" << Index << ": ";
		cout << Problem(Argument1, Argument2) << endl;
	}
	return 0;
}


string Problem(int Shield, string RawInstructions)
{
	int NumInstructions = RawInstructions.size();
	char* RobotInstructions = &RawInstructions[0];

	bool HackSuccess = true;
	int NumberHacks = 0;
	while (HackSuccess)
	{
		if (CanShieldHold(RobotInstructions, NumInstructions, Shield))
		{
			return to_string(NumberHacks);
		}

		HackSuccess = bPerformHack(RobotInstructions, NumInstructions);
		NumberHacks++;
	}
	return "IMPOSSIBLE";
}

bool CanShieldHold(char* RobotInstructions, int NumInstructions, int Shield)
{
	int CurrentDamage = 1;
	int TotalDamage = 0;
	for (int Index = 0; Index < NumInstructions; Index++)
	{
		if (RobotInstructions[Index] == Charge)
		{
			CurrentDamage *= 2;
		}
		else if (RobotInstructions[Index] == Shoot)
		{
			TotalDamage += CurrentDamage;
		}
	}

	return (Shield >= TotalDamage);
}

bool bPerformHack(char* RobotInstructions, int NumInstructions)
{
	for (int Index = NumInstructions - 1; Index > 0; --Index)
	{
		// Find CS and Swap it
		if (RobotInstructions[Index] == Shoot && RobotInstructions[Index - 1] == Charge)
		{
			// Swap!
			RobotInstructions[Index] = Charge;
			RobotInstructions[Index - 1] = Shoot;
			return true;
		}
	}
	return false; // No hack to perform
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