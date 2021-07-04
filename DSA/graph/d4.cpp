/*Reverse Delete Algorithm for Minimum Spanning Tree

Reverse Delete algorithm is closely related to Kruskal’s algorithm. 
In Kruskal’s algorithm what we do is : Sort edges by increasing order 
of their weights. After sorting, we one by one pick edges in increasing order. 
We include current picked edge if by including this in spanning tree not 
form any cycle until there are V-1 edges in spanning tree, 
where V = number of vertices.

In Reverse Delete algorithm, we sort all edges in decreasing 
order of their weights. After sorting, we one by one pick edges in 
decreasing order. We include current picked edge if excluding current 
edge causes disconnection in current graph. The main idea is delete edge 
if its deletion does not lead to disconnection of graph.

The Algorithm

1) Sort all edges of graph in non-increasing order of
   edge weights.

2) Initialize MST as original graph and remove extra
   edges using step 3.

3) Pick highest weight edge from remaining edges and 
   check if deleting the edge disconnects the graph  
   or not.
       If disconnects, then we don't delete the edge.
       Else we delete the edge and continue. 
Illustration:
Let us understand with the following example:


If we delete highest weight edge of weight 14, graph doesn’t become 
disconnected, so we remove it.
reversedelete2

Next we delete 11 as deleting it doesn’t disconnect the graph.
reversedelete3

Next we delete 10 as deleting it doesn’t disconnect the graph.
reversedelete4

Next is 9. We cannot delete 9 as deleting it causes disconnection.
reversedelete5

We continue this way and following edges remain in final MST.

Edges in MST
(3, 4) 
(0, 7) 
(2, 3) 
(2, 5) 
(0, 1) 
(5, 6) 
(2, 8) 
(6, 7) 
Note : In case of same weight edges, we can pick any edge of the same weight edges.*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;

class graph{
    int v;
    list<int>*adj;
    vector<pair<int, ipair>>edges;
    void DFS(int v, bool visited[]);
public:
    graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }
    void addedge(int u, int v, int w){
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({w, {u,v}});
    }
    bool isconnected();
    void reverseDeleteMST();
};

void graph::DFS(int v, bool visited[]){
    visited[v]=true;

    for(auto i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if(!visited[*i])
        {
            DFS(*i, visited);
        }
    }
}

bool graph::isconnected()
{
    bool visited[v];
    memset(visited, false, sizeof(visited));

    DFS(0,visited);

    for(int i=1; i<v;i++)
        if(!visited[i])
            return false;

return true;
}

void graph::reverseDeleteMST()
{
    // sort in increasing order
    sort(edges.begin(), edges.end());
    int mst_wt=0;

    cout<<"edges in mst"<<endl;

    for(int i=edges.size()-1; i>=0; i--)
    {
        int u=edges[i].second.first;
        int v=edges[i].second.second;

        // remove edges from undirested graph
        adj[u].remove(v);
        adj[v].remove(u);

        // if disconnection then undo the operation of delete
        if(isconnected()==false)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);

            cout<<"("<<u<<", "<<v<<")"<<endl;
            mst_wt+=edges[i].first;
        }
    }
    cout<<"total weight of MST: "<<mst_wt<<endl;
}


int main(){
    // create the graph given in above fugure
    int V = 9;
    graph g(V);
  
    //  making above shown graph
    g.addedge(0, 1, 4);
    g.addedge(0, 7, 8);
    g.addedge(1, 2, 8);
    g.addedge(1, 7, 11);
    g.addedge(2, 3, 7);
    g.addedge(2, 8, 2);
    g.addedge(2, 5, 4);
    g.addedge(3, 4, 9);
    g.addedge(3, 5, 14);
    g.addedge(4, 5, 10);
    g.addedge(5, 6, 2);
    g.addedge(6, 7, 1);
    g.addedge(6, 8, 6);
    g.addedge(7, 8, 7);
  
    g.reverseDeleteMST();
    return 0;
}