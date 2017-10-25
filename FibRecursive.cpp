
/***************************************************************************
Author: Jason Klamert                                                      *
Goal: Program that calculates the Fibonacci numbers up to value 'n'.       *
These values are calculated recursively and includes a small driver with   *
validation. This satisfies part 'A' of project 1.                          *
Date: 2/4/2016                                                             *
***************************************************************************/
#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;


//Declaration of fib for later use.
unsigned long long int Fib(unsigned int n);

int main()
{
	cout << "Enter The N'th Fibonacci Number You Would Like To Calculate." << endl;
	int n;
	try{ cin >> n; }
	catch (exception ex)
	{
		cerr << "Exception Caught:" << ex.what() << '\n';
	}
	
	//If 'n' is less than 1, report an error and re-enter value 'n'.
	if (n < 0)
	{
		bool NotCorrect = true;
		while (NotCorrect)
		{
			cout << "Error: Negative or Zero Input Passed!" << endl;
			cout << "Re-enter your 'n' value:" << endl;
			cin >> n;
			if (n > 0)
			NotCorrect = false;
		}		
	}

	cout << "____________________________________________________________________" << endl;
	
	//Our call to Fib to recursively calculate our Fibonacci Number.
	cout << Fib(n) << endl;
	
	return 0;
}

/**********************************************************
Parameters: 'n' for calculating fib series up to 'n'.	  *
Description: Takes in a value 'n' and fib calls itself    *
recursively to calculate the n'th fibonacci number.       *
This function also takes care of base cases.		  *	
***********************************************************/
unsigned long long int Fib(unsigned int n)
{
		//Base cases for Fibonacci Sequence
		if (n == 0)
		{
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		//If Base Cases Pass, Perform Recursive Call
		else
		{
			return Fib(n - 1) + Fib(n - 2);
		}
}