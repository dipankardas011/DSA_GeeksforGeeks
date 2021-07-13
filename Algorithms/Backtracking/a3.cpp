/*N Queen Problem | Backtracking-3
Difficulty Level : Hard
Last Updated : 16 Oct, 2019
We have discussed Knight’s tour and Rat in a Maze problems in Set 1 and Set 2 respectively. Let us discuss N Queen as another example problem that can be solved using Backtracking.

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.

![](https://media.geeksforgeeks.org/wp-content/uploads/N_Queen_Problem.jpg)

The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example, following is the output matrix for above 4 queen solution.

              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0}
Optimization in is_safe() function
The idea is not to check every element in right and left diagonal instead use property of diagonals:
1.The sum of i and j is constant and unique for each right diagonal where i is the row of element and j is the
column of element.
2.The difference of i and j is constant and unique for each left diagonal where i and j are row and column of element respectively.

Implementation of Backtracking solution(with optimization)*/
#define N 4
#include <stdbool.h>
#include <stdio.h>
/* ld is an array where its indices indicate row-col+N-1
 (N-1) is for shifting the difference to store negative 
 indices */
int ld[30] = { 0 };
/* rd is an array where its indices indicate row+col
   and used to check whether a queen can be placed on 
   right diagonal or not*/
int rd[30] = { 0 };
/*column array where its indices indicates column and 
  used to check whether a queen can be placed in that
    row or not*/
int cl[30] = { 0 };
/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
  
/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;
  
    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        /* Check if the queen can be placed on
          board[i][col] */
        /* A check if a queen can be placed on 
           board[row][col].We just need to check
           ld[row-col+n-1] and rd[row+coln] where
           ld and rd are for left and right 
           diagonal respectively*/
        if ((ld[i - col + N - 1] != 1 &&
                  rd[i + col] != 1) && cl[i] != 1) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            ld[i - col + N - 1] =
                          rd[i + col] = cl[i] = 1;
  
            /* recur to place rest of the queens */
            if (solveNQUtil(board, col + 1))
                return true;
  
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] =
                         rd[i + col] = cl[i] = 0;
        }
    }
  
    /* If the queen cannot be placed in any row in
        this colum col  then return false */
    return false;
}
/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to 
   solve the problem. It returns false if queens
   cannot be placed, otherwise, return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
  
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    printSolution(board);
    return true;
}
int main(int argc, char const *argv[])
{
    solveNQ();
    remove(argv[0]);
    return 0;
}
