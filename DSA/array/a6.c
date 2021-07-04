/*Rearrange array in alternating positive & negative items with O(1) extra space
Examples : 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0} 
*/

#include <stdio.h>

void cal(int ar[], int n){
    int i,j;
    printf("\ninput arr[]: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");

    int negsize=0, possize=0;
    for(i=0;i<n;i++){
        if(ar[i]>=0)
            possize++;
        else
            negsize++;
    }

    int neg_arr[negsize];
    int pos_arr[possize];
    j=0;
    int k=0;
    for(i=0;i<n;i++){
        if(ar[i]>=0)
            pos_arr[j++]=ar[i];
        if(ar[i]<0)
            neg_arr[k++]=ar[i];
    }

    j=0;
    for(i=0;i<negsize;i++,j+=2)
        ar[j]=neg_arr[i];

    int count=0;
    int pos=0;
    for(i=1;i<n;i++){
        if(count<=negsize){
            ar[i++]=pos_arr[pos++];
            count++;
        }
        else
            ar[i]=pos_arr[pos++];
    }


    printf("\noutput: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
}

int main(){
    int arr[]={1, 2, 3, -4, -1, 4};
    cal(arr, (sizeof(arr)/sizeof(arr[0])));
    int arr1[]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    cal(arr1, (sizeof(arr1)/sizeof(arr1[0])));
}