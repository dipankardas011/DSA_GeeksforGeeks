/*Count Inversions of size three in a given array
Difficulty Level : Hard
Last Updated : 12 Apr, 2021
Given an array arr[] of size n. Three elements arr[i], arr[j] and arr[k] form an inversion of size 3 if a[i] > a[j] >a[k] and i < j < k. Find total number of inversions of size 3.
Example : 
 

Input:  {8, 4, 2, 1}
Output: 4
The four inversions are (8,4,2), (8,4,1), (4,2,1) and (8,2,1).

Input:  {9, 6, 4, 5, 8}
Output:  2
The two inversions are {9, 6, 4} and {9, 6, 5}
We have already discussed inversion count of size two by merge sort, Self Balancing BST and BIT.

We can reduce the complexity if we consider every element arr[i] as middle element of inversion, find all the numbers greater than a[i] whose index is less than i, find all the numbers which are smaller than a[i] and index is more than i. We multiply the number of elements greater than a[i] to the number of elements smaller than a[i] and add it to the result. 
Below is the implementation of the idea.*/
#include <bits/stdc++.h>
using namespace std;
// return count of inversion of size 3
int getinvCount(int arr[], int n){
    int invcount=0;
    for(int i=1;i<n-1;i++){
        int small=0;
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                small++;
        int great=0;
        for(int j=i+1;j>=0;j--)
            if(arr[i]<arr[j])
                great++;

        invcount+=great*small;
    }
    return invcount;
}
int main(){
    int arr[]={8,4,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"inversion count: "<<getinvCount(arr, n);
    return 0;
}