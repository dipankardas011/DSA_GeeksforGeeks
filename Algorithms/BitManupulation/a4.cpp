/*Compute the integer absolute value (abs) without branching
Difficulty Level : Hard
Last Updated : 25 Mar, 2021
We need not to do anything if a number is positive. We want to change only negative numbers. Since negative numbers are stored in 2’s complement form, to get the absolute value of a negative number we have to toggle bits of the number and add 1 to the result.
For example -2 in a 8 bit system is stored as follows 1 1 1 1 1 1 1 0 where leftmost bit is the sign bit. To get the absolute value of a negative number, we have to toggle all bits and add 1 to the toggled number i.e, 0 0 0 0 0 0 0 1 + 1 will give the absolute value of 1 1 1 1 1 1 1 0. Also remember, we need to do these operations only if the number is negative (sign bit is set).
Method 1 
1) Set the mask as right shift of integer by 31 (assuming integers are stored using 32 bits). 
 mask = n>>31 
2) For negative numbers, above step sets mask as 1 1 1 1 1 1 1 1 and 0 0 0 0 0 0 0 0 for positive numbers. Add the mask to the given number. 
 mask + n 
3) XOR of mask +n and mask gives the absolute value. 
 (mask + n)^mask */
#include <iostream>

u_int32_t getAbs(int n)
{
    /* 4*8 -1 */
    u_int32_t const mask = n >> (sizeof(u_int32_t)*__CHAR_BIT__ -1);
    return (n+mask)^mask;
}

int main(int argc, char const *argv[])
{
    int n=-6;
    std::cout<<"absolute value = "<<n<<" = "<<getAbs(n)<<std::endl;
    remove(argv[0]);
    return 0;
}
