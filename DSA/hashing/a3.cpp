/*Smallest subarray with all occurrences of a most frequent element
Given an array, A.Let x be an element in the array.x has the maximum frequency in the array.Find the smallest subsegment of the array which also has x as the maximum frequency element.

Examples:

Input :  arr[] = {4, 1, 1, 2, 2, 1, 3, 3} 
Output :   1, 1, 2, 2, 1
The most frequent element is 1. The smallest
subarray that has all occurrences of it is
1 1 2 2 1

Input :  A[] = {1, 2, 2, 3, 1}
Output : 2, 2
Note that there are two elements that appear
two times, 1 and 2. The smallest window for
1 is whole array and smallest window for 2 is
{2, 2}. Since window for 2 is smaller, this is
our output.*/
#include <bits/stdc++.h>
using namespace std;

void smallestsubarray(int a[], int n)
{
    unordered_map<int, int>left;
    unordered_map<int, int>count;

    int mx=0; // store maximum frequency
    int mn, strindex; // to store length and starting 
    // index of smallest result windows

    for(int i=0;i<n;i++)
    {
        int x=a[i];

        if(count[x] == 0) {
            left[x] = i;
            count[x]=1;
        }
        else    count[x]++;


        if(count[x] > mx)
        {
            // maximum frequency
            mx=count[x];
            mn= i-left[x] +1;
            strindex=left[x];
        }
        else if(count[x] ==mx && i-left[x]+1 <mn) {
            mn = i-left[x]+1;
            // for equal frequency 
            // but smaller subarray
            strindex=left[x];
        }
    }

    for(int i=strindex; i<strindex+mn;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {4, 1, 1, 2, 2, 1, 3, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    smallestsubarray(arr,n);
    return 0;
}