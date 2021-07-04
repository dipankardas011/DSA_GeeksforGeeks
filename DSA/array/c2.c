/*Majority Element
Write a function which takes an array and prints the majority 
element (if it exists), otherwise prints “No Majority Element”. 
A majority element in an array A[] of size n is an element that
appears more than n/2 times (and hence there is at most one such element). 

Examples : 

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater
than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is
greater than the half of the size of the array size.
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

void find(int *ar, int n){
    int i,j;
    int count=0;
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++)
            if(ar[j]==ar[i])
                count++;
        if(count > n/2){
            printf("the element: %d is of frequency: %d\n",ar[i],count);
            return ;
        }
    }
    printf("NO MAJORITY ELEMENT\n");
}

int main(){
    int arr[]={3, 3, 4, 2, 4, 4, 2, 4, 4};
    sort(arr, sizeof(arr)/sizeof(arr[0]));
    find(arr, sizeof(arr)/sizeof(arr[0]));
    int arr1[]={3, 3, 4, 2, 4, 4, 2, 4};
    sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    find(arr1, sizeof(arr1)/sizeof(arr1[0]));
}