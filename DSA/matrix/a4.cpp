/**
 * Shift matrix elements row-wise by k
Difficulty Level : Easy
Last Updated : 24 May, 2021
Given a square matrix mat[][] and a number k. The task is to shift the first k elements of each row to the right of the matrix.

Examples :  

Input : mat[N][N] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}}
        k = 2
Output :mat[N][N] = {{3, 1, 2}
                     {6, 4, 5}
                     {9, 7, 8}}

Input : mat[N][N] = {{1, 2, 3, 4}
                     {5, 6, 7, 8}
                     {9, 10, 11, 12}
                     {13, 14, 15, 16}}
        k = 2
Output :mat[N][N] = {{3, 4, 1, 2}
                     {7, 8, 5, 6}
                     {11, 12, 9, 10}
                     {15, 16, 13, 14}}

Note: Matrix should be a square matrix 
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
*/
#include <iostream>
using namespace std;
#define N 4
 
// Function to shift first k elements of
// each row of matrix.
void shiftMatrixByK(int mat[N][N], int k)
{
    if (k > N) {
        cout << "shifting is not possible" << endl;
        return;
    }
     
    int j = 0;
    while (j < N) {
         
        // Print elements from index k
        for (int i = k; i < N; i++)
            cout << mat[j][i] << " ";
             
        // Print elements before index k
        for (int i = 0; i < k; i++)
            cout << mat[j][i] << " ";
             
        cout << endl;
        j++;
    }
}
 
// Driver code
int main()
{
    int mat[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int k = 2;
     
    // Function call
    shiftMatrixByK(mat, k);
     
    return 0;
}