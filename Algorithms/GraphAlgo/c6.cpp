/*Vertex Cover Problem | Set 1 (Introduction and Approximate Algorithm)
Difficulty Level : Medium
Last Updated : 04 Nov, 2020
A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, either ‘u’ or ‘v’ is in the vertex cover. Although the name is Vertex Cover, the set covers all edges of the given graph. Given an undirected graph, the vertex cover problem is to find minimum size vertex cover. 
The following are some examples. 
 

VertexCover

Vertex Cover Problem is a known NP Complete problem, i.e., there is no polynomial-time solution for this unless P = NP. There are approximate polynomial-time algorithms to solve the problem though. Following is a simple approximate algorithm adapted from CLRS book.
Approximate Algorithm for Vertex Cover: 
 

1) Initialize the result as {}
2) Consider a set of all edges in given graph.  Let the set be E.
3) Do following while E is not empty
...a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
...b) Remove all edges from E which are either incident on u or v.
4) Return result 

Below diagram to show the execution of the above approximate algorithm: 
 

[vertexCover](https://media.geeksforgeeks.org/wp-content/uploads/vertexcover.png)

![](https://media.geeksforgeeks.org/wp-content/uploads/minimumvertexcover.png)

How well the above algorithm perform? 
It can be proved that the above approximate algorithm never finds a vertex cover whose size is more than twice the size of the minimum possible vertex cover (Refer this for proof)*/
// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <list>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void printVertexCover(); // prints vertex cover
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
	// Initialize all vertices as not visited.
	bool visited[V];
	for (int i=0; i<V; i++)
		visited[i] = false;

	list<int>::iterator i;

	// Consider all edges one by one
	for (int u=0; u<V; u++)
	{
		// An edge is only picked when both visited[u] and visited[v]
		// are false
		if (visited[u] == false)
		{
			// Go through all adjacents of u and pick the first not
			// yet visited vertex (We are basically picking an edge
			// (u, v) from remaining edges.
			for (i= adj[u].begin(); i != adj[u].end(); ++i)
			{
				int v = *i;
				if (visited[v] == false)
				{
					// Add the vertices (u, v) to the result set.
					// We make the vertex u and v visited so that
					// all edges from/to them would be ignored
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	// Print the vertex cover
	for (int i=0; i<V; i++)
		if (visited[i])
		cout << i << " ";
    std::cout<<std::endl;
}

// Driver program to test methods of graph class
int main(int argc, char const *argv[])
{
	// Create a graph given in the above diagram
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);

	g.printVertexCover();
    remove(argv[0]);
	return 0;
}
