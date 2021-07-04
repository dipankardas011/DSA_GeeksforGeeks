/*Number of NGEs to the right
Given an array of n integers and q queries, 
print the number of next greater elements to the right 
of the given index element. 
Examples: 

Input: a[] = {3, 4, 2, 7, 5, 8, 10, 6}  
              q = 2 
              index = 0, 
              index = 5
Output: 6
        1 
Explanation:
The next greater elements
to the right of 3(index 0) are 4,7,5,8,10,6. 
The next greater elements to the right
of 8(index 5) are 10.
*/
#include <stdio.h>
#include <stdlib.h>
int size;
int no_queries;

void nge(int *arr, int q[]){
    int i;
    for(i=0;i<no_queries;i++){
        int count=0;
        for(int j=q[i]+1;j<size;j++){
            if(arr[q[i]] < arr[j])
            count++;
        }
        printf("no of NGE of query %d is: %d\n",i+1, count);
    }
}

int main(){
    int i;
    printf("enter the size and elements of arr[]\n");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",arr+i);

    printf("enter the number of queries\n");
    
    scanf("%d",&no_queries);
    printf("enter the index(s):\n");
    int q[no_queries];
    for(i=0;i<no_queries;i++)
        scanf("%d",q+i);
    int m[size];
    nge(arr, q);
}