/*Sort a string according to the order defined by another string
Difficulty Level : Easy
Last Updated : 16 Jun, 2021
Given two strings (of lowercase letters), a pattern and a string. The task is to sort string according to the order defined by pattern. It may be assumed that pattern has all characters of the string and all characters in pattern appear only once.
Examples: 
 

Input  : pat = "bca", str = "abc"
Output : str = "bca"

Input  : pat = "bxyzca", str = "abcabcabc"
Output : str = "bbbcccaaa"

Input  : pat = "wcyuogmlrdfphitxjakqvzbnes", str = "jcdokai"
Output : str = "codijak"
The idea is to first count occurrences of all characters in str and store these counts in a count array. Then traverse pattern from left to right, and for each character pat[i], see how many times it appears in count array and copy this character these many times to str.*/

/*task:
Exercise : In the above solution, it is assumed that pattern has all characters of str. Consider a modified version where pattern may not have all characters and the task is to put all remaining characters (in string but not in pattern) at the end. The remaining characters need to be put in alphabetically sorted order.
Hint : In the second loop, when increase index and put character in str, we can also decrease count at that time. And finally we traverse the count array to put remaining characters in alphabetically sorted order.*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR  26

// Sort str according to the order defined by pattern.
void sortByPattern(string& str, string pat)
{
	// Create a count array store count of characters in str.
	int count[MAX_CHAR] = { 0 };

	// Count number of occurrences of each character in str.
	for (int i = 0; i < str.length(); i++)
		count[str[i] - 'a']++;

    
	// Traverse the pattern and print every characters same number of times as it appears in str. This loop takes O(m + n) time where m is length of pattern and n is length of str.
	int index = 0;
	for (int i = 0; i < pat.length(); i++)
		for (int j = 0; j < count[pat[i] - 'a']; j++)
			str[index++] = pat[i];
}

int main()
{
	string pat = "bca";
	string str = "abc";
	sortByPattern(str, pat);
	cout << str<<endl;

    string pat1 = "wcyuogmlrdfphitxjakqvzbnes";
	string str1 = "jcdokai";
	sortByPattern(str1, pat1);
	cout << str1<<endl;
	return 0;
}
