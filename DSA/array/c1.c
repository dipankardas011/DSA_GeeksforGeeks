/*Given an array A[] and a number x, check for pair in A[] with sum as x
Write a program that, given an array A[] of n numbers and 
another number x, determines whether or not there exist two 
elements in S whose sum is exactly x. 
Examples: 

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists.
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

void cal(int ar[], int n, int sum){
    int left, right;
    left=0;
    right=n-1;
    while(left<right){
        if((ar[left]+ar[right]) == sum){
            printf("{%d, %d}\n",ar[left],ar[right]);
            return ;
        }
        else if((ar[left]+ar[right]) < sum)
            left++;
        else
            right--;
    }
    printf("not found\n");
}

int main(){

    int arr[] = {0, -1, 2, -3, 1};
    sort(arr,sizeof(arr)/sizeof(arr[0]));

    cal(arr, sizeof(arr)/sizeof(arr[0]),-2);
    
    int arr1[] = {1, -2, 1, 0, 5};
    sort(arr1,sizeof(arr1)/sizeof(arr1[0]));
    
    cal(arr1, sizeof(arr1)/sizeof(arr1[0]),0);
    
}