/*Find the subarray with least average
Examples :

Input:  arr[] = {3, 7, 90, 20, 10, 50, 40}, k = 3
Output: Subarray between indexes 3 and 5
The subarray {20, 10, 50} has the least average 
among all subarrays of size 3.

Input:  arr[] = {3, 7, 5, 20, -10, 0, 12}, k = 2
Output: Subarray between [4, 5] has minimum average
*/
#include <stdio.h>

void cal(int ar[], int n, int k){
    if(k>n){
        printf("INVALID! value for k\n");
        return ;
    }
    int sub_arr[k];
    int i,j;
    int sum=0;
    for(i=0;i<k;i++)
        sum+=ar[i];

    int start=0, end=0;
    int min_sum=sum;
    for(i=k;i<n;i++){
        sum+=-ar[i-k]+ar[i];
        if(min_sum>sum){
            min_sum=sum;
            start=i-k+1;
            end=i;
        }
    }
    printf("\n{ ");
    for(i=start;i<=end;i++)
        printf("%d ",ar[i]);

    printf("}\n");
    
}

int main(){
    int arr[]={3, 7, 90, 20, 10, 50, 40};
    cal(arr, sizeof(arr)/sizeof(arr[0]), 3);
    int ar1[]={3, 7, 5, 20, -10, 0, 12};
    cal(ar1, sizeof(ar1)/sizeof(ar1[0]), 2);
}