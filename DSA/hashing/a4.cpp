/*Find elements which are present in first array and not in second
Given two arrays, the task is that we find numbers which are present in first array, but not present in the second array.
Examples :

Input : a[] = {1, 2, 3, 4, 5, 10};
    b[] = {2, 3, 1, 0, 5};
Output : 4 10    
4 and 10 are present in first array, but
not in second array.

Input : a[] = {4, 3, 5, 9, 11};
        b[] = {4, 9, 3, 11, 10};
Output : 5  */
#include <bits/stdc++.h>

void AbsenceOfElements(int a[], int n, int b[], int m)
{
    std::unordered_set<int> x;

    for(int i=0;i<m;i++)
        x.insert(b[i]);
    
    for(int i=0;i<n;i++)
    {
        if(x.find(a[i]) == x.end())
            std::cout<<a[i]<<" ";
    }
    return;
}


int main()
{
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    AbsenceOfElements(a,n,b,m);
    return 0;
}