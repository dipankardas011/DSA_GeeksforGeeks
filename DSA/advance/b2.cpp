/*@b2.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define N 4

struct query
{
    int x1, y1; // x and y co-ordinates of bottom left
    int x2, y2; // x and y co-ordinates of top right
};

void updateBIT(int bit[][N + 1], int x, int y, int val)
{
    for (; x <= N; x += (x & -x))
    {
        // this loop update all the 1D BIT inside the array of 1D bit = bit[x]
        for (; y <= N; y += (y & -y))
            bit[x][y] += val;
    }
    return;
}
// a function to get sum from (0,0) - (x,y)
int getsum(int bit[][N + 1], int x, int y)
{
    int sum = 0;
    for (; x > 0; x -= (x & -x))
    {
        for (; y > 0; y -= (y & -y))
            sum += bit[x][y];
    }
    return sum;
}

void constructAUX(int mat[][N], int aux[][N + 1])
{
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            aux[i][j] = 0;
    // to get auxillary matrix
    for (int j = 1; j <= N; j++)
        for (int i = 1; i <= N; i++)
            aux[i][j] = mat[N - j][i - 1];
}

void construct2DBIT(int mat[][N], int bit[][N + 1])
{
    int aux[N + 1][N + 1];
    constructAUX(mat, aux);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            bit[i][j] = 0;

    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            int v1 = getsum(bit, i, j);
            int v2 = getsum(bit, i, j - 1);
            int v3 = getsum(bit, i - 1, j - 1);
            int v4 = getsum(bit, i - 1, j);

            updateBIT(bit, i, j, aux[i][j] - (v1 + v2 + v3 + v4));
        }
    }
}
// A function to answer the queries
void answerQueries(query q[], int m, int BIT[][N + 1])
{
    for (int i = 0; i < m; i++)
    {
        int x1 = q[i].x1 + 1;
        int y1 = q[i].y1 + 1;
        int x2 = q[i].x2 + 1;
        int y2 = q[i].y2 + 1;

        int ans = getsum(BIT, x2, y2) - getsum(BIT, x2, y1 - 1) -
                  getsum(BIT, x1 - 1, y2) + getsum(BIT, x1 - 1, y1 - 1);

        printf("Query(%d, %d, %d, %d) = %d\n",
               q[i].x1, q[i].y1, q[i].x2, q[i].y2, ans);
    }
    return;
}

int main()
{
    int mat[N][N] = {{1, 2, 3, 4},
                     {5, 3, 8, 1},
                     {4, 6, 7, 5},
                     {2, 4, 8, 9}};

    // Create a 2D Binary Indexed Tree
    int BIT[N + 1][N + 1];
    construct2DBIT(mat, BIT);

    /* Queries of the form - x1, y1, x2, y2
       For example the query- {1, 1, 3, 2} means the sub-matrix-
    y
    /\
 3  |       1 2 3 4      Sub-matrix
 2  |       5 3 8 1      {1,1,3,2}      --->     3 8 1
 1  |       4 6 7 5                                 6 7 5
 0  |       2 4 8 9
    |
  --|------ 0 1 2 3 ----> x
    |
  
    Hence sum of the sub-matrix = 3+8+1+6+7+5 = 30
  
    */

    query q[] = {{1, 1, 3, 2}, {2, 3, 3, 3}, {1, 1, 1, 1}};
    int m = sizeof(q) / sizeof(q[0]);

    answerQueries(q, m, BIT);
    return 0;
}