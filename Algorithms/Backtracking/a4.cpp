/*m Coloring Problem | Backtracking-5
Difficulty Level : Medium
Last Updated : 07 Jul, 2021
Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 

Input-Output format: 

Input: 

A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is an adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.
An integer m is the maximum number of colors that can be used.
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


Method 2: Backtracking.

Approach: The idea is to assign colors one by one to different vertices, starting from the vertex 0. Before assigning a color, check for safety by considering already assigned colors to the adjacent vertices i.e check if the adjacent vertices have the same color or not. If there is any color assignment that does not violate the conditions, mark the color assignment as part of the solution. If no assignment of color is possible then backtrack and return false.

Algorithm: 

1. Create a recursive function that takes the graph, current index, number of vertices, and output color array.
2. If the current index is equal to the number of vertices Print the color configuration in output array.
3. Assign a color to a vertex (1 to m).
4. For every assigned color, check if the configuration is safe, (i.e. check if the adjacent vertices do not have the same color) recursively call the function with next index and number of vertices
5. If any recursive function returns true break the loop and return true.
6. If no recursive function returns true then return false.*/

#include <bits/stdc++.h>
using namespace std;

class node
{
    // connected to the node
    // A node class which stores the color and the edges
public:
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node> &nodes, int n, int m)
{

    // Create a visited array of n
    // nodes, initialized to zero
    vector<int> visited(n + 1, 0);

    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;

    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++)
    {

        if (visited[sv])
            continue;

        // If the starting point is unvisited,
        // mark it visited and push it in queue
        visited[sv] = 1;
        queue<int> q;
        q.push(sv);

        // BFS Travel starts here
        while (!q.empty())
        {

            int top = q.front();
            q.pop();

            // Checking all adjacent nodes
            // to "top" edge in our queue
            for (auto it = nodes[top].edges.begin(); it != nodes[top].edges.end(); it++)
            {

                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;

                // If number of colors used shoots m, return
                // 0
                maxColors = std::max(maxColors, std::max(nodes[top].color, nodes[*it].color));
                if (maxColors > m)
                    return 0;

                // If the adjacent node is not visited, mark it visited and push it in queue
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }

    return 1;
}

int main(int argc, char const *argv[])
{

    int n = 4;
    bool graph[n][n] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3; // Number of colors

    // Create a vector of n+1
    // nodes of type "node"
    // The zeroth position is just
    // dummy (1 to n to be used)
    vector<node> nodes(n + 1);

    // Add edges to each node as per given input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                // Connect the undirected graph
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

    // Display final answer
    cout << canPaint(nodes, n, m);
    cout << "\n";
    remove(argv[0]);
    return 0;
}