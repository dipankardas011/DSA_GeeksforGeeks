/*Check divisibility by 7
Difficulty Level : Easy
Last Updated : 07 Apr, 2021
Given a number, check if it is divisible by 7. You are not allowed to use modulo operator, floating point arithmetic is also not allowed. 
A simple method is repeated subtraction. Following is another interesting method.
Divisibility by 7 can be checked by a recursive method. A number of the form 10a + b is divisible by 7 if and only if a – 2b is divisible by 7. In other words, subtract twice the last digit from the number formed by the remaining digits. Continue to do this until a small number. 
Example: the number 371: 37 – (2×1) = 37 – 2 = 35; 3 – (2 × 5) = 3 – 10 = -7; thus, since -7 is divisible by 7, 371 is divisible by 7. */
#include <iostream>

int isDivisible7(int n)
{
    // if number id -ve make it +ve
    if (n < 0)
        return isDivisible7(-n);

    if (n == 0 || n == 7)
        return 1;
    if (n < 10)
        return 0;
    // Recur for ( num / 10 - 2 * num % 10 )
    return isDivisible7(n / 10 - 2 * (n - n / 10 * 10));
}

int main(int argc, char const *argv[])
{
    int num = 616;
    std::cout << (isDivisible7(num) ? "Divisible by 7" : "not Divisible by 7") << std::endl;
    remove(argv[0]);
    return 0;
}
