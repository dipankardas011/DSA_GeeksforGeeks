// /*Diameter of an N-ary tree

// The diameter of an N-ary tree is the longest path present between any two nodes of the tree. These two nodes must be two leaf nodes. The following examples have the longest path[diameter] shaded.*/
// //Optimizations to above solution : 

// We can make a hash table to store the heights of all nodes. If we precompute these heights, we don’t need to call depthOfTree() for every node. 

// A different optimized solution: Longest path in an undirected tree

// Another Approach to get diameter using DFS in one traversal:

// The diameter of a tree can be calculated as for every node

// The current node isn’t part of diameter (i.e Diameter lies on one of the children of the current node).
// The current node is part of diameter (i.e Diameter passes through the current node).
// C++ implementation to find
// diameter of a tree using
// DFS in ONE TRAVERSAL

#include <iostream>
#include <vector>
using namespace std;
#define maxN 10005

// The array to store the
// height of the nodes
int height[maxN];

// Adjacency List to store
// the tree
vector<int> tree[maxN];

// varaiable to store diameter
// of the tree
int diameter = 0;

// Function to add edge between
// node u to node v
void addEdge(int u, int v)
{
	// add edge from u to v
	tree[u].push_back(v);

	// add edge from v to u
	tree[v].push_back(u);
}

void dfs(int cur, int par)
{
	// Variables to store the height of children
	// of cur node with maximum heights
	int max1 = 0;
	int max2 = 0;

	// going in the adjacency list of the current node
	for (auto u : tree[cur]) {
		
		// if that node equals parent discard it
		if (u == par)
			continue;

		// calling dfs for child node
		dfs(u, cur);

		// calculating height of nodes
		height[cur] = max(height[cur], height[u]);

		// getting the height of children
		// of cur node with maximum height
		if (height[u] >= max1) {
			max2 = max1;
			max1 = height[u];
		}
		else if (height[u] > max2) {
			max2 = height[u];
		}
	}

	height[cur] += 1;

	// Diameter of a tree can be calculated as
	// diameter passing through the node
	// diameter doesn't includes the cur node
	diameter = max(diameter, height[cur]);
	diameter = max(diameter, max1 + max2 + 1);
}

// Driver Code
int main()
{
	// n is the number of nodes in tree
	int n = 7;

	// Adding edges to the tree
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 5);
	addEdge(4, 6);
	addEdge(4, 7);

	// Calling the dfs function to
	// calculate the diameter of tree
	dfs(1, 0);

	cout << "Diameter of tree is : " << diameter - 1
		<< "\n";

	return 0;
}
