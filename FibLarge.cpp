/***************************************************************************
Author: Jason Klamert                                                      *
Goal: Program that calculates the Fibonacci numbers up to value 'n'.       *
These values are calculated iteratively and includes a small driver with   *
validation. This satisfies part D of project 1.                            *
Date: 2/14/2016                                                            *
***************************************************************************/

#include<stdio.h>
#include<iostream>

//We define the size of our array as a constant and as a preprocessor directive it runs faster.
#define maximum 100

using namespace std;

//Declaration for function fib, which calculates the n'th Fibonacci number.
void fib(int array1 [],int array2[], int array3[]);

int main()
{
        int array1[maximum],array2[maximum],array3[maximum];
	int number,i,n,index = 0;
        
        //Prepare the arrays for calculations.
	for(i = 0; i < maximum; i++)
        {
            array1[i] = 0;
            array2[i] = 0;
            array3[i] = 0;
        }
        
	array2[maximum - 1] = 1;

        //Standard IO for getting the n'th term from user.
	cout << "Enter The N'th Fibonacci Number You Would Like To Calculate." << endl;
	try{ cin >> number; }
	catch (exception ex)
        {
		cerr << "Exception Caught:" << ex.what() << '\n';
	}
        
        cout << "______________________________________________________________________" << endl;
        
        //Base cases to cover fib(0) and fib(1).
        if(number == 0)
        {
            cout << "0" << endl;
            return 0;  
        }
        else if(number == 1)
        {
            cout << "1" << endl;
            return 0;
        }
        //Restricts the calculations to under 100 digits in length.
        else if (number > 475)
        {
            cout << "Error: The number of digits is greater than 100!\n";
            cout << "The last acceptable Fibonacci number is:" << endl;
            number = 475;
        }
        
        number++;

	for(i = 0; i < number; i++)
	{
                fib(array1,array2,array3);

		if(i == number - 3)
                    break;
                
                //We can think of these arrays as the previous and current indices for Fibonacci calculation.
                //After calculating next index (previous + current), previous index becomes current index and current index becomes next index.
		for(n = 0; n < maximum; n++)
			array1[n] = array2[n];

		for(n = 0; n < maximum; n++)
			array2[n] = array3[n];

	}
        
        //Printing out the result for our final viewing pleasure.
	for(i = 0; i < maximum; i++)
	{
		if(index || array3[i])
		{
			index = 1;
			cout << array3[i];
		}
	}
        
        cout << endl;
        
	return 0;
}

/************************************************************************
Author: Jason Klamert                                                   *
Description: Function to calculate and return the n'th Fibonacci number *
using iteration instead of recursion and using arrays to store and add  *
the Fibonacci numbers. This uses a practice similar to binary addition  *
with carries except it is mod 10.                                       *
*************************************************************************/
void fib(int array1[], int array2[], int array3[])
{
	int i,temp;
	for(i = 0; i < maximum; i++)
		array3[i] = array1[i] + array2[i];

	for(i = maximum - 1; i > 0; i--)
	{
		if(array3[i] > 9)
		{
			temp = array3[i];
			array3[i] %= 10;
			array3[i - 1] += temp / 10;
		}
	}
}