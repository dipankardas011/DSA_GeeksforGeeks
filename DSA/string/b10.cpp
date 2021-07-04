// Reverse string without using any temporary variable
// We are given a string. We are also given indexes of first and last characters in string. The task is to reverse the string without using any extra variable.
// Examples: 
 

// Input  : str = "abc"
// Output : str = "cba" 

// Input :  str = "GeeksforGeeks"
// Output : str = "skeeGrofskeeG"
// Reversing a string using reverse()
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   string str = "geeksforgeeks";

   // Reverse str[beign..end]
   std::reverse(str.begin(), str.end());

   cout << str;
   return 0;
}