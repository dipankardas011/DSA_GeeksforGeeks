/*Transitive Closure of a Graph using DFS

Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v) in the given graph. Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
 

For example, consider below graph

Transitive closure of above graphs is 
     1 1 1 1 
     1 1 1 1 
     1 1 1 1 
     0 0 0 1 
We have discussed a O(V3) solution for this here. The solution was based on Floyd Warshall Algorithm. In this post a O(V2) algorithm for the same is discussed.*/
#include <bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    bool **tc;
    list<int> *adj;
    void DFSutil(int u, int v);

public:
    graph(int v);
    void addedge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void transitiveClosure();
};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
    tc = new bool *[v];

    for (int i = 0; i < v; i++)
    {
        tc[i] = new bool[v];
        // makeing the row elments as false
        memset(tc[i], false, v * sizeof(bool));
    }
}

void graph::DFSutil(int s, int v)
{
    // mark reachability from s to t as true
    tc[s][v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (tc[s][*i] == false)
            DFSutil(s, *i);
    }
}

void graph::transitiveClosure()
{
    for (int i = 0; i < v; i++)
        DFSutil(i, i); // every vertx is reachable from self
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    cout<<"transitiveclosure"<<endl;
    g.transitiveClosure();
    return 0;
}