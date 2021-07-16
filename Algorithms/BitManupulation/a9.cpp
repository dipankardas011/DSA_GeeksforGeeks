/*How to turn off a particular bit in a number?
Difficulty Level : Easy
Last Updated : 26 Apr, 2021
Given a number n and a value k, turn off the k’th bit in n. Please note that k = 1 means the rightmost bit.
Examples: 
 

Input:  n = 15, k = 1
Output: 14

Input:  n = 14, k = 1
Output: 14
The rightmost bit was already off, so no change.

Input:  n = 15, k = 2
Output: 13

Input:  n = 15, k = 3
Output: 11

Input:  n = 15, k = 4
Output: 7

Input:  n = 15, k >= 5
Output: 15 
The idea is to use bitwise <<, & and ~ operators. Using expression “~(1 << (k – 1))“, we get a number which has all bits set, except the k’th bit. If we do bitwise & of this expression with n, we get a number which has all bits same as n except the k’th bit which is 0. */
#include <iostream>

int turnOffKbit(int n, int k)
{
    if(k<=0)
        return n;
    return ( n & ~(1 << (k - 1)) );
}
int main(int argc, char const *argv[])
{
    std::cout<<turnOffKbit(15,1)<<std::endl;
    remove(argv[0]);
    return 0;
}
