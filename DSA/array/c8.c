/*Sort the given matrix
Given a n x n matrix. 
The problem is to sort the given matrix in strict order. 
Here strict order means that matrix is sorted in a way 
such that all elements in a row are sorted in increasing 
order and for row ‘i’, where 1 <= i <= n-1, first element 
of row 'i' is greater than or equal to the last element of row 'i-1'.

Examples:

Input : mat[][] = { {5, 4, 7},
                    {1, 3, 8},
                    {2, 9, 6} }
Output : 1 2 3
         4 5 6
         7 8 9
*/
#include <stdio.h>

void sort(int *ar, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }
}

int main(){
    int n;
    printf("enter the size of the arr\n");
    scanf("%d",&n);
    int arr[n][n];
    printf("enter the elments\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",*(arr+i)+j);
    
    int temp[n*n];
    int pos=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            temp[pos++]=arr[i][j];
    }
    sort(temp, n*n);
    pos=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            arr[i][j]=temp[pos++];
    }

    printf("matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}