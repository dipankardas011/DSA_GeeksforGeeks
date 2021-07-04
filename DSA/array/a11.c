/*Find the smallest missing number
Examples 

Input: {0, 1, 2, 6, 9}, n = 5, m = 10 
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12 
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5 
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11 
Output: 8
*/

#include <Stdio.h>

void cal(int ar[], int n, int m){
    int i,j;
    printf("\ninput arr[]: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
        
    int count;
    for(j=0;j<m;j++){
        count=0;
        for(i=0;i<n;i++){
            if(ar[i]==j){
                count++;
                break;
            }
        }
        if(count==0)
        break;
    }
    printf("\nsmallest missing number: %d\n",j);
}

int main(){
    int a[]={0, 1, 2, 6, 9};
    cal(a,5,10);

    int a1[]={4, 5, 10, 11};
    cal(a1,4,12);

    int a2[]={0, 1, 2, 3};
    cal(a2,4,5);

    int a3[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
    cal(a3,9,11);
}