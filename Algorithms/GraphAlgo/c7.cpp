/*Check whether a given graph is Bipartite or not
Difficulty Level : Medium
Last Updated : 02 Jul, 2021
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.
 

[Bipartite1](https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraph-1.jpg)

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. Note that it is possible to color a cycle graph with even cycle using two colors. For example, see the following graph.
 

[Bipartite2](https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraphfive.sixJPG.jpg)

It is not possible to color a cycle graph with odd cycle using two colors. 



[Bipartite3](https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraphfive.jpg)

Algorithm to check if a graph is Bipartite: 
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem. 
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS). 
1. Assign RED color to the source vertex (putting into set U). 
2. Color all the neighbors with BLUE color (putting into set V). 
3. Color all neighbor’s neighbor with RED color (putting into set U). 
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) */
#include <iostream>
#include <vector>
#include <queue>
bool isBipartite(int v, std::vector<int> adj[])
{
    /**
     * @def col 
     * if -1 "no color"
     * if 0 or 1 coloured
     */
    std::vector<int>col(v,-1);
    // {vertex, colour}
    std::queue<std::pair<int, int>> q;

    for(int i=0;i<v;i++)
    {
        if(col[i]==-1)
        {
            q.push({i,0});
            col[i]=0;
            while(!q.empty())
            {
                std::pair<int, int> p=q.front();
                q.pop();

                int v=p.first;
                int color=p.second;

                for(int j:adj[v])
                {
                    if(col[j]==color)
                        return 0;

                    if(col[j]==-1)
                    {
                        // coloring the opposite
                        col[j]= (color)?0:1;
                        q.push({j,col[j]});
                    }
                }
            }
        }
    }
    // if all vertices are coloured such that no two connected vertex have same colour
    return 1;
}
int main(int argc, char const *argv[])
{
    int v=4,e=8;
    std::vector<int> adj[v];
    adj[0]={1,3};
    adj[1]={0,2};
    adj[2]={1,3};
    adj[3]={0,2};
    bool ans=isBipartite(v,adj);
    std::cout<<((ans)?"Yes":"No")<<std::endl;
    remove(argv[0]);
    return 0;
}
