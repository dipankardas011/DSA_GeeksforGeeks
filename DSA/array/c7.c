/*Rotate a matrix by 90 degree without using any extra space 
Given a square matrix, turn it by 90 degrees in anti-clockwise 
direction without using any extra space.

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
90 degrees in anti-clockwise direction.
*/
#include <stdio.h>

int n;

void rotate_90anticlockwise(int ar[][n]){
    int i,j;
    int t=0;
    for(i=0;i<n;i++){// transpose arr[][]
        for(j=i;j<n;j++){
            t=ar[i][j];
            ar[i][j]=ar[j][i];
            ar[j][i]=t;
        }
    }

    for(i=0;i<n/2;i++){//swapping the rows of the arr[][]
        for(j=0;j<n;j++){
            t=ar[i][j];
            ar[i][j]=ar[n-i-1][j];
            ar[n-i-1][j]=t;
        }
    }

    printf("matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d\t",ar[i][j]);
        printf("\n");
    }
}


int main(){
    printf("enter the size of the arr\n");
    scanf("%d",&n);
    int arr[n][n];
    printf("enter the elments\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",*(arr+i)+j);
    
    rotate_90anticlockwise(arr);
}