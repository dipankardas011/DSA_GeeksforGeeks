/*Check if binary representations of two numbers are anagram
Difficulty Level : Easy
Last Updated : 29 Apr, 2021
Given two numbers you are required to check whether they are anagrams of each other or not in binary representation.
Examples: 
 

Input : a = 8, b = 4 
Output : Yes
Binary representations of both
numbers have same 0s and 1s.

Input : a = 4, b = 5
Output : No*/
// A simple C++ program to check if binary
// representations of two numbers are anagram.
#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

const int SIZE = 8 * sizeof(ull);

bool bit_anagram_check(ull a, ull b)
{
	// Find reverse binary representation of a
	// and store it in binary_a[]
	int i = 0, binary_a[SIZE] = { 0 };
	while (a > 0) {
		binary_a[i] = a % 2;
		a /= 2;
		i++;
	}

	// Find reverse binary representation of b
	// and store it in binary_a[]
	int j = 0, binary_b[SIZE] = { 0 };
	while (b > 0) {
		binary_b[j] = b % 2;
		b /= 2;
		j++;
	}

	// Sort two binary representations
	sort(binary_a, binary_a + SIZE);
	sort(binary_b, binary_b + SIZE);

	// Compare two sorted binary representations
	for (int i = 0; i < SIZE; i++)
		if (binary_a[i] != binary_b[i])
			return false;

	return true;
}

// Driver code
int main()
{
	ull a = 8, b = 4;
	cout << (bit_anagram_check(a, b)?"YES":"NO") << endl;
	return 0;
}