/*Rat in a Maze | Backtracking-2

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



Following is the solution matrix (output of program) for the above input matrix. 

{1, 0, 0, 0}
{1, 1, 0, 0}
{0, 1, 0, 0}
{0, 1, 1, 1}
All enteries in solution path are marked as 1.*/
#include <bits/stdc++.h>
using namespace std;
#define N 4
#define WALL 35
#define PATH 64


bool isSafe(int maze[][N], int x, int y)
{
    if(x>=0 && x<N &&
        y>=0 && y<N &&
        maze[x][y]==1)
        return true;

    return false;
}


bool Path_Finder(int src[N][N], int sol[N][N], int pos_x, int pos_y)
{
    if(pos_x==N-1 && pos_y==N-1 &&
        src[pos_x][pos_y]==1)
    {
        sol[pos_x][pos_y]=PATH;
        return true;
    }
    if(isSafe(src, pos_x, pos_y))
    {
        if(sol[pos_x][pos_y]==1)
            //already there
            return false;
        
        sol[pos_x][pos_y]=PATH;

        if(Path_Finder(src, sol, pos_x+1, pos_y))
            return true;
        if(Path_Finder(src, sol, pos_x, pos_y+1))
            return true;
        
        if(Path_Finder(src, sol, pos_x-1, pos_y))
            return true;
        if(Path_Finder(src, sol, pos_x, pos_y-1))
            return true;

        sol[pos_x][pos_y]=WALL;
        return false;
    }
    return false;
}


int main()
{
    int org[N][N] = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 1}};
    
    int res[N][N]={
        {WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL}
    };
    if(!Path_Finder(org, res, 0, 0))
    {
        cout<<"not FOUND!"<<endl;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<(char)res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}