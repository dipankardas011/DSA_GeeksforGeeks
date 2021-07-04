/*Find size of the largest ‘+’ formed by all ones in a binary matrix
Difficulty Level : Hard
Last Updated : 08 Apr, 2021
Given a N X N binary matrix, find the size of the largest ‘+’ formed by all 1s.
Example: 
 



For above matrix, largest ‘+’ would be formed by highlighted part of size 17.
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
The idea is to maintain four auxiliary matrices left[][], right[][], top[][], bottom[][] to store consecutive 1’s in every direction. For each cell (i, j) in the input matrix, we store below information in these four matrices –
 

left(i, j) stores maximum number of
consecutive 1's to the left of cell (i, j) 
including cell (i, j).

right(i, j) stores maximum number of
consecutive 1's to the right of cell (i, j) 
including cell (i, j).

top(i, j) stores maximum number of
consecutive 1's at top of cell (i, j) 
including cell (i, j).

bottom(i, j) stores maximum number of
consecutive 1's at bottom of cell (i, j) 
including cell (i, j).
After computing value for each cell of above matrices, the largest + would be formed by a cell of input matrix that has maximum value by considering minimum of (left(i, j), right(i, j), top(i, j), bottom(i, j) )
We can use Dynamic Programming to compute the total amount of consecutive 1’s in every direction. 
 



if mat(i, j) == 1
    left(i, j) = left(i, j - 1) + 1
else left(i, j) = 0

if mat(i, j) == 1
    top(i, j) = top(i - 1, j) + 1;
else
    top(i, j) = 0;

if mat(i, j) == 1
    bottom(i, j) = bottom(i + 1, j) + 1;
else
    bottom(i, j) = 0;    

if mat(i, j) == 1
    right(i, j) = right(i, j + 1) + 1;
else
    right(i, j) = 0;*/

// C++ program to find the size of the largest '+'
// formed by all 1's in given binary matrix
#include <bits/stdc++.h>
using namespace std;

// size of binary square matrix
#define N 10

// Function to find the size of the largest '+'
// formed by all 1's in given binary matrix
int findLargestPlus(int mat[N][N])
{
	// left[j][j], right[i][j], top[i][j] and
	// bottom[i][j] store maximum number of
	// consecutive 1's present to the left,
	// right, top and bottom of mat[i][j] including
	// cell(i, j) respectively
	int left[N][N], right[N][N], top[N][N],
		bottom[N][N];

	// initialize above four matrix
	for (int i = 0; i < N; i++)
	{
		// initialize first row of top
		top[0][i] = mat[0][i];

		// initialize last row of bottom
		bottom[N - 1][i] = mat[N - 1][i];

		// initialize first column of left
		left[i][0] = mat[i][0];

		// initialize last column of right
		right[i][N - 1] = mat[i][N - 1];
	}

	// fill all cells of above four matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			// calculate left matrix (filled left to right)
			if (mat[i][j] == 1)
				left[i][j] = left[i][j - 1] + 1;
			else
				left[i][j] = 0;

			// calculate top matrix
			if (mat[j][i] == 1)
				top[j][i] = top[j - 1][i] + 1;
			else
				top[j][i] = 0;

			// calculate new value of j to calculate
			// value of bottom(i, j) and right(i, j)
			j = N - 1 - j;

			// calculate bottom matrix
			if (mat[j][i] == 1)
				bottom[j][i] = bottom[j + 1][i] + 1;
			else
				bottom[j][i] = 0;

			// calculate right matrix
			if (mat[i][j] == 1)
				right[i][j] = right[i][j + 1] + 1;
			else
				right[i][j] = 0;

			// revert back to old j
			j = N - 1 - j;
		}
	}

	// n stores length of longest + found so far
	int n = 0;

	// compute longest +
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// find minimum of left(i, j), right(i, j),
			// top(i, j), bottom(i, j)
			int len = min(min(top[i][j], bottom[i][j]),
						min(left[i][j], right[i][j]));

			// largest + would be formed by a cell that
			// has maximum value
			if(len > n)
				n = len;
		}
	}

	// 4 directions of length n - 1 and 1 for middle cell
	if (n)
	return 4 * (n - 1) + 1;

	// matrix contains all 0's
	return 0;
}

/* Driver function to test above functions */
int main()
{
	// Binary Matrix of size N
	int mat[N][N] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};

	cout << findLargestPlus(mat);

	return 0;
}