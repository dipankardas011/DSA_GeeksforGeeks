/*Shortest path with exactly k edges in a directed and weighted graph
Difficulty Level : Hard
Last Updated : 14 Jun, 2021
Given a directed and two vertices ‘u’ and ‘v’ in it, find shortest path from ‘u’ to ‘v’ with exactly k edges on the path.
The graph is given as adjacency matrix representation where value of graph[i][j] indicates the weight of an edge from vertex i to vertex j and a value INF(infinite) indicates no edge from i to j.
For example, consider the following graph. Let source ‘u’ be vertex 0, destination ‘v’ be 3 and k be 2. There are two walks of length 2, the walks are {0, 2, 3} and {0, 1, 3}. The shortest among the two is {0, 2, 3} and weight of path is 3+6 = 9.
 

graph1

The idea is to browse through all paths of length k from u to v using the approach discussed in the previous post and return weight of the shortest path. A simple solution is to start from u, go to all adjacent vertices, and recur for adjacent vertices with k as k-1, source as adjacent vertex and destination as v. Following are C++ and Java implementations of this simple solution. */
#include <iostream>
#include <climits>
#define V 4
#define INF INT_MAX

int shortestPath(int graph[][V], int u, int v, int k)
{
    if(k==0 && u==v) return 0;
    if(k==1 && graph[u][v]!=INF)    return graph[u][v];
    if(k<=0)    return INF;

    int res=INF;
    for(int i=0;i<V;i++){
        if(graph[u][v]!=INF && u!=i && v!=i)
        {
            int rec=shortestPath(graph, i, v, k-1);
            if(rec!=INF)
                res=std::min(res, graph[u][i]+rec);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int graph[V][V]={
        {0,10,3,2},
        {INF, 0, INF, 7},
        {INF, INF, 0,6},
        {INF, INF, INF ,0}
    };
    int u=0, v=3, k=2;
    std::cout<<"weight of the shortest path is "<<shortestPath(graph, u, v, k)<<std::endl;
    remove(argv[0]);
    return 0;
}
