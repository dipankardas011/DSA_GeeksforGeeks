/*First uppercase letter in a string (Iterative and Recursive)
Difficulty Level : Basic
Last Updated : 26 Apr, 2021
Given a string find its first uppercase letter
Examples : 

Input : geeksforgeeKs
Output : K

Input  : geekS
Output : S*/
// C++ program to find the first
// uppercase letter using linear search
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function to find string which has
// first character of each word.
char first(string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isupper(str[i]))
			return str[i];
	return 0;
}

int main()
{
	string str = "geeksforGeeKS";
	char res = first(str);
	if (res == 0)
		cout << "No uppercase letter";
	else
		cout << res << "\n";
	return 0;
}
