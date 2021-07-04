/*Sort an array in wave form
Given an unsorted array of integers, sort the array into a wave like array. 
An array ‘arr[0..n-1]’ is sorted in wave form 
if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
Examples:

 Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                 {20, 5, 10, 2, 80, 6, 100, 3} OR
                 any other array that is in wave form

 Input:  arr[] = {20, 10, 8, 6, 4, 2}
 Output: arr[] = {20, 8, 10, 4, 6, 2} OR
                 {10, 8, 20, 2, 6, 4} OR
                 any other array that is in wave form

 Input:  arr[] = {2, 4, 6, 8, 10, 20}
 Output: arr[] = {4, 2, 8, 6, 20, 10} OR
                 any other array that is in wave form

 Input:  arr[] = {3, 6, 5, 10, 7, 20}
 Output: arr[] = {6, 3, 10, 5, 20, 7} OR
                 any other array that is in wave form
*/
#include <stdio.h>

void cal(int *ar, int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1-i;j++){
            if((j+1)%2==0 && ar[j]>=ar[j+1]){ //even index if [j]>=[j+1]
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if((j+1)%2!=0 && ar[j]<=ar[j+1]){ //odd index if [j]<=[j+1]
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}

int main(){
    int i;
    int arr[]={10, 5, 6, 3, 2, 20, 100, 80};
    cal(arr, sizeof(arr)/sizeof(arr[0]));
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",arr[i]);
    printf("\n");

    int arr1[]={20, 10, 8, 6, 4, 2};
    cal(arr1, sizeof(arr1)/sizeof(arr1[0]));
    for(i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
        printf("%d ",arr1[i]);
    printf("\n");

    int arr2[]={2, 4, 6, 8, 10, 20};
    cal(arr2, sizeof(arr2)/sizeof(arr2[0]));
    for(i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
        printf("%d ",arr2[i]);
    printf("\n");

    int arr3[]={3, 6, 5, 10, 7, 20};
    cal(arr3, sizeof(arr3)/sizeof(arr3[0]));
    for(i=0;i<sizeof(arr3)/sizeof(arr3[0]);i++)
        printf("%d ",arr3[i]);
    printf("\n");
}