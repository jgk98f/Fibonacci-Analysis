
/***************************************************************************
Author: Jason Klamert                                                      *
Goal: Program that calculates the Fibonacci numbers up to value 'n'.       *
These values are calculated recursively and iteratively. In addition, this *
program includes a small driver with validation and time monitoring.       *
This satisfies part 'C' of project 1.                                      *
Date: 2/8/2016                                                             *
***************************************************************************/
#include <cstdlib>
#include <iostream>
#include <exception>
#include <sys/time.h>
using namespace std;

//Declaration of FibI and FibR for later use.
unsigned long long int FibI(unsigned int n);
unsigned long long int FibR(unsigned int n);

int main() {

	int n;
        hrtime_t start, end, start2, end2;

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

	//Our call to FibI to fetch our number and start timer.
        start = gethrtime();
	cout << FibI(n) << " (From Iterative)" << endl;
        end = gethrtime();

        cout << "______________________________________________________________________" << endl;
        
        cout << "Fibonacci Iterative Took: " << (end - start) << " nanoseconds." << endl;

        cout << "______________________________________________________________________" << endl;

        start2 = gethrtime();
        cout << FibR(n) << " (From Recursive)" << endl;
        end2 = gethrtime();

        cout << "______________________________________________________________________" << endl;
        
        cout << "Fibonacci Recursive Took: " << (end2 - start2) << " nanoseconds." << endl;

        cout << "______________________________________________________________________" << endl;

	return 0;
}

/**********************************************************
Parameters: 'n' for calculating fib series up to 'n'.	  *
Description: Takes in a value 'n' and fib calls itself    *
recursively to calculate the n'th fibonacci number.       *
This function also takes care of base cases.		  *
***********************************************************/
unsigned long long int FibR(unsigned int n)
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
        return FibR(n - 1) + FibR(n - 2);
    }
}

/************************************************************************
Parameters: 'n' for calculating fib series up to 'n'.                   *
Description: Function to calculate and return the n'th Fibonacci number *
using iteration instead of recursion.                                   *
*************************************************************************/
unsigned long long int FibI(unsigned int n) {
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