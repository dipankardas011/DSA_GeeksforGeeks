/*Program to add two polynomials
Difficulty Level : Basic
Last Updated : 13 Apr, 2021
Given two polynomials represented by two arrays, write a function that adds given two polynomials. 
Example: 
 

Input:  A[] = {5, 0, 10, 6} 
        B[] = {1, 2, 4} 
Output: sum[] = {6, 2, 14, 6}

The first input array represents "5 + 0x^1 + 10x^2 + 6x^3"
The second array represents "1 + 2x^1 + 4x^2" 
And Output is "6 + 2x^1 + 14x^2 + 6x^3"
We strongly recommend to minimize your browser and try this yourself first. 
Addition is simpler than multiplication of polynomials. We initialize result as one of the two polynomials, then we traverse the other polynomial and add all terms to the result.
 

add(A[0..m-1], B[0..n01])
1) Create a sum array sum[] of size equal to maximum of 'm' and 'n'
2) Copy A[] to sum[].
3) Traverse array B[] and do following for every element B[i]
          sum[i] = sum[i] + B[i]
4) Return sum[].*/

#include <iostream>

void print(int a[], int n) {
    for(int i=0;i<n;i++)
    {
        std::cout<<a[i];
        if(i!=0)
            std::cout<<"x^"<<i;
        if(i!=n-1)
            std::cout<<" + ";
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    int a[]={5,0,10,6};
    int b[]={3,5,1};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    print(a,n);
    print(b,m);

    int len=std::max(n,m);
    int res[len];
    int i=0;
    while(i<len && i<n && i<m)
    {
        res[i]=a[i]+b[i];
        i++;
    }
    // left over a
    while(i<n)
    {
        res[i]=a[i];
        i++;
    }
    //left over b
    while(i<m)
    {
        res[i]=b[i];
        i++;
    }

    printf("res = ");
    print(res,len);
    remove(argv[0]);
    return 0;
}
