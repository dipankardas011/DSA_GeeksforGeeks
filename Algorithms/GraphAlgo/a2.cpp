//Depth First Search or DFS for a Graph
#include <iostream>
#include <map>
#include <list>
class graph{
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj;
public:
    void addEdge(int, int );
    void DFS(int);
};

void graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void graph::DFS(int v)
{
    visited[v]=true;
    std::cout<<v<<' ';
    std::list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end();i++)
        if(!visited[*i])
            DFS(*i);
}

int main(int argc, char const *argv[])
{

    // Create a graph given in the above diagram
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    remove(argv[0]);
    return 0;
}
