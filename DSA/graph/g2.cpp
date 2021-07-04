/*Find the Degree of a Particular vertex in a Graph
Difficulty Level : Medium
Last Updated : 06 Nov, 2020
Given a graph G(V,E) as an adjacency matrix representation and a vertex, find the degree of the vertex v in the graph.

Examples : 

0-----1
|\    |
|  \  |
|    \|
2-----3
Input : ver = 0
Output : 3

Input : ver = 1
Output : 2*/
#include <bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *adj;

    public:
    graph(int);
    void AddEdge(int, int);
    int FindDegree(int);
};

graph::graph(int v){
    this->V = v;
    adj=new list<int>[V];
}

void graph::AddEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int graph::FindDegree(int ver){
    int count=0;
    for(auto i = adj[ver].begin(); 
            i!= adj[ver].end() ; i++)
    {
        count++;
    }

    return count;
}

int main(){
    graph g(4);
    g.AddEdge(0,1);
    g.AddEdge(1,3);
    g.AddEdge(2,3);
    g.AddEdge(0,2);
    g.AddEdge(0,3);

    cout<<"0: "<<g.FindDegree(0)<<endl;
    cout<<"1: "<<g.FindDegree(1)<<endl;
    return 0;
}