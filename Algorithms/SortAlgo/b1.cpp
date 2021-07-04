/*Check whether Arithmetic Progression can be formed from the given array
Difficulty Level : Medium
Last Updated : 08 Jun, 2021
Geek-O-Lympics
Given an array of n integers. The task is to check whether an arithmetic progression can be formed using all the given elements. If possible print “Yes”, else print “No”.

Examples: 

Input : arr[] = {0, 12, 4, 8}
Output : Yes
Rearrange given array as {0, 4, 8, 12} 
which forms an arithmetic progression.

Input : arr[] = {12, 40, 11, 20}
Output : No*/
#include <iostream>
#include <algorithm>
using namespace std;

bool isAP(int arr[], int n)
{
    sort(arr,arr+n);
    int d=arr[1]-arr[0];
    for(int i=2;i<n;i++)
        if(d!=(arr[i]-arr[i-1]))
            return false;

    return true;
}

int main(int argc, char const *argv[])
{
    int arr[]={0,12,4,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<(isAP(arr,n)? "yes":"no")<<endl;
    remove(argv[0]);
    return 0;
}
