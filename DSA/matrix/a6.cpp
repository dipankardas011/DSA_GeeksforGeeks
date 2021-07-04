/*
Check given matrix is magic square or not
Difficulty Level : Easy
Last Updated : 10 Jun, 2021
Given a matrix, check whether it’s Magic Square or not. A Magic Square is a n x n matrix of the distinct elements from 1 to n2 where the sum of any row, column, or diagonal is always equal to the same number.
Examples: 
 

Input : n = 3
  2   7   6
  9   5   1
  4   3   8
Output : Magic matrix
Explanation:In matrix sum of each
row and each column and diagonals sum is 
same = 15.

Input : n = 3
  1   2   2 
  2   2   1
  2   1   2
Output : Not a Magic Matrix
Explanation:In matrix sum of each
row and each column and diagonals sum is
not same.*/
#include <iostream>
using namespace std;

bool isMagicSquare(int a[][3]){
    int n=3;
    int sumd1=0,sumd2=0;
    for(int i=0;i<n;i++){
        sumd1+=a[i][i];
        sumd2+=a[i][n-i-1];
    }
    if(sumd1!=sumd2)    return false;

    for(int i=0;i<n;i++){
        int rowsum=0, colsum=0;
        for(int j=0;j<n;j++){
            rowsum+=a[i][j];
            colsum+=a[j][i];
        }
        if(rowsum!=colsum || colsum!=sumd1) return false;

    }
    return true;
}

int main(){
    int mat[3][3]={2,7,6,9,5,1,4,3,8};
    (isMagicSquare(mat))?cout<<"Magic Sq."<<endl : cout<<"Not Magic Sq."<<endl;
    return 0;
}