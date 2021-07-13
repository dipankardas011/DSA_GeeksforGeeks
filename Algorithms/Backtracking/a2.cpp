/*Rat in a Maze | Backtracking-2
Difficulty Level : Medium
Last Updated : 01 Jul, 2021
We have discussed Backtracking and Knight’s tour problem in Set 1. Let us discuss Rat in a Maze as another example problem that can be solved using Backtracking.

A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down. 

In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination. Note that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with a limited number of moves.

Following is an example maze.  

 Gray blocks are dead ends (value = 0).




Following is a binary matrix representation of the above maze. 

{1, 0, 0, 0}
{1, 1, 0, 1}
{0, 1, 0, 0}
{1, 1, 1, 1}
Following is a maze with highlighted solution path.

![](https://www.geeksforgeeks.org/wp-content/uploads/ratinmaze_filled11.png)

Following is the solution matrix (output of program) for the above input matrix. 

{1, 0, 0, 0}
{1, 1, 0, 0}
{0, 1, 0, 0}
{0, 1, 1, 1}
All enteries in solution path are marked as 1*/
#include <iostream>
#define N 4

void printSol(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        std::cout << std::endl;
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}

bool execUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y))
    {
        if (sol[x][y] == 1) // already a part
            return false;
        sol[x][y] = 1;
        // move forward in x direction
        if (execUtil(maze, x + 1, y, sol))
            return true;
        // if moving x-direc ==false
        // then down by y+1
        if (execUtil(maze, x, y + 1, sol))
            return true;

        // if moving the y+1 direc==false
        // then move back x-direction
        if (execUtil(maze, x - 1, y, sol))
            return true;

        // if mmoving x-backward gives false
        // then move backward in y
        if (execUtil(maze, x, y - 1, sol))
            return true;

        // if none has worked
        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {};

    if (!execUtil(maze, 0, 0, sol))
    {
        std::cerr << "Solution doesn't exist";
        return false;
    }
    printSol(sol);
    return true;
}

int main(int argc, char const *argv[])
{
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};

    solveMaze(maze);
    remove(argv[0]);
    return 0;
}
