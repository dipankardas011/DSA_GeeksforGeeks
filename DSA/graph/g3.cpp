/*Find the minimum cost to reach destination using a train
Difficulty Level : Medium
Last Updated : 26 Dec, 2018
There are N stations on route of a train. The train goes from station 0 to N-1. The ticket cost for all pair of stations (i, j) is given where j is greater than i. Find the minimum cost to reach the destination.

Consider the following example:

Input: 
cost[N][N] = { {0, 15, 80, 90},
              {INF, 0, 40, 50},
              {INF, INF, 0, 70},
              {INF, INF, INF, 0}
             };
There are 4 stations and cost[i][j] indicates cost to reach j 
from i. The entries where j < i are meaningless.

Output:
The minimum cost is 65
The minimum cost can be obtained by first going to station 1 
from 0. Then from station 1 to station 3.*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 4
/*  here the train start from 0 to N-1  */

int CostFinder(int cost[N][N], int s, int d){

    // if source == distination and vice versa
    /*
        The minimum cost to reach N-1 from 0 can be recursively written as following:

minCost(0, N-1) = MIN { cost[0][n-1],  
                        cost[0][1] + minCost(1, N-1),  
                        minCost(0, 2) + minCost(2, N-1), 
                        ........, 
                        minCost(0, N-2) + cost[N-2][n-1] } 
The following is the implementation of above recursive formula.
    */
    if(s==d || s+1 == d)
        return cost[s][d];

    int min=cost[s][d];

    for(int i=s+1; i<d; i++)
    {
        int c = CostFinder(cost, s, i)+CostFinder(cost, i,d);

        if(min>c)   min=c;
    }
    return min;
}

int mincost(int cost[][N]){
    return CostFinder(cost, 0, N-1);
}

int main(){
    int cost[N][N] = { 
            {0, 15, 80, 90},
            {INF, 0, 40, 50},
            {INF, INF, 0, 70},
            {INF, INF, INF, 0}
    };

    cout<<"the min cost: $"<<mincost(cost)<<endl;
    //d
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=i;j<N;j++)
    //         printf("%d\t",cost[i][j]);
    //     printf("\n");
    // }
    return 0;
}