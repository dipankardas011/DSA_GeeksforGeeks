/*Lexicographically smallest string whose hamming distance from given string is exactly K
Given a lowercase string A of length N and an integer K, find the lexicographically smallest string B of the same length as A such that hamming distance between A and B is exactly K.
Examples: 
 

Input : A = "pqrs", k = 1.
Output : aqrs
We can differ by at most one
character. So we put 'a' in the
beginning to make the result 
lexicographically smallest.

Input : A = "pqrs", k = 2.
Output : aars*/
// CPP program to find Lexicographically
// smallest string whose hamming distance
// from given string is exactly K
#include <bits/stdc++.h>
using namespace std;

// function to find Lexicographically
// smallest string with hamming distance k
void findString(string str, int n, int k)
{
    // If k is 0, output input string
    if (k == 0)
    {
        cout << str << endl;
        return;
    }

    // Copying input string into output
    // string
    string str2 = str;
    int p = 0;

    // Traverse all the character of the
    // string
    for (int i = 0; i < n; i++)
    {

        // If current character is not 'a'
        if (str2[i] != 'a')
        {

            // copy character 'a' to
            // output string
            str2[i] = 'a';
            p++;

            // If hamming distance became k,
            // break;
            if (p == k)
                break;
        }
    }

    // If k is less than p
    if (p < k)
    {

        // Traversing string in reverse
        // order
        for (int i = n - 1; i >= 0; i--)
            if (str[i] == 'a')
            {
                str2[i] = 'b';
                p++;

                if (p == k)
                    break;
            }
    }

    cout << str2 << endl;
}

// Driven Program
int main()
{
    string str = "pqrs";
    int n = str.length();
    int k = 2;

    findString(str, n, k);

    return 0;
}
