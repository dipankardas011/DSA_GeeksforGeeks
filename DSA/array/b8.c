/*Sort an array according to absolute difference with given value
Given an array of n distinct elements and a number x, arrange array elements according to the absolute difference with x, i. e., an element having minimum difference comes first, and so on. 
Note: If two or more elements are at equal distance arrange them in the same sequence as in the given array.
Examples : 

Input : arr[] : x = 7, arr[] = {10, 5, 3, 9, 2}
Output : arr[] = {5, 9, 10, 3, 2}
Explanation:
7 - 10 = 3(abs)
7 - 5 = 2
7 - 3 = 4 
7 - 9 = 2(abs)
7 - 2 = 5
So according to the difference with X, 
elements are arranged as 5, 9, 10, 3, 2.

Input : x = 6, arr[] = {1, 2, 3, 4, 5}   
Output :  arr[] = {5, 4, 3, 2, 1}

Input : x = 5, arr[] = {2, 6, 8, 3}   
Output :  arr[] = {6, 3, 2, 8}
*/
#include <stdio.h>
#include <math.h>

void cal(int *ar, int n, int x){
    int hash[n];
    int i,j;
    for(i=0;i<n;i++)
        hash[i] = abs(x - *(ar+i));
    // for(i=0;i<n;i++)
    //     printf("%d\n",hash[i]);
    int temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(hash[j] > hash[j+1]){
                temp=hash[j];
                hash[j]=hash[j+1];
                hash[j+1]=temp;

                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if(hash[j]==hash[j+1]){
                if(ar[j] > ar[j+1]){
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
        }
    }
}

int main(){
    int arr[]={10, 5, 3, 9, 2};
    cal(arr,sizeof(arr)/sizeof(arr[0]), 7);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",*(arr+i));
printf("\n");
    int arr2[]={1, 2, 3, 4, 5};
    cal(arr2,sizeof(arr2)/sizeof(arr2[0]), 6);
    for(int i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
        printf("%d ",*(arr2+i));
printf("\n");
    int arr1[]={2, 6, 8, 3};
    cal(arr1,sizeof(arr1)/sizeof(arr1[0]), 5);
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
        printf("%d ",*(arr1+i));
}