/*Queries on substring palindrome formation
Difficulty Level : Medium
Last Updated : 14 May, 2021
Given a string S, and two types of queries. 

Type 1: 1 L x, Indicates update Lth index 
               of string S by x character.
Type 2: 2 L R, Find if characters between position L and R 
               of string, S can form a palindrome string. 
               If palindrome can be formed print "Yes", 
               else print "No".
1 <= L, R <= |S| 
Examples: 
 

Input : S = "geeksforgeeks"
Query 1: 1 4 g
Query 2: 2 1 4
Query 3: 2 2 3
Query 4: 1 10 t
Query 5: 2 10 11
Output :
Yes
Yes
No

Query 1: update index 3 (position 4) of string S by 
character 'g'. So new string S = "geegsforgeeks".

Query 2: find if rearrangement between index 0 and 3
can form a palindrome. "geegs" is palindrome, print "Yes".

Query 3: find if rearrangement between index 1 and 2 
can form a palindrome. "ee" is palindrome, print "Yes".

Query 4: update index 9 (position 10) of string S by 
character 't'. So new string S = "geegsforgteks".

Query 3: find if rearrangement between index 9 and 10 
can form a palindrome. "te" is not palindrome, print "No".
Substring S[L…R] form a palindrome only if frequencies of all the characters in S[L…R] are even, with one except allowed. 
 

For query of type 1, simply update string 
S[L] by character x.

For each query of type 2, calculate the 
frequency of character and check if 
frequencies of all characters is even (with)
one exception allowed.
Following are two different methods to find the frequency of each character in S[L…R]:*/
// C++ program to Queries on substring palindrome
// formation.
#include <bits/stdc++.h>
#define max 1000
using namespace std;

// Return the frequency of the character in the
// i-th prefix.
int getFrequency(int tree[max][27], int idx, int i)
{
    int sum = 0;

    while (idx > 0)
    {
        sum += tree[idx][i];
        idx -= (idx & -idx);
    }

    return sum;
}

// Updating the BIT
void update(int tree[max][27], int idx, int val, int i)
{
    while (idx <= max)
    {
        tree[idx][i] += val;
        idx += (idx & -idx);
    }
}

// Query to update the character in the string.
void qType1(int tree[max][27], int l, int x, char str[])
{
    // Adding -1 at L position
    update(tree, l, -1, str[l - 1] - 97 + 1);

    // Updating the character
    str[l - 1] = x;

    // Adding +1 at R position
    update(tree, l, 1, str[l - 1] - 97 + 1);
}

// Query to find if rearrangement of character in range
// L...R can form palindrome
void qType2(int tree[max][27], int l, int r, char str[])
{
    int count = 0;

    for (int i = 1; i <= 26; i++)
    {
        // Checking on the first character of the string S.
        if (l == 1)
        {
            if (getFrequency(tree, r, i) % 2 == 1)
                count++;
        }
        else
        {
            // Checking if frequency of character is even or odd.
            if ((getFrequency(tree, r, i) - getFrequency(tree, l - 1, i)) % 2 == 1)
                count++;
        }
    }

    (count <= 1) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

// Creating the Binary Index Tree of all aphabet
void buildBIT(int tree[max][27], char str[], int n)
{
    memset(tree, 0, sizeof(tree));

    for (int i = 0; i < n; i++)
        update(tree, i + 1, 1, str[i] - 97 + 1);
}

// Driven Program
int main()
{
    char str[] = "geeksforgeeks";
    int n = strlen(str);

    int tree[max][27];
    buildBIT(tree, str, n);

    qType1(tree, 4, 'g', str);
    qType2(tree, 1, 4, str);
    qType2(tree, 2, 3, str);
    qType1(tree, 10, 't', str);
    qType2(tree, 10, 11, str);

    return 0;
}
