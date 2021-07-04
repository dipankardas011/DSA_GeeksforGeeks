/*Detect Cycle in a directed graph using colors
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.

Example:

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes
Explanation:

This diagram clearly shows a cycle 0 -> 2 -> 0.

Input:n = 4, e = 3
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 3
Output:No
Explanation:

This diagram clearly shows no cycle.
Solution

Approach: Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (selfloop) or one of its ancestor in the tree produced by DFS. In the following graph, there are 3 back edges, marked with cross sign. It can be observed that these 3 back edges indicate 3 cycles present in the graph.





For a disconnected graph, we get the DFS forest as output. To detect cycle, we can check for cycle in individual trees by checking back edges.

Image Source: http://www.cs.yale.edu/homes/aspnes/pinewiki/DepthFirstSearch.html

In the previous post, we have discussed a solution that stores visited vertices in a separate array which stores vertices of the current recursion call stack.

In this post, a different solution is discussed. The solution is from CLRS book. The idea is to do DFS of a given graph and while doing traversal, assign one of the below three colours to every vertex.

WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.

GRAY: Vertex is being processed (DFS for this vertex has started, but not finished which means that all descendants (in DFS tree) of this vertex are not processed yet (or this vertex is in the function call stack)

BLACK : Vertex and all its descendants are processed. While doing DFS, if an edge is encountered from current vertex to a GRAY vertex, then this edge is back edge and hence there is a cycle.



Algorithm:

Create a recursive function that takes the edge and color array (this can be also kept as a global variable)
Mark the current node as GREY.
Traverse all the adjacent nodes and if any node is marked GREY then return true as a loop is bound to exist.
If any adjacent vertex is WHITE then call the recursive function for that node. If the function returns true. Return true.
If no adjacent node is grey or has not returned true then mark the current Node as BLACK and return false.*/
#include <iostream>
#include <list>
using namespace std;

enum color{
    white,
    gray,
    black
};

class graph{
    int v;
    list<int>* adj;
    bool DFS(int v, int color[]);
    public:
    graph(int v);
    void addedge(int v, int w);
    bool isCycle();
};

graph::graph(int x){
    this->v=x;
    adj=new list<int>[v];
}

void graph::addedge(int v, int w){
    adj[v].push_back(w);
}

bool graph::DFS(int u, int color[])
{
    color[u] = gray;
    for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
    {
        int v=*i;// has the adjacent nodes
        if(color[v]==gray)  return true;
        // If v is not processed and there is a back
        // edge in subtree rooted with v
        if(color[v]==white && DFS(v, color))    return true;

    }

    color[u]=black;
    return false;
}

bool graph::isCycle(){
    int *color=new int [v];

    memset(color, white, v);

    for(int i=0;i<v;i++)
        if(color[i] == white)
            if(DFS(i, color) == true)
                return true;

    return false;
}

int main(){
    
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);

    (g.isCycle())? cout<<"Cyclic Graph"<<endl :
                    cout<<"Acyclic Graph"<<endl;
    return 0;
}