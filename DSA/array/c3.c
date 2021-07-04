/*Find the only repetitive element between 1 to n-1
We are given an array arr[] of size n. 
Numbers are from 1 to (n-1) in random order. 
The array has only one repetitive element. 
We need to find the repetitive element.

Examples :

Input  : a[] = {1, 3, 2, 3, 4}
Output : 3

Input  : a[] = {1, 5, 1, 2, 3, 4}
Output : 1
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

void cal(int *ar, int n){
    sort(ar, n);
    for(int i=0;i<n-1;i++){
        if(ar[i]==ar[i+1])
        {
            printf("found it is: %d\n",ar[i]);
            return;
        }
    }
    printf("no repeting elements\n");
}

int main(){
    int a[]={1, 3, 2, 3, 4};
    cal(a,sizeof(a)/sizeof(a[0]));
    int a1[]={1, 5, 1, 2, 3, 4};
    cal(a1,sizeof(a1)/sizeof(a1[0]));
}