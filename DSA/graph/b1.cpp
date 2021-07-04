/*All Topological Sorts of a Directed Acyclic Graph
We are given a map of cities connected with each other 
via cable lines such that there is no cycle between any 
two cities. We need to find the maximum length of cable 
between any two cities for given city map.

Input : n = 6  
        1 2 3  // Cable length from 1 to 2 (or 2 to 1) is 3
        2 3 4
        2 6 2
        6 4 6
        6 5 5
Output: maximum length of cable = 12*/
#include <bits/stdc++.h>
using namespace std;

// We create undirected graph for given city map and do DFS from 
// every city to find maximum length of cable. While traversing, we look 
// for total cable length to reach the current city and 
// if it’s adjacent city is not visited then call DFS for it but if all 
// adjacent cities are visited for current node, then update the value of 
// max_length if previous value of max_length is less than current value of total cable length.


void SearchingLongestPath(vector<pair<int, int>> graph[],
            int src,int len,
            vector<bool>& visited, 
            int& maxlen)
{
    int curr=0;

    visited[src]=true;
    
    for(int i=0; i<graph[src].size(); i++)
    {
        if(!visited[ graph[src][i].first ])
        {
            curr=len+graph[src][i].second;
            SearchingLongestPath(graph, graph[src][i].first, curr, visited, maxlen);
        }
        // if visited stop and check
        if(maxlen < curr)    maxlen=curr;
        curr=0;
    }
}

int LongestDist(vector<pair<int, int>> graph[], int n){

    int maxlen=INT_MIN;

    // taking one vertex at a time and seeing it's distance from it's adjacent
    // nodes

    for(int i=1;i<=n;i++)
    {
        // some function that will return the maxlen by reference
        // fromt the graph[vertex]
        vector<bool> visited(n+1, false);
        // here the N+1 because the last element we have to take as
        // index like[0, ..... , N] so that we can hash it
        SearchingLongestPath(graph, i, 0, visited, maxlen);
    }

    return maxlen;
}




int main(){
    int N=6;// number of vertices
    vector<pair<int, int>> graph[N+1];
    graph[1].push_back(make_pair(2,3));
    graph[2].push_back(make_pair(1,3));

    graph[2].push_back(make_pair(3,4));
    graph[3].push_back(make_pair(2,4));

    graph[2].push_back(make_pair(6,2));
    graph[6].push_back(make_pair(2,2));

    graph[6].push_back(make_pair(4,6));
    graph[4].push_back(make_pair(6,6));

    graph[6].push_back(make_pair(5,5));
    graph[5].push_back(make_pair(6,5));
    // make the undirected graph
    cout<<"longest path: "<<LongestDist(graph, N)<<endl;
    return 0;
}