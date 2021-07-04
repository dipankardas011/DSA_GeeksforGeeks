/* Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed */
//Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possible summation of i*arr[i]

#include <stdio.h>

int cal(int ar[],int n,int d){
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

    int sum=0;
    for(i=0;i<n;i++){
        sum+=i*ar[i];
    }
    return sum;
}

int main(){
    int arr[]={10,1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i,n=size;
    // as rotation can be n times
    int key=1, max=0;
    while(n-->0){
        i=cal(arr,size,key);
        if(i>=max){
            max=i;
        }
        key++;
    }
    printf("the maximum summation: %d\n",max);
}