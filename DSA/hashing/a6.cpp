/*Find pairs in array whose sums already exist in array

Given an array of n distinct and positive elements, the task is to find pair whose sum already exists in given array.

Examples :

Input : arr[] = {2, 8, 7, 1, 5};
Output : 2 5
         7 1

Input : arr[] = {7, 8, 5, 9, 11};
Output : Not Exist*/
#include <bits\stdc++.h>

void SumPairExist(int a[], int n)
{
    std::unordered_set<int> x;
    for(int i=0;i<n;i++)
        x.insert(a[i]);
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {// it is i+1 because we have done comparasion before
            if(x.find(a[j]+a[i]) != x.end())
                std::cout<<a[i]<<", "<<a[j]<<std::endl;
        }
    }
}

int main() {
    int a[] = {2, 8, 7, 1, 5};
    int n=sizeof(a)/sizeof(a[0]);
    SumPairExist(a,n);
    return 0;
}