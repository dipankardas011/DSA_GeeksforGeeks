/*Print all ways to break a string in bracket form
Difficulty Level : Hard
Last Updated : 05 Nov, 2020
Given a string, find all ways to break the given string in bracket form. Enclose each substring within a parenthesis.

Examples: 

Input : abc
Output: (a)(b)(c)
        (a)(bc)
        (ab)(c)
        (abc)


Input : abcd
Output : (a)(b)(c)(d)
         (a)(b)(cd)
         (a)(bc)(d)
         (a)(bcd)
         (ab)(c)(d)
         (ab)(cd)
         (abc)(d)
         (abcd)
![](./image12.png)*/
// C++ Program to find all combinations of Non-
// overlapping substrings formed from given
// string
#include <iostream>
using namespace std;

// find all combinations of non-overlapping
// substrings formed by input string str
// index – index of the next character to
//		 be processed
// out - output string so far
void findCombinations(string str, int index, string out)
{
	if (index == str.length())
		cout << out << endl;

	for (int i = index; i < str.length(); i++)
	{
		// append substring formed by str[index,
		// i] to output string
		findCombinations(str,i + 1,	out + "(" + str.substr(index, i + 1 - index)+ ")");
	}
}

// Driver Code
int main()
{
	// input string
	string str = "abcd";

	findCombinations(str, 0, "");

	return 0;
}
