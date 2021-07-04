/*Rearrange array such that arr[i] >= arr[j]
if i is even and arr[i]<=arr[j] if i is odd and j < i.


Given an array of n elements. Our task is to write a 
program to rearrange the array such that elements at even 
positions are greater than all elements and elements at odd 
positions are less than all elements before it.*/

#include <stdio.h>

int main(){
    int arr[]={1,2,1,4,5,6,8,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,j;
    int t;
    printf("\ninput arr[]: ");
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");

    int evenpos=n/2, oddpos=n-evenpos;
    int temp[n];
    for(i=0;i<n;i++)
        temp[i]=arr[i];
    

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(temp[j]>temp[j+1]){
                t=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=t;
            }
        }
    }
    j=oddpos-1;
    for(i=0;i<n;i+=2){
        arr[i]=temp[j];
        j--;
    }
    j=oddpos;
    for(i=1;i<n;i+=2){
        arr[i]=temp[j];
        j++;
    }
    printf("\noutput: ");
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));
}