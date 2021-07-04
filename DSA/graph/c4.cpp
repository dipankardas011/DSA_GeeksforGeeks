/*Magical Indices in an array
Given an array A of integers. Index i of A is said to be connected to index j if j = (i + A[i]) % n + 1 (Assume 1-based indexing). Start traversing array from index i and jump to its next connected index. If on traversing array in the described order, index i is again visited then index i is a magical index. Count the number of magical indexes in the array. Assume that array A consists of non-negative integers.

Examples :

Input : A = {1, 1, 1, 1}
Output : 4
Possible traversals:
1 -> 3 -> 1
2 -> 4 -> 2
3 -> 1 -> 3
4 -> 2 -> 4
Clearly all the indices are magical

Input : A = {0, 0, 0, 2}
Output : 2
Possible traversals:
1 -> 2 -> 3 -> 4 -> 3...
2 -> 3 -> 4 -> 3...
3 -> 4 -> 3
4 -> 3 ->4
Magical indices = 3, 4*/
// 1. For each node in the graph:
//      if node i is not visited then:
//        for every adjacent node j:
//          if node j is not visited:
//             par[j] = i
//          else:
//            if par[j]==i
//              cycle detected
//              count nodes in cycle
// 2. return count
// C++ program to find number of magical
// indices in the given array.
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define mod 1000000007

// Function to count number of magical indices.
int solve(int A[], int n)
{
    int i, cnt = 0, j;

    // Array to store parent node of traversal.
    int parent[n + 1];

    // Array to determine whether current node
    // is already counted in the cycle.
    int vis[n + 1];

    // Initialize the arrays.
    memset(parent, -1, sizeof(parent));
    memset(vis, 0, sizeof(vis));

    for (i = 0; i < n; i++)
    {
        j = i;

        // Check if current node is already traversed or not. If node is not traversed yet then parent valuewill be -1.
        if (parent[j] == -1)
        {

            // Traverse the graph until an
            // already visited node is not
            // found.
            while (parent[j] == -1)
            {
                parent[j] = i;
                j = (j + A[j] + 1) % n;
            }

            // Check parent value to ensure
            // a cycle is present.
            if (parent[j] == i)
            {

                // Count number of nodes in
                // the cycle.
                while (!vis[j])
                {
                    vis[j] = 1;
                    cnt++;
                    j = (j + A[j] + 1) % n;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    int A[] = {0, 0, 0, 2};
    int n = sizeof(A) / sizeof(A[0]);
    cout << solve(A, n);
    return 0;
}
