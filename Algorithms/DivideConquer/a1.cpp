/*Write a program to calculate pow(x,n)
Difficulty Level : Easy
Last Updated : 22 Jun, 2021
 
Given two integers x and n, write a function to compute xn. We may assume that x and n are small and overflow doesn’t happen.


Examples : 

Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49*/

/*
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);      
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 
*/

#include <iostream>
u_int32_t pow(u_int32_t x, u_int32_t n)
{
//     Algorithmic Paradigm: Divide and conquer.
// Above function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it. 
    u_int32_t temp;
    if(n==0)
        return 1;
    temp=pow(x,n/2);
    if(n&1)//odd
        return temp*temp*x;
    else
        return temp*temp;
}

int main(int argc, char const *argv[])
{
    std::cout<<"2^3: "<<pow(2,3)<<std::endl;
    remove(argv[0]);
    return 0;
}
