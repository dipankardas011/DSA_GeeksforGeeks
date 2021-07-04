/*MO’s Algorithm (Query Square Root Decomposition) | Set 1 (Introduction)
Example: 

Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
        query[] = [0, 4], [1, 3] [2, 4]
Output: Sum of arr[] elements in range [0, 4] is 8
        Sum of arr[] elements in range [1, 3] is 4  
        Sum of arr[] elements in range [2, 4] is 6
        
*/
#include <stdio.h>

int main(){
    int arr[]={1, 1, 2, 1, 3, 4, 5, 2, 8};
    int query[][2]={{0,4}, {1,3}, {2,4}};
    int i,j;
    int sum;
    int n=sizeof(query)/sizeof(query[0]);
    for(i=0;i<n;i++){
        sum=0;
        for(j=query[i][0]; j<=query[i][1]; j++)
            sum+=arr[j];
        printf("Sum of arr[] elements in range [%d, %d] is: %d\n",query[i][0],query[i][1],sum);
    }
}