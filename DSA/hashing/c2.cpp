/*Minimum number of distinct elements after removing m items
Difficulty Level : Medium
Last Updated : 13 Jan, 2021
Given an array of items, an i-th index element denotes the item id’s, and given a number m, the task is to remove m elements such that there should be minimum distinct id’s left. Print the number of distinct id’s.
Examples: 
 

Input : arr[] = { 2, 2, 1, 3, 3, 3} 
            m = 3
Output : 1
Remove 1 and both 2's.So, only 3 will be 
left that's why distinct id is 1.

Input : arr[] = { 2, 4, 1, 5, 3, 5, 1, 3} 
            m = 2
Output : 3
Remove 2 and 4 completely. So, remaining ids 
are 1, 3 and 5 i.e. 3*/
#include <bits/stdc++.h>
using namespace std;

int MinDistinctElement(int a[], int n, int m)
{
    unordered_map<int,int> map;
    int count=0;
    //find the frequency
    for(int i=0;i<n;i++)
        map[a[i]] += 1;
    vector<pair<int, int>> v;
    //reverse storing so that we can sort it
    for (auto it = map.begin(); it != map.end(); it++)
        v.push_back(make_pair(it->second, it->first));
    sort(v.begin(), v.end());

      int size = v.size();
 
    // Start removing elements from the beginning
    for (int i = 0; i < size; i++) {
 
        // Remove if current value is less than
        // or equal to mi
        if (v[i].first <= m) {
            m -= v[i].first;
            count++;
        }
 
        // Return the remaining size
        else
            return size - count;
    }
    return size - count;
}


int main()
{
    int arr[] = { 2, 2, 1, 3, 3, 3};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<MinDistinctElement(arr,size,3)<<endl;
    return 0;
}