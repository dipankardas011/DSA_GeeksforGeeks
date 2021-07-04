/*Number of sextuplets (or six values) that satisfy an equation
Difficulty Level : Medium
Last Updated : 02 Jun, 2021
Geek-O-Lympics
Given an array of n elements. The task is to find number of sextuplets that satisfy the below equation such that a, b, c, d, e and f belong to the given array:

(a * b + c)/d - e = f
    |
   \/
a*b+c = (e+f)*d

Examples: 

Input :  arr[] = { 1 }.
Output : 1
a = b = c = d = e = f = 1 satisfy
the equation.

Input :  arr[] = { 2, 3 }
Output : 4

Input :  arr[] = { 1, -1 }
Output : 24

First, reorder the equation, a * b + c = (f + e) * d. 
Now, make two arrays, one for LHS (Left Hand Side) of the equation and one for the RHS (Right Hand Side) of the equation. Search each element of RHS’s array in the LHS’s array. Whenever you find a value of RHS in LHS, check how many times it is repeated in LHS and add that count to the total. Searching can be done using binary search, by sorting the LHS array*/
#include <iostream>
#include <algorithm>
int findSextuplets(int arr[], int n){
    int index=0;
    int rhs[n*n*n+1];
    for(int i=0;i<n;i++)
    {
        if(arr[i])
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    rhs[index++]=arr[i] *(arr[j]+arr[k]);
    }
    std::sort(rhs,rhs+n);
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                int val=arr[i]*arr[j]+arr[k];//lhs
                result+=(std::upper_bound(rhs,rhs+index,val) - std::lower_bound(rhs,rhs+index, val));
            }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[]={2,3};
    int n=sizeof arr / sizeof arr[0];
    std::cout<<findSextuplets(arr,n)<<std::endl;
    remove(argv[0]);
    return 0;
}
