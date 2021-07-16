/*Smallest power of 2 greater than or equal to n
Difficulty Level : Medium
Last Updated : 15 Apr, 2021
Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a smallest power of 2. 

Examples : 

    Input : n = 5
    Output: 8     

    Input  : n = 17
    Output : 32     

    Input  : n = 32
    Output : 32     

Method 3(Shift result one by one) 
This method is a variation of method 2 where instead of getting count, we shift the result one by one in a loop. */
#include <stdio.h>

unsigned int nextPowerOf2(unsigned int n) {
    unsigned int p=1;
    if(n && !(n&(n-1)))
        return n;

    while(p<n)
        p <<= 1;
    
    return p;
}

int main(int argc, char const *argv[])
{
    unsigned int n=5;
    printf("%d\n",nextPowerOf2(n));
    remove(argv[0]);
    return 0;
}
