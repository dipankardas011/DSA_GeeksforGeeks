/*Maximum number of edges to be added to a tree so that it stays a Bipartite graph
A tree is always a Bipartite Graph as we can always break into two disjoint sets with alternate levels. In other words we always color it with two colors such that alternate levels have same color. The task is to compute the maximum no. of edges that can be added to the tree so that it remains Bipartite Graph.

Examples:

Input : Tree edges as vertex pairs 
        1 2
        1 3
Output : 0
Explanation :
The only edge we can add is from node 2 to 3.
But edge 2, 3 will result in odd cycle, hence 
violation of Bipartite Graph property.

Input : Tree edges as vertex pairs 
        1 2
        1 3
        2 4
        3 5
Output : 2
Explanation : On colouring the graph, {1, 4, 5} 
and {2, 3} form two different sets. Since, 1 is 
connected from both 2 and 3, we are left with 
edges 4 and 5. Since, 4 is already connected to
2 and 5 to 3, only options remain {4, 3} and 
{5, 2}.*/
#include <bits/stdc++.h>
using namespace std;
// 1) Do a simple DFS (or BFS) traversal of graph and color it with two colors.
// 2) While coloring also keep track of counts of nodes colored with the two colors. Let the two counts be count_color0 and count_color1.
// 3) Now we know maximum edges a bipartite graph can have are count_color0 x count_color1.
// 4) We also know tree with n nodes has n-1 edges.
// 5) So our answer is count_color0 x count_color1 – (n-1).
// CPP code to print maximum edges such that
// Tree remains a Bipartite graph
// To store counts of nodes with two colors
long long count_color[2];

void dfs(vector<int> adj[], int node, int parent, int color)
{
	// Increment count of nodes with current
	// color
	count_color[color]++;

	// Traversing adjacent nodes
	for (int i = 0; i < adj[node].size(); i++) {

		// Not recurring for the parent node
		if (adj[node][i] != parent)
			dfs(adj, adj[node][i], node, !color);
	}
}

// Finds maximum number of edges that can be added
// without violating Bipartite property.
int findMaxEdges(vector<int> adj[], int n)
{
	// Do a DFS to count number of nodes
	// of each color
	dfs(adj, 1, 0, 0);

	return count_color[0] * count_color[1] - (n - 1);
}

// Driver code
int main()
{
	int n = 5;
	vector<int> adj[n + 1];
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(5);
	cout << findMaxEdges(adj, n);
	return 0;
}
