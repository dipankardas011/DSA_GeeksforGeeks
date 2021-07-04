/*Range Queries for Frequencies of array elements
Difficulty Level : Medium
Last Updated : 18 Nov, 2019
Given an array of n non-negative integers. The task is to find frequency of a particular element in the arbitrary range of array[]. The range is given as positions (not 0 based indexes) in array. There can be multiple queries of given type.
Examples:

Input  : arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
         left = 2, right = 8, element = 8
         left = 2, right = 5, element = 6      
Output : 3
         1
The element 8 appears 3 times in arr[left-1..right-1]
The element 6 appears 1 time in arr[left-1..right-1]*/
#include <bits/stdc++.h>
using namespace std;

void creatingHash(int a[], int size, 
            unordered_map<int, vector<int>>& map)
{
    // the position of the element in arr is in vector
    // and element is itself in the index
    for(int i=0;i<size;i++)
    {
        map[a[i]].push_back(i);
    }
    return;
}

void query(unordered_map<int, vector<int>>& map,
           int left, int right, int ele)
{
    // then the position in the vector is <=left-1 and >= right-1
    // then count++
    int count=0;
    for(int i=0;i<map[ele].size(); i++)
    {
        if(map[ele].at(i) >= left-1 && 
                map[ele].at(i) <= right-1)
        {
            count++;
        }
    }
    cout<<"the frequency of element = "
        << ele << " is "<<count<<endl;
}

int main()
{
    int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
    int size=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int, vector<int>> Hash;
    creatingHash(arr, size, Hash);
    query(Hash,2,8,8);
    query(Hash,2,5,6);
    return 0;
}