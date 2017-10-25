
/***************************************************************************
Author: Jason Klamert                                                      *
Goal: Program that calculates the Fibonacci numbers up to value 'n'.       *
These values are calculated iteratively and includes a small driver with   *
validation. This satisfies part B of project 1.                                                              *
Date: 2/4/2016                                                             *
***************************************************************************/
#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;


//Declaration of Fib for later use.
unsigned long long int Fib(unsigned int n);

int main() {
	
	int n;
	cout << "Enter The N'th Fibonacci Number You Would Like To Calculate." << endl;
	try{ cin >> n; }
	catch (exception ex){
		cerr << "Exception Caught:" << ex.what() << '\n';
	}
	

	//If 'n' is less than 0, report an error and re-enter value 'n'.
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

	cout << "______________________________________________________________________" << endl;
	
	//Our call to Fib to fetch our number.
	cout << Fib(n) << endl;
	

	return 0;
}

/************************************************************************
Author: Jason Klamert                                                   *
Description: Function to calculate and return the n'th Fibonacci number *
using iteration instead of recursion.                                   *
*************************************************************************/
unsigned long long int Fib(unsigned int n) {
		//Base cases
		if (n == 0) return 0;
		unsigned long long previousIndex = 0;
		unsigned long long currentIndex = 1;
		//Loop through and add previousIndex and currentIndex to obtain nextIndex then shift indices. Repeat until the n'th index is calculated.
		for (unsigned int i = 1; i < n; i++) {
			unsigned long long nextIndex = previousIndex + currentIndex;
			previousIndex = currentIndex;
			currentIndex = nextIndex;
		}
		return currentIndex;
}