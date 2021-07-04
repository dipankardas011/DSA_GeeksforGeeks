/*Two elements whose sum is closest to zero
Question: An Array of integers is given, both +ve and -ve. 
You need to find the two elements such that their sum is closest to zero.
int arr[] = {1, 60, -10, 70, -80, 85};
For the below array, program should print -80 and 85
*/
#include <stdio.h>
#include <math.h>
void cal(int *ar, int n){
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
    int left=0,right=n-1;
    int min=__INT_MAX__;
    int a,b,sum;
    while(left<right){
        sum=ar[left]+ar[right];
        if(abs(sum-0) < abs(min-0)){
            min=sum;
            a=left;
            b=right;
        }
        if(sum > 0)
            right--;
        else if(sum<0)
            left++;
        else
            break;
    }
    printf("{%d, %d}\n",ar[a],ar[b]);
}

int main(){
    int arr[] = {1, 60, -10, 70, -80, 85};
    cal(arr,sizeof(arr)/sizeof(arr[0]));
}