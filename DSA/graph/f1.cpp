/*Dijkstra’s shortest path algorithm | Greedy Algo-7

Given a graph and a source vertex in the graph, find shortest paths 
from source to all vertices in the given graph.
Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum 
spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) 
with given source as root. We maintain two sets, one set contains vertices 
included in shortest path tree, other set includes vertices not yet 
included in shortest path tree. At every step of the algorithm, we find 
a vertex which is in the other set (set of not yet included) and has a 
minimum distance from the source.
Below are the detailed steps used in Dijkstra’s algorithm to find the 
shortest path from a single source vertex to all other vertices in the 
given graph. 

Algorithm 
1) Create a set sptSet (shortest path tree set) that keeps track of 
vertices included in shortest path tree, i.e., whose minimum distance 
from source is calculated and finalized. Initially, this set is empty. 
2) Assign a distance value to all vertices in the input graph. 
Initialize all distance values as INFINITE. Assign distance value 
as 0 for the source vertex so that it is picked first. 
3) While sptSet doesn’t include all vertices 
….a) Pick a vertex u which is not there in sptSet and has minimum 
distance value. 
….b) Include u to sptSet. 
….c) Update distance value of all adjacent vertices of u. To update 
the distance values, iterate through all adjacent vertices. For every 
adjacent vertex v, if sum of distance value of u (from source) and 
weight of edge u-v, is less than the distance value of v, then update 
the distance value of v. 

Let us understand with the following example: 
The set sptSet is initially empty and distances assigned to vertices 
are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. 
Now pick the vertex with minimum distance value. The vertex 0 is picked, 
include it in sptSet. So sptSet becomes {0}. After including 0 to sptSet, 
update distance values of its adjacent vertices. Adjacent vertices 
of 0 are 1 and 7. The distance values of 1 and 7 are updated as 4 and 8. 
Following subgraph shows vertices and their distance values, only the 
vertices with finite distance values are shown. 
The vertices included in SPT are shown in green colour.
Pick the vertex with minimum distance value and not already included 
in SPT (not in sptSET). The vertex 1 is picked and added to sptSet. 
So sptSet now becomes {0, 1}. Update the distance values of adjacent 
vertices of 1. The distance value of vertex 2 becomes 12.
Pick the vertex with minimum distance value and not already included 
in SPT (not in sptSET). Vertex 7 is picked. So sptSet now becomes 
{0, 1, 7}. Update the distance values of adjacent vertices of 7. The 
distance value of vertex 6 and 8 becomes finite (15 and 9 respectively). 
Pick the vertex with minimum distance value and not already included 
in SPT (not in sptSET). Vertex 6 is picked. So sptSet now becomes 
{0, 1, 7, 6}. Update the distance values of adjacent vertices of 6. 
The distance value of vertex 5 and 8 are updated.
We repeat the above steps until sptSet does include all vertices of given 
graph. Finally, we get the following Shortest Path Tree (SPT).*/
#include <bits/stdc++.h>
using namespace std;

#define V 9

int mindistance(int dist[], bool sptSet[])
{
    int min=INT_MAX, min_index;

    for(int v=0;v<V;v++)
        if(sptSet[v]==false && 
            dist[v]<=min)
            min=dist[v],min_index=v;

    return min_index;
}

void dijkstra(int graph[][V], int src){
    int dist[V];
    // it is the output array

    bool sptset[V]; // shorted dist
    // if from src to i
    for(int i=0;i<V;i++)
        sptset[i]=false, dist[i]=INT_MAX;

    // source is 0
    dist[src]=0;

    for(int count=0; count<V-1; count++) {
        // intiially the u=src
        int u=mindistance(dist, sptset);

        sptset[u]=true;

        for(int v=0; v<V;v++)
            if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX &&
                dist[u]+graph[u][v] < dist[v])
                dist[v]=dist[u]+graph[u][v];
    }

    cout<<"vertex\tdistance from src\n";

    for(int i=0;i<V;i++)
        printf("%d \t\t %d\n",i,dist[i]);
}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    dijkstra(graph, 0);
    return 0;
}