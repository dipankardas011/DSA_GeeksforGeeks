/*Check divisibility of binary string by 2^k
Difficulty Level : Easy
Last Updated : 04 May, 2021
Given a binary string and a number k, task is to check whether the binary string is evenly divisible by 2k or not. 

Examples : 

Input : 11000  k = 2
Output : Yes
Explanation :
(11000)2 = (24)10
24 is evenly divisible by 2k i.e. 4.
 
Input : 10101  k = 3
Output : No
Explanation : 
(10101)2 = (21)10
21 is not evenly divisible by 2k i.e. 8.*/
// C++ implementation to check whether
// given binary number is evenly
// divisible by 2^k or not
#include <bits/stdc++.h>
using namespace std;

// function to check whether
// given binary number is
// evenly divisible by 2^k or not
bool isDivisible(char str[], int k)
{
	int n = strlen(str);
	int c = 0;
	
	// count of number of 0 from last
	for (int i = 0; i < k; i++)
		if (str[n - i - 1] == '0')		
			c++;
	
	// if count = k, number is evenly
	// divisible, so returns true else
	// false
	return (c == k);
}

// Driver program to test above
int main()
{
	// first example
	char str1[] = "10101100";
	int k = 2;
	if (isDivisible(str1, k))
		cout << "Yes" << endl;
	else
		cout << "No"
			<< "\n";

	// Second example
	char str2[] = "111010100";
	k = 2;
	if (isDivisible(str2, k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}