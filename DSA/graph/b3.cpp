/*Topological Sort of a graph using departure time of vertex
Difficulty Level : Medium
Last Updated : 08 Jan, 2021
GeeksforGeeks - Summer Carnival Banner
Given a Directed Acyclic Graph (DAG), find Topological Sort of the graph.
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. For example, another topological sorting of the following graph is “4 5 2 3 1 0”.
 

Topological Sort

Please note that the first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges). For above graph, vertex 4 and 5 have no incoming edges.
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We have already discussed a DFS-based algorithm using stack and Kahn’s Algorithm for Topological Sorting. We have also discussed how to print all topological sorts of the DAG here. In this post, another DFS based approach is discussed for finding Topological sort of a graph by introducing concept of arrival and departure time of a vertex in DFS.
What is Arrival Time & Departure Time of Vertices in DFS? 
In DFS, Arrival Time is the time at which the vertex was explored for the first time and Departure Time is the time at which we have explored all the neighbors of the vertex and we are ready to backtrack.
How to find Topological Sort of a graph using departure time? 
To find Topological Sort of a graph, we run DFS starting from all unvisited vertices one by one. For any vertex, before exploring any of its neighbors, we note the arrival time of that vertex and after exploring all the neighbors of the vertex, we note its departure time. Please note only departure time is needed to find Topological Sort of a graph, so we can skip arrival time of vertex. Finally, after we have visited all the vertices of the graph, we print the vertices in order of their decreasing departure time which is our desired Topological Order of Vertices.
Below is C++ implementation of above idea –*/
#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>* adj;
    public:
    graph(int k){
        this->v=k;
        adj=new list<int>[v];
    }
    void addedge(int u, int v){
        adj[u].push_back(v);
    }
    void DFS(int, vector<int> &, vector<int>&, int &);
    void topologicalSort();
};

void graph::DFS(int v, vector<int>& visited, vector<int>& departure, int& time)
{
    // departure time and the starting time
    visited[v]=true;

    for(int i:adj[v])
        if(!visited[i])
            DFS(i, visited, departure, time);
    
    departure[++time]=v;
}

void graph::topologicalSort(){
    vector<int>departure(v, false);
    vector<int>visited(v, false);

    int time=-1;
    // DFS(1, visited, departure, time);
    for(int i=0;i<v;i++)
    {
        DFS(i, visited, departure, time);
        cout<<departure[i]<<" ";
    }
    cout<<endl;
}


int main(){
    graph g(6);
    g.addedge(5,2);
    g.addedge(5,0);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(2,3);
    g.addedge(3,1);
    cout<<"the topogical sort: ";
    g.topologicalSort();
    return 0;
}