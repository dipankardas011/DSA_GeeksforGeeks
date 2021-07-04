/*Find all elements in array which have at-least two greater elements
Input : arr[] = {2, 8, 7, 1, 5};
Output : 2  1  5  
The output three elements have two or
more greater elements
      
Input  : arr[] = {7, -2, 3, 4, 9, -1};
Output : -2  3  4 -1  
*/

#include <stdio.h>

void cal(int ar[],int n){
    printf("INPUT arr[]: ");
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
    
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(ar[i]<ar[j])
                count++;
        }
        if(count>=2)
            printf("%d ",ar[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2, 8, 7, 1, 5};
    int arr1[] = {7, -2, 3, 4, 9, -1};

    cal(arr,(sizeof(arr)/sizeof(arr[0])));
    cal(arr1,(sizeof(arr1)/sizeof(arr1[0])));
}