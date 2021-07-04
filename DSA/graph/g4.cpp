/*Calculate number of nodes between two vertices in an acyclic Graph by Disjoint Union method
Difficulty Level : Medium
Last Updated : 21 Oct, 2019
Given a connected acyclic graph, a source vertex and a destination vertex, your task is to count the number of vertices between the given source and destination vertex by Disjoint Union Method .

Examples:

Input : 1 4
        4 5
        4 2
        2 6
        6 3
        1 3 
Output : 3
In the input 6 is the total number of vertices
labeled from 1 to 6 and the next 5 lines are the connection 
between vertices. Please see the figure for more
explanation. And in last line 1 is the source vertex
and 3 is the destination vertex. From the figure 
it is clear that there are 3 nodes(4, 2, 6) present
between 1 and 3.*/
// C++ program to calculate number
// of nodes between two nodes
#include <bits/stdc++.h>
using namespace std;

// function to calculate no of nodes
// between two nodes
int totalNodes(vector<int> adjac[], int n,
               int x, int y)
{
    // x is the source node and
    // y is destination node

    // visited array take account of
    // the nodes visited through the bfs
    bool visited[n + 1] = {0};

    // parent array to store each nodes
    // parent value
    int p[n];

    queue<int> q;
    q.push(x);

    // take our first node(x) as first element
    // of queue and marked it as
    // visited through visited[] array
    visited[x] = true;

    int m;

    // normal bfs method starts
    while (!q.empty())
    {
        m = q.front();
        q.pop();
        for (int i = 0; i < adjac[m].size(); ++i)
        {
            int h = adjac[m][i];
            if (!visited[h])
            {
                visited[h] = true;

                // when new node is encountered
                // we assign it's parent value
                // in parent array p
                p[h] = m;
                q.push(h);
            }
        }
    }

    // count variable stores the result
    int count = 0;

    // loop start with parent of y
    // till we encountered x
    int i = p[y];
    while (i != x)
    {
        // count increases for counting
        // the nodes
        count++;

        i = p[i];
    }

    return count;
}

// Driver program to test above function
int main()
{
    // adjacency list for graph
    vector<int> adjac[7];

    // creating graph, keeping length of
    // adjacency list as (1 + no of nodes)
    // as index ranges from (0 to n-1)
    adjac[1].push_back(4);
    adjac[4].push_back(1);
    adjac[5].push_back(4);
    adjac[4].push_back(5);
    adjac[4].push_back(2);
    adjac[2].push_back(4);
    adjac[2].push_back(6);
    adjac[6].push_back(2);
    adjac[6].push_back(3);
    adjac[3].push_back(6);

    cout << totalNodes(adjac, 7, 1, 3);

    return 0;
}