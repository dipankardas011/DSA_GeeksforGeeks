/*Array range queries for searching an element
Given an array of N elements and Q queries of the form L R X. 
For each query, you have to output if the element X exists in the array between the 
indices L and R(included)
Examples :

Input : N = 5
        arr = [1, 1, 5, 4, 5]
        Q = 3
        0 2 2
        1 4 1
        2 4 5         
Output : No
         Yes
         Yes
Explanation :
For the first query, 2 does not exist between the indices 1 and 3.
For the second query, 1 exists between the indices 2 and 5.
For the third query, 5 exists between the indices 3 and 5.
*/
#include <stdio.h>

void search(int ar[], int n, int query[][3], int q){
    q--;
    while(q>=0){
        int count=0;
        for(int i=query[q][0]; i<=query[q][1]; i++){
            if(ar[i] == query[q][2]){
                count++;
                break;
            }
        }
        if(count==0)
            printf("NO for {%d, %d, %d}\n",query[q][0],query[q][1],query[q][2]);
        else
            printf("YES for {%d, %d, %d}\n",query[q][0],query[q][1],query[q][2]);
        q--;
    }
}

int main(){
    int N,Q;
    int i;
    printf("enter the number of elements\n");
    scanf("%d",&N);
    int arr[N];
    printf("enter the elements:\n");
    for(i=0;i<N;i++)
        scanf("%d",arr+i);

    printf("enter the number of Queries\n");
    scanf("%d",&Q);
    int query[Q][3];
    for(i=0;i<Q;i++){
        printf("enter the start, end, search element for %d query\n",i);
        scanf("%d%d%d",&query[i][0],&query[i][1],&query[i][2]);
    }

    search(arr,N,query,Q);
}