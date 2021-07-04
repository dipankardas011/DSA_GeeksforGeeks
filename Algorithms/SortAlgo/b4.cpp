/*Program to check if an array is sorted or not (Iterative and Recursive)
Difficulty Level : Easy
Last Updated : 09 Jun, 2021
Geek-O-Lympics
Given an array of size n, write a program to check if it is sorted in ascending order or not. Equal values are allowed in an array and two consecutive equal values are considered sorted.

Examples: 

Input : 20 21 45 89 89 90
Output : Yes

Input : 20 20 45 89 89 90
Output : Yes

Input : 20 20 78 98 99 97
Output : No*/
// C++ program to check if an
// Array is sorted or not
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if array is
// sorted in non-decreasing order.
bool arraySortedOrNot(int arr[], int n)
{
	// Array has one or no element
	if (n == 0 || n == 1)
		return true;

	for (int i = 1; i < n; i++)

		// Unsorted pair found
		if (arr[i - 1] > arr[i])
			return false;

	// No unsorted pair found
	return true;
}
int main(int argc, char const *argv[])
{
	int arr[] = { 20, 23, 23, 45, 78, 88 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (arraySortedOrNot(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";

    remove(argv[0]);
    return 0;
}
