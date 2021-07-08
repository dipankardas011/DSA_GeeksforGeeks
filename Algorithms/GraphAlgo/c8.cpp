/*Ford-Fulkerson Algorithm for Maximum Flow Problem
Difficulty Level : Hard
Last Updated : 24 Jun, 2021
 
Given a graph which represents a flow network where every edge has a capacity. Also given two vertices source ‘s’ and sink ‘t’ in the graph, find the maximum possible flow from s to t with following constraints:
a) Flow on an edge doesn’t exceed the given capacity of the edge.
b) Incoming flow is equal to outgoing flow for every vertex except s and t.
For example, consider the following graph from CLRS book. 

[ford_fulkerson1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ford_fulkerson11.png)

The maximum possible flow in the above graph is 23. 
 

[ford_fulkerson2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ford_fulkerson2.png)
Prerequisite : Max Flow Problem Introduction



Ford-Fulkerson Algorithm 
The following is simple idea of Ford-Fulkerson algorithm:
1) Start with initial flow as 0.
2) While there is a augmenting path from source to sink. 
           Add this path-flow to flow.
3) Return flow.
Time Complexity: Time complexity of the above algorithm is O(max_flow * E). We run a loop while there is an augmenting path. In worst case, we may add 1 unit flow in every iteration. Therefore the time complexity becomes O(max_flow * E).
How to implement the above simple algorithm? 
Let us first define the concept of Residual Graph which is needed for understanding the implementation. 
Residual Graph of a flow network is a graph which indicates additional possible flow. If there is a path from source to sink in residual graph, then it is possible to add flow. Every edge of a residual graph has a value called residual capacity which is equal to original capacity of the edge minus current flow. Residual capacity is basically the current capacity of the edge. 
Let us now talk about implementation details. Residual capacity is 0 if there is no edge between two vertices of residual graph. We can initialize the residual graph as original graph as there is no initial flow and initially residual capacity is equal to original capacity. To find an augmenting path, we can either do a BFS or DFS of the residual graph. We have used BFS in below implementation. Using BFS, we can find out if there is a path from source to sink. BFS also builds parent[] array. Using the parent[] array, we traverse through the found path and find possible flow through this path by finding minimum residual capacity along the path. We later add the found path flow to overall flow. 
The important thing is, we need to update residual capacities in the residual graph. We subtract path flow from all edges along the path and we add path flow along the reverse edges We need to add path flow along reverse edges because may later need to send flow in reverse direction (See following link for example).
https://www.geeksforgeeks.org/max-flow-problem-introduction/*/
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>

#define V 6

bool bfs(int residualG[V][V], int src, int dest, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    std::queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        //BFS
        for(int v=0; v<V; v++){
            if(!visited[v] && residualG[u][v]>0)
            {
                if(v==dest)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return false;
}

int fordFulkerson(int graph[V][V], int src, int dest)
{
    int u, v;

    int residualG[V][V];

    for(u=0;u<V;u++)
        for(v=0;v<V;v++)
            residualG[u][v]=graph[u][v];

    int parent[V];      // this array is filled by BFS to store the path

    int maxflow=0;      // no flow initially

    while(bfs(residualG, src, dest, parent))
    {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int pathflow=INT_MAX;
        for(v=dest; v!=src; v=parent[v])
        {
            u=parent[v];
            pathflow=std::min(pathflow, residualG[u][v]);
        }
        // update esidual capacity of edges and reverse edges along the path
        for(v=dest; v!=src; v=parent[v])
        {
            u=parent[v];
            residualG[u][v] -= pathflow;
            residualG[v][u] += pathflow;
        }
        // add pathflow to overall flow
        maxflow +=pathflow;
    }

    return maxflow;
}

int main(int argc, char const *argv[])
{
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    std::cout<<"the maximum flow : "<<fordFulkerson(graph, 0,5)<<std::endl;
    remove(argv[0]);
    return 0;
}
