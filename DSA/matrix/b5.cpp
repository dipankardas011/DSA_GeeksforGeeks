/*Replace every matrix element with maximum of GCD of row or column
Difficulty Level : Easy
Last Updated : 21 May, 2021
Given a matrix of n rows and m columns. The task is to replace each matrix element with Greatest Common Divisor of its row or column, whichever is maximum. That is, for each element (i, j) replace it from GCD of i’th row or GCD of j’th row, whichever is greater.
Examples : 
 

Input : mat[3][4] = {1, 2, 3, 3,
                     4, 5, 6, 6
                     7, 8, 9, 9}  
Output :  1 1 3 3
          1 1 3 3
          1 1 3 3
For index (0,2), GCD of row 0 is 1, GCD of row 2 is 3.
So replace index (0,2) with 3 (3>1). 

An Efficient method is to make two arrays of size n and m for row and column respectively. And store the GCD of each row and each column. An Array of size n will contain GCD of each row and array of size m will contain the GCD of each column. And replace each element with maximum of its corresponding row GCD or column GCD.*/
#include <iostream>
#include <algorithm>
using namespace std;
#define r 3
#define c 4
/**
 * @def finding the gcd of each row and col and replacing with each ele
 * with max of gcd of row and col
*/
void replaceMatrix(int a[r][c], int m, int n)
{
    int rgcd[r] = {0}, cgcd[c] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rgcd[i] = __gcd(rgcd[i], a[i][j]);
            cgcd[j] = __gcd(cgcd[j], a[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = max(cgcd[j], rgcd[i]);
}

int main()
{
    int a[r][c] = {1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9};
    replaceMatrix(a, r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}