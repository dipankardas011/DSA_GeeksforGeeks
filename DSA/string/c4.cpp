/*Minimum cost to sort strings using reversal operations of different costs

Given an array of strings and costs of reversing all strings, we need to sort the array. We cannot move strings in array, only string reversal is allowed. We need to reverse some of the strings in such a way that all strings make a lexicographic order and cost is also minimized. If it is not possible to sort strings in any way, output not possible. 
Examples: 
 

Input  : arr[] = {“aa”, “ba”, “ac”}, 
        reverseCost[] = {1, 3, 1}
Output : Minimum cost of sorting = 1
Explanation : We can make above string array sorted 
by reversing one of 2nd or 3rd string, but reversing
2nd string cost 3, so we will reverse 3rd string to 
make string array sorted with a cost 1 which is 
minimum.

We can solve this problem using dynamic programming. We make a 2D array for storing the minimum cost of sorting.
 

dp[i][j] represents the minimum cost to make first i
strings sorted.
 j = 1 means i'th string is reversed.
 j = 0 means i'th string is not reversed.

Value of dp[i][j] is computed using dp[i-1][1] and 
dp[i-1][0].

Computation of dp[i][0]
If arr[i] is greater than str[i-1], we update dp[i][0] 
by dp[i-1][0] 
If arr[i] is greater than reversal of previous string 
we update dp[i][0] by dp[i-1][1] 

Same procedure is applied to compute dp[i][1], we 
reverse str[i] before applying the procedure.

At the end we will choose minimum of dp[N-1][0] and 
dp[N-1][1] as our final answer if both of them not 
updated yet even once, we will flag that sorting is
not possible.*/
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::string;

int minCost(string arr[], int cost[], int n){
    /**
     * @param dp[] minimum cost to make first t strings sorted
     * @param j = 1 means ith string is reversed
     * @param j = 0 means ith string is not reversed
     */
    int dp[n][2];
    dp[0][0]=0;
    dp[0][1]=cost[0];
    string revstr[n];
    for(int i=0;i<n;i++){
        revstr[i]=arr[i];
        reverse(revstr[i].begin(), revstr[i].end());
    }
    string curstr;
    int curcost;
    // looping 2 once for string and once for reversed string
    for(int i=1;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=INT_MAX;

            curstr=(j==0)?arr[i]:revstr[i];
            curcost=(j==0)?0:cost[i];
            // update dp value only if current string is lexicographically larger
            if(curstr>=arr[i-1])
                dp[i][j]=std::min(dp[i][j], dp[i-1][0]+curcost);
            if(curstr>=revstr[i-1])
                dp[i][j]=std::min(dp[i][j], dp[i-1][1]+curcost);
        }
    }
    int res=std::min(dp[n-1][0], dp[n-1][1]);
    return (res==INT_MAX)?-1:res;
}


int main(void){
    string arr[]={"aa","ba","ac"};
    int cost[]={1,3,1};
    int N=sizeof(arr)/sizeof(arr[0]);
    int res=minCost(arr,cost,N);
    if(res==-1)
        cout<<"sorting not possible"<<endl;
    else
        cout<<"min cost to sort="<<res<<endl;
    return 0;
}