/*Count number of binary strings without consecutive 1’s
Difficulty Level : Medium
Last Updated : 15 Apr, 2021
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Examples: 

Input:  N = 2
Output: 3
// The 3 strings are 00, 01, 10

Input: N = 3
Output: 5
// The 5 strings are 000, 001, 010, 100, 101*/
#include <iostream>

int countString(int n)
{
    int a[n],b[n];
    a[0]=b[0]=1;
    for(int i=1;i<n;i++) {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return a[n-1]+b[n-1];
}

int main(int argc, char const *argv[])
{
    std::cout<<countString(3)<<std::endl;
    remove(argv[0]);
    return 0;
}
/*If we take a closer look at the pattern, we can observe that the count is actually (n+2)’th Fibonacci number for n >= 1. The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, …. 

n = 1, count = 2  = fib(3)
n = 2, count = 3  = fib(4)
n = 3, count = 5  = fib(5)
n = 4, count = 8  = fib(6)
n = 5, count = 13 = fib(7)
................
Therefore we can count the strings in O(Log n) time also using the method 5 here.*/