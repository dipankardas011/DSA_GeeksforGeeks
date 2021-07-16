/*Check for Integer Overflow
Difficulty Level : Easy
Last Updated : 09 Nov, 2020
Write a “C” function, int addOvf(int* result, int a, int b) If there is no overflow, the function places the resultant = sum a+b in “result” and returns 0. Otherwise it returns -1. The solution of casting to long and adding to find detecting the overflow is not allowed.*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int addErr(int *res, int a, int b)
{
    if(a >INT_MAX -b)
        return -1;
    else
    {
        *res=a+b;
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int res;
    int x=2147483640;
    int y=10;
    if(addErr(&res, x,y)==-1)
    {
        printf("OVerflow\n");
        exit(0);
    }
    else
        printf("res= %d\n", res);

    remove(argv[0]);
    return 0;
}
