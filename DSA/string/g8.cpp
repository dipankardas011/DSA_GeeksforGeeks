/*Breaking a number such that first part is integral division of second by a power of 10
Difficulty Level : Easy
Last Updated : 30 Dec, 2019
Given a very large number N, we need to count the total ways such that if we divide the number into two parts a and b, the first part a can be obtained by integral division of second b by some power p of 10 and p>=0.
1 <= No of digits in N <= 10^5.

Examples:

Input : 220
Output : 1
220 can be divided as a = 2 and b = 20
such that for p = 1, b/10 = a.


Input : 1111
Output : 2
We get answer 2 because we need to consider
integral division.
Let's consider the first partition a = 1,
b = 111. for p = 2, b/pow(10,p) = a thus
this is a valid partition.
now a = 11, b = 11. for p = 0, b/pow(10,p) 
= a thus this too is a valid combination.

Input : 2202200
Output : 2
for a = 2 b = 202200, p = 5 and
a = 220, b = 2200, p = 1*/
#include <bits/stdc++.h>
using namespace std;

// c++ function to count ways to divide a string in two parts a and b such that b/pow(10, p) == a
int calculate(string N)
{
    int len = N.length();
    int l = (len) / 2;
    int count = 0;

    for (int i = 1; i <= l; i++)
    {

        // substring representing int a
        string s = N.substr(0, i);

        // no of digits in a
        int l1 = s.length();

        // consider only most significant  l1 characters of remaining string  for int b
        string t = N.substr(i, l1);

        // if any of a or b contains leading 0s discard this combination
        if (s[0] == '0' || t[0] == '0')
            continue;

        // if both are equal
        if (s.compare(t) == 0)
            count++;
    }
    return count;
}

int main()
{
    string N = "2202200";
    cout << calculate(N) << endl;
    return 0;
}