/*Given a matrix of ‘O’ and ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’

Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it. 
Examples: 
 

Input: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
 

Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
 

Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
 

This is mainly an application of Flood-Fill algorithm. The main difference here is that a ‘O’ is not replaced by ‘X’ if it lies in region that ends on a boundary. Following are simple steps to do this special flood fill.
1) Traverse the given matrix and replace all ‘O’ with a special character ‘-‘.
2) Traverse four edges of given matrix and call floodFill(‘-‘, ‘O’) for every ‘-‘ on edges. The remaining ‘-‘ are the characters that indicate ‘O’s (in the original matrix) to be replaced by ‘X’.
3) Traverse the matrix and replace all ‘-‘s with ‘X’s. 
Let us see steps of above algorithm with an example. Let following be the input matrix. 



       mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Step 1: Replace all ‘O’ with ‘-‘. 

       mat[M][N] =  {{'X', '-', 'X', 'X', 'X', 'X'},
                     {'X', '-', 'X', 'X', '-', 'X'},
                     {'X', 'X', 'X', '-', '-', 'X'},
                     {'-', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', '-', 'X', '-'},
                     {'-', '-', 'X', '-', '-', '-'},
                    };
Step 2: Call floodFill(‘-‘, ‘O’) for all edge elements with value equals to ‘-‘ 

       mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', '-', 'X'},
                     {'X', 'X', 'X', '-', '-', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Step 3: Replace all ‘-‘ with ‘X’. 

       mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };*/

#include <iostream>
using namespace std;

// Size of given matrix is M X N
#define M 6
#define N 6

/** @def A recursive function to replace previous value 'prevV' at '(x, y)' and all surrounding values of (x, y) with new value 'newV'.*/
void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;

    if (mat[x][y] != prevV)
        return;

    // Replace the color at (x, y)
    mat[x][y] = newV;

    // Recur for north, east, south and west
    floodFillUtil(mat, x + 1, y, prevV, newV);

    floodFillUtil(mat, x - 1, y, prevV, newV);

    floodFillUtil(mat, x, y + 1, prevV, newV);

    floodFillUtil(mat, x, y - 1, prevV, newV);
}

/** @def Returns size of maximum size subsquare matrix surrounded by 'X'*/
void replaceSurrounded(char mat[][N])
{
    // Step 1: Replace all 'O' with '-'
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    // Call floodFill for all '-' lying on edges
    for (int i = 0; i < M; i++) // Left side
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');

    for (int i = 0; i < M; i++) // Right side
        if (mat[i][N - 1] == '-')
            floodFillUtil(mat, i, N - 1, '-', 'O');

    for (int i = 0; i < N; i++) // Top side
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');

    for (int i = 0; i < N; i++) // Bottom side
        if (mat[M - 1][i] == '-')
            floodFillUtil(mat, M - 1, i, '-', 'O');

    // Step 3: Replace all '-' with 'X'
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

// Driver program to test above function
int main()
{
    char mat[][N] = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };
    replaceSurrounded(mat);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
