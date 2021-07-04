/*Convert decimal fraction to binary number
Difficulty Level : Medium
Last Updated : 01 Jun, 2021
Given a fraction decimal number n and integer k, convert decimal number n into equivalent binary number up-to k precision after decimal point. 
Examples: 
 

Input: n = 2.47, k = 5
Output: 10.01111

Input: n = 6.986 k = 8
Output: 110.11111100
 

We strongly recommend that you click here and practice it, before moving on to the solution.
A) Convert the integral part of decimal to binary equivalent 
 

Divide the decimal number by 2 and store remainders in array. 
Divide the quotient by 2. 
Repeat step 2 until we get the quotient equal to zero.
Equivalent binary number would be reverse of all remainders of step 1.
B) Convert the fractional part of decimal to binary equivalent 
 

Multiply the fractional decimal number by 2. 
Integral part of resultant decimal number will be first digit of fraction binary number. 
Repeat step 1 using only fractional part of decimal number and then step 2. 
 
C) Combine both integral and fractional part of binary number.
Illustration 
 



Let's take an example for n = 4.47 k = 3

Step 1: Conversion of 4 to binary
1. 4/2 : Remainder = 0 : Quotient = 2
2. 2/2 : Remainder = 0 : Quotient = 1
3. 1/2 : Remainder = 1 : Quotient = 0

So equivalent binary of integral part of decimal is 100.

Step 2: Conversion of .47 to binary
1. 0.47 * 2 = 0.94, Integral part: 0
2. 0.94 * 2 = 1.88, Integral part: 1
3. 0.88 * 2 = 1.76, Integral part: 1

So equivalent binary of fractional part of decimal is .011

Step 3: Combined the result of step 1 and 2.

Final answer can be written as:
100 + .011 = 100.011*/
#include<bits/stdc++.h>
using namespace std;

// Function to convert decimal to binary upto k-precision after decimal point
string decimalToBinary(double num, int k_prec)
{
	string binary = "";

	// Fetch the integral part of decimal number
	int Integral = num;

	// Fetch the fractional part decimal number
	double fractional = num - Integral;

	// Conversion of integral part to binary equivalent
	while (Integral)
	{
		int rem = Integral % 2;

		// Append 0 in binary
		binary.push_back(rem +'0');

		Integral /= 2;
	}

	// Reverse string to get original binary equivalent
	reverse(binary.begin(),binary.end());

	// Append point before conversion of fractional part
	binary.push_back('.');

	// Conversion of fractional part to binary equivalent
	while (k_prec--)
	{
		// Find next bit in fraction
		fractional *= 2;
		int fract_bit = fractional;

		if (fract_bit == 1)
		{
			fractional -= fract_bit;
			binary.push_back(1 + '0');
		}
		else
			binary.push_back(0 + '0');
	}

	return binary;
}

int main()
{

	double n = 4.47;
	int k = 3;
	cout << decimalToBinary(n, k) <<endl;

	n = 6.986 , k = 5;
	cout << decimalToBinary(n, k)<<endl;
	return 0;
}
