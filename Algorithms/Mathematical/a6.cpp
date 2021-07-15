/*How to check if a given number is Fibonacci number?
Difficulty Level : Medium
Last Updated : 15 Apr, 2021
Given a number ‘n’, how to check if n is a Fibonacci number. First few Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, .. 
Examples : 
 

Input : 8
Output : Yes

Input : 34
Output : Yes

Input : 41
Output : No

A simple way is to generate Fibonacci numbers until the generated number is greater than or equal to ‘n’. Following is an interesting property about Fibonacci numbers that can also be used to check if a given number is Fibonacci or not. 
A number is Fibonacci if and only if one or both of (5*n2 + 4) or (5*n2 – 4) is a perfect square */
#include <iostream>
#include <math.h>


// A utility function that returns true if x is perfect square
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}

// Returns true if n is a Fibinacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perferct square
    return isPerfectSquare(5 * n * n + 4) ||
           isPerfectSquare(5 * n * n - 4);
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
        isFibonacci(i) ? std::cout << i << " is a Fibonacci Number \n" : std::cout << i << " is a not Fibonacci Number \n";
    remove(argv[0]);
    return 0;
}