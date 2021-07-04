/*Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.
Examples: 

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.

Input: k = 3, arr[] = {1, 2, 3, 4, 5}
Output: false

Input: k = 3, arr[] = {1, 2, 3, 4, 4}
Output: true*/
#include <iostream>
#include <vector>
using namespace std;

void FindDuplicateAtKth(int arr[], int size, int k)
{
    for(int i=0;i<size;i++)
    {
        if(i+k >= size){
            cout<<"not found"<<endl;
            return;
        }
        if(arr[i] == arr[i+k]){
            cout<<"found "<<arr[i] <<" at "<< i<<", "<<i+k<<endl;
            return;
        }
    }
    cout<<"not found"<<endl;
}


int main()
{
    int arr[]={1, 2, 3, 4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    FindDuplicateAtKth(arr, n, 3);
    return 0;
}