/*Find the number of islands | Set 1 (Using DFS)
 
Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands
Example: 

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1} 
Output : 5
This is a variation of the standard problem: “Counting the number of connected components in an undirected graph”. 

Before we go to the problem, let us understand what is a connected component. A connected component of an undirected graph is a subgraph in which every two vertices are connected to each other by a path(s), and which is connected to no other vertices outside the subgraph. 
For example, the graph shown below has three connected components. 
![](https://media.geeksforgeeks.org/wp-content/uploads/connectedcomponents.png)
A graph where all vertices are connected with each other has exactly one connected component, consisting of the whole graph. Such a graph with only one connected component is called a Strongly Connected Graph.
The problem can be easily solved by applying DFS() on each component. In each DFS() call, a component or a sub-graph is visited. We will call DFS on the next un-visited component. The number of calls to DFS() gives the number of connected components. BFS can also be used.
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190704154734/FindNumberOfIslands.png)
What is an island? 
A group of connected 1s forms an island. For example, the below matrix contains 4 islands
*/
// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

// A utility function to do DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices

void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}

// The main function that returns count of islands in a given boolean 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells. Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and travese through the all cells of given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not visited yet, then new island found Visit all cells in this island.
            if (M[i][j] && !visited[i][j])
            {
                DFS(M, i, j, visited);

                // and increment island count
                ++count;
            }

    return count;
}

int main(int argc, char const *argv[])
{
    int M[][COL] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M) << endl;
    remove(argv[0]);
    return 0;
}
