/*Delete Edge to minimize subtree sum differenceGiven an undirected 
tree whose each node is associated with a weight. We need to delete 
an edge in such a way that difference between sum of weight in one 
subtree to sum of weight in other subtree is minimized.

Example: 



In above tree, 
We have 6 choices for edge deletion,
edge 0-1,  subtree sum difference = 21 - 2 = 19
edge 0-2,  subtree sum difference = 14 - 9 = 5
edge 0-3,  subtree sum difference = 15 - 8 = 7
edge 2-4,  subtree sum difference = 20 - 3 = 17
edge 2-5,  subtree sum difference = 18 - 5 = 13
edge 3-6,  subtree sum difference = 21 - 2 = 19*/

// We can solve this problem using DFS. One simple solution is to delete each edge one by one and check subtree sum difference. Finally choose the minimum of them. This approach takes quadratic amount of time. An efficient method can solve this problem in linear time by calculating the sum of both subtrees using total sum of the tree. We can get the sum of other tree by subtracting sum of one subtree from the total sum of tree, in this way subtree sum difference can be calculated at each node in O(1) time. First we calculate the weight of complete tree and then while doing the DFS at each node, we calculate its subtree sum, by using these two values we can calculate subtree sum difference. 
// In below code, another array subtree is used to store sum of subtree rooted at node i in subtree[i]. DFS is called with current node index and parent index each time to loop over children only at each node. 

#include <bits/stdc++.h>
using namespace std;

/* DFS method to traverse through edges,
calculating subtree sum at each node and
updating the difference between subtrees */
void dfs(int u, int parent, int totalSum,
		vector<int> edge[], int subtree[], int& res)
{
	int sum = subtree[u];

	/* loop for all neighbors except parent and
		aggregate sum over all subtrees */
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != parent)
		{
			dfs(v, u, totalSum, edge, subtree, res);
			sum += subtree[v];
		}
	}

	// store sum in current node's subtree index
	subtree[u] = sum;

	/* at one side subtree sum is 'sum' and other side
		subtree sum is 'totalSum - sum' so their difference
		will be totalSum - 2*sum, by which we'll update
		res */
	if (u != 0 && abs(totalSum - 2*sum) < res)
		res = abs(totalSum - 2*sum);
}

// Method returns minimum subtree sum difference
int getMinSubtreeSumDifference(int vertex[],
					int edges[][2], int N)
{
	int totalSum = 0;
	int subtree[N];

	// Calculating total sum of tree and initializing
	// subtree sum's by vertex values
	for (int i = 0; i < N; i++)
	{
		subtree[i] = vertex[i];
		totalSum += vertex[i];
	}

	// filling edge data structure
	vector<int> edge[N];
	for (int i = 0; i < N - 1; i++)
	{
		edge[edges[i][0]].push_back(edges[i][1]);
		edge[edges[i][1]].push_back(edges[i][0]);
	}

	int res = INT_MAX;

	// calling DFS method at node 0, with parent as -1
	dfs(0, -1, totalSum, edge, subtree, res);
	return res;
}

// Driver code to test above methods
int main()
{
	int vertex[] = {4, 2, 1, 6, 3, 5, 2};
	int edges[][2] = {{0, 1}, {0, 2}, {0, 3},
					{2, 4}, {2, 5}, {3, 6}};
	int N = sizeof(vertex) / sizeof(vertex[0]);

	cout << getMinSubtreeSumDifference(vertex, edges, N);
	return 0;
}
