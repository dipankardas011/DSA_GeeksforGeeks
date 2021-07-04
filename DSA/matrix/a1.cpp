/*Rotate a matrix by 90 degree without using any extra space | Set 2
Difficulty Level : Medium
Last Updated : 22 Apr, 2021
Given a square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.
Examples: 
 
Input:
 1  2  3
 4  5  6
 7  8  9
Output:
 3  6  9 
 2  5  8 
 1  4  7 
Rotated the input matrix by
90 degrees in anti-clockwise direction.

Input:
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15 16 
Output:
 4  8 12 16 
 3  7 11 15 
 2  6 10 14 
 1  5  9 13
Rotated the input matrix by
90 degrees in anti-clockwise direction.*/
#include <iostream>
using namespace std;
#define n 4

void reverseCol(int a[][n]){
    for(int i=0;i<n/2;i++){

        for(int j=0;j<n;j++){
            swap(a[i][j],a[n-i-1][j]);
        }
    }
}

void transpose(int a[][n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            swap(a[i][j], a[j][i]);
    }
}

int main()
{
    int arr[n][n] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    /**
     * first we are going to convert the matrix to transpose
     * second we are going to make columns revered
     */
    transpose(arr);
    reverseCol(arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}