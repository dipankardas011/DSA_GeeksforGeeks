/*Minimum cost to connect all cities
Difficulty Level : Medium
Last Updated : 07 Nov, 2020
There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair a particular road. Find out the minimum cost to connect all the cities by repairing roads. Input is in matrix(city) form, if city[i][j] = 0 then there is not any road between city i and city j, if city[i][j] = a > 0 then the cost to rebuild the path between city i and city j is a. Print out the minimum cost to connect all the cities. 
It is sure that all the cities were connected before the roads were damaged.

Examples: 

Input : {{0, 1, 2, 3, 4},
         {1, 0, 5, 0, 7},
         {2, 5, 0, 6, 0},
         {3, 0, 6, 0, 0},
         {4, 7, 0, 0, 0}};
Output : 10


min-cost

Input : {{0, 1, 1, 100, 0, 0},
         {1, 0, 1, 0, 0, 0},
         {1, 1, 0, 0, 0, 0},
         {100, 0, 0, 0, 2, 2},
         {0, 0, 0, 2, 0, 2},
         {0, 0, 0, 2, 2, 0}};
Output : 106*/
// Method: Here we have to connect all the cities by path which will cost us least.
// The way to do that is to find out the Minimum Spanning Tree(MST)
// of the map of the cities(i.e. each city is a node of the graph and all the damaged roads
// between cities are edges). And the total cost is the addition of the path edge values in the Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;

// Function to find out minimum valued node
// among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[])
{
    int mini = INT_MAX;
    int mini_index;

    for (int i = 0; i < n; i++)
    {
        if (!mstset[i] && keyval[i] < mini)
            mini = keyval[i], mini_index = i;
    }
    return mini_index;
}

// function to find out the MST and
// the cost of the MST
void findcost(int n, vector<vector<int>> city)
{
    // to store the parent node of particular node
    int parent[n];
    // array to store key value of each node
    int keyval[n];
    //whether the node is included in MST
    bool mstset[n];

    for (int i = 0; i < n; i++)
    {
        keyval[i] = INT_MAX;
        mstset[i]=false;
    }
    parent[0]=-1;
    keyval[0]=0;
    for(int i=0;i<n-1;i++){
        // min node from the unvisited nodes
        int u=minnode(n, keyval, mstset);

        mstset[u]=true;

        for(int v=0;v<n;v++){
            if(city[u][v] && !mstset[v] &&
                city[u][v]<keyval[v]){
                    keyval[v]=city[u][v];
                    parent[v]=u;
                }
        }
    }

    // find the cost
    int cost=0;
    for(int i=1;i<n;i++)
        cost+=city[parent[i]][i];
    cout<<cost<<endl;
}
int main() {
 
  // Input 1
  int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};
  findcost(n1, city1);
 
  // Input 2
  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},  
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2}, 
                               {0, 0, 0, 2, 2, 0}};
  findcost(n2, city2);
 
  return 0;
}