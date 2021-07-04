/*K’th Smallest/Largest Element in Unsorted Array | Set 3 (Worst Case Linear Time)
Given an array and a number k where k is smaller than the size of the array, we 
need to find the k’th smallest element in the given array. 
It is given that all array elements are distinct*/

#include <stdio.h>

void find(int ar[],int n){
    int k;
    printf("enter the value of k\n");
    scanf("%d",&k);
    if(k>=n){
        printf("ERROR! k > size of array[]\n");
        return ;
    }
    int temp[n];
    int i,j;
    for(i=0;i<n;i++)
        temp[i]=ar[i];

    i=k;
    int min;
    int pos=0;
    while(i>0){
        min=temp[0];
        pos=0;
        // find the min
        for(j=0;j<n;j++){
            if(min>temp[j]){
                min=temp[j];
                pos=j;
            }
        }
        temp[pos]=99999;// changing the element of ar so that the min can work 
        i--;
    }
    printf("\ninput arr[]: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\nthe K'th min element: %d\n",min);
}

int main(){
    int arr[]={7, 10, 4, 3, 20, 15};
    int arr1[]={7, 10, 4, 3, 20, 15};
    find(arr,(sizeof(arr)/sizeof(arr[0])));
    find(arr1,(sizeof(arr1)/sizeof(arr1[0])));
}