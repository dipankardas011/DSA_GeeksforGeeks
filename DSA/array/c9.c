/*Find unique elements in a matrix
Given a matrix mat[][] having n rows and m columns. 
We need to find unique elements in matrix i.e, 
those elements which are not repeated in the matrix 
or those elements whose frequency is 1.

Examples:

Input :  20  15  30  2
         2   3   5   30
         6   7   6   8
Output : 3  20  5  7  8  15 

Input :  1  2  3  
         5  6  2
         1  3  5
         6  2  2
Output : No unique element in the matrix
*/
#include <stdio.h>
int m,n;

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

void cal(int ar[][n]){
    int hash[m*n];
    int i,j,pos=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            hash[pos++]=ar[i][j];

    sort(hash,m*n);
    int flag=0;
    printf("the element: ");
    for(i=0;i<m*n;i++){
        int count=0;
        for(j=0;j<m*n;j++)
            if(hash[j]==hash[i])
                count++;
        if(count == 1){
            flag++;
            printf("%d ",hash[i]);
        }
    }
    if(flag==0)
        printf("no unique element in mat[][]\n");
}
int main(){
    
    printf("enter the size mxnof the arr\n");
    scanf("%dx%d",&m,&n);
    int arr[m][n];
    printf("enter the elments\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",*(arr+i)+j);
    
    cal(arr);
}