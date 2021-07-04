/*Program to Print Matrix in Z form
Difficulty Level : Basic
Last Updated : 18 May, 2021
Given a square matrix of order n*n, we need to print elements of the matrix in Z form
 

    Input: [[4, 5, 6, 8], 
            [1, 2, 3, 1], 
            [7, 8, 9, 4], 
            [1, 8, 7, 5]]
        
    Output: 4 5 6 8
                3
              8
            1 8 7 5
    
    Input: [[4, 5, 6, 8, 5],
            [1, 2, 3, 1, 4],
            [7, 8, 9, 4, 7],
            [1, 8, 7, 5, 2],
            [7, 9, 5, 6, 9],
            [9, 4, 5, 6, 6]]
        
    Output: 4 5 6 8 5
                  1
                9
              8
            7
           9 4 5 6 6*/
#include <iostream>
using namespace std;
#define n 5

void printZigZag(int a[n][n])
{
    /**
     * @def print first andd last row execpt their last and first ele
     * @def and the right diagonal*/

    for(int i=0;i<n-1;i++)
        cout<<a[0][i]<<" ";
    
    // it could be square
    for(int i=0;i<n;i++)
        cout<<a[i][n-1-i]<<" ";

    for(int i=1;i<n;i++)
        cout<<a[n-1][i]<<" ";
    cout<<endl;
    return;
}

int main()
{
    int a[n][n] = {4, 5, 6, 8, 5,
                 1, 2, 3, 1, 4,
                 7, 8, 9, 4, 7,
                 1, 8, 7, 5, 2,
                 9, 4, 5, 6, 6};
    printZigZag(a);
    return 0;
}