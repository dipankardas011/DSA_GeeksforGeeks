/*Print left rotation of array in O(n) time and O(1) space*/

#include <stdio.h>

void rotate(int ar[], int n, int d){
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
    int arr[]={1,3,5,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int m;
    int key=0;
    do{
        printf("enter the rotation magnitude\n");
        scanf("%d",&key);
        rotate(arr,size,key);
        printf("\nenter the 1 to continue\n");
        scanf("%d",&m);
    }while(m==1);
}