/*m Coloring Problem | Backtracking-5
Difficulty Level : Medium
Last Updated : 19 Feb, 2021
Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 
Input-Output format: 
Input: 

A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.
An integer m which is the maximum number of colors that can be used.
Output: 
An array color[V] that should have numbers from 1 to m. color[i] should represent the color assigned to the ith vertex. The code should also return false if the graph cannot be colored with m colors.

Example: 

Input:  
graph = {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
Output: 
Solution Exists: 
Following are the assigned colors
 1  2  3  2
Explanation: By coloring the vertices 
with following colors, adjacent 
vertices does not have same colors

Input: 
graph = {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
Output: Solution does not exist.
Explanation: No solution exits.
Following is an example of a graph that can be coloured with 3 different colours.*/
#include <bits/stdc++.h>
using namespace std;
#define V 4
// we can use bool for 1, 0 as it saves space
bool isSafe(int graph[V][V], int color[V]){
    for(int i=0;i<V;i++)
        // here it started from i+1 as we dont compare
        // with itself
        for(int j=i+1;j<V;j++)
            if(graph[i][j] == 1 &&
                color[j]==color[i])
                return false;
    
    return true;
}
/* A utility function to print solution */
void printSolution(int color[])
{
    cout << "Solution Exists:" " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << "  " << color[i];
    cout << "\n";
}
 
bool GraphColoring(int graph[][V], int m, int i, int color[V])
{
    // current index reached end
    if(i==V){
        if(isSafe(graph, color))
        {
            printSolution(color);
            return true;
        }
        return false;
    }

    for(int j=1; j<=m;j++)
    {
        color[j]=j;
        if(GraphColoring(graph, m,i+1,color))
            return true;
        color[i]=0;
    }

    return false;
}


int main(){
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m=3;
    int color[V]={0};
    if(!GraphColoring(graph, m,0,color))
        cout<<"not possible\n";
    return 0;
}