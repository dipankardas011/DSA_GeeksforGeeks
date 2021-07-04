/*Shuffle a given array using Fisher–Yates shuffle Algorithm
Given an array, write a program to generate a random permutation of array elements. 
This question is also asked as “shuffle a deck of cards” or “randomize a given array”.
Here shuffle means that every permutation of array element should equally likely*/

#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void random(int arr[], int n){
    for(int i=n-1;i>0;i--){
        int j=rand()%(i+1);
        swap(&arr[i],&arr[j]);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    random(arr,n);
    printarray(arr,n);
}