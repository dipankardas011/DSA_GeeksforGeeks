/*Swap major and minor diagonals of a square matrix
Given a square matrix, swap the element of major and minor diagonals.

Major Diagonal Elements of a Matrix :
The Major Diagonal Elements are the ones that occur 
from Top Left of Matrix Down To Bottom Right Corner. 
The Major Diagonal is also known as Main Diagonal or Primary Diagonal.

Minor Diagonal Elements of a Matrix :
The Minor Diagonal Elements are the ones that occur 
from Top Right of Matrix Down To Bottom Left Corner. 
Also known as Secondary Diagonal.

Example :

Input : 0 1 2
        3 4 5
        6 7 8

Output : 2 1 0
         3 4 5
         8 7 6
*/
#include <stdio.h>
int n;
void reverse_diag(int ar[][n]){
    int i,j;
    int t;
    for(i=0;i<n;i++){
        t=ar[i][i];
        ar[i][i]=ar[i][n-i-1];
        ar[i][n-i-1]=t;
    }
    printf("matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d\t",ar[i][j]);
        printf("\n");
    }
}

int main(){

    printf("enter the size of a square matrix\n");
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",*(arr+i)+j);

    reverse_diag(arr);
}