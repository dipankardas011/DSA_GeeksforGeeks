/*Find minimum s-t cut in a flow network
Difficulty Level : Hard
Last Updated : 10 Oct, 2020
In a flow network, an s-t cut is a cut that requires the source ‘s’ and the sink ‘t’ to be in different subsets, and it consists of edges going from the source’s side to the sink’s side. The capacity of an s-t cut is defined by the sum of the capacity of each edge in the cut-set. (Source: Wiki)
The problem discussed here is to find minimum capacity s-t cut of the given network. Expected output is all edges of the minimum cut.

For example, in the following flow network, example s-t cuts are {{0 ,1}, {0, 2}}, {{0, 2}, {1, 2}, {1, 3}}, etc. The minimum s-t cut is {{1, 3}, {4, 3}, {4 5}} which has capacity as 12+7+4 = 23.

[minCut](https://www.geeksforgeeks.org/wp-content/uploads/minCut.png)

Ford-Fulkerson Algorithm for Maximum Flow Problem

Minimum Cut and Maximum Flow
Like Maximum Bipartite Matching, this is another problem which can solved using Ford-Fulkerson Algorithm. This is based on max-flow min-cut theorem.
The max-flow min-cut theorem states that in a flow network, the amount of maximum flow is equal to capacity of the minimum cut. See CLRS book for proof of this theorem.

From Ford-Fulkerson, we get capacity of minimum cut. How to print all edges that form the minimum cut? The idea is to use residual graph.

Following are steps to print all edges of the minimum cut.

1) Run Ford-Fulkerson algorithm and consider the final residual graph.

2) Find the set of vertices that are reachable from the source in the residual graph.

3) All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges. Print all such edges.*/
#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

#define V 6

int BFS(int resG[V][V], int src, int dest, int parent[])
{
    bool visited[V];
    memset(visited, false, sizeof(visited));

    std::queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && resG[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[dest] == true);
}

void DFS(int resG[V][V], int src, bool visited[])
{
    visited[src] = true;
    for (int i = 0; i < V; i++)
    {
        if (resG[src][i] && !visited[i])
            DFS(resG, i, visited);
    }
}

void minCut(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];

    while (BFS(rGraph, s, t, parent))
    {
        int pathflow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            pathflow = std::min(rGraph[u][v], pathflow);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= pathflow;
            rGraph[v][u] += pathflow;
        }
    }
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    DFS(rGraph, s, visited);
    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            if (visited[i] && !visited[j] && graph[i][j])
                std::cout << i << " - " << j << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    int graph[V][V] = {{0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0}};

    minCut(graph, 0, 5);
    remove(argv[0]);
    return 0;
}
