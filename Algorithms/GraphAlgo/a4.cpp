/*Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)

A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
Union: Join two subsets into a single subset.
In this post, we will discuss the application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.
Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes that the graph doesn’t contain any self-loops. 
We can keep track of the subsets in a 1D array, let’s call it parent[].
Let us consider the following graph: 
 
cycle-in-graph

For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.
Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

0   1   2
-1 -1  -1
Now process all edges one by one.
Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa. 

0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
1  -1  -1
Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
1   2  -1
Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.
How subset of 0 is same as 2? 
0->1->2 // 1 is parent of 0 and 2 is parent of 1  */
#include <iostream>
#include <cstring>
class Edge
{
public:
    int src, dest;
};
// v-> number of vertices e-> number of edges
class graph
{
public:
    int v, e;
    Edge *edge; // array representation of edges
};

graph *createGraph(int v, int e)
{
    graph *g = new graph();
    g->v = v;
    g->e = e;
    g->edge = new Edge[g->e * sizeof(Edge)];
    return g;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

int isCycle(graph *g)
{
    int *parent = new int[g->v * sizeof(int)];

    memset(parent, -1, sizeof(int)*g->v);
    for (int i = 0; i < g->e; i++)
    {
        int x = find(parent, g->edge[i].src);
        int y = find(parent, g->edge[i].dest);
        if (x == y)
            //dest==src they point to the same parent
            return 1;        //cycle present
        Union(parent, x, y); //when no cycle found
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int V = 3, E = 3;
    graph *g = createGraph(V, E);
    // 0 -> 1
    g->edge[0].src = 0;
    g->edge[0].dest = 1;

    // 1 -> 2
    g->edge[1].src = 1;
    g->edge[1].dest = 2;

    // 0 -> 2
    g->edge[2].src = 0;
    g->edge[2].dest = 2;

    std::cout << ((isCycle(g)) ? "Graph contains Cycle" : "No cycles present") << std::endl;
    remove(argv[0]);
    return 0;
}
