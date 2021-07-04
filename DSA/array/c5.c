/*Find a triplet that sum to a given value
Given an array and a value, 
find if there is a triplet in array whose sum is equal to 
the given value. If there is such a triplet present in array, 
then print the triplet and return true. Else return false. 
Example: 

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24. 

Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9. 
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


void find_triplet(int *ar, int n){
    sort(ar,n);
    int sum=0;
    printf("enter the sum to be found\n");
    scanf("%d",&sum);
    for (int i = 0; i < n - 2; i++) { 
  
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        int l = i + 1; // index of the first element in the 
        // remaining elements 
  
        int r = n - 1; // index of the last element 
        while (l < r) { 
            if (ar[i] + ar[l] + ar[r] == sum) { 
                printf("Triplet is %d, %d, %d", ar[i], ar[l], ar[r]); 
                return ; 
            } 
            else if (ar[i] + ar[l] + ar[r] < sum) 
                l++; 
            else // A[i] + A[l] + A[r] > sum 
                r--; 
        } 
    }
    printf("no such triplet found\n");
}

int main(){
    int arr[]={1, 2, 3, 4, 5};
    find_triplet(arr, sizeof(arr)/sizeof(arr[0]));
}