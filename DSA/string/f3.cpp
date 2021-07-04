/*Min flips of continuous characters to make all characters same in a string
Difficulty Level : Easy
Last Updated : 07 Apr, 2021
Given a string consisting only of 1’s and 0’s. In one flip we can change any continuous sequence of this string. Find this minimum number of flips so the string consist of same characters only.
Examples: 
 

Input : 00011110001110
Output : 2
We need to convert 1's sequence
so string consist of all 0's.

Input : 010101100011
Output : 4*/
// CPP program to find min flips in binary
// string to make all characters equal
#include <bits/stdc++.h>
using namespace std;

// To find min number of flips in binary string
int findFlips(char str[], int n)
{
    char last = ' ';
    int res = 0;

    for (int i = 0; i < n; i++)
    {

        // If last character is not equal
        // to str[i] increase res
        if (last != str[i])
            res++;
        last = str[i];
    }

    // To return min flips
    return res / 2;
}

// Driver program to check findFlips()
int main()
{
    char str[] = "00011110001110";
    int n = strlen(str);

    cout << findFlips(str, n)<<endl;

    return 0;
}
