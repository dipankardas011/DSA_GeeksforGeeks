/*Minimum number of deletions to make a string palindrome
Difficulty Level : Medium
Last Updated : 18 Jun, 2021
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

Note: The order of characters should be maintained. 

Examples : 

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8

Algorithm: 

1. str is the given string.

2. n length of str

3. len be the length of the longest 
  palindromic subsequence of str

4. minimum number of deletions 
  min = n – len
  O(n^2)
  
Another Approach:

Take two indexes first as ‘i’ and last as a ‘j’
now compare the character at the index ‘i’ and ‘j’
if characters are equal, then 
recursively call the function by incrementing ‘i’ by ‘1’ and decrementing ‘j’ by ‘1’
else 
recursively call the two functions, the first increment ‘i’ by ‘1’ keeping ‘j’ constant, second decrement ‘j’ by ‘1’ keeping ‘i’ constant.
take a minimum of both and return by adding ‘1’
*/
// C++ program for above approach
#include <iostream>
using namespace std;

// Utility function for calculating
// Minimum element to delete
int utility_fun_for_del(string str, int i, int j)
{
	if (i >= j)
		return 0;

	// Condition to compare characters
	if (str[i] == str[j])
	{

		// Recursive function call
		return utility_fun_for_del(str, i + 1, j - 1);
	}

	// Return value, incrementing by 1
	return 1 + std::min(utility_fun_for_del(str, i + 1, j), utility_fun_for_del(str, i, j - 1));
}

// Function to calculate the minimum
// Element required to delete for
// Making string pelindrom
int min_ele_del(string str)
{

	// Utility function call
	return utility_fun_for_del(str, 0, str.length() - 1);
}

// Driver code
int main()
{
	string str = "abefbac";
	cout << "Minimum element of deletions = "<< min_ele_del(str) << endl;
	return 0;
}