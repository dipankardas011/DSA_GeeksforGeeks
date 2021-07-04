/*Find a rotation with maximum hamming distance*/

#include <stdio.h>

int cal(int ar[],int n,int d){
    int m[d] ,i;
    int temp[n];
    for(i=0;i<n;i++)
        temp[i]=ar[i];
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

    int count=0;
    for(i=0;i<n;i++){
        if(ar[i]!=temp[i])
            count++;
    }
    return count;
}
int main(){
    int arr[]={1,4,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    int n=size,max=0,key=1,i;
    
    while(n-->0){
        i=cal(arr,size,key);
        if(i>=max){
            max=i;
        }
        key++;
    }
    printf("the maximum hamming distance: %d\n",max);
}