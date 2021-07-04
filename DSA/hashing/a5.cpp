/*Find all permuted rows of a given row in a matrix

We are given a m*n matrix of positive integers and a row number. The task is to find all rows in given matrix which are permutations of given row elements. It is also given that values in every row are distinct.

Examples:

Input : mat[][] = {{3, 1, 4, 2}, 
                   {1, 6, 9, 3},
                   {1, 2, 3, 4},
                   {4, 3, 2, 1}}
        row = 3    
Output: 0, 2
Rows at indexes 0 and 2 are permutations of
row at index 3.*/
// we have to check which rows have equal elements as 
// specified in the row index r
#include<bits/stdc++.h>
#define MAX 100

using namespace std;

// Function to find all permuted rows of a given row r
void permutatedRows(int mat[][MAX], int m, int n, int r)
{
	// Creating an empty set
	unordered_set<int> s;

	// Count frequencies of elements in given row r
	for (int j=0; j<n; j++)
		s.insert(mat[r][j]);

	// Traverse through all remaining rows
	for (int i=0; i<m; i++)
	{
		// we do not need to check for given row r
		if (i==r)
			continue;

		// initialize hash i.e; count frequencies
		// of elements in row i
		int j;
		for (j=0; j<n; j++)
			if (s.find(mat[i][j]) == s.end())
				break;
		if (j != n)
		continue;

		cout << i << " ";
	}
}

// Driver program to run the case
int main()
{
	int m = 4, n = 4,r = 3;
	int mat[][MAX] = {{3, 1, 4, 2},
					{1, 6, 9, 3},
					{1, 2, 3, 4},
					{4, 3, 2, 1}};
	permutatedRows(mat, m, n, r);
	return 0;
}