/*Sort a nearly sorted (or K sorted) array
Difficulty Level : Medium
Last Updated : 31 May, 2021
Geek-O-Lympics
 
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Examples: 

Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
         k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*We can sort such arrays more efficiently with the help of Heap data structure. Following is the detailed process that uses Heap. 
1) Create a Min Heap of size k+1 with first k+1 elements. This will take O(k) time (See this GFact) 
2) One by one remove min element from heap, put it in result array, and add a new element to heap from remaining elements.
Removing an element and adding a new element to min heap will take log k time. So overall complexity will be O(k) + O((n-k) * log(k)).*/
int sortK(int a[], int n, int k)
{
    int size;
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>,greater<int>> pq(a,a+size);
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        a[index++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(pq.empty()==false){
        a[index++]=pq.top();
        pq.pop();
    }
}


int main(int argc, char const *argv[])
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);
 
    cout << "Following is sorted array" << endl;
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
    remove(argv[0]);
    return 0;
}
