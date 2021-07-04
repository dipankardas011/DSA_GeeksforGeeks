/*Median in a stream of integers (running integers)
Given that integers are read from a data stream. 
Find median of elements read so for in efficient way. 
For simplicity assume there are no duplicates. 
For example, let us consider the stream 5, 15, 1, 3 …

After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...

Making it clear, when the input size is odd, we take the middle element 
of sorted data. 
If the input size is even, we pick average of middle two elements in sorted stream.

Note that output is effective median of integers read from the stream so far. 
Such an algorithm is called online algorithm. Any algorithm that can 
guarantee output of i-elements after processing i-th element, 
is said to be online algorithm. 
Let us discuss three solutions for the above problem.
*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *ar, int n){
    int i,j;
    // sort them
    int t;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }
}

void median(int ar[], int n){
    int i;
    if(n%2 !=0)//even
        printf("\tMedian is: %d\n",ar[n/2]);
    else{
        // odd
        printf("\tMedian is: %d\n",(ar[n/2]+ar[n/2-1])/2);
    }
}

int main(){
    int *arr=NULL;
    int size=0;
    int i=0;
    int m=0;
    do{
        // making the size reflect the size of arr[]
        size++;
        if(arr == NULL){
            // creating the arr[] memory
            arr=malloc(size*sizeof(int));
            printf("enter element\n");
            scanf("%d",&arr[i]);
        }
        else{
            // resize of arr[]
            arr=realloc(arr, sizeof(int)*size);
            printf("enter element\n");
            scanf("%d",&arr[i]);
        }
        //sorting then median
        sort(arr, size);
        median(arr, size);
        printf("enter 1 to continue\n");
        scanf("%d",&m);
        i++;
    }while(m==1);
    
    for(i=0;i<size;i++)
        printf("%d\n",arr[i]);

    free(arr);
    // contributed by Dipankar Das
}