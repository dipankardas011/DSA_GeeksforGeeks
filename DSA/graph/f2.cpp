/*Bellman–Ford Algorithm 

Given a graph and a source vertex src in graph, find shortest 
paths from src to all vertices in the given graph. The graph may 
contain negative weight edges.
We have discussed Dijkstra’s algorithm for this problem. Dijkstra’s
algorithm is a Greedy algorithm and
time complexity is O(VLogV) (with the use of Fibonacci heap). D
ijkstra doesn’t work for Graphs with 
negative weight edges, Bellman-Ford works 
for such graphs. Bellman-Ford is also simpler than Dijkstra and suites 
well for distributed systems. But time complexity of Bellman-Ford is O(VE),
which is more than Dijkstra.*/
#include <bits/stdc++.h>
using namespace std;
/*
    Algorithm
Following are the detailed steps.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. 
If there is a negative weight cycle, then shortest distances are not 
calculated, negative weight cycle is reported.

1) This step initializes distances from the source to all vertices 
as infinite and distance to the source itself as 0. Create an array 
dist[] of size |V| with all values as infinite except dist[src] 
where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times 
where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph. 
Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains 
negative weight cycle”
The idea of step 3 is, step 2 guarantees the shortest distances if 
the graph doesn’t contain a negative weight cycle. If we iterate through 
all edges one more time and get a shorter path for any vertex, then there 
is a negative weight cycle
*/

struct edge{
    int src, dest, weight;
};

struct graph{
    int V, E;
    struct edge* edge;
};

graph* create(int v, int e){
    struct graph* g = new graph;
    g->V=v, g->E=e;
    g->edge = new edge[e];
    return g;
}

void BellmanFord(graph* g, int src){
    int v=g->V;
    int e=g->E;
    int dist[v];

    memset(dist, INT_MAX, v);

    dist[src]=0;
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for(int i=1;i<=v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=g->edge[j].src;
            int v=g->edge[j].dest;
            int weight=g->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                dist[v]=dist[u]+weight;
        }
    }
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int j = 0; j < e; j++)
    {
        int u = g->edge[j].src;
        int v = g->edge[j].dest;
        int weight = g->edge[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout<<"graph conatins cycle\n";
            return;
        }
    }

    cout<<"vertex\tdistance from src\n\n";
    for(int i=0;i<v;i++)
        printf("%d \t %d\n",i,dist[i]);
}


int main(){
    int v=5;
    int e=8;
    struct graph* g=create(v,e);

    g->edge[0].src=0;
    g->edge[0].dest=1;
    g->edge[0].weight=-1;

    g->edge[1].src=0;
    g->edge[1].dest=2;
    g->edge[1].weight=4;

    g->edge[2].src=1;
    g->edge[2].dest=2;
    g->edge[2].weight=3;

    g->edge[3].src=1;
    g->edge[3].dest=3;
    g->edge[3].weight=2;

    g->edge[4].src=1;
    g->edge[4].dest=4;
    g->edge[4].weight=2;

    g->edge[5].src=3;
    g->edge[5].dest=2;
    g->edge[5].weight=5;

    g->edge[6].src=3;
    g->edge[6].dest=1;
    g->edge[6].weight=1;

    g->edge[7].src=4;
    g->edge[7].dest=3;
    g->edge[7].weight=-3;

    BellmanFord(g, 0);
    return 0;
}