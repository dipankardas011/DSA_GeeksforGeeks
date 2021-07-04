/*Iterative Depth First Traversal of Graph
Depth First Traversal (or Search) for a graph is similar to Depth First Traversal (DFS) of a tree. The only catch here is, unlike trees, graphs may contain cycles, so a node might be visited twice. To avoid processing a node more than once, use a boolean visited array. 

Example:  

Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3 
Explanation: 
DFS Diagram: 
 
1  -> 2 ----
^   ^ |    |
|   | |    |
0 --- \/   |
^     3--  |
|     ^ |  |
|     |_|  |
------------ 


Input: n = 4, e = 6 
2 -> 0, 0 -> 2, 1 -> 2, 0 -> 1, 3 -> 3, 1 -> 3 
Output: DFS from vertex 2 : 2 0 1 3 
Explanation: 
DFS Diagram: */

#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int v);
    void addedge(int v, int w);
    void DFS(int root);
};

Graph::Graph(int x)
{
    this->v = x;
    adj = new list<int>[x];
}

void Graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int root)
{
    stack<int> st;
    vector<bool> visited(v, false);

    st.push(root);
    while (!st.empty())
    {
        int ff = st.top();

        st.pop();

        if (!visited[ff])
        {
            cout << ff << " ";
            visited[ff] = true;
        }

        for (auto i = adj[ff].begin(); i != adj[ff].end(); i++)
        {
            if (!visited[*i])
                st.push(*i);
        }
    }
}

int main()
{
    Graph g(5);

    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2, 1);
    g.addedge(0, 3);
    g.addedge(1, 4);
    cout << "dfs traversal: ";
    g.DFS(0);
    return 0;
}