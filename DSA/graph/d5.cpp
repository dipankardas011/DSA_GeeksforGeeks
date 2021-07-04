/*Minimum Product Spanning Tree
Difficulty Level : Medium
Last Updated : 27 Nov, 2020
GeeksforGeeks - Summer Carnival Banner
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum product spanning tree for a weighted, connected and undirected graph is a spanning tree with weight product less than or equal to the weight product of every other spanning tree. The weight product of a spanning tree is the product of weights corresponding to each edge of the spanning tree. All weights of the given graph will be positive for simplicity.

Examples:



Minimum Product that we can obtain is 
180 for above graph by choosing edges 
0-1, 1-2, 0-3 and 1-4*/
// This problem can be solved using standard minimum spanning tree algorithms like krushkal and prim’s algorithm, but we need to modify our graph to use these algorithms. Minimum spanning tree algorithms tries to minimize total sum of weights, here we need to minimize total product of weights. We can use property of logarithms to overcome this problem. 
// As we know, 

//   log(w1* w2 * w3 * …. * wN) = 
//      log(w1) + log(w2) + log(w3) ….. + log(wN)
// We can replace each weight of graph by its log value, then we apply any minimum spanning tree algorithm which will try to minimize sum of log(wi) which in-turn minimizes weight product. 
// For example graph, steps are shown in below diagram,
// A C++ program for getting minimum product
// spanning tree The program is for adjacency matrix
// representation of the graph
#include <bits/stdc++.h>

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum
// key value, from the set of vertices not yet included
// in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed MST
// stored in parent[] and print Minimum Obtaiable
// product
int printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge Weight\n");
	int minProduct = 1;
	for (int i = 1; i < V; i++) {
		printf("%d - %d %d \n",
			parent[i], i, graph[i][parent[i]]);

		minProduct *= graph[i][parent[i]];
	}
	printf("Minimum Obtainable product is %d\n",
		minProduct);
}

// Function to construct and print MST for a graph
// represented using adjacency matrix representation
// inputGraph is sent for printing actual edges and
// logGraph is sent for actual MST operations
void primMST(int inputGraph[V][V], double logGraph[V][V])
{
	int parent[V]; // Array to store constructed MST
	int key[V]; // Key values used to pick minimum
	// weight edge in cut
	bool mstSet[V]; // To represent set of vertices not
	// yet included in MST

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	key[0] = 0; // Make key 0 so that this vertex is
	// picked as first vertex
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum key vertex from the set of
		// vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of the
		// adjacent vertices of the picked vertex.
		// Consider only those vertices which are not yet
		// included in MST
		for (int v = 0; v < V; v++)

			// logGraph[u][v] is non zero only for
			// adjacent vertices of m mstSet[v] is false
			// for vertices not yet included in MST
			// Update the key only if logGraph[u][v] is
			// smaller than key[v]
			if (logGraph[u][v] > 0 && mstSet[v] == false && 
                logGraph[u][v] < key[v])
			parent[v] = u, key[v] = logGraph[u][v];
	}

	// print the constructed MST
	printMST(parent, V, inputGraph);
}

// Method to get minimum product spanning tree
void minimumProductMST(int graph[V][V])
{
	double logGraph[V][V];

	// Constructing logGraph from original graph
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] > 0)
				logGraph[i][j] = log(graph[i][j]);
			else
				logGraph[i][j] = 0;
		}
	}

	// Applyting standard Prim's MST algorithm on
	// Log graph.
	primMST(graph, logGraph);
}

// driver program to test above function
int main()
{
	/* Let us create the following graph
		   2    3
       (0)--(1)--(2)
        |   / \   |
       6| 8/   \5 |7
        | /     \ |
       (3)-------(4)
             9     		 */
	int graph[V][V] = {
		{ 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 },
	};

	// Print the solution
	minimumProductMST(graph);

	return 0;
}
