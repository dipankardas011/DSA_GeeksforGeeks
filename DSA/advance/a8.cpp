/*Construct a unique matrix n x n for an input n

Given an odd integer n, find a matrix of size n x n with following conditions:
 

Each cell contains an integer from 1 and n (inclusive).
No integer appears twice in the same row or the same column.
All 1’s must be at every possible distance from the center of the matrix. The center of a n x n square is cell ((n-1)/2, (n-1)/2) for odd n.
Example : 
 

Input  : n = 1
Output : 1

Input : n = 3
Output: 3 2 1
        1 3 2
        2 1 3

Input : n = 5
Output : 5 3 2 4 1 
         1 4 3 5 2 
         2 5 4 1 3 
         3 1 5 2 4 
         4 2 1 3 5 
 
*/
#include <bits/stdc++.h>
using namespace std;
#define max 100
int mat[max][max];

void fillMatrix(int i, int j, int n){
    int x=2;
    // fill all values below i as 2,3,..p
    for(int p=i+1;p<n;p++)
        mat[p][j]=x++;
    // fill all values above i as p+1,p+2,..n
    for(int k=0;k<i;k++)
        mat[k][j]=x++;
}

void construct(int n){
    // filling the 1 in alternating series
    // like
    // n=3
    // __1
    // _1_
    // 1__
    int right=n-1,left=0;
    for(int i=0;i<n;i++){
        // if i even
        if(i%2==0)
        {
            mat[i][right]=1;
            fillMatrix(i,right,n);
            right--;
        }
        else{
            mat[i][left]=1;
            fillMatrix(i,left,n);
            left++;
        }
    }
}

int main(){
    int n=5;
    construct(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}