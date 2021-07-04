/*All Topological Sorts of a Directed Acyclic Graph
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG, print all topological sorts of the graph.
 

For example, consider the below graph.
graph

All topological sorts of the given graph are:
4 5 0 2 3 1 
4 5 2 0 3 1 
4 5 2 3 0 1 
4 5 2 3 1 0 
5 2 3 4 0 1 
5 2 3 4 1 0 
5 2 4 0 3 1 
5 2 4 3 0 1 
5 2 4 3 1 0 
5 4 0 2 3 1 
5 4 2 0 3 1 
5 4 2 3 0 1 
5 4 2 3 1 0 
*/
#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>* adj;
    vector<int> indegree;

    void topologicalSort(vector<int>& res, bool visited[])
    {
        bool flag=false;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0 && !visited[i])
            {
                for(auto j=adj[i].begin(); j!=adj[i].end();j++)
                {
                    indegree[*j]--;
                }
                visited[i]=true;
                res.push_back(i);
                topologicalSort(res,visited);

                // backtracking
                visited[i]=false;
                res.erase(res.end()-1);
                for(auto j=adj[i].begin(); j!=adj[i].end();j++)
                {
                    indegree[*j]++;
                }

                flag=true;
            }
        }

        if(!flag)
        {
            for(auto i:res)
            cout<<res[i]<<" ";
            cout<<endl;
        }
    }
    public:
    graph(int v)
    {
        this->v=v;
        adj=new list<int>[v];
        for(int i=0;i<v;i++)
            indegree.push_back(0);
    }
    void addedge(int u, int w)
    {
        adj[u].push_back(w);

        indegree[w]++;
    }
    void exec(void);
};


void graph::exec(){
    bool visited[v];
    memset(visited, 0, v);

    vector<int>res;
    topologicalSort(res, visited);
}


int main(){
    graph g (6);
    g.addedge(5,2);
    g.addedge(5,0);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(2,3);
    g.addedge(3,1);

    g.exec();
    return 0;
}