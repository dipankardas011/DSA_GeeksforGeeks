/*Find Shortest distance from a guard in a Bank
Difficulty Level : Medium
Last Updated : 23 Feb, 2021
Given a matrix that is filled with ‘O’, ‘G’, and ‘W’ where ‘O’ represents open space, ‘G’ represents guards and ‘W’ represents walls in a Bank. Replace all of the O’s in the matrix with their shortest distance from a guard, without being able to go through any walls. Also, replace the guards with 0 and walls with -1 in output matrix.
Expected Time complexity is O(MN) for a M x N matrix.

Examples:

O ==> Open Space
G ==> Guard
W ==> Wall

Input: 
  O  O  O  O  G
  O  W  W  O  O
  O  O  O  W  O
  G  W  W  W  O
  O  O  O  O  G

Output:  
  3  3  2  1  0
  2 -1 -1  2  1
  1  2  3 -1  2
  0 -1 -1 -1  1
  1  2  2  1  0*/

#include <bits/stdc++.h>
using namespace std;

// store dimensions of the matrix
#define M 5
#define N 5

// An Data Structure for queue used in BFS
struct queueNode
{
	// i, j and distance stores x and y-coordinates
	// of a matrix cell and its distance from guard
	// respectively
	int i, j, distance;
};

// These arrays are used to get row and column
// numbers of 4 neighbors of a given cell
int row[] = { -1, 0, 1, 0};
int col[] = { 0, 1, 0, -1 };

// return true if row number and column number
// is in range
bool isValid(int i, int j)
{
	if ((i < 0 || i > M - 1) || (j < 0 || j > N - 1))
		return false;

	return true;
}

// return true if current cell is an open area and its
// distance from guard is not calculated yet
bool isSafe(int i, int j, char matrix[][N], int output[][N])
{
	if (matrix[i][j] != 'O' || output[i][j] != -1)
		return false;

	return true;
}

// Function to replace all of the O's in the matrix
// with their shortest distance from a guard
void findDistance(char matrix[][N])
{
	int output[M][N];
	queue<queueNode> q;

	// finding Guards location and adding into queue
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// initialize each cell as -1
			output[i][j] = -1;
			if (matrix[i][j] == 'G')
			{
				queueNode pos = {i, j, 0};
				q.push(pos);
				// guard has 0 distance
				output[i][j] = 0;
			}
		}
	}

	// do till queue is empty
	while (!q.empty())
	{
		// get the front cell in the queue and update
		// its adjacent cells
		queueNode curr = q.front();
		int x = curr.i, y = curr.j, dist = curr.distance;

		// do for each adjacent cell
		for (int i = 0; i < 4; i++)
		{
			// if adjacent cell is valid, has path and
			// not visited yet, en-queue it.
			if (isSafe(x + row[i], y + col[i], matrix, output)
				&& isValid(x + row[i], y + col[i]))
			{
				output[x + row[i]][y + col[i]] = dist + 1;

				queueNode pos = {x + row[i], y + col[i], dist + 1};
				q.push(pos);
			}
		}

		// dequeue the front cell as its distance is found
		q.pop();
	}

	// print output matrix
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << std::setw(3) << output[i][j];
		cout << endl;
	}
}

// Driver code
int main()
{
	char matrix[][N] =
	{
		{'O', 'O', 'O', 'O', 'G'},
		{'O', 'W', 'W', 'O', 'O'},
		{'O', 'O', 'O', 'W', 'O'},
		{'G', 'W', 'W', 'W', 'O'},
		{'O', 'O', 'O', 'O', 'G'}
	};

	findDistance(matrix);

	return 0;
}
