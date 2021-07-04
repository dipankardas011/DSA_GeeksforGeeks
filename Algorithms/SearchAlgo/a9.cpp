/*Search an element in an array where difference between adjacent elements is 1
Difficulty Level : Medium
Last Updated : 12 Apr, 2021
Given an array where difference between adjacent elements is 1, write an algorithm to search for an element in the array and return the position of the element (return the first occurrence).
Examples : 

Let element to be searched be x

Input: arr[] = {8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3}     
       x = 3
Output: Element 3 found at index 7

Input: arr[] =  {1, 2, 3, 4, 5, 4}
       x = 5
Output: Element 5 found at index 4 */
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x){
    // traverse the given array stating from leftmost element
    int i=0;
    while(i<n){
        if(arr[i]==x)
            return i;

        i+=abs(arr[i]-x);
    }
    cout<<"number NOT PRESENT!"<<endl;
    return -1;
}
int main(){
    int arr[]={8,7,6,7,6,5,4,3,2,3,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=3;
    cout<<"element "<<x<<" is present at idx: "<<search(arr,n,x);
    cout<<endl;
    return 0;
}