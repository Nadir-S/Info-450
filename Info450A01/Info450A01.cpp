// Info450A01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <cctype>
#include "Info450A01.h"

float begBalance;
double accBalance;
double checks = 0;
double withdrawls = 0;
double deposits = 0;

int validInput()
{
	int x;
	cin >> x;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid entry. Enter a NUMBER: ";
		cin >> x;
	}
	return x;
}


int main()
{
	cout << "Enter beginning account balance:" << endl;
	cin >> accBalance;
	begBalance = accBalance;

	bool anotherTrans = true;

	cout << "Which transaction would you like to make?" << endl;

	while (anotherTrans) 
	{
		char userInput;
		cout << "\n(W)ithdrawl, (D)eposit, (C)heck, (Q)uit" << endl;
		cin >> userInput;

		if ((userInput == 'W') || (userInput == 'w')) 
		{
			double w;
			cout << "Enter amount to withdraw: ";
			w = validInput();
			withdrawls += w;
			accBalance -= w;
		}
		else if ((userInput == 'D') || (userInput == 'd')) 
		{
			double d;
			cout << "Enter amount to deposit: ";
			d = validInput();
			deposits += d;
			accBalance += d;
		}
		else if ((userInput == 'C') || (userInput == 'c'))
		{
			double c;
			cout << "Enter amount of check: ";
			c = validInput();
			checks += c;
			accBalance -= c;
		}
		else if ((userInput == 'Q') || (userInput == 'q'))
		{
			anotherTrans = false;
		}
		else 
		{
			cout << "Invalid entry, try again." << endl;
		}
	}


	
	cout << "-------------------------------" << endl;
	cout << "Beginning Balance: " << begBalance << fixed << endl;
	cout.precision(2);
	cout << "Total Deposits: " << deposits << fixed << endl;
	cout << "Total Withdrawals: " << withdrawls << fixed << endl;
	cout << "Total Checks: " << checks << fixed << endl;
	cout << "-------------------" << endl;
	cout << "Ending Balance: " << accBalance << fixed << endl;
    
	return 0;
}


