//Breadth First Search or BFS for a Graph
#include <list>
#include <iostream>

class graph{
private:
    int v;
    std::list<int> *adj;
public:
    graph(int x)
    {
        this->v=x;
        this->adj=new std::list<int>[this->v];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void BFS(int s);
};

void graph::BFS(int s)
{
    //s is the current node
    bool *visited=new bool [v];
    
    for(int i=0; i<v; i++)
        visited[i]=false;
    
    std::list<int> que;
    que.push_back(s);
    std::list<int>::iterator i;
    while(!que.empty())
    {
        s=que.front();
        std::cout<<s<<' ';
        que.pop_front();
        for(i=adj[s].begin(); i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                que.push_back(*i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    std::cout<<"BFS sttarting from the vertex 2\n";
    g.BFS(2);
    remove(argv[0]);
    return 0;
}
