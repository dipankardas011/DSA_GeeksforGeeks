/* Program for array rotation */
#include <stdio.h>

void rotate(int ar[], int d, int n){
    int m[d] ,i;
    for(i=0;i<d;i++){
        m[i]=ar[i];
    }
    for(i=0;i<n-d;i++){
        ar[i]=ar[i+d];
    }
    int t;
    for(i=n-d,t=0;i<n;i++,t++){
        ar[i]=m[t];
    }

    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
}

int main(){
    printf("enter the size of the array and its elements\n");
    int size, i;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",arr+i);
    printf("array: ");
    for(i=0;i<size;i++)
        printf("%d ",*arr+i);
    printf("\nenter the no of elments to be rotates\n");
    int d=0;
    scanf("%d",&d);
    rotate(arr,d,size);
}