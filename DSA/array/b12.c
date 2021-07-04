/*Construct an array from its pair-sum array
Given a pair-sum array and size of the original array (n), 
construct the original array.

A pair-sum array for an array is the array that contains sum 
of all pairs in ordered form. For example pair-sum array 
for arr[] = {6, 8, 3, 4} is {14, 9, 10, 11, 12, 7}.
In general, pair-sum array for arr[0..n-1] 
is {arr[0]+arr[1], arr[0]+arr[2], ……., arr[1]+arr[2], arr[1]+arr[3], ……., 
arr[2]+arr[3], arr[2]+arr[4], …., arr[n-2]+arr[n-1}.

“Given a pair-sum array, construct the original array.”
*/
#include <stdio.h>

void cal(int pair[]){
    int n, i, j;
    printf("enter the size for the originial arr[]: ");
    scanf("%d",&n);
    int org[n];
    int pos=0;
    org[0] = (pair[0]+pair[1]-pair[n-1])/2;
    for(i=1;i<n;i++)
        org[i]=pair[i-1]-org[0];
    printf("{ ");
    for(i=0;i<n;i++)
        printf("%d ",org[i]);
    printf("}\n");
}

int main(){
    int ns;
    
    printf("enter the size of pair-sum arr\n");
    scanf("%d",&ns);

    int pair_sum[ns];
    int i,j;
    printf("enter the element of the pair-sum arr[]\n");
    for(i=0;i<ns;i++)
        scanf("%d",pair_sum+i);
    cal(pair_sum);
}