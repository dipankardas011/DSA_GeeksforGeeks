/*K-th Largest Sum Contiguous Subarray
Given an array of integers. Write a program to find the K-th largest sum of 
contiguous subarray within the array of numbers which has negative and positive numbers.
Examples:


Input: a[] = {20, -5, -1} 
         k = 3
Output: 14
Explanation: All sum of contiguous 
subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40} 
         k = 6
Output: -10 
Explanation: The 6th largest sum among 
sum of all contiguous subarrays is -10.*/

#include <stdio.h>

void cal(int ar[], int n){
    int i,j;
    printf("\ninput arr[]: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n{ ");
    int count=0;
    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=ar[j];
            count++;
            printf("%d ",sum);
        }
    }
    printf("}\n");

    int t[count];
    count=0;
    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=ar[j];
            t[count++]=sum;
        }
    }
    
    int k;
    printf("enter the value of k\n");
    scanf("%d",&k);
    i=k;
    int max;
    int pos=0;
    while(i>0){
        max=t[0];
        pos=0;
        // find the min
        for(j=0;j<count;j++){
            if(max<t[j]){
                max=t[j];
                pos=j;
            }
        }
        t[pos]=-99999;// changing the element of ar so that the min can work 
        i--;
    }
    printf("\nthe K'th largest sum: %d\n",max);
}

int main(){
    int a[] = {20, -5, -1};
    int a1[]={10, -10, 20, -40};
    cal(a,(sizeof(a)/sizeof(a[0])));
    cal(a1,(sizeof(a1)/sizeof(a1[0])));
}