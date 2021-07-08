/*Articulation Points (or Cut Vertices) in a Graph

A vertex in an undirected connected graph is an articulation point (or cut vertex) iff removing it (and edges through it) disconnects the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more components. They are useful for designing reliable networks. 
For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
Following are some example graphs with articulation points encircled with red color. 
 
[ArticulationPoints](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ArticulationPoints-300x189.png)

[ArticulationPoints1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ArticulationPoints1-129x300.png)

[ArticulationPoints2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/ArticulationPoints21-300x177.png)

How to find all articulation points in a given graph? 
A simple approach is to one by one remove all vertices and see if removal of a vertex causes disconnected graph. Following are steps of simple approach for connected graph.
1) For every vertex v, do following 
…..a) Remove v from graph 
..…b) See if the graph remains connected (We can either use BFS or DFS) 
…..c) Add v back to the graph
Time complexity of above method is O(V*(V+E)) for a graph represented using adjacency list. Can we do better?
A O(V+E) algorithm to find all Articulation Points (APs) 
The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a vertex u is articulation point if one of the following two conditions is true. 
1) u is root of DFS tree and it has at least two children. 
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
Following figure shows same points as above with one additional point that a leaf in DFS Tree can never be an articulation point.
 
We do DFS traversal of given graph with additional code to find out Articulation Points (APs). In DFS traversal, we maintain a parent[] array where parent[u] stores parent of vertex u. Among the above mentioned two cases, the first case is simple to detect. For every vertex, count children. If currently visited vertex u is root (parent[u] is NIL) and has more than two children, print it. 
How to handle second case? The second case is trickier. We maintain an array disc[] to store discovery time of vertices. For every node u, we need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we maintain an additional array low[] which is defined as follows. 
 

low[u] = min(disc[u], disc[w]) 
where w is an ancestor of u and there is a back edge from 
some descendant of u to w.*/
#include <iostream>
#include <list>
#define nil -1

using namespace std;

class Graph{
    int v;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void AP();
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    // undirected
    adj[v].push_back(w);
    adj[w].push_back(v);
}

/* A recursive function that find articulation points using DFS traversal
 u --> The vertex to be visited next
 visited[] --> keeps tract of visited vertices
 disc[] --> Stores discovery times of visited vertices
 low[] -- >> earliest visited vertex (the vertex with minimum
    discovery time) that can be reached from subtree rooted with current vertex
 parent[] --> Stores parent vertices in DFS tree
 ap[] --> Store articulation points
 */
void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time=0;
    int children=0;
    visited[u]=true;

    disc[u]=low[u]= ++time;
    list<int>::iterator i;
    for(i=adj[u].begin(); i!=adj[u].end(); i++)
    {
        int v=*i;   //v -> current adjacent of u
        if(!visited[v]){
            children++;
            parent[v]=u;

            APUtil(v,visited, disc,low,parent, ap);

            low[u]=std::min(low[u],low[v]);
            if(parent[u]==nil && children > 1)
                ap[u]=true;

            if(parent[u]!=nil && low[v]>=disc[u])
                ap[u]=true;
        }
        else if(v!=parent[u])
            low[u]=std::min(low[u],disc[v]);
    }
}

void Graph::AP(){
    bool *visited=new bool[v];
    int *disc=new int [v];
    int *low=new int [v];
    int *parent=new int [v];
    bool *ap=new bool [v];
    for(int i=0;i<v;i++){
        parent[i]=nil;
        visited[i]=false;
        ap[i]=false;
    }
    for(int i=0;i<v;i++)
        if(visited[i]==false)
            APUtil(i,visited,disc,low,parent, ap);
    
    for(int i=0;i<v;i++)
        if(ap[i]==true)
            cout<<i<<" ";
}

int main(int argc, char const *argv[])
{
    cout<<"articulation points in first graph "<<endl;
    Graph g1(5);
     g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();
 
    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
    cout<<endl;
    remove(argv[0]);
    return 0;
}
