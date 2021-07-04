/*Transitive closure of a graph

Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called the transitive closure of a graph.

For example, consider below graph
transitiveclosure

Transitive closure of above graphs is 
     1 1 1 1 
     1 1 1 1 
     1 1 1 1 
     0 0 0 1*/
#include <bits/stdc++.h>
using namespace std;

#define V 4

void PathMap(int graph[][V]){

    int dist[V][V];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];
    
    int i,j,k;
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){

                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            if(i!=j)
                printf("%d\t",dist[i][j]);
            else
                printf("1\t");  // when the source is the distination as well
        printf("\n");
    }
}


int main(){
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    
    PathMap(graph);
    return 0;
}