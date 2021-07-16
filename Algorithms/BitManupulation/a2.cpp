/*Smallest of three integers without comparison operators
Difficulty Level : Medium
Last Updated : 22 Mar, 2021
Write a program to find the smallest of three integers, without using any of the comparison operators. 
Let 3 input numbers be x, y and z.
Method 1 (Repeated Subtraction) 
Take a counter variable c and initialize it with 0. In a loop, repeatedly subtract x, y and z by 1 and increment c. The number which becomes 0 first is the smallest. After the loop terminates, c will hold the minimum of 3*/
#include <iostream>

int smallestAmong3(int a, int b, int c)
{
    int min = a;
    if (min > b)
        min = b;
    if (min > c)
        min = c;

    return min;
}

/**
 * Method 2 (Use Bit Operations) 
 * Use method 2 of this post to find minimum of two numbers (We can’t use Method 1 as Method 1 uses comparison operator). Once we have functionality to find minimum of 2 numbers, we can use this to find minimum of 3 numbers. 
 */
int min(int x, int y)
{
    return y + ((x - y) & ((x - y) >> (sizeof(int) * __CHAR_BIT__ - 1)));
}

inline int smallest(int x, int y, int z) { return min(x, min(y, z)); }

int main(int argc, char const *argv[])
{
    /* method 1: */
    std::cout << smallestAmong3(1, 3, 5) << std::endl;

    /* method 2: */
    std::cout << smallest(12, 14, 45) << std::endl;
    remove(argv[0]);
    return 0;
}
