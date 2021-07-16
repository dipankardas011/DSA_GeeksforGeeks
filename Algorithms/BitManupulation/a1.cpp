/*Swap bits in a given number
Difficulty Level : Hard
Last Updated : 29 Apr, 2021
Given a number x and two positions (from the right side) in the binary representation of x, write a function that swaps n bits at given two positions and returns the result. It is also given that the two sets of bits do not overlap.

Method 1 
Let p1 and p2 be the two given positions.

Example 1 

Input:
x = 47 (00101111)
p1 = 1 (Start from the second bit from the right side)
p2 = 5 (Start from the 6th bit from the right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from the right side) are 
swapped with 3 bits starting from 6th position (from the right side)
Example 2 

Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
Output:
7 (00111)
The 2 bits starting from 0th position (from right side) are
swapped with 2 bits starting from 4th position (from right side)

1) Move all bits of the first set to the rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that 
contains last n bits set and other bits as 0. We do & 
with this expression so that bits other than the last 
n bits become 0.
2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
3) XOR the two sets of bits
   xor = (set1 ^ set2) 
4) Put the xor bits back to their original positions. 
   xor = (xor << p1) | (xor << p2)
5) Finally, XOR the xor with original number so 
   that the two sets are swapped.
   result = x ^ xor */

#include <iostream>

u_int32_t swapBits(u_int32_t x, u_int32_t p1, u_int32_t p2, u_int32_t n)
{
    u_int32_t set1 = (x >> p1) & ((1U << n) - 1);
    u_int32_t set2 = (x >> p2) & ((1U << n) - 1);
    u_int32_t XOR = set1 ^ set2;
    XOR = (XOR << p1) | (XOR << p2);
    /* Xor the 'Xor' with the original number so that the
    two sets are swapped */
    u_int32_t res = x ^ XOR;

    return res;
}

int main(int argc, char const *argv[])
{
    std::cout << "result= " << swapBits(28, 0, 3, 2) << std::endl;
    remove(argv[0]);
    return 0;
}
