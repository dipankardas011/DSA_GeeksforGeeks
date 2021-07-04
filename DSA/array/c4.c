/*Find the two repeating elements in a given array
You are given an array of n+2 elements. 
All elements of the array are in range 1 to n. 
And all elements occur once except two numbers which occur twice. 
Find the two repeating numbers. 

Example:

Input: 
arr = [4, 2, 4, 5, 2, 3, 1] 
n = 5
Output:
4 2
Explanation:
The above array has n + 2 = 7 elements with all elements 
occurring once except 2 and 4 which occur twice. So the output should be 4 2.
*/
#include <stdio.h>
#include <stdlib.h>

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

void cal(int *ar, int n){
    int i, j;
    sort(ar, n);
    int flag=0;
    for(i=0;i<n;i++){
        for(j=0;j<n,j!=i;j++){
            if(flag==0){
                if(ar[i]==ar[j]){
                    flag=ar[i];
                    printf("%d ",flag);
                    break;
                }
            }
            else{
                if(ar[i]==ar[j] && flag != ar[i]){
                    flag=ar[i];
                    printf("%d ",flag);
                    break;
                }
            }
        }
    }
}

int main(){
    int arr[]={4,2,4,5,2,3,1};
    cal(arr, sizeof(arr)/sizeof(arr[0]));
}