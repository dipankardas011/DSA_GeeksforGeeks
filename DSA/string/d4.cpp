/*Program to count occurrence of a given character in a string
Difficulty Level : Basic
Last Updated : 16 Jun, 2021
Given a string and a character, task is to make a function which count occurrence of the given character in the string.
Examples: 
 

Input : str = "geeksforgeeks"
         c = 'e'
Output : 4
'e' appears four times in str.

Input : str = "abccdefgaa"
          c = 'a' 
Output : 3
'a' appears three times in str.*/
// CPP program to count occurrences of
// a character using library
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    string str = "geeksforgeeks";
    char c = 'e';

    // Count returns number of occurrences of
    // c between two given positions provided
    // as two iterators.
    cout << count(str.begin(), str.end(), c);
    return 0;
}