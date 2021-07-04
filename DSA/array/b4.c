/*Maximum Occurrence in a Given Range
Given an array of n integers in non-decreasing order. 
Find the number of occurrences of the most frequent value within a given range.

Examples:

Input : arr[] = {-5, -5, 2, 2, 2, 2, 3, 7, 7, 7}
        Query 1: start = 0, end = 9
        Query 2: start = 4, end = 9
Output : 4
         3
Explanation:  
Query 1: '2' occurred the most number of times
with a frequency of 4 within given range.
Query 2: '7' occurred the most number of times
with a frequency of 3 within given range.
*/
#include <stdio.h>

void query(int arr[], int N){
    int i;
    int l,r;
    
    
    printf("\nenter the start, end for the query\n");
    scanf("%d%d",&l,&r);
    if(l<0 || r>=N)
        return;
    int freq_arr[N];
    for(int i=l;i<=r;i++){
        int count=0;
        for(int j=l;j<=r;j++)
            if(arr[i]==arr[j])
                count++;
        freq_arr[i]=count;
    }
    int max=0;
    for(i=l;i<=r;i++){
        if(max<freq_arr[i])
            max=freq_arr[i];
    }
    printf("%d\n",max);
}

int main(){
    
    int m;

    int n;
    printf("Enter size for array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the element\n");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    do{
        query(arr, n);
        printf("\tENTER 1 TO CONTINUE\n");
        scanf("%d",&m);
    }while(m==1);
}