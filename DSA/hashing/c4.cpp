/*Longest subarray having count of 1s one more than count of 0s

Given an array of size n containing 0’s and 1’s only. The problem is to find the length of the longest subarray having count of 1’s one more than count of 0’s.

Examples:

Input : arr = {0, 1, 1, 0, 0, 1}
Output : 5
From index 1 to 5.

Input : arr[] = {1, 0, 0, 1, 0}
Output : 1
Approach: Following are the steps:

Consider all the 0’s in the array as ‘-1’.
Initialize sum = 0 and maxLen = 0.
Create a hash table having (sum, index) tuples.
For i = 0 to n-1, perform the following steps:
If arr[i] is ‘0’ accumulate ‘-1’ to sum else accumulate ‘1’ to sum.
If sum == 1, update maxLen = i+1.
Else check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.
Check if (sum-1) is present in the hash table or not. if present, then obtain index of (sum-1) from the hash table as index. Now check if maxLen is less than (i-index), then update maxLen = (i-index).
Return maxLen.*/
#include <bits/stdc++.h>
using namespace std;

int LenghtOFSubarray(int a[], int n)
{
    unordered_map<int,int > um;
    int sum=0,maxlen=0;

    for(int i=0;i<n;i++)
    {
        sum += (a[i]==0)? -1 : 1;
        if(sum==1)
            maxlen=i+1;
        else if(um.find(sum) == um.end())
            um[sum]=i;
        
        if(um.find(sum-1) != um.end())
        {
            // if present
            if(maxlen<(i-um[sum-1]))
                maxlen=i-um[sum-1];
        }
    }
    return maxlen;
}

int main()
{
    int a[]={0,1,1,0,0,1};
    int n=sizeof(a)/sizeof(int);
    cout<<"length= "<<LenghtOFSubarray(a,n)<<endl;
    return 0;
}