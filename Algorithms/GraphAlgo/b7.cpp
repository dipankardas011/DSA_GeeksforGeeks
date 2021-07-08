/*Eulerian path and circuit for undirected graph
Difficulty Level : Medium
Last Updated : 06 Jun, 2020
Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

Euler1

Euler2

Euler3

How to find whether a given graph is Eulerian or not?
The problem is same as following question. “Is it possible to draw a given graph without lifting pencil from the paper and without tracing any of the edges more than once”.



A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path. The problem seems similar to Hamiltonian Path which is NP complete problem for a general graph. Fortunately, we can find whether a given graph has a Eulerian Path or not in polynomial time. In fact, we can find it in O(V+E) time.

Following are some interesting properties of undirected graphs with an Eulerian path and cycle. We can use these properties to find whether a graph is Eulerian or not.

Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
….b) All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
….a) Same as condition (a) for Eulerian Cycle
….b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

How does this work?
In Eulerian path, each time we visit a vertex v, we walk through two unvisited edges with one end point as v. Therefore, all middle vertices in Eulerian Path must have even degree. For Eulerian Cycle, any vertex can be middle vertex, therefore all vertices must have even degree.*/
#include <iostream>
#include <list>
using namespace std;

class graph{
    int v;
    list<int> *adj;
public:
    graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }
    ~graph(){
        delete[] adj;
    }
    void addEdge(int v, int w){
        this->adj[v].push_back(w);
        this->adj[w].push_back(v);
    }
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};

void graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

bool graph::isConnected()
{
    bool visited[v];
    int i;
    for(i=0;i<v;i++)
        visited[i]=false;

    for(i=0;i<v;i++)
        if(adj[i].size()!=0)
            break;
    
    if(i==v)
        return true;

    DFSUtil(i,visited);
    for(i=0;i<v;i++)
        if(visited[i]==false && adj[i].size()>0)
            return false;

    return true;
}
/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int graph::isEulerian(){
    if(isConnected()==false)
        return 0;

    int odd=0;
    for(int i=0;i<v;i++)
        if(adj[i].size()&1)
            odd++;

    if(odd>2)   return 0;
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)?1:2;
}

void test(graph &g)
{
    int res=g.isEulerian();
    if( res==0)
        cout<<"graph is not eulerian\n";
    else if( res==1)
        cout<<"graph has a euler path\n";
    else
        cout<<"graph has a euler cycle\n";
}
int main(int argc, char const *argv[])
{
    // Let us create and test graphs shown in above figures
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);
  
    graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);
  
    graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);
  
    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);

    // Let us create a graph with all veritces
    // with zero degree
    graph g5(3);
    test(g5);
    remove(argv[0]);
    return 0;
}
