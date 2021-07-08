/*Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo-2
Difficulty Level : Hard
Last Updated : 19 Apr, 2021
What is Minimum Spanning Tree? 
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
How many edges does a minimum spanning tree has? 
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 
What are the applications of the Minimum Spanning Tree? 
See this for applications of MST.

Below are the steps for finding MST using Kruskal’s algorithm

1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

Step #2 uses the Union-Find algorithm to detect cycles. So we recommend reading the following post as a prerequisite. 
Union-Find Algorithm | Set 1 (Detect Cycle in a Graph) 
Union-Find Algorithm | Set 2 (Union By Rank and Path Compression)
The algorithm is a Greedy Algorithm. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far. Let us understand it with an example: Consider the below input graph. 
The graph contains 9 vertices and 14 edges. So, the minimum spanning tree formed will be having (9 – 1) = 8 edges. 

After sorting:

Weight   Src    Dest
1         7      6
2         8      2
2         6      5
4         0      1
4         2      5
6         8      6
7         2      3
7         7      8
8         0      7
8         1      2
9         3      4
10        5      4
11        1      7
14        3      5
Now pick all edges one by one from the sorted list of edges 
1. Pick edge 7-6: No cycle is formed, include it. 
2. Pick edge 8-2: No cycle is formed, include it. 
3. Pick edge 6-5: No cycle is formed, include it. 
4. Pick edge 0-1: No cycle is formed, include it. 
5. Pick edge 2-5: No cycle is formed, include it. 
6. Pick edge 8-6: Since including this edge results in the cycle, discard it.
7. Pick edge 2-3: No cycle is formed, include it. 
8. Pick edge 7-8: Since including this edge results in the cycle, discard it.
9. Pick edge 0-7: No cycle is formed, include it. 
10. Pick edge 1-2: Since including this edge results in the cycle, discard it.
11. Pick edge 3-4: No cycle is formed, include it. 
Since the number of edges included equals (V – 1), the algorithm stops here.

Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)
*/
#include <iostream>
#include <algorithm>
class Edge{
public:
    int src,dest,weight;
};

class Graph{
public:
    int V,E;
    Edge *edge;
};

Graph *createGraph(int v,int e){

    Graph *g=new Graph;
    g->E=e;
    g->V=v;

    g->edge=new Edge[g->E];
    return g;
}

class subset{
public:
    int parent;
    int rank;
};

int find(subset sub[], int i)
{
    // find root and make root as parent of i
    if(sub[i].parent!=i)
        sub[i].parent=find(sub, sub[i].parent);

    return sub[i].parent;
}

void Union(subset sub[], int x, int y)
{
    int xroot=find(sub,x);
    int yroot=find(sub,y);
    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if(sub[xroot].rank < sub[yroot].rank)
        sub[xroot].parent=yroot;

    else if(sub[xroot].rank > sub[yroot].rank)
        sub[yroot].parent=xroot;
    // if rank are == then make one as root and rank of other++
    else{
        sub[yroot].parent=xroot;
        sub[xroot].rank++;
    }
}
// sort()
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph *graph)
{
    /*first sort then starting from the smallest weight till the edge added becomed V-1 find wheter cyclic if not add it to the mst*/
    int V=graph->V;
    Edge result[V];
    /**
     * @type {e}
     * used for result
     */
    int e=0;
    /**
     * @type {i}
     * used for sorted edges
     */
    int i=0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);

    subset* sub = new subset[V*sizeof sub];
    for(int v=0;v<V;v++)
        sub[v].parent=v,
        sub[v].rank=0;

    while(e<V-1 && i<graph->E)
    {
        Edge next=graph->edge[i++];
        int x=find(sub, next.src);
        int y=find(sub, next.dest);

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if(x!=y)
            result[e++]=next, 
            Union(sub, x,y);
    }
    std::cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        std::cout << result[i].src << " -- " << result[i].dest<< " == " << result[i].weight << std::endl;
        minimumCost = minimumCost + result[i].weight;
    }
    // return;
    std::cout << "Minimum Cost Spanning Tree: " << minimumCost<< std::endl;
}

int main(int argc, char const *argv[])
{
    /* Let us create following weighted graph
      10
    0-----1
    | \   |
   6| 5\  |15
    |   \ |
    2-----3
       4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
   
    // Function call
    KruskalMST(graph);
    remove(argv[0]);
    return 0;
}
