/*Space optimization using bit manipulations
There are many situations where we use integer values as index in array 
to see presence or absence, we can use bit manipulations to optimize space 
in such problems.

Let us consider below problem as an example.

Given two numbers say a and b, mark the multiples of 2 and 5 between a and b 
using less than O(|b – a|) space and output each of the multiples.
Note : We have to mark the multiples i.e save (key, value) pairs in memory 
such that each key either have value as 1 or 0 
representing as multiple of 2 or 5 or not respectively.
Examples :

Input : 2 10
Output : 2 4 5 6 8 10

Input: 60 95
Output: 60 62 64 65 66 68 70 72 74 75 76 78 
        80 82 84 85 86 88 90 92 94 95
*/
#include <stdio.h>

int main(){
    // using hashing
    int a,b;
    printf("enter the value of a, b\n");
    scanf("%d%d",&a,&b);
    int n=b-a+1;
    int hash_arr[n];
    int i;
    for(i=a;i<=b;i++){
        if(i%2 == 0 || i%5 == 0)
            hash_arr[i-a]=1;
        else
            hash_arr[i-a]=0;
    }// we used the [i-a] to change the base from a to 0 as it is the index of array

    printf("output: ");
    for(i=a;i<=b;i++)
        if(hash_arr[i-a] == 1)
            printf("%d ",i);
    printf("\n");
}