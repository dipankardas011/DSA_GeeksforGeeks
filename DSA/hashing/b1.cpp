/*Printing longest Increasing consecutive subsequence
Given n elements, write a program that prints the longest increasing subsequence whose adjacent element difference is one.

Examples:

Input : a[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12}
Output : 3 4 5 6 7 8
Explanation: 3, 4, 5, 6, 7, 8 is the longest increasing subsequence whose adjacent element differs by one.

Input : a[] = {6, 7, 8, 3, 4, 5, 9, 10}
Output : 6 7 8 9 10
Explanation: 6, 7, 8, 9, 10 is the longest increasing subsequence*/
#include <bits/stdc++.h>
using namespace std;

void LongestConsecutiveSequence(int a[], int n)
{
    // the difference is 1
    // and it is a increasing sequence
       
    // sort(a,a+n);
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<endl;
    
    int max=1;
    int len=1;
    int end;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]+1 == a[i+1])
        {
            end=i+1;
            len++;
        }
        else{
            if(len > max)
            {
                max=len;
                len=0;
            }
            else{
                // if len found is < max
                len=0;
                continue;
            }
        }
    }
    for(int i=end-max;i<=end;i++)
        cout<<a[i]<< " ";
    cout<<endl;
}


int main()
{
    int a[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    int n=sizeof(a)/sizeof(a[0]);
    LongestConsecutiveSequence(a,n);
    return 0;
}